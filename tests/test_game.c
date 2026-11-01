#include <stdio.h>
#include "../include/game.h"

int main(void) {
    char board[BOARD_SIZE][BOARD_SIZE];

    init_board(board);

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}