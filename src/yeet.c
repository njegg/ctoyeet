#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "strstr_hashmap.h"
#include "yeet_generator.h"
#include <errno.h>
#include <string.h>

/*
 * TODO:
 * in a while where reading a file
 * add else if that checks if c is []()#=,...
 * dont forget to add space when writing
 * if its a '"' just leave it
 *
 * BUG: sometimes inserts ^E, its not generate(), but its in the map
 * look vefore inserting in map, maybe length etc
 *
 *
 * !! '\"' <- its gonna thing its the end of the string
 * comments
 *
 *
 * How it works:
 * 1. skip includes and write them to file
 * 2. from there go through code and fill the map
 *      - map = [code_string : yeet_string]
 * 3. after filling the map, contiue writing and write defines
 * 4. read the original file after the includes part the same way
 *    like when filling the map, but now after reading a part of code
 *    find that part in map and write the val from map in the new file.
 * */

#define MAX_LINE 256

int DEBUG_INFO = 1;

void extract_key_from_line(char **, char *);
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
        while (*cp != '\0' &&  *cp!= EOF && *cp != '\n') {
            if (isspace(*cp)) {
                cp++;
                continue;
            }
            
            extract_key_from_line(&cp, key);
            
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

    add_defines(fw, map);

    // write the code using the map
    rewind(fr);
    skip_to_code(fr);
    fprintf(fw, "\n");

    while (fgets(line, MAX_LINE, fr)) {
        int line_length = strlen(line);

        char *cp = line; // string pointer
        while (*cp != '\0' &&  *cp!= EOF && *cp != '\n') {
            if (isspace(*cp)) {
                fprintf(fw, "%c", *cp);
                cp++;
                continue;
            }

            extract_key_from_line(&cp, key);
            
            yeet = hm_get(map, key);
            if (!yeet) {
                printf("Not in map: '%s'\n", key);
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
void extract_key_from_line(char **line_pointer_pointer, char *key) {
    char *cp = *line_pointer_pointer;

    if (*cp == '\"') {
        strcpy(key, "\"");
        sscanf(cp+1, "%[^\"]s", key+1);
        strcat(key, "\"");
    } else {
        sscanf(cp, "%[^\n\" ]s", key); // TODO CHECK

        if (*cp == '\"') {
            //                    
        }
    }
        
    *line_pointer_pointer += strlen(key);
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
        /* fprintf(f, "\n"); */
    }
}

