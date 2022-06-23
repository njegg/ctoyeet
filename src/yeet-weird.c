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

int skip_to_code(FILE* f);
void add_defines(FILE *f, hashmap *map);
int handle_inclueds_and_defines(FILE* fr, FILE* fw);

int main(int argc, char **args)
{
    if (argc > 3) {
        // TODO FIX
        printf("You need to pass a file name as an argumetn\n");
        return 1;
    }

    FILE *fr = fopen(args[1], "r");
    if (!fr) {
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
    
    handle_inclueds_and_defines(fr, fw);

    if (ftell(fr) == 0) {
        printf("File is empty\n");
        return 0;
    }

    fseek(fr, -1, SEEK_CUR);

    hashmap *map = hm_create_size(2);

    // fill the map
    char c, prevc;
    char buf[64];
    char buf2[64];
    char *yeet;
    char *key = (char*) malloc(sizeof(char) * strlen(buf));
    while ((c = fgetc(fr)) != EOF) {
        // if it finds \", its 
        if (c == '\\') {
            char next = fgetc(fr);
            char escaped[3] = {c, next, '\0'};
            strcpy(key, escaped);

            yeet = generate(map->size);   
            int added = hm_put(map, key, yeet);

            if (added) {
                printf("ADDED entry: '%s' : '%s'\n", key, yeet);
            } else {
                printf("FAILED entry: '%s' : '%s'\n", key, yeet);
            }

        } else if (c == '\"' && prevc == '\\') {
            printf("\nfound bad\n");
        } else if (c == '\"') { // read the whole string
            strcpy(buf, "\"");
            fscanf(fr, "%[^\"]s", buf2);
            strcat(buf, buf2);
            strcat(buf, "\"");

            printf("found string: '%s'\n", buf);

            yeet = generate(map->size);

            strcpy(key, buf);

            int added = hm_put(map, key, yeet);
            if (added) {
                printf("ADDED entry: '%s' : '%s'\n", key, yeet);
            } else {
                printf("FAILED entry: '%s' : '%s'\n", key, yeet);
            }

            fgetc(fr);

        } else if (!isspace(c)) {
            ungetc(c, fr);
            fscanf(fr, "%[^\"\n\\ ]s", buf);
            /* fscanf(fr, "%s", buf); */

            yeet = generate(map->size);   
            strcpy(key, buf);
            
            int added = hm_put(map, key, yeet);
            if (added) {
                printf("ADDED entry: '%s' : '%s'\n", key, yeet);
            } else {
                printf("FAILED entry: '%s' : '%s'\n", key, yeet);
            }
        } 
        prevc = c;
    }

    printf("\nMAP:\n");
    hm_print(map);

    add_defines(fw, map);

    // write the code using the map
    rewind(fr);
    skip_to_code(fr);
    fprintf(fw, "\n");

    while ((c = fgetc(fr)) != EOF) {
        if (isspace(c)) {
            fprintf(fw , "%c", c);
        } else if (c == '\\') {
            char next = fgetc(fr);
            char escaped[3] = {c, next, '\0'};
            strcpy(buf, escaped);

            yeet = hm_get(map, buf);
            if (yeet == NULL) {
                printf("Not in map: '%s'\n", buf);
                free(yeet);
                fclose(fr);
                fclose(fw);
                hm_destroy(map);
                return 1;
            }

            strcat(yeet, " ");
            fprintf(fw, "%s", yeet);
        } else if (c == '\"') {
            // found '\"'
            strcpy(buf, "\"");
            fscanf(fr, "%[^\"]s", buf2);
            /* if (c != '\"') { */
            /*     printf("Error while looking for other '\"'\nc='%c'\nbuffers:\n1: %s\n2: %s\n", c,buf, buf2); */
            /*     return 1; */
            /*     // TODO FREE and CLOSE */
            /* } */
            strcat(buf, buf2);
            strcat(buf, "\"");
            fgetc(fr); // \" at the end of string

            yeet = hm_get(map, buf);
            if (yeet == NULL) {
                printf("Not in map: '%s'\n", buf);
                free(yeet);
                fclose(fr);
                fclose(fw);
                hm_destroy(map);
                return 1;
            }

            strcat(yeet, " ");
            fprintf(fw, "%s", yeet);
        } else {
            ungetc(c, fr);
            /* fscanf(fr, "[^\"\n ]%s", buf); */
            fscanf(fr, "%[^\"\n\\ ]s", buf);
            /* buf[(int)(strlen(buf))] = '\0'; */

            /* yeet = generate(map->size); */   
            /* char *key = (char*) malloc(sizeof(char) * strlen(buf)); */
            /* strcpy(key, buf); */
            
            yeet = hm_get(map, buf);
            if (yeet == NULL) {
                printf("Not in map: %s\n", buf);
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
    
    fclose(fr);
    fclose(fw);
    return 0;
}


int handle_inclueds_and_defines(FILE* fr, FILE* fw)
{
    char buf[256];
    while (1) {
        char c = fgetc(fr);
        if (c == EOF) {
            return 0;
        } else if (c == '#' || isspace(c)) {
            ungetc(c, fr);          // go back
            fgets(buf, 256, fr);    // read
            fputs(buf, fw);         // write
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

