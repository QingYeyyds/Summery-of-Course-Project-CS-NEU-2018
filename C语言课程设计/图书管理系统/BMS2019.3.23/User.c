#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "Chain.h"


void  User()
{
    struct User *SearchUser1(struct User*pHead,char stu[10]);
	int C;                       //C2��Ϊ�����˵��ж�ֵ
	system("cls");
	printf(">>�װ����û�����ӭ��½\n\n");
	printf(">>����ѡ��\n\n");
	printf("(1)�û�����\n(2)�鼮��ѯ\n");
	printf("(3)�軹��¼��ѯ\n(0)�˳�����\n>>");
	scanf("%d", &C);
	getchar();
	while (C != 1 && C != 2 && C != 3 && C != 0)             //����ָ��
	{
		system("cls");
		printf(">>�װ����û�����ӭ��½\n");
		printf(">>��������ȷ�Ĳ������\n\n");
		printf(">>����ѡ��\n\n");
        printf("(1)�û�����\n(2)�鼮��ѯ\n");
        printf("(3)�軹��¼��ѯ\n(0)�˳�����\n>>");
		scanf("%d", &C);
		getchar();
	}
	if (1 == C)                   //�û�����
	{
		system("cls");
		UserDate2();
	}
	else if (2 == C)                //�鼮��ѯ
	{
		system("cls");
		BookSearch(2);
	}
	else if (3 == C)              //�鼮�軹��¼��ѯ
	{
		/*system("cls");
		UserBooksBAR();*/
		system("cls");
		struct User*pHead, *p;
	    pHead = OpenFile1();
	    p = SearchUser1(pHead,loadingstu_id);
		UserBooksBAR1(p);
		Freechain(pHead);

	}

	else if (0 == C)              //�˳�����
	{
		system("cls");
		Login();
	}
}                         //�û���������


int LongJudge(char *pch,int n)                                     //�ж������Ƿ񳬳�����
{
    int  l;
    l=strlen(pch);
	if (l>15)
	{
		return 0;                            //   0����       1 �Ϸ�
	}
	else
	{

		return 1;
	}
}

int Num(char *pch, int n)                        //�ж��ֽ����Ƿ����ַ�     0 ����   1 ������
{
	int i, m;
	for (i = 0; i < n; i++)
	{
		if (*(pch + i) < '0' || *(pch + i) > '9')
		{
			return 0;
		}
	}
	return 1;
}

int NumJudge(char *pch, int n)
{
	if (Num(pch, n) == 0 /*|| LongJudge(pch, n) == 0 || LongJudge(pch, n - 1) == 1*/)
	{
		return 0;
	}
	else return 1;
}

void PutIn(struct User*pNew)              //���뺯��
{
    printf(">>ע�����\n\n");
	printf(">>������������");
	gets(pNew->user.name);
	printf(">>������ѧ�ţ�");
	gets(pNew->user.stu_id);
	printf(">>������רҵ��");
	gets(pNew->user.major);
	printf(">>���������֤�ţ�");
	gets(pNew->user.id);
	printf(">>�������ֻ����룺");
	gets(pNew->user.tel);
	printf(">>����������(ʮ��λ����)��");
	gets(pNew->user.password);
	strcpy(pNew->user.per, "user");
	pNew->n = 0;
}

int Judge(struct User*pNew)
{//�жϽ����ʾ
	int k = 1;
	system("cls");
	printf(">>ע�����\n\n");
	if (NumJudge(pNew->user.stu_id, 8) == 0)
	{
		k = 0;
		printf(">>���ʵѧ��\n");
		puts(pNew->user.stu_id);
	}
	if (NumJudge(pNew->user.tel, 11) == 0)
	{
		k = 0;
		printf(">>���ʵ�ֻ�����\n");
		puts(pNew->user.tel);
	}
	if (NumJudge(pNew->user.id, 18) == 0)
	{
		k = 0;
		printf(">>���ʵ���֤��\n");
		puts(pNew->user.id);
	}
	if (LongJudge(pNew->user.password,15) == 0)
	{
		k = 0;
		printf("���ʵ���루���ܳ���15λ��\n");
		puts(pNew->user.password);
	}
	return k;

}                 //�ж�����Ϸ�

struct User *Creat()                 //��������
{
	struct User*pHead = NULL;
	struct User*pNew;
	pNew = (struct User*)malloc(sizeof(struct User));
	PutIn(pNew);
	int k;
	k = Judge(pNew);                   //�����ж�ֵ 1�Ϸ� 0���Ϸ�
	if (1 == k)
	{
		pHead = pNew;
		printf(">>ע�����\n\n");
		printf(">>ע��ɹ������¼\n");
		strcpy(pNew->user.per, "administrator");
		pNew->next = NULL;
	}
	else
	{
		free(pNew);
		pHead = NULL;
	}
	return pHead;                  //�����׵�ַ
}

struct User *Insert(struct User*pHead)    //�����û�
{
	struct User*pNew;
	pNew = (struct User*)malloc(sizeof(struct User));
	PutIn(pNew);
	int k;
	k = Judge(pNew);                   //�����ж�ֵ 1�Ϸ� 0���Ϸ�
	if (1 == k)
	{
		pNew->next = pHead;
		pHead = pNew;
		system("cls");
		printf(">>ע��ɹ������¼\n");
	}
	else
	{
		free(pNew);
	}
	return pHead;
}

void Register()                      //ע�ắ��
{
	struct User*pHead;
	pHead = OpenFile1();
	if (pHead == NULL)
	{
		pHead = Creat();
		while (NULL == pHead)
		{
			printf(">>ע��ʧ��\n");
			int t=1;
			printf("1������ע��\n0������������\n");
			scanf("%d",&t);
			getchar();
			while(t!=0)
            {
                pHead = Creat();
                printf("1������ע��\n0������������\n");
                scanf("%d",&t);
                getchar();
            }
            if(t==0)    {system("cls");Login();}
		}
		SaveFile1(pHead);
		Freechain(pHead);
	}
	else
	{
		struct User*p;
		p = pHead;
		pHead = Insert(p);
		while (p == pHead)
		{
			printf(">>ע��ʧ��\n");
			int t=1;
			printf("1������ע��\n0������������\n");
			scanf("%d",&t);
			getchar();
			while(t!=0)
            {
                pHead = Insert(p);
                printf("1������ע��\n0������������\n");
                scanf("%d",&t);
                getchar();
            }
            if(t==0)    {system("cls");Login();}
		}
		SaveFile1(pHead);
		Freechain(pHead);
	}
}


/////////////////////////////Sign in
void Hide(char *password)
{
	int i;
	for (i = 0; i < 15; i++)
	{
		*(password + i) = getch();
		if (*(password + i) == '\r')
			break;
		else if (*(password + i) == '\b')
		{
			i = i - 2;
			printf("\b");
		}
		else
			printf("*");
	}
	*(password + i) = '\0';
}

void Code(char*stu_id, char*code)                     //��½����
{
    printf(">>��½����\n\n");
	printf(">>�����������˺�����\n\n");
	printf(">>ѧ��:");
	gets(stu_id);
	printf(">>����:");
	Hide(code);
}

int Confirm(char*stu_id, char*code)            //��½��֤����
{
	int T;               //�ж�ֵ   T 1����Ա   2���û�   0����
	T = SearchLogin(stu_id, code);
	//printf("%d", T);
	if (1 == T)
	{
		return 1;
	}
	else if (2 == T)
	{
		return 2;
	}
	else if (0 == T)
	{
		return 9;
	}
}

int SignIn()                                     //��½����
{
	char stu_id[8];
	char code[15];
	int Per;                          //Ȩ��  1������Ա   2���û�    9���˺��������
	Code(stu_id, code);                  //�����˻�����
	Per = Confirm(stu_id, code);
	system("cls");
	return Per;
}

void UserDate2()                //�û�����
{
	printf(">>�û����ģ�\n\n");
	struct User *pHead, *p;
	p = pHead = OpenFile1();
	while (strcmp(loadingstu_id, p->user.stu_id) != 0)
	{
		p = p->next;
	}
	PrintUserInfo(p);
	int t;
	printf("(1)�޸���Ϣ\n(0)������һ��\n>>");
	scanf("%d", &t);
	getchar();
	while (t != 0 && t != 1)
	{
	    printf(">>�û����ģ�\n\n");
		printf(">>��������ȷָ��\n>>");
		scanf("%d", &t);
		getchar();
	}
	if (1 == t) UserEdit();
	else if (0 == t) User();

}

void UserEdit()              //�û���Ϣ�༭����
{
	struct User *pHead, *p;
	p = pHead = OpenFile1();
	while (strcmp(loadingstu_id, p->user.stu_id) != 0)
	{
		p = p->next;
	}
	changestudent(p);
	Freechain(pHead);
	return;
}

void changestudent(struct User*n)            //�û��޸���Ϣ����
{
	int a;
	printf(">>�޸���Ϣ\n\n");
	printf(">>(1)�޸��ֻ���\n(2)�޸�����\n(3)�޸��ֻ��ź�����\n(0)������һ��\n>>");
	scanf("%d", &a);
	if (a == 1)
	{
	    printf(">>ԭ�ֻ���Ϊ��");
	    puts(n->user.tel);
		printf(">>�޸��ֻ��ţ�");
		gets(n->user.tel);
	}
	else if (a == 2)
	{
	    printf(">>ԭ����Ϊ��");
	    puts(n->user.password);
		printf(">>�޸����룺");
		gets(n->user.password);
	}
	else if (a == 3)
	{
	    printf(">>ԭ�ֻ���Ϊ��");
	    puts(n->user.tel);
		printf(">>�޸��ֻ��ţ�");
		gets(n->user.tel);
		printf(">>ԭ����Ϊ��");
	    puts(n->user.password);
		printf(">>�޸����룺");
		gets(n->user.password);
	}
	else if (a == 0)
	{
		User();
	}
	printf(">>���������������һ��\n");
	getchar();
	User();
}

void PrintUserInfo(struct User*p)                  //��ӡ�û���Ϣ
{
	printf(">>����:%s\n", p->user.name);
	printf(">>ѧ��:%s\n", p->user.stu_id);
	printf(">>���֤��:%s\n", p->user.id);
	printf(">>�绰:%s\n", p->user.tel);
	printf(">>רҵ:%s\n", p->user.major);
	printf(">>����:%s\n", p->user.password);
	printf(">>����:%d����\n\n", p->n);
	for (int j = 0; j < p->n; j++)
	{
		printf(">>�����鼮����:%s\n", p->book[j].Bookname);
		printf(">>�鼮���:%s\n", p->book[j].Bian_Hao);
		printf(">>����ʱ��:%d��%d��%d��\n", p->book[j].borrowtime.year, p->book[j].borrowtime.mon, p->book[j].borrowtime.day);
		printf(">>��ֹʱ��:%d��%d��%d��\n", p->book[j].returntime.year, p->book[j].returntime.mon, p->book[j].returntime.day);
	}
}

struct User *SearchUser(struct User*pHead)                      //ͨ��ѧ�Ų�ѯ�����ص�ַ
{
	char stu[8];
	struct User*p, *q;
	p = pHead;
	printf(">>ѧ�Ų�ѯ\n\n");
	printf(">>�������û�ѧ�ţ�\n>>");
	gets(stu);
	//puts(stu);
	int t = 0;
	while (NULL != p || t != 1)
	{
		q = p;
		t = Compare(stu, p->user.stu_id);
		if (t == 1) break;
		p = q->next;
		if (p == NULL) break;
	}
	while (t == 0)
	{
	    printf(">>ѧ�Ų�ѯ\n\n");
		printf(">>��������ȷ��ѧ�ţ�\n>>");
		gets(stu);
		while (NULL != p || t != 1)
		{
			q = p;
			t = Compare(stu, p->user.stu_id);
			if (t == 1) break;
			p = q->next;
			if (p == NULL) break;
		}
	}
	return q;
}

void UserBooksBAR()      //�û�ͼ��軹��¼
{
    printf(">>���ļ�¼\n\n");
	struct User*pHead, *p;
	pHead = OpenFile1();
	p = SearchUser(pHead);
	int l;
	l = p->n;
	if (0 == l)
		printf(">>���κν��ļ�¼\n");
	int i;
	for (i = 0; i < l; i++)
	{
		printf(">>����:");
		puts(p->book[i].Bookname);
		printf(">>���:");
		puts(p->book[i].Bian_Hao);
		printf(">>��ȡʱ��:%d-%d-%d\n", p->book[i].borrowtime.year, p->book[i].borrowtime.mon, p->book[i].borrowtime.day);
		printf(">>��ֹʱ��:%d-%d-%d\n\n", p->book[i].returntime.year, p->book[i].returntime.mon, p->book[i].returntime.day);
	}
	Freechain(pHead);
	int t;
	printf(">>����0������һ��\n>>");
	scanf("%d", &t);
	getchar();
	while (t != 0)
	{
		printf(">>��������ȷָ��\n\n");
		printf(">>����0������һ��\n>>");
		scanf("%d", &t);
		getchar();
	}
	User();
}

void UserBooksBAR1(struct User*p)      //�û�ͼ��軹��¼
{
    printf(">>���ļ�¼\n\n");
	int l;
	l = p->n;
	if (0 == l)
		printf(">>���κν��ļ�¼\n");
	int i;
	for (i = 0; i < l; i++)
	{
		printf(">>����:");
		puts(p->book[i].Bookname);
		printf(">>���:");
		puts(p->book[i].Bian_Hao);
		printf(">>��ȡʱ��:%d-%d-%d\n", p->book[i].borrowtime.year, p->book[i].borrowtime.mon, p->book[i].borrowtime.day);
		printf(">>��ֹʱ��:%d-%d-%d\n\n", p->book[i].returntime.year, p->book[i].returntime.mon, p->book[i].returntime.day);
	}
	int t;
	printf(">>����0������һ��\n>>");
	scanf("%d", &t);
	getchar();
	while (t != 0)
	{
		printf(">>��������ȷָ��\n\n");
		printf(">>����0������һ��\n>>");
		scanf("%d", &t);
		getchar();
	}
	User();
}

struct User *SearchUser1(struct User*pHead,char stu[10])                      //ͨ��ѧ�Ų�ѯ�����ص�ַ
{

	struct User*p, *q;
	p = pHead;
	//puts(stu);
	int t = 0;
	while (NULL != p || t != 1)
	{
		q = p;
		t = Compare(stu, p->user.stu_id);
		if (t == 1) break;
		p = q->next;
		if (p == NULL) break;
	}
	return q;
}



