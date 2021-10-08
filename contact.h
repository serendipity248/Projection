#pragma once

# include <stdio.h>
# include <string.h>

# define NAME_MAX 15
# define SEX_MAX 6
# define TELE_MAX 20
# define ADDRE_MAX 30
# define DATA_MAX 100

//��ϵ����Ϣ
struct people
{
	char name[NAME_MAX]; //����
	int age; //����
	char sex[SEX_MAX]; //�Ա�
	char tele[TELE_MAX];//�绰
	char address[ADDRE_MAX]; //��ַ
};

//ͨѶ¼�Ĵ���
struct Contact
{
	struct people data[DATA_MAX];
	int sz;
};


//��ʼ��ͨѶ¼
void InitContact(struct Contact* pc);

//������ϵ��
void AddContact(struct Contact* pc);

//չʾͨѶ¼
void ShowContact(const struct Contact* pc);

//����ָ����ϵ�˲���ӡ
void SearchContact(const struct Contact* pc);

//���ҵ�ָ������ϵ��,�����±�
int FindContact(struct Contact* pc, char name[]);



//ɾ����ϵ��
void DelContact(struct Contact* pc);

//�޸���ϵ��
void ModifyContact(struct Contact* pc);
