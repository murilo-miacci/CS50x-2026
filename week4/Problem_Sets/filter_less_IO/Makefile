CC = gcc

CFLAGS = -ggdb3 -O0 -std=c11 \
          -Wall -Werror -Wextra \
          -Wno-sign-compare \
          -Wno-unused-parameter \
          -Wno-unused-variable \
          -Wshadow

LDFLAGS = -lm

filter: filter.c helpers.c
	$(CC) $(CFLAGS) filter.c helpers.c -o filter $(LDFLAGS)

clean:
	rm -f filter