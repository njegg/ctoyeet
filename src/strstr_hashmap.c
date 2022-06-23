#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strstr_hashmap.h"

hashmap *hm_create();
hashmap *hm_create_size(size_t table_size);
void hm_destroy(hashmap *map);

int hm_put(hashmap *map, K key, V val);
int hm_remove(hashmap *map, K key);
int hm_replace(hashmap *map, K key, V new_val);
V hm_get(hashmap *map, K key);
unsigned long place_in_table(size_t table_size, K key);

typedef struct search_chain_res
{
    node *prev;
    node *res;
} search_chain_res;


search_chain_res *search_chain(hashmap *map, K key)
{
    search_chain_res *res = (search_chain_res*) malloc(sizeof(search_chain_res));
    res->prev = NULL;
    res->res = NULL;

    int hash = place_in_table(map->table_size, key);
    node *cur = map->table[hash];

    if (!cur) { // not found
        return res;
    }

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

/*
 * borrowed from http://www.cse.yorku.ca/~oz/hash.html
 * */
unsigned long place_in_table(size_t table_size, K key)
{
        unsigned long hash = 5381;
        int c;

        while (c = *key++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash % table_size;
}

hashmap *hm_create_size(size_t table_size)
{
    hashmap *map = (hashmap*) malloc(sizeof(hashmap));
    map->table = (node**) malloc(sizeof(node*) * table_size);
    map->table_size = table_size;
    return map;
}

void hm_destroy(hashmap *map)
{
    // TODO
    free(map->table);
}

int hm_print(hashmap *map)
{
    if (!map)
    {
        printf("Map may not be initialised. Use hm_create_size(size_t table_size).\n");
        return 0;
    }

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
    if (!map)
    {
        printf("Map may not be initialised. Use hm_create_size(size_t table_size).\n");
        return 0;
    }

    search_chain_res *res = search_chain(map, key); 
    int exists = res->res != NULL;
    free(res);
    if (exists) {
        return 0;
    }

    int hash = place_in_table(map->table_size, key);

    node *new_node = (node*) malloc(sizeof(node));
    new_node->key = (char*) malloc(sizeof(char) * 128);
    new_node->val = (char*) malloc(sizeof(char) * 128);

    strcpy(new_node->key, key);
    strcpy(new_node->val, val);

    new_node->next = map->table[hash];
    map->table[hash] = new_node;

    map->size++;

    return 1;
}

V hm_get(hashmap *map, K key)
{
    if (!map) {
        printf("Map may not be initialised. Use hm_create_size(size_t table_size).\n");
        return 0;
    }
    
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
    if (!map) {
        printf("Map may not be initialised. Use hm_create_size(size_t table_size).\n");
        return 0;
    }

    search_chain_res *res = search_chain(map, key);

    if (!res->res) {
        return 0;
    }

    // remove root
    if (!res->prev) {
        node **root = &map->table[place_in_table(map->table_size, key)];
        *root = (*root)->next;
        free(res->res);
    } else {
        node *del = res->res;
        res->prev->next = res->res->next;
        free(del);
    }

    map->size--;

    return 0;
}

int hm_replace(hashmap *map, K key, V new_val)
{
    if (!map) {
        printf("Map may not be initialised. Use hm_create_size(size_t table_size).\n");
        return 0;
    }

    search_chain_res *res = search_chain(map, key);

    if (!res->res) {
        return 0;
    }

    res->res->val = new_val;

    return 1;
}


int main_f(void)
{
    hashmap* map = hm_create_size(3);

    hm_put(map, "asdjad", "bjabda");
    hm_put(map, "ass", "hole");
    hm_put(map, "yeetl", "jjj");
    hm_put(map, "90932", "2222");
    hm_put(map, "a0 0 0 ", "  9 9 9  ");
    hm_put(map, "a0 0 0 ", "  9 9 9  ");

    printf("%s -> %s\n", "a", hm_get(map, "A"));

    hm_print(map);
    printf("\n");

    hm_remove(map, "ass");
    hm_remove(map, "nonexistant");
    hm_remove(map, "ass");

    hm_print(map);
    printf("\n");

    printf("%s -> %s\n", "ass", hm_get(map, "ass"));
    printf("%s -> %s\n", "a0 0 0 ", hm_get(map, "a0 0 0 "));
    printf("\n");

    hm_replace(map, "a0 0 0 ", "new stuuf");

    printf("%s -> %s\n", "a0 0 0 ", hm_get(map, "a0 0 0 "));
    hm_print(map);
    printf("\n");

    hm_remove(map, "a0 0 0 ");

    hm_print(map);
    printf("\n");
    
    hm_destroy(map);

    return 0;
}

