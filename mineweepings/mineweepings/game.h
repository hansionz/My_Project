#ifndef _GAME_H_
#define _GAME_H_

#pragma warning(disable:4996)
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

enum
{
	EXIT,
	START
};

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

#define mine_count 10

typedef unsigned int uint;

void init_board(char board[ROWS][COLS], int rows, int cols, char set);
void print_board(char board[ROWS][COLS], int row, int col);
void  set_mine(char mine[ROWS][COLS], int row, int col);
void find_mine(char board[ROWS][COLS], char mine[ROWS][COLS], int row, int col);
int get_mine_count(char mine[ROWS][COLS], int x, int y);
//各个函数的声明

#endif //_GAME_H_