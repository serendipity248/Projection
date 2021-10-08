#pragma once

# include <stdio.h>
# include <string.h>

# define NAME_MAX 15
# define SEX_MAX 6
# define TELE_MAX 20
# define ADDRE_MAX 30
# define DATA_MAX 100

//联系人信息
struct people
{
	char name[NAME_MAX]; //名字
	int age; //年龄
	char sex[SEX_MAX]; //性别
	char tele[TELE_MAX];//电话
	char address[ADDRE_MAX]; //地址
};

//通讯录的创建
struct Contact
{
	struct people data[DATA_MAX];
	int sz;
};


//初始化通讯录
void InitContact(struct Contact* pc);

//增加联系人
void AddContact(struct Contact* pc);

//展示通讯录
void ShowContact(const struct Contact* pc);

//搜索指定联系人并打印
void SearchContact(const struct Contact* pc);

//查找到指定的联系人,返回下标
int FindContact(struct Contact* pc, char name[]);



//删除联系人
void DelContact(struct Contact* pc);

//修改联系人
void ModifyContact(struct Contact* pc);
