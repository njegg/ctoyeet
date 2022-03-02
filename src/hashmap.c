#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"

hashmap *hm_create();
hashmap *hm_create_size(size_t table_size);
void hm_destroy(hashmap *map);

int hm_put(hashmap *map, K key, V val);
int hm_remove(hashmap *map, K key);
int hm_replace(hashmap *map, K key, V new_val);
V hm_get(hashmap *map, K key);
int key_hash(size_t table_size, K key);

typedef struct search_chain_res
{
    node *prev;
    node *res;
} search_chain_res;


search_chain_res *search_chain(hashmap *map, K key)
{
    search_chain_res *res = (search_chain_res*) malloc(sizeof(search_chain_res));
    
    int hash = key_hash(map->table_size, key);
    
    node *cur = map->table[hash];

    if (cur->key == key) {
        res->prev = NULL;
        res->res = cur;
        return res;
    }

    while (cur->next) {
        if (cur->next->key == key) {
            res->prev = cur;
            res->res = cur->next;
            return res;
        }
        cur = cur->next;
    }

    return res;
}

int key_hash(size_t table_size, K key)
{
    return (int) key % table_size;
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
        printf("%i -> [ ", i);      
        if (map->table[i] != NULL)
        {
            node *cur = map->table[i];
            while (cur)
            {
                printf("'%c->%i' ", cur->key, cur->val);
                cur = cur->next;
            }
        }
        printf("]\n");
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

    int hash = key_hash(map->table_size, key);

    node *new_node = (node*) malloc(sizeof(node));
    new_node->key = key;
    new_node->val = val;

    new_node->next = map->table[hash];
    map->table[hash] = new_node;

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
        return NOKEY;
    }
    
    return res->res->val;
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
        node **root = &map->table[key_hash(map->table_size, key)];
        *root = (*root)->next;
        free(res->res);
    } else {
        node *del = res->res;
        res->prev->next = res->res->next;
        free(del);
    }

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


int main(void)
{
    hashmap* map = hm_create_size(3);

    hm_put(map, 'u', 21);
    hm_put(map, 'a', 1);
    hm_put(map, 'c', 3);
    hm_put(map, 'b', 2);
    hm_put(map, 'g', 5);

    printf("%c -> %i\n", 'u', hm_get(map, 'u'));

    hm_print(map);
    printf("\n");

    /* hm_remove(map, 'u'); */
    hm_remove(map, 'c');
    /* hm_remove(map, 'g'); */

    hm_print(map);
    printf("\n");

    printf("%c -> %i\n", 'u', hm_get(map, 'u'));
    printf("%c -> %i\n", 'a', hm_get(map, 'a'));
    printf("\n");

    hm_replace(map, 'a', 69);

    printf("%c -> %i\n", 'a', hm_get(map, 'a'));
    hm_print(map);
    printf("\n");

    hm_remove(map, 'a');

    hm_print(map);
    printf("\n");
    return 0;
}

