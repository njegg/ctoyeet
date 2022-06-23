compile:
	gcc src/strstr_hashmap.c src/yeet_generator.c  src/yeet.c -o yeet

test:
	gcc src/strstr_hashmap.c src/yeet_generator.c  src/yeet.c -o yeet
	./yeet file.c
	gcc out.c
	./a.out
