#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <ctype.h>

#define NOKEY 1<<31

#define MAX_LINE 256
#define GO_TO_NEW_LINE 1
#define FIND_END_OF_COMMENT 2

// yeet_generator.h

char *generate(int n);

// yeet_generator.c

char *generate(int n)
{
    n++;
    int bit = 16;
    int yeet_size = 4;
    while (bit <= INT_MAX) {
        if (n < bit) break;
        bit <<= 1;
        yeet_size++;
    }
    
    char *yeet = (char*) malloc(sizeof(char) * yeet_size);

    int capital;
    for (int i = 0; i < yeet_size; i++) {
        capital = n % 2; // first right bit
        if (i == 0) {
            yeet[i] = capital ? 'Y' : 'y';
        } else if (i == yeet_size - 1) {
            yeet[i] = capital ? 'T' : 't';
        } else {
            yeet[i] = capital ? 'E' : 'e';
        }

        n >>= 1;
    }

    return yeet;
}


// strstr_hashmap.h


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


// strstr_hashmap.c


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

int DEBUG_INFO = 1;

int fill_map(hashmap *, char *, char *, char *, FILE *, FILE *);
int write_to_file_from_map(hashmap *, char *, char *, char *, FILE *, FILE *);
int extract_key_from_line(char **, char *);
void find_end_of_comment(char **, char *, FILE *);
int skip_to_code(FILE *);
void add_defines(FILE *, hashmap *);
int handle_includes_and_defines(FILE *, FILE *);

int main(int argc, char **args)
{
    if (argc > 3) {
        // TODO FIX
        printf("You need to pass a file name as an argument\n");
        return 1;
    }

    // Opening files

    FILE *fr = fopen(args[1], "r");
    if (!fr) {
        // TODO: ERRNO
        printf("Cant open file: \"%s\", maybe it doesn't exist\n", args[1]);
        return 1;
    }

    FILE *fw;
    char *write_file;
    if (argc == 3) {
        write_file = args[2];
    } else {
        write_file = "out.c";
    }

    fw = fopen(write_file, "w");
    if (!fw) {
        printf("Cant open file: '%s' for writing\n", write_file);
        return 1;
    }

    handle_includes_and_defines(fr, fw);
    
    if (ftell(fr) == 0) {
        printf("File is empty\n");
        return 0;
    }

    fseek(fr, -1, SEEK_CUR);

    // Initializing stuff

    hashmap *map = hm_create_size(101);

    char *yeet;                                             // value for map
    char *key = (char*) malloc(sizeof(char) * MAX_LINE);    // key for map
    char *line = (char*) malloc(sizeof(char) * MAX_LINE);   // buffer for reading a file


    int status = fill_map(map, line, yeet, key, fr, fw);
    if (DEBUG_INFO) {
        printf("\nMAP:\n");
        hm_print(map);
        printf("\n");
    }

    if (status == EXIT_SUCCESS) {
        status = write_to_file_from_map(map, line, yeet, key, fr, fw);
    }

    // Memory cleanup

    fclose(fr);
    fclose(fw);

    hm_destroy(map);

    if (yeet) free(yeet);
    if (line) free(line);
    if (key)  free(key);
    
    return status;
}

int fill_map(hashmap *map, char *line, char *yeet, char *key, FILE *fr, FILE *fw)
{
    while (fgets(line, MAX_LINE, fr)) {
        int line_length = strlen(line);

        char *cp = line; // pointer to a char from a line
        while (*cp != '\0' &&  *cp!= EOF) {
            if (isspace(*cp)) {
                cp++;
                continue;
            }
            
            int status = extract_key_from_line(&cp, key);

            if (status == GO_TO_NEW_LINE) {
                break;
            }

            if (status == FIND_END_OF_COMMENT) {
                find_end_of_comment(&cp, line, fr);
                if (!cp) {
                    printf("NOT FOUND COMMENT END\n");
                    printf("LINE: %s\n", line);
                    return EXIT_FAILURE;
                }

                continue;
            }

            yeet = generate(map->size);
            int added = hm_put(map, key, yeet);

            if (DEBUG_INFO) {
                printf("%s: '%s' : '%s'\n", added ? "ADDED" : "FAILED", key, yeet);
                printf("+%li, cp -> %c\n", strlen(key), *cp);
            }
        }
    }

    return EXIT_SUCCESS;
}

int write_to_file_from_map(hashmap *map, char *line, char *yeet, char *key, FILE *fr, FILE *fw)
{
    add_defines(fw, map);

    rewind(fr);
    skip_to_code(fr);

    fprintf(fw, "\n");

    while (fgets(line, MAX_LINE, fr)) {
        int line_length = strlen(line);

        char *cp = line; // string pointer
        while (*cp != '\0' &&  *cp!= EOF) {
            if (isspace(*cp)) {
                fprintf(fw, "%c", *cp);
                cp++;
                continue;
            }

            int status = extract_key_from_line(&cp, key);

            if (status == GO_TO_NEW_LINE) {
                break;
            }

            if (status == FIND_END_OF_COMMENT) {
                find_end_of_comment(&cp, line, fr);
                if (!cp) {
                    printf("NOT FOUND COMMENT END\n");
                    printf("LINE: %s\n", line);
                    return EXIT_FAILURE;
                }

                continue;
            }

            if (DEBUG_INFO) {
                printf("READ: %s\n", key);
            }

            yeet = hm_get(map, key);

            if (!yeet) {
                printf("Not in map: '%s'\n", key);
                printf("line : %s\n", line);
                return EXIT_FAILURE;
            }

            strcat(yeet, " ");
            fprintf(fw, "%s", yeet);
        }
    }

    return EXIT_SUCCESS;
}

/*
 *  line_pointer_pointer points to the pointer that points a char in a string 
 *  from there, find the part thats gonna be added to the map
 *  and store it in key
 *  move pointer to the next char <= this is why pointer to pointer is needed
 */
int extract_key_from_line(char **line_pointer_pointer, char *key) {
    char *cp = *line_pointer_pointer;

    // TODO change to if
    if (*cp == '/') {                           // maybe its a commnet 
        switch (*(cp + 1))
        {
            case '/': return GO_TO_NEW_LINE;
            case '*': return FIND_END_OF_COMMENT;

            default: break;
        }
    }

    char buf[MAX_LINE];
    strcpy(key, "");

    if (*cp == '\"') {                          // string
        strcat(key, "\"");
        sscanf(cp + 1, "%[^\"]s", key + 1);
        strcat(key, "\"");
        cp += strlen(key);

        while (*(cp - 2) == '\\') {             // ignore all escaped \"
            if (*cp == '\"') {
                strcat(key, "\"");
                cp++;
                continue;
            } else {
                sscanf(cp, "%[^\"]s", buf);
                strcat(key, buf);
                strcat(key, "\"");
                cp += strlen(buf) + 1;
            }
        }
    } else {                                    // not a string
        sscanf(cp, "%[^\n\" ]s", key);
        cp += strlen(key);

        if (*cp == '\"' && *(cp - 1) == '\\') { // \" but not in a string
            strcat(key, "\"");
            cp++;
            sscanf(cp, "%[^\"\n ]s", buf);
            strcat(key, buf);
            cp += strlen(buf);
        }
    }

    *line_pointer_pointer = cp;

    return 0;
}

/*
    Finds end of the multiline comment
    starts search at a current passed line
    if not there, reads the rest of the file 

    Returns the pointer inside of the line
*/
void find_end_of_comment(char **cpp, char *line, FILE *fr)
{
    char *cp = *cpp;
    int line_cnt = 0;

    cp = strstr(line, "*/");
    if (cp) {
        *cpp = cp + 2;
        return;
    }
    
    while (fgets(line, MAX_LINE, fr)) {
        cp = strstr(line, "*/");
        if (cp) {
            *cpp = cp + 2;
            return;
        }
    }

    *cpp = NULL;
}

int handle_includes_and_defines(FILE* fr, FILE* fw)
{
    char buf[MAX_LINE];
    while (1) {
        char c = fgetc(fr);
        if (c == EOF) {
            return 0;
        } else if (c == '#' || isspace(c)) {
            ungetc(c, fr);               // go back
            fgets(buf, MAX_LINE, fr);    // read
            fputs(buf, fw);              // write
        } else {
            return 1;
        }
    }
}

// skips lines that start with #include 
int skip_to_code(FILE* f)
{
    while (1) {
        char c = fgetc(f);
        if (c == EOF) {
            return 0;
        } else if (c == '#' || isspace(c)) {
            fscanf(f, "%*[^\n]\n");   
        } else {
            ungetc(c, f);
            return 1;
        }
    }
}

void add_defines(FILE *f, hashmap *map)
{
    for (int i = 0; i < map->table_size; i++) {
        node *cur = map->table[i];
        while (cur) {
            fprintf(f, "#define %s %s\n", cur->val, cur->key);      
            cur = cur->next;
        } 
    }
}
