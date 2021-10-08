#define _CRT_SECURE_NO_WARNINGS

//通讯录实现
//一个通讯录要有最起码的增加、删除、修改和查看功能

# include "contact.h"

//菜单实现
void Meau()
{
	printf("*********************************\n");
	printf("****   1.add     2.delete  ******\n");
	printf("****   3.modify  4.show    ******\n");
	printf("****   5.search  6.exit    ******\n");
	printf("*********************************\n");
	
}

//菜单选项进行一一列举
enum option
{
	ADD = 1,
	DELETE,
	MODIFY,
	SHOW,
	SEARCH,
	EXIT
};

int main(void)
{
	int input = 0;

	//创建一个通讯录
	struct Contact con;
	//初始化通讯录
	InitContact(&con);

	do
	{
		Meau();
		printf("请选择菜单：");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DELETE:
			DelContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case EXIT:
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (input != 6);
	printf("您已退出通讯录");
}