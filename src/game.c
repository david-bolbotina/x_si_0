#include "../include/game.h"


void init_board(char board[BOARD_SIZE][BOARD_SIZE]){
    for(int i = 0; i < BOARD_SIZE; i++)
        for(int j = 0; j < BOARD_SIZE; j++){
            board[i][j] = ' ';
        }
}

int make_move(
    char board[BOARD_SIZE][BOARD_SIZE],
    int row,
    int col,
    char symbol
){
        if((row >= 0 && row < BOARD_SIZE) &&
        (col >= 0 && col < BOARD_SIZE) &&
        (symbol == 'X' || symbol == 'O') &&
        (board[row][col] == ' '))
            return 1;

        return 0;
}

char check_winner(char board[BOARD_SIZE][BOARD_SIZE]){
    //linii
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 1; j < BOARD_SIZE - 1; j++){
            if(board[i][j] != ' ')
                if(board[i][j] == board[i][j-1] && board[i][j] == board[i][j+1]){
                    return board[i][j];
                }
        }
    }
    //coloane
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 1; j < BOARD_SIZE - 1; j++){
            if(board[j][i] != ' ')
                if(board[j][i] == board[j][i-1] && board[j][i] == board[j][i+1]){
                    return board[i][j];
                }
        }
    }
    //diagonale
    if(board[1][1] == board[0][0] && board[1][1] == board[2][2]){
        if(board[1][1] != ' '){
            return board[1][1];
        }
    }

    if(board[1][1] == board[0][2] && board[1][1] == board[2][0]){
        if(board[1][1] != ' '){
            return board[1][1];
        }
    }


    return '\0';
}


int is_draw(char board[BOARD_SIZE][BOARD_SIZE]){
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}