#include <stdio.h>

#define SHORT_INPUT "d02_short_input"
#define INPUT	    "d02_input"


void main(void) {

	FILE *fp = fopen(INPUT, "r");

	if (fp == NULL) {
		printf("cant read file");
		return;
	}

	int x = 0, y = 0;

	char word[16];
	int move;

	while(fscanf(fp, "%s ", word) != EOF) {

		fscanf(fp, "%i", &move);
		
		if      (word[0] == 'f') x += move;
		else if (word[0] == 'u') y -= move;
		else    		         y += move;
	}

	printf("forward = %i; depth = %i\n", x, y);
	printf("resault = %i", x*y);

}
