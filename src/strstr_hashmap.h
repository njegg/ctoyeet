/*
 * Basic hashmap with string key and string value
 */

typedef char * K;
typedef char * V;

typedef struct node
{
    K key;
    V val;
    struct node *next;
} node;

typedef struct hashmap
{
    node **table;
    size_t table_size;
    int size;
} hashmap;

typedef struct search_chain_res
{
    node *prev; //!< node that is behind searched node, if found
    node *res;  //!< node that is being searched
} search_chain_res;


/**
 * @brief           Creates a hashmap
 * @details         Should be freed with hm_destroy(hashmap *)
 */
hashmap *hm_create(size_t table_size);

/**
 * @brief           Frees all elements (nodes) in the map and the map itself
 */
void hm_destroy(hashmap *map);


// Basic operations

int hm_print(hashmap* map);
int hm_put(hashmap *map, K key, V val);
int hm_remove(hashmap *map, K key);
int hm_replace(hashmap *map, K key, V new_val);
V hm_get(hashmap *map, K key);

/**
 * @brief           String hash function borrowed from http://www.cse.yorku.ca/~oz/hash.html
 */
unsigned long hash_table_index(size_t table_size, K key);
