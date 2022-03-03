#include <stdio.h>

typedef char * K;
typedef char * V;
#define NOKEY 1<<31

typedef struct node
{
    K key;
    V val;
    struct node *next;
} node;

typedef struct hashmap
{
    node **table; // array of pointers to nodes
    size_t table_size;
    int size;
} hashmap;

hashmap *hm_create();
hashmap *hm_create_size(size_t table_size);
void hm_destroy(hashmap *map);
int hm_print(hashmap* map);

int hm_put(hashmap *map, K key, V val);
int hm_remove(hashmap *map, K key);
int hm_replace(hashmap *map, K key, V new_val);
V hm_get(hashmap *map, K key);
unsigned long place_in_table(size_t table_size, K key);

