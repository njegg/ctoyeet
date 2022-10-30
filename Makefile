compile:
	@echo -n 'Compiling yeet.c... '
	@gcc src/strstr_hashmap.c src/yeet_generator.c  src/yeet.c -o yeet
	@echo ✔

test:compile
	cp yeet tests/yeet
	tests/yeet tests/file.c
	gcc out.c
	./a.out

clean:
	@trash out.c
	@trash a.out