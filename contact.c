#define _CRT_SECURE_NO_WARNINGS

# include "contact.h"

//初始化通讯录
void InitContact(struct Contact* pc)
{
	pc->sz = 0; //联系人个数初始化为0
	memset(pc->data, 0, sizeof(pc->data)); //初始化数组的每一个字节为0
}

//增加联系人
void AddContact(struct Contact* pc)
{
	int tmp = pc->sz;
	if (tmp >= DATA_MAX)
	{
		printf("通讯录满了，无法添加");
		return;
	}
	else
	{
		printf("请输入信息：\n");
		printf("名字：");
		scanf("%s", pc->data[tmp].name);
		printf("年龄：");
		scanf("%d", &(pc->data[tmp].age));
		printf("性别：");
		scanf("%s", pc->data[tmp].sex);
		printf("电话：");
		scanf("%s", pc->data[tmp].tele);
		printf("地址：");
		scanf("%s", pc->data[tmp].address);
		printf("添加成功！\n");
		pc->sz++;
	}
}


//展示通讯录
void ShowContact(const struct Contact* pc)
{
	//打印标题
	int i = 0;
	printf("%15s\t%5s\t%8s\t%15s\t%30s\n\n",
		"name", "age", "sex", "telephone", "address");
	for (i = 0; i < pc->sz; i++)
	{
		//打印每一个数据
		printf("%15s\t%5d\t%8s\t%15s\t%30s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].address);
	}
}

//搜索联系人并展示
void SearchContact(const struct Contact* pc)
{
	char name[NAME_MAX] = { 0 };
	printf("输入要查找人的名字:");
	scanf("%s", name);
	int pos = FindContact(pc, name);
	if (-1 == pos)
	{
		printf("查无此人\n");
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

//找到需要删除的联系人
int FindContact(struct Contact* pc, const char name[])
{
	int i = 0;
	//遍历每一个成员
	for (i = 0; i < pc->sz; i++)
	{
		//如果找到一样的名字，使用字符串比较，相等则返回0
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i; //返回下标
		}
	}
	//找不到
	return -1;
}

//删除联系人
void DelContact(struct Contact* pc)
{
	//采用数组删除一个元素的思想
	if (pc->sz == 0)
	{
		printf("通讯录为空，无法删除！\n");
		return;
	}
	else
	{
		char name[NAME_MAX] = { 0 };
		printf("输入你先要删除的联系人姓名：");
		scanf("%s", name);
		int position = FindContact(pc, name); //查找该联系人，保存下标
		if (position == -1)
		{
			printf("你的通讯录中无该联系人！\n");
		}
		else
		{
			//删除
			int i = 0;
			for (i = position; i < pc->sz - 1; i++) //删除后联系人少了一个，所以循环次数减一
			{
				pc->data[i] = pc->data[i + 1];
			}
			pc->sz--; //删除成功后联系人少一
			printf("删除成功！\n");
		}
	}

}

//修改联系人
void ModifyContact(struct Contact* pc)
{
	char Name[NAME_MAX] = { 0 };
	printf("请输入你要修改的联系人姓名：");
	scanf("%s", Name);
	int position2 = FindContact(pc, Name);
	if (position2 == -1)
	{
		printf("通讯录找不到该联系人\n");
	}
	else
	{
		printf("请输入新的名字:>");
		scanf("%s", pc->data[position2].name);
		printf("请输入新的年龄:>");
		scanf("%d", &(pc->data[position2].age));
		printf("请输入新的性别:>");
		scanf("%s", pc->data[position2].sex);
		printf("请输入新的电话:>");
		scanf("%s", pc->data[position2].tele);
		printf("请输入新的地址:>");
		scanf("%s", pc->data[position2].address);
		printf("修改成功！\n");
	}
}