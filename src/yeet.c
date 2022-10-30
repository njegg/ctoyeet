/*
 * TODO:
 *  more errno and checks
 *  free stuff
 *  defines ?
 *  better main
 *
 * 
 * How it works:
 *      1. copy #include's and #define's to output file
 *      2. go through rest of the code and fill the map: [code_string : yeet_string]
 *      3. contiue writing to output and write defines from the map - #define KEY VAL
 *      4. read a part of code from the input file, find that part in map and write
 *         the value from map in the new file.
 *
 *  At the end, it will look something like this:
 *  
 *  input:
 *      int i = 0;
 *
 *  output:
 *      #define yeeT int
 *      #define yEet i
 *      #define yEeT =
 *      #define yEEt 0;
 *      
 *      yeeT yEet yEeT yEEt 
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>

#include "strstr_hashmap.h"
#include "yeet_generator.h"

#define MAX_LINE 256
#define GO_TO_NEW_LINE 1
#define FIND_END_OF_COMMENT 2

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
    if (argc == 1) {
        printf("Usage:\n$ yeet input.c [output.c]");
        return EXIT_SUCCESS;
    }

    char *write_file   = argc > 2 ? args[2] : "out.c";
    int write_file_len = strlen(write_file);

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

    handle_includes_and_defines(fr, fw);
    
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
    char *key = (char*) malloc(sizeof(char) * MAX_LINE);    // key for map
    char *line = (char*) malloc(sizeof(char) * MAX_LINE);   // buffer for reading a file


    int yeet_was_a_success = 
           fill_map(map, line, yeet, key, fr, fw)
        && write_to_file_from_map(map, line, yeet, key, fr, fw);
    
    if (yeet_was_a_success && DEBUG_INFO) hm_print(map);

    // Memory cleanup
    fclose(fr);
    fclose(fw);
    fclose(fw_h);

    hm_destroy(map);

    if (yeet) free(yeet);
    if (line) free(line);
    if (key)  free(key);
    
    return yeet_was_a_success ? EXIT_SUCCESS : EXIT_FAILURE;
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
                    return 0;
                }

                continue;
            }

            yeet = generate_yeet(map->size);
            int added = hm_put(map, key, yeet);

            if (DEBUG_INFO) {
                printf("%s: '%s' : '%s'\n", added ? "ADDED" : "FAILED", key, yeet);
                printf("+%li, cp -> %c\n", strlen(key), *cp);
            }
        }
    }

    return 1;
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
                    return 0;
                }

                continue;
            }

            if (DEBUG_INFO) {
                printf("READ: %s\n", key);
            }

            yeet = hm_get(map, key);

            if (!yeet) {
                printf("NOT IN MAP: '%s'\n", key);
                printf("LINE : %s\n", line);
                return 0;
            }

            strcat(yeet, " ");
            fprintf(fw, "%s", yeet);
        }
    }

    return 1;
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
