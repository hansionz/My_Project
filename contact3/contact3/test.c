#include"contact3.h"  

void menu()
{
	printf("********通讯录(3)********\n");
	printf("***1.Add       2.Dele****\n");
	printf("***3.Search    4.Alter***\n");
	printf("***5.Show      6.Empty***\n");
	printf("***7.Sort      0.Exit****\n");
	printf("*************************\n");
}

int main()
{
	int input = 0;
	contact book;
	Init_contact(&book);
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			Add_people(&book);
			break;
		case DELE:
			Dele_people(&book);
			break;
		case SEARCH:
			Search_people(&book);
			break;
		case ALERT:
			Alert_people(&book);
			break;
		case SHOW:
			Show_people(&book);
			break;
		case EMPTY:
			Empty_people(&book);
			break;
		case SORT:
			Sort_people(&book);
			break;
		default:
			printf("输入有误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}