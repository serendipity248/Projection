#define _CRT_SECURE_NO_WARNINGS

# include "contact.h"

//��ʼ��ͨѶ¼
void InitContact(struct Contact* pc)
{
	pc->sz = 0; //��ϵ�˸�����ʼ��Ϊ0
	memset(pc->data, 0, sizeof(pc->data)); //��ʼ�������ÿһ���ֽ�Ϊ0
}

//������ϵ��
void AddContact(struct Contact* pc)
{
	int tmp = pc->sz;
	if (tmp >= DATA_MAX)
	{
		printf("ͨѶ¼���ˣ��޷����");
		return;
	}
	else
	{
		printf("��������Ϣ��\n");
		printf("���֣�");
		scanf("%s", pc->data[tmp].name);
		printf("���䣺");
		scanf("%d", &(pc->data[tmp].age));
		printf("�Ա�");
		scanf("%s", pc->data[tmp].sex);
		printf("�绰��");
		scanf("%s", pc->data[tmp].tele);
		printf("��ַ��");
		scanf("%s", pc->data[tmp].address);
		printf("��ӳɹ���\n");
		pc->sz++;
	}
}


//չʾͨѶ¼
void ShowContact(const struct Contact* pc)
{
	//��ӡ����
	int i = 0;
	printf("%15s\t%5s\t%8s\t%15s\t%30s\n\n",
		"name", "age", "sex", "telephone", "address");
	for (i = 0; i < pc->sz; i++)
	{
		//��ӡÿһ������
		printf("%15s\t%5d\t%8s\t%15s\t%30s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].address);
	}
}

//������ϵ�˲�չʾ
void SearchContact(const struct Contact* pc)
{
	char name[NAME_MAX] = { 0 };
	printf("����Ҫ�����˵�����:");
	scanf("%s", name);
	int pos = FindContact(pc, name);
	if (-1 == pos)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("%15s\t%5s\t%8s\t%15s\t%30s\n\n",
			"name", "age", "sex", "tele", "addr");
		printf("%15s\t%5d\t%8s\t%15s\t%30s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].address);
	}
}

//�ҵ���Ҫɾ������ϵ��
int FindContact(struct Contact* pc, const char name[])
{
	int i = 0;
	//����ÿһ����Ա
	for (i = 0; i < pc->sz; i++)
	{
		//����ҵ�һ�������֣�ʹ���ַ����Ƚϣ�����򷵻�0
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i; //�����±�
		}
	}
	//�Ҳ���
	return -1;
}

//ɾ����ϵ��
void DelContact(struct Contact* pc)
{
	//��������ɾ��һ��Ԫ�ص�˼��
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ����\n");
		return;
	}
	else
	{
		char name[NAME_MAX] = { 0 };
		printf("��������Ҫɾ������ϵ��������");
		scanf("%s", name);
		int position = FindContact(pc, name); //���Ҹ���ϵ�ˣ������±�
		if (position == -1)
		{
			printf("���ͨѶ¼���޸���ϵ�ˣ�\n");
		}
		else
		{
			//ɾ��
			int i = 0;
			for (i = position; i < pc->sz - 1; i++) //ɾ������ϵ������һ��������ѭ��������һ
			{
				pc->data[i] = pc->data[i + 1];
			}
			pc->sz--; //ɾ���ɹ�����ϵ����һ
			printf("ɾ���ɹ���\n");
		}
	}

}

//�޸���ϵ��
void ModifyContact(struct Contact* pc)
{
	char Name[NAME_MAX] = { 0 };
	printf("��������Ҫ�޸ĵ���ϵ��������");
	scanf("%s", Name);
	int position2 = FindContact(pc, Name);
	if (position2 == -1)
	{
		printf("ͨѶ¼�Ҳ�������ϵ��\n");
	}
	else
	{
		printf("�������µ�����:>");
		scanf("%s", pc->data[position2].name);
		printf("�������µ�����:>");
		scanf("%d", &(pc->data[position2].age));
		printf("�������µ��Ա�:>");
		scanf("%s", pc->data[position2].sex);
		printf("�������µĵ绰:>");
		scanf("%s", pc->data[position2].tele);
		printf("�������µĵ�ַ:>");
		scanf("%s", pc->data[position2].address);
		printf("�޸ĳɹ���\n");
	}
}