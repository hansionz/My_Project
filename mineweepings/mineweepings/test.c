#include"game.h"

void meun()
{
	printf("******   扫雷游戏   ******\n");
	printf("**************************\n");
	printf("******   1.PLAY     ******\n");
	printf("******   2.EXIT     ******\n");
	printf("**************************\n");

}
void game()
{
	char board[ROWS][COLS] = { ' 0 ' };
	char mine[ROWS][COLS] = { ' 0 ' };

	init_board(board, ROWS, COLS, '*');
	init_board(mine, ROWS, COLS, '0');
	set_mine(mine, ROW, COL);
	/*printf("雷区\n");*/
	/*print_board(mine, ROW, COL);*/
	/*printf("展示区\n");*/
	print_board(board, ROW, COL);
	find_mine(board, mine, ROW, COL);
	

}

int main()
{
	int input = 0;
	srand((uint)time(NULL));
	do{
		meun();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case START:
			game();
			break;
		case EXIT:
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
}