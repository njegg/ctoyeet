#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 *  Generates a unique 'yeet looking' string based on
 *  the bits of a provided number
 *  
 *      n |  bits  | string
 *      --+--------+-------
 *      0 |  0000  | yeet
 *      1 |  0001  | yeeT
 *           ...
 *      5 |  0101  | yEeT
 *           ...  
 *     69 | 101010 | YeEeEt
 *  
 *  Minimal length is 4, as numbers get bigger so do the strings
 */
char *generate_yeet(unsigned int n)
{
    /* Find the length of the string starting from 4 based on
     * the position of most significant bit with value 1
     * Example: 0000 -> 4, 1000 -> 4, 1010000 -> 7 */
    
    /* make n > 0, which prevents 0->'yeet'
     * 'yeet' is commonly used in this project and that can lead to problems
     * Example: #define yeet X, now if 'yeet' is used somewhere it will be replaced with X
     * Of course if any other 'yeet like' string is used there will be problems */
    n++;

    int bit = 16;               // start from fifth bit
    int yeet_size = 4;
    while (bit <= INT_MAX && n >= bit) {
        bit <<= 1;
        yeet_size++;
    }
    
    char *yeet = (char*) malloc(sizeof(char) * yeet_size);
    
    
    // Fill the string

    int capital; // if least significant bit is 1 - uppercase, else lowercase
    for (int i = yeet_size - 1; i >= 0; i--) {
        capital = n % 2;
        if      (i == 0)             yeet[i] = capital ? 'Y' : 'y'; // first  letter  'y'
        else if (i == yeet_size - 1) yeet[i] = capital ? 'T' : 't'; // middle letters 'e'
        else                         yeet[i] = capital ? 'E' : 'e'; // last   letter  't'

        n >>= 1; // get the next bit
    }

    return yeet;
}

int test(void)
/* int main() */
{
    char *yeet;
    for (int i = 0; i < 20; i++) {
        yeet = generate_yeet(i);
        printf("%s\n", yeet);
        free(yeet);
    }

    return 0;
}
