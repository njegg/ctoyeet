#include <stdio.h>

#define SHORT_INPUT "d02_short_input"
#define INPUT	    "d02_input"


void main(int argc) {

	FILE *fp = fopen(argc > 1 ? INPUT : SHORT_INPUT, "r");

	if (fp == NULL) {
		printf("cant read file");
		return;
	}
    
    char c = '\"';
    char *s = "asdasd"

	int x = 0, y = 0, aim = 0;

	char word[16];
	int move;

	while(fscanf(fp, "%s %i", word, &move) != EOF) {
		
		if (word[0] == 'f') {
			x += move;
			y += aim * move;
		} else {
			aim += word[0] == 'd' ? move : -move;
		}

	}

	printf("forward = %i; depth = %i\n", x, y);
	printf("resault = %i", x*y);

}
