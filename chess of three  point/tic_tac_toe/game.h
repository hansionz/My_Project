#ifndef _GAME_H_
#define _GAME_H_

#include<stdio.h>
#include"game.h"
#include<stdlib.h>
#include<time.h>
#include<string.h>
#pragma warning(disable:4996)

typedef unsigned int uint;

enum OPTION
{
	EXIT,
	START
};

#define ROW 3
#define  COL 3

void menu();
void init_board(char board[ROW][COL], int row, int col);
void print_board(char board[ROW][COL], int row, int col);
void computer_move(char board[ROW][COL], int row, int col);
void  paiyer_move(char board[ROW][COL], int row, int col);
int is_full(char board[ROW][COL], int row, int col);
char is_win(char board[ROW][COL], int row, int col);


#endif //_GAME_H_