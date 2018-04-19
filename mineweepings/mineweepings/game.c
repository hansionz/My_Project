#include"game.h"

void init_board(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void print_board(char board[ROWS][COLS], int row, int col)
{
	{
		int i = 0;
		int j = 0;
		for (i = 0; i <= row; i++)
		{
			printf("%d ", i);//给雷区注释行列号
		}
		printf("\n");
		for (i = 0; i <row; i++)
		{
			printf("%d ", i+1);
			for (j = 0; j < col; j++)
			{
				printf("%c ", board[i + 1][j + 1]);
			}
			printf("\n");
		}
	}
}

void set_mine(char mine[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = mine_count;
	while (count)
	{
	     x = rand() % row  + 1;
		 y = rand() % col  + 1;
		 //随机数生成坐标
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

static int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	int count = (mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1]) - 8 * '0';
	return count;
}
//获取以(x,y)坐标周围的雷的个数
void find_mine(char board[ROWS][COLS], char mine[ROWS][COLS], int row, int col)
{
	int sum = 0;
	int x = 0;
	int y = 0;
	while (sum <= (row*col - mine_count))
	{
		printf("请输入要扫雷的坐标:\n");
		scanf("%d%d", &x, &y);
		if (mine[x][y] == '1')
		{
			printf("很遗憾，你被炸死了！\n");
			break;
		}
		else
		{
			board[x][y] = get_mine_count(mine, x, y) + '0';
			print_board(board, row, col);
			sum++;
		}
	}
	if (sum > (row*col - mine_count))
	{
		printf("恭喜你，扫雷成功！\n");
		print_board(mine, row, col);
	}
}



