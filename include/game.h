#ifndef GAME_H
#define GAME_H

#define BOARD_SIZE 3

//pentru un state machine folosim enum
typedef enum {
    GAME_IN_PROGRESS,
    GAME_FINISHED,
    GAME_WAITING_REMATCH,
    GAME_CLOSED
} GameStatus;

// initializeaza celulele cu spatiu liber
void init_board(char board[BOARD_SIZE][BOARD_SIZE]);

// 1 - mutare valida ; 0 altfel
int make_move(
    char board[BOARD_SIZE][BOARD_SIZE],
    int row,
    int col,
    char symbol
);

// returneaza X, 0 sau \0
char check_winner(char board[BOARD_SIZE][BOARD_SIZE]);

// returneaza 1 pentru remiza, 0 altfel
int is_draw(char board[BOARD_SIZE][BOARD_SIZE]);

#endif