#include <stdio.h>
#include "hashmap.h"

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

