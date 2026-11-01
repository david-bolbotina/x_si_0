CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude

all: test_game

test_game: src/game.c tests/test_game.c
	$(CC) $(CFLAGS) src/game.c tests/test_game.c -o test_game

clean:
	rm -f test_game
