#define _CRT_SECURE_NO_WARNINGS

//ͨѶ¼ʵ��
//һ��ͨѶ¼Ҫ������������ӡ�ɾ�����޸ĺͲ鿴����

# include "contact.h"

//�˵�ʵ��
void Meau()
{
	printf("*********************************\n");
	printf("****   1.add     2.delete  ******\n");
	printf("****   3.modify  4.show    ******\n");
	printf("****   5.search  6.exit    ******\n");
	printf("*********************************\n");
	
}

//�˵�ѡ�����һһ�о�
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

	//����һ��ͨѶ¼
	struct Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);

	do
	{
		Meau();
		printf("��ѡ��˵���");
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
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input != 6);
	printf("�����˳�ͨѶ¼");
}