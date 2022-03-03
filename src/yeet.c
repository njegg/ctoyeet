#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "strstr_hashmap.h"
#include "yeet_generator.h"

int main(int argc, char **args)
{
    printf("argc = %i\n", argc);
    if (argc < 2) {
        printf("You need to pass a file name as an argumetn\n");
        return 1;
    }

    FILE *fr = fopen(args[1], "r");
    FILE *fw = fopen("yeet_out.c", "w");
    
    hashmap *map = hm_create_size(101);

    char c;
    char buf[64];
    char *yeet;
    while ((c = fgetc(fr)) != EOF) {

        if (!isspace(c)) {
            fprintf(fw , "%c", c);
        } else {
            ungetc(c, fr);
            fscanf(fr, "%s", buf);
            buf[(int)(strlen(buf))] = '\0';

            yeet = generate(map->size);   
            char *key = (char*) malloc(sizeof(char) * strlen(buf));
            strcpy(key, buf);
            
            printf("%s : %i\n", key, (int)strlen(buf));

            int added = hm_put(map, key, yeet);
            if (added) {
                printf("ADDED entry: \"%s\" : \"%s\"\n", key, yeet);
            } else {
                printf("FAILED entry: \"%s\" : \"%s\"\n", key, yeet);
            }
        } 
    }

    hm_print(map);
    hm_destroy(map);
    
    fclose(fr);
    fclose(fw);
    return 0;
}


