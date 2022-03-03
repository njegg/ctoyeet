#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char *generate(int n)
{
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

int main_test_generate(void)
{
    int n = 0;

    while (n >= 0) {
        printf("> ");
        scanf("%i", &n);
        char *yeet = generate(n);
        printf("generated yeet for %i = %s\n\n", n, yeet);
    }

    return 0;
}

