speller: speller.o dictionary.o
	gcc -g -O0 -std=c11 -Wall -Wextra -Werror -Wshadow -o speller speller.o dictionary.o -lm

speller.o: speller.c dictionary.h
	gcc -g -O0 -std=c11 -Wall -Wextra -Werror -Wshadow -c speller.c -o speller.o

dictionary.o: dictionary.c dictionary.h
	gcc -g -O0 -std=c11 -Wall -Wextra -Werror -Wshadow -c dictionary.c -o dictionary.o

clean:
	rm -f speller speller.o dictionary.o