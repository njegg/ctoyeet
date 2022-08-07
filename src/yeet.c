#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "strstr_hashmap.h"
#include "yeet_generator.h"
#include <errno.h>
#include <string.h>

#define MAX_LINE 256
#define GO_TO_NEW_LINE 1
#define FIND_END_OF_COMMENT 2

/*
 * TODO:
 *
 * more errno and checks
 * free stuff
 * 
 * How it works:
 *      1. go through includes and write them to file
 *      2. from there go through code and fill the map
 *           - map = [code_string : yeet_string]
 *      3. after filling the map, contiue writing and write defines - #define KEY VAL
 *      4. read the original file after the includes part the same way, read a part of code
 *         find that part in map and write the yeet val from map in the new file.
 * */

int DEBUG_INFO = 1;

int extract_key_from_line(char **, char *);
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

    /*  TODO
     *  code bellow in a function
     *  so if there is an error the cleaning stuff is in one place
     *  (after calling the function) 
     */
    
    handle_includes_and_defines(fr, fw);

    if (ftell(fr) == 0) {
        printf("File is empty\n");
        return 0;
    }

    fseek(fr, -1, SEEK_CUR);

    hashmap *map = hm_create_size(101);

    // Filling the map with strings from file
    char *line = (char*) malloc(sizeof(char) * MAX_LINE);
    char *key = (char*) malloc(sizeof(char) * MAX_LINE);
    char *yeet;

    while (fgets(line, MAX_LINE, fr)) {
        int line_length = strlen(line);

        char *cp = line; // pointer to a char from a line
        while (*cp != '\0' &&  *cp!= EOF) {
            if (isspace(*cp)) {
                cp++;
                continue;
            }
            
            int extract_status = extract_key_from_line(&cp, key);
            if (extract_status == GO_TO_NEW_LINE) break;
            // TODO this is copy paste, can go in seperate function
            if (extract_status == FIND_END_OF_COMMENT) {
                // check line
                char *end_of_comment;
                int line_cnt = 0;
                int found_end = 0;
                
                // check in current line, if not found, check others
                do {
                    if (line_cnt) {
                        cp = line;
                    }
                    end_of_comment = strstr(cp, "*/");
                    
                    if (end_of_comment) {
                        cp = end_of_comment + 2; // continue after */
                        // TODO use break
                        found_end = 1;
                    }

                    line_cnt++;
                } while (!found_end && fgets(line, MAX_LINE, fr));

                if (!found_end) {
                    printf("NOT FOUND COMMENT END\n");
                    return 1;
                    // TODO FREE
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

    if (DEBUG_INFO) {
        printf("\nMAP:\n");
        hm_print(map);
        printf("\n");
    }

    char *error9 = "\"\\\"\"";
    char *from_map = hm_get(map, error9);
    printf("get: %s\n", from_map);
    char buf[MAX_LINE];

    add_defines(fw, map);

    // write the code using the map
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

            int extract_status = extract_key_from_line(&cp, key);
            if (extract_status == GO_TO_NEW_LINE) break;
            
            // TODO this is copy paste, can go in seperate function
            if (extract_status == FIND_END_OF_COMMENT) {
                // check line
                char *end_of_comment;
                int line_cnt = 0;
                int found_end = 0;
                
                // check in current line, if not found, check others
                do {
                    if (line_cnt) {
                        cp = line;
                    }
                    end_of_comment = strstr(cp, "*/");
                    
                    if (end_of_comment) {
                        cp = end_of_comment + 2; // continue after */
                        // TODO use break
                        found_end = 1;
                    }

                    line_cnt++;
                } while (!found_end && fgets(line, MAX_LINE, fr));

                if (!found_end) {
                    printf("NOT FOUND COMMENT END\n");
                    return 1;
                    // TODO FREE
                }

                continue;
            }

            printf("READ: %s\n", key);

            yeet = hm_get(map, key);

            if (!yeet) {
                printf("Not in map: '%s'\n", key);
                printf("line : %s\n", line);
                free(yeet);
                fclose(fr);
                fclose(fw);
                hm_destroy(map);
                return 1;
            }

            strcat(yeet, " ");
            fprintf(fw, "%s", yeet);
        }
    }

    if (yeet) free(yeet);
    hm_destroy(map);

    if (line) free(line);
    
    fclose(fr);
    fclose(fw);
    return 0;
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
    if (*cp == '/') {                           // maybe commnet 
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
