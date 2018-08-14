#include"contact.h"
//增加联系人
void Add_people(contact *book)
{
	assert(book != NULL);
	if (book->count == MAX)
	{
		printf("通讯录已满\n");
		return;
	}
	else
	{
		printf("请输入姓名：");
		scanf("%s", book->data[book->count].name);
		printf("请输入性别：");
		scanf("%s", book->data[book->count].sex);
		printf("请输入年龄：");
		scanf("%d", &book->data[book->count].age);
		printf("请输入电话：");
		scanf("%s", book->data[book->count].tele);
		printf("请输入地址：");
		scanf("%s", book->data[book->count].addr);
		book->count++;
		printf("添加成功\n");
	}
}
//只在本源文件内使用，加上static改变链接属性，使用更加安全
//函数的作用是返回输入姓名的下标
static int find_people(contact *book)
{
	char names[20];
	printf("请输入姓名：");
	scanf("%s", names);
	int i = 0;
	for (; i < book->count; i++)
	{
		if (0 == strcmp(book->data[i].name, names))
		{
			return i;
		}
	}
	return -1;
}
//删除联系人
void Dele_people(contact *book)
{
	if (book->count == 0)
	{
		printf("通讯录已空\n");
		return;
	}
	else
	{
		int ret = find_people(book);
		if (ret < 0)
		{
			printf("查无此人\n");
			return;
		}
		else
		{
			int i = ret;
			for (; i < book->count - 1; i++)
			{
				book->data[i] = book->data[i + 1];
			}
			book->count--;
		}
	}
}
//修改联系人信息
void Alert_people(contact *book)
{
	int ret = find_people(book);
	if (ret < 0)
	{
		printf("查无此人\n");
		return;
	}
	else
	{
		printf("请输入要修改的姓名：");
		scanf("%s", book->data[ret].name);
		printf("请输入要修改的性别：");
		scanf("%s", book->data[ret].sex);
		printf("请输入要修改的年龄：");
		scanf("%d", &book->data[ret].age);
		printf("请输入要修改的电话：");
		scanf("%s", book->data[ret].tele);
		printf("请输入要修改的地址：");
		scanf("%s", book->data[ret].addr);
		printf("修改成功\n");
	}
}
//搜索指定联系人
void Search_people(contact *book)
{
	int ret = find_people(book);
	if (ret < 0)
	{
		printf("没有查找到该联系人\n");
		return;
	}
	else
	{
		printf("名字：%s 性别：%s 年龄：%d 电话：%s 地址：%s\n",
			book->data[ret].name,
			book->data[ret].sex,
			book->data[ret].age,
			book->data[ret].tele,
			book->data[ret].addr);
	}	
}
//打印所以联系人信息
void Show_people(contact *book)
{
	if (book->count == 0)
	{
		printf("此通讯录为空\n");
		return;
	}
	else
	{
		int i = 0;
		printf("%-5s\t%-5s\t%-3s\t%-12s\t%-12s\n", "名字", "性别", "年龄", "电话", "地址");
		for (; i < book->count; i++)
		{
			printf("%-5s\t%-5s\t%-3d\t%-12s\t%-17s\n",
				book->data[i].name,
				book->data[i].sex,
				book->data[i].age,
				book->data[i].tele,
				book->data[i].addr);
		}
	}
}
//初始化通讯录
void Init_contact(contact *book)
{
	book->count = 0;
	book->max = 3;
	book->data = (people*)malloc(book->max * sizeof(people));
}
//清空通讯录
void Empty_people(contact *book)
{
	book->count = 0;
	book->max = 3;
	book->data = (people*)malloc(book->max * sizeof(people));
	printf("清空成功\n");
}
//按姓名排序通讯录
void Sort_people(contact *book)
{
	if (book->count > 1)
	{
		int i = 0;
		for (; i < book->count - 1; i++)
		{
			int j = 0;
			for (; j < book->count - 1 - i; j++)
			{
				if (strcmp(book->data[j].name, book->data[j + 1].name))
				{
					people temp = book->data[j];
					book->data[j] = book->data[j + 1];
					book->data[j + 1] = temp;
				}
			}
		}
	}
	printf("排序成功\n");
}