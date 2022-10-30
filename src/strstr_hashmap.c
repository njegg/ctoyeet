/*
 * Basic hashmap with string key and string value
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strstr_hashmap.h"

int check_map_created(hashmap *map) {
    if (!map) {
        printf("Map may not be created. Use hm_create(size_t table_size).\n");
        return 0;
    }
    
    return 1;
}

/*
 * @brief Searches the map and returns the element whose key is matching the one provided
 * @param map pointer to a hashmap
 * @param key searches the map with key
 * @returns search_chain_res struct with pointer to target element and one behind him or NULL if not found
 */
search_chain_res *search_chain(hashmap *map, K key)
{
    search_chain_res *res = (search_chain_res*) malloc(sizeof(search_chain_res));
    res->prev = NULL;
    res->res = NULL;
    
    if (!check_map_created(map)) return 0;

    int hash = hash_table_index(map->table_size, key);
    node *cur = map->table[hash];

    if (!cur) return res; // not found

    if (strcmp(cur->key, key) == 0) {
        res->res = cur;
        return res;
    }

    while (cur->next) {
        if (strcmp(cur->next->key, key) == 0) {
            res->prev = cur;
            res->res = cur->next;
            return res;
        }
        cur = cur->next;
    }

    return res;
}

unsigned long hash_table_index(size_t table_size, K key)
{
        unsigned long hash = 5381;
        int c;

        while (c = *key++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash % table_size;
}

hashmap *hm_create(size_t table_size)
{
    hashmap *map = (hashmap*) malloc(sizeof(hashmap));
    map->table = (node**) calloc(table_size, sizeof(node*));
    map->table_size = table_size;

    return map;
}

int hm_print(hashmap *map)
{
    if (!check_map_created(map)) return 0;

    for (int i = 0; i < map->table_size; i++)
    {
        if (map->table[i] != NULL)
        {
            printf("%i -> [ ", i);      
            node *cur = map->table[i];
            while (cur)
            {
                printf("'%s->%s' ", cur->key, cur->val);
                cur = cur->next;
            }
            printf("]\n");
        }
    }

    return 1;
}

int hm_put(hashmap *map, K key, V val)
{
    if (!check_map_created(map)) return 0;

    search_chain_res *res = search_chain(map, key); 
    if (res->res != NULL) {
        free(res);
        return 0;
    }

    int hash = hash_table_index(map->table_size, key);

    node *new_node = (node*) malloc(sizeof(node));
    new_node->key = (char*) malloc(sizeof(char) * 128);
    new_node->val = (char*) malloc(sizeof(char) * 128);

    strcpy(new_node->key, key);
    strcpy(new_node->val, val);

    new_node->next = map->table[hash];
    map->table[hash] = new_node;

    map->size++;

    free(res);
    return 1;
}

V hm_get(hashmap *map, K key)
{
    if (!check_map_created(map)) return 0;
    
    search_chain_res *res = search_chain(map, key);

    if (!res->res) {
        free(res);
        return NULL;
    }
    
    V val = res->res->val;

    free(res);
    return val;
}

int hm_remove(hashmap *map, K key)
{
    if (!check_map_created(map)) return 0;

    search_chain_res *res = search_chain(map, key);

    if (!res->res) {
        free(res);
        return 0;
    }

    // remove root
    if (!res->prev) {
        node **root = &map->table[hash_table_index(map->table_size, key)];
        *root = (*root)->next;
        free(res->res);
    } else {
        node *del = res->res;
        res->prev->next = res->res->next;
        free(del);
    }

    map->size--;

    free(res);
    return 0;
}

int hm_replace(hashmap *map, K key, V new_val)
{
    if (!check_map_created(map)) return 0;

    search_chain_res *res = search_chain(map, key);

    if (!res->res) {
        free(res);
        return 0;
    }

    res->res->val = new_val;
    
    free(res);
    return 1;
}


void free_chain(node *head) {
    if (!head) return;
    free_chain(head->next);

    free(head->key);
    free(head->val);
    free(head);
}

void hm_destroy(hashmap *map)
{
    for (int i = 0; i < map->table_size; i++)
        free_chain(map->table[i]);

    free(map->table);
    free(map);
}
