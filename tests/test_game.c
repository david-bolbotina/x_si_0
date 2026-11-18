#include <stdio.h>
#include "../include/game.h"

int test_board(char board[BOARD_SIZE][BOARD_SIZE]){
    for(int i = 0; i < BOARD_SIZE; i++)
        for(int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j] != ' ')
                return 0;
        }
    return 1;
}

void test_move_out_of_bounds()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    if(make_move(board, -1, 0, 'X'))
    {
        printf("Test make_move out of bounds: FAILED\n");
    }
    else
    {
        printf("Test make_move out of bounds: PASSED\n");
    }
}

void test_move_invalid_symbol()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    if(make_move(board, 0, 0, 'A'))
    {
        printf("Test make_move invalid symbol: FAILED\n");
    }
    else
    {
        printf("Test make_move invalid symbol: PASSED\n");
    }
}

void test_move_cell_occupied()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    make_move(board, 0, 0, 'X');
    if(make_move(board, 0, 0, 'O'))
    {
        printf("Test make_move cell occupied: FAILED\n");
    }
    else
    {
        printf("Test make_move cell occupied: PASSED\n");
    }
}

void test_check_winner_no_winner()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    if(check_winner(board) == '\0')
    {
        printf("Test check_winner no winner: PASSED\n");
    }
    else
    {
        printf("Test check_winner no winner: FAILED\n");
    }
}

void test_check_winner_line()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    make_move(board, 0, 0, 'X');
    make_move(board, 0, 1, 'X');
    make_move(board, 0, 2, 'X');
    if(check_winner(board) == 'X')
    {
        printf("Test check_winner line: PASSED\n");
    }
    else
    {
        printf("Test check_winner line: FAILED\n");
    }
}

void test_check_winner_column()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    make_move(board, 0, 0, 'O');
    make_move(board, 1, 0, 'O');
    make_move(board, 2, 0, 'O');
    if(check_winner(board) == 'O')
    {
        printf("Test check_winner column: PASSED\n");
    }
    else
    {
        printf("Test check_winner column: FAILED\n");
    }
}


void test_check_winner_diagonal()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    make_move(board, 0, 0, 'X');
    make_move(board, 1, 1, 'X');
    make_move(board, 2, 2, 'X');
    if(check_winner(board) == 'X')
    {
        printf("Test check_winner diagonal: PASSED\n");
    }
    else
    {
        printf("Test check_winner diagonal: FAILED\n");
    }
}
void test_check_winner_diagonal_reverse()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    make_move(board, 0, 2, 'O');
    make_move(board, 1, 1, 'O');
    make_move(board, 2, 0, 'O');
    if(check_winner(board) == 'O')
    {
        printf("Test check_winner diagonal reverse: PASSED\n");
    }
    else
    {
        printf("Test check_winner diagonal reverse: FAILED\n");
    }
}

void test_check_is_draw()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    make_move(board, 0, 0, 'X');
    make_move(board, 0, 1, 'O');
    make_move(board, 0, 2, 'X');
    make_move(board, 1, 0, 'X');
    make_move(board, 1, 1, 'O');
    make_move(board, 1, 2, 'X');
    make_move(board, 2, 0, 'O');
    make_move(board, 2, 1, 'X');
    make_move(board, 2, 2, 'O');
    if(is_draw(board) == 1)
    {
        printf("Test is_draw: PASSED\n");
    }
    else
    {
        printf("Test is_draw: FAILED\n");
    }
}
void test_is_draw_not_draw()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    make_move(board, 0, 0, 'X');
    make_move(board, 0, 1, 'O');
    make_move(board, 0, 2, 'X');
    make_move(board, 1, 0, 'X');
    make_move(board, 1, 1, 'O');
    make_move(board, 1, 2, 'X');
    make_move(board, 2, 0, 'O');
    make_move(board, 2, 1, 'X');
    //make_move(board, 2, 2, 'O'); // This move is commented out to create a non-draw situation
    if(is_draw(board) == 0)
    {
        printf("Test is_draw not draw: PASSED\n");
    }
    else
    {
        printf("Test is_draw not draw: FAILED\n");
    }
}

int main(void) {
    char board[BOARD_SIZE][BOARD_SIZE];

    init_board(board);

    if(test_board(board) == 1)
        printf("Test init_board: PASSED\n");
    else
        printf("Test init_board: FAILED\n");

    test_move_out_of_bounds();
    test_move_invalid_symbol();
    test_move_cell_occupied();
    test_check_winner_no_winner();
    test_check_winner_line();
    test_check_winner_column();
    test_check_winner_diagonal();
    test_check_winner_diagonal_reverse();
    test_check_is_draw();
    test_is_draw_not_draw();
    return 0;
}