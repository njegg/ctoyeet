compile:
	@echo -n 'Compiling yeet.c... '
	@gcc src/strstr_hashmap.c src/yeet_generator.c  src/yeet.c -o yeet
	@echo ✔

test:compile
	@echo

	@echo "$$ ./yeet.c file.c\n"
	@./yeet file.c

	@echo -n "Compiling generated yeet file..."
	@gcc out.c
	@echo ✔
	@echo "\n$$ ./a.out\n"
	@./a.out
