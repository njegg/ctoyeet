#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <limits.h>
#include <stdarg.h>
#include <ctype.h>
     

#define MAX_LINE 256
#define SINGLE_LINE_COMMENT 1
#define MULTILINE_COMMENT 2

#define PUNCTS "(),;[]"
#define SSCANF_NON_STRING_FORMAT "%[^]\n\"()\[,; ]s"
#define SSCANF_STRING_FORMAT "%[^\"]s"

char *generate_yeet(unsigned int n)
{
    n++;

    int bit = 16;               // start from fifth bit
    int yeet_size = 4;
    while (bit <= INT_MAX && n >= bit) {
        bit <<= 1;
        yeet_size++;
    }
    
    char *yeet = (char*) malloc(sizeof(char) * yeet_size + 1);
    yeet[yeet_size] = '\0';
    
    // Fill the string

    int capital; // if least significant bit is 1 - uppercase, else lowercase
    for (int i = yeet_size - 1; i >= 0; i--) {
        capital = n % 2;
        if      (i == 0)             yeet[i] = capital ? 'Y' : 'y'; // first  letter  y
        else if (i == yeet_size - 1) yeet[i] = capital ? 'T' : 't'; // last   letter  t
        else                         yeet[i] = capital ? 'E' : 'e'; // middle letters e

        n >>= 1; // get the next bit
    }

    return yeet;
}


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


int check_map_created(hashmap *map) {
    if (!map) {
        printf("Map may not be created. Use hm_create(size_t table_size).\n");
        return 0;
    }
    
    return 1;
}

/**
 * @brief           Searches the map and returns the element whose key is matching the one provided
 * @returns         Struct with pointer to target element and one behind him or NULL if not found:
 * @code{.c}
 * typedef struct search_chain_res
 * {
 *     node *prev;
 *     node *res;
 * } search_chain_res;
 * @endcode
 */
search_chain_res *search_chain(hashmap *map, K key)
{
    search_chain_res *res = (search_chain_res*) malloc(sizeof(search_chain_res));
    res->prev = NULL;
    res->res = NULL;
    
    if (!check_map_created(map)) return 0;

    size_t hash = hash_table_index(map->table_size, key);
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
        unsigned char c;

        while ((c = *key++))
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

char *rtrim(char *s)
{
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}

int hm_put(hashmap *map, K key, V val)
{
    if (!check_map_created(map)) return 0;

    search_chain_res *res = search_chain(map, key); 
    if (res->res != NULL) {
        free(res);
        return 0;
    }

    size_t hash = hash_table_index(map->table_size, key);

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
    return rtrim(val);
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


int DEBUG_INFO = 0;

int fill_map(hashmap *map, char *line, char *yeet, char *token, FILE *fr);
int write_to_file_from_map(hashmap *map, char *line, char *yeet, char *token, FILE *fr, FILE *fw, FILE *fw_h);
int extract_token_from_line(char **token_start, char *token);
void find_end_of_comment(char **, char *, FILE *);
int skip_to_code(FILE *);
void add_defines(FILE *, hashmap *);
int handle_includes_and_defines(FILE *, FILE *);

int main(int argc, char **args)
{
    if (argc == 1) {
        printf("Usage:\n$ yeet input.c [output.c]");
        return EXIT_SUCCESS;
    }

    char *write_file   = argc > 2 ? args[2] : "out.c";
    size_t write_file_len = strlen(write_file);

    if (write_file_len < 3 || write_file[write_file_len - 1] != 'c') {
        printf("ERROR: Output file name must be a '.c' file\n");
        return EXIT_FAILURE;
    }

    // Create a header file, name is the same as the output file but ends with h
    char write_file_h[write_file_len];
    strncpy(write_file_h, write_file, write_file_len);
    write_file_h[write_file_len - 1] = 'h';


    // Opening files, if one fails, dont continue, but close ones opened before
    FILE *fr = NULL, *fw = NULL, *fw_h = NULL;
    int fopen_errno = 0;

    if (!(fr = fopen(args[1], "r"))) {
        fopen_errno = errno;
    }

    if (!fopen_errno && !(fw = fopen(write_file, "w"))) {
        fopen_errno = errno;
    }

    if (!fopen_errno && !(fw_h = fopen(write_file_h, "w"))) {
        fopen_errno = errno;
    }
    
    if (fopen_errno) {
        printf("Error while opening files: %s\n", strerror(fopen_errno));
        if (fr)   fclose(fr);
        if (fw)   fclose(fw);
        if (fw_h) fclose(fw_h);
        return EXIT_FAILURE;
    }

    handle_includes_and_defines(fr, fw_h);
    
    fprintf(fw, "#include \"%s\"", write_file_h);
    
    if (ftell(fr) == 0) {
        printf("File is empty\n");
        fclose(fr);
        fclose(fw);
        fclose(fw_h);
        return EXIT_FAILURE;
    }

    fseek(fr, -1, SEEK_CUR);


    // Initialization
    hashmap *map = hm_create(101);

    char *yeet = NULL;                                      // value for map
    char *token = (char*) malloc(sizeof(char) * MAX_LINE);    // token for map
    char *line = (char*) malloc(sizeof(char) * MAX_LINE);   // buffer for reading a file

    int fill_map_ok = fill_map(map, line, yeet, token, fr);
    if (fill_map_ok && DEBUG_INFO) hm_print(map);

    int all_good =
            fill_map_ok &&
            write_to_file_from_map(map, line, yeet, token, fr, fw, fw_h);

    if (!all_good) fprintf(stderr, "Something went wrong");


    // Memory cleanup
    fclose(fr);
    fclose(fw);
    fclose(fw_h);

    hm_destroy(map);

    if (yeet) free(yeet);
    if (line) free(line);
    if (token)  free(token);
    
    return all_good ? EXIT_SUCCESS : EXIT_FAILURE;
}

/**
 * Fills the map with key = code_token, value = yeet_token
 * Reads the file line by line. From each line get the token,
 * and add it to the map as a key, and as a value, add the value from the
 * generate(int) function
 * 1 if ok; 0 if not ok
 */
int fill_map(hashmap *map, char *line, char *yeet, char *token, FILE *fr)
{
    while (fgets(line, MAX_LINE, fr)) {
        char *cp = line; // pointer to a char from a line

        while (*cp != '\0' &&  *cp!= EOF) {
            if (isspace(*cp)) {
                cp++;
                continue;
            }
            
            int status = extract_token_from_line(&cp, token);

            if (status == SINGLE_LINE_COMMENT) { // found a comment or something
                break;
            }

            if (status == MULTILINE_COMMENT) { // found start of multiline comment, search for end
                find_end_of_comment(&cp, line, fr);

                if (!cp) {
                    fprintf(stderr, "Not found comment end\n");
                    fprintf(stderr, "Line: %s\n", line);
                    return 0;
                }

                continue;
            }

            yeet = generate_yeet(map->size);
            int added = hm_put(map, token, yeet); // add a key and a unique string from generate(int)

        }
    }
    
    return 1;
}

/**
 * Replaces source code tokens with corresponding 'yeet' tokens from the map
 * Reads the source code file once again and for each token it gets the value
 * from the map and writes that to the output file. Before that it adds defines
 * to the header file
 * 1 if ok; 0 if not ok
 */
int write_to_file_from_map(hashmap *map, char *line, char *yeet, char *token, FILE *fr, FILE *fw, FILE *fw_h)
{
    add_defines(fw_h, map); // Write #define * * to the header file

    rewind(fr);
    skip_to_code(fr);

    fprintf(fw, "\n");

    while (fgets(line, MAX_LINE, fr)) {
        char *cp = line; // string pointer
        while (*cp != '\0' &&  *cp!= EOF) {
            if (isspace(*cp)) {
                fprintf(fw, "%c", *cp);
                cp++;
                continue;
            }

            int status = extract_token_from_line(&cp, token);

            if (status == SINGLE_LINE_COMMENT) {
                break;
            }

            if (status == MULTILINE_COMMENT) {
                find_end_of_comment(&cp, line, fr);
                if (!cp) {
                    printf("NOT FOUND COMMENT END\n");
                    printf("LINE: %s\n", line);
                    return 0;
                }

                continue;
            }

            if (DEBUG_INFO) {
                printf("READ: %s\n", token);
            }

            yeet = hm_get(map, token);

            if (!yeet) {
                printf("NOT IN MAP: '%s'\n", token);
                printf("LINE : %s\n", line);
                return 0;
            }

            strcat(yeet, " ");
            fprintf(fw, "%s", yeet);
        }
    }

    return 1;
}

/**
 * From the pointer token_start find the end of the token
 * and copy it to token if it's not a comment or similar.
 * token_start - points to the character where the token starts.
 * token - pointer to memory where the token is gonna be stored.
 * 1 for ok or 0 for not ok
 */
int extract_token_from_line(char **token_start, char *token) {
    char *cp = *token_start;

    if (*cp == '/') { // found comment
        char next = *(cp + 1);
        if (next == '/') return SINGLE_LINE_COMMENT;
        if (next == '*') return MULTILINE_COMMENT;
    }

    char buf[MAX_LINE];
    strcpy(token, "");

    if (strchr(PUNCTS, *cp)) {
        // Punctuation mark found

        char punct[2];
        punct[0] = *cp;
        punct[1] = '\0';
        strcpy(token, punct);
        cp++;
    } else if (*cp == '\"') {
        // String found

        strcat(token, "\"");
        sscanf(cp + 1, SSCANF_STRING_FORMAT, token + 1); // Scan till next '"' - could be escaped
        strcat(token, "\"");
        cp += strlen(token);

        while (*(cp - 2) == '\\') { // ignore all escaped \", find real end of the string
            if (*cp == '\"') {
                strcat(token, "\"");
                cp++;
                continue;
            } else {
                sscanf(cp, SSCANF_STRING_FORMAT, buf);
                strcat(token, buf);
                strcat(token, "\"");
                cp += strlen(buf) + 1;
            }
        }
    } else {
        // Not a string

        sscanf(cp, SSCANF_NON_STRING_FORMAT, token);
        cp += strlen(token);

        if (*cp == '\"' && *(cp - 1) == '\\') { // char c = '\"';
            strcat(token, "\"");
            cp++;
            sscanf(cp, SSCANF_NON_STRING_FORMAT, buf);
            strcat(token, buf);
            cp += strlen(buf);
        }
    }

    *token_start = cp; // Update pointer

    return 0;
}

/**
 * Finds end of the multiline comment
 * Starts search at a current passed line
 * If not there, reads the rest of the file.
 * cpp - pointer to a character inside line.
 * line - buffer.
 * fr - source code file.
*/
void find_end_of_comment(char **cpp, char *line, FILE *fr)
{
    char *cp = strstr(line, "*/");
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

/**
 * Reads #include and #define lines from source file
 * and writes them to output file.
 * 1 if ok. 0 if not ok
 */
int handle_includes_and_defines(FILE* fr, FILE* fw)
{
    char buf[MAX_LINE];
    while (1) {
        char c = fgetc(fr);
        if (c == EOF) {
            return 0;
        } else if (c == '#' || isspace(c)) {
            ungetc(c, fr);                  // go back
            fgets(buf, MAX_LINE, fr);  // read
            fputs(buf, fw);              // write
        } else {
            return 1;
        }
    }
}

/**
 * Skips #include and #define lines
 * If #define is in the middle of the source code - rip
 * 1 if ok; 0 if not ok
 */
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

/**
 * Reads from the map and writes #define key value to output header file
 */
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


