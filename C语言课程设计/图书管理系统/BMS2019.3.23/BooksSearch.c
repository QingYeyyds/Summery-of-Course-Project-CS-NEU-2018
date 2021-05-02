#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "Chain.h"
void Print(struct BooksInfo *p)                 //��ӡ����
{
	printf("�鼮����:%s\n", p->name);
	printf("ISBN:%s\t", p->ISBN);
	printf("�鼮���:%s\t", p->BianHao);
	printf("����:%s\t", p->writer);
	printf("����:%.2f\t", p->price);
	printf("������:%s\t", p->print);
	printf("����ʱ��:%d�� ", p->PubTime.year);
	printf("%d��\t", p->PubTime.mon);
	//printf("%d�� ", p->PubTime.day);
	printf("���:%s\t", p->cate);
	if (p->zt == 0)
	{
		printf("δ���\n");
	}
	else
	{
		printf("\t�ѽ��\t ");
		printf("�����ˣ�%s\n", p->BorrowStu_id);
	}
}

int Compare(char ino[], char org[])                               //�Աȹؼ��ֺ���   1��   0��
{
	int t, k1, k2;
	k1 = strlen(ino);
	k2 = strlen(org);
	t = 0;
	for (int j = 0; j <= k2 - k1; j++)
	{
		int d;
		d = j;
		for (int h = 0; h < k1; h++, d++)
		{
			if (ino[h] == org[d])
			{
				t = 1;
			}
			else
			{
				t = 0;
				break;
			}
		}
		if (t == 1)
		{
			return 1;
		}
	}
	return 0;
}

void SearchName(int per)                    //�����������鼮
{
    system("cls");
	struct  BooksInfo *pHead, *p, *q;
	char BookName[30];
	printf("�������鼮����\n");                 //����ؼ���
	gets(BookName);
	q = p = pHead = OpenFile2();
	int n = 0;                              //���鼮���ļ�
	while (q != NULL)
	{
		int t = 0;
		p = q;
		t = Compare(BookName, p->name);                //�ȽϹؼ���
		if (1 == t)
		{
			Print(p);                             //��������Ϣ
			n++;
		}
		q = p->next;
	}
	if (n == 0)
	{
		printf("�޼������\n");
	}
	else printf("�ܹ���%d�����\n", n);
	int k;
	printf("����0������һ��\n");
	scanf("%d", &k);
	getchar();
	while (k != 0)
	{
		printf("��������ȷ��ָ��\n");
		scanf("%d", &k);
		getchar();
	}
	BookSearch(per);
}

void SearchBianhao(int per)
{
    system("cls");
	struct  BooksInfo *pHead, *p, *q;
	char BookBianhao[30];
	printf("�������鼮��ţ�\n");                 //����ؼ���
	gets(BookBianhao);
	pHead = q = p = OpenFile2();                               //���鼮���ļ�
	int n = 0;
	while (q != NULL)
	{
		p = q;
		int t = 0;
		//puts(p->BianHao);
		t = Compare(BookBianhao, p->BianHao);                //�ȽϹؼ���
		if (1 == t)                       //1 ���ڹؼ���
		{
			Print(p);
			printf("\n");                            //��������Ϣ
			n++;
		}
		q = p->next;
	}
	if (n == 0)
	{
		printf("�޼������\n");
	}
	else printf("�ܹ���%d�����\n", n);
	int k;
	printf("����0������һ��\n");
	scanf("%d", &k);
	getchar();
	while (k != 0)
	{
		printf("��������ȷ��ָ��\n");
		scanf("%d", &k);
		getchar();
	}
	BookSearch(per);

}

void SearchWriter(int per)
{
    system("cls");
	struct  BooksInfo *pHead, *p, *q;
	char BookWriter[30];
	printf("���������ߣ�\n");                 //����ؼ���
	gets(BookWriter);
	q = p = pHead = OpenFile2();                               //���鼮���ļ�
	int n = 0;
	while (q != NULL)
	{
		int t = 0;
		p = q;
		t = Compare(BookWriter, p->writer);                //�ȽϹؼ���
		if (1 == t)
		{
			Print(p);                             //��������Ϣ
			n++;
		}
		q = p->next;
	}
	if (n == 0)
	{
		printf("�޼������\n");
	}
	else printf("�ܹ���%d�����\n", n);
	int k;
	printf("����0������һ��\n");
	scanf("%d", &k);
	getchar();
	while (k != 0)
	{
		printf("��������ȷ��ָ��\n");
		scanf("%d", &k);
		getchar();
	}
	BookSearch(per);
}

void SearchPress(int per)
{
    system("cls");
	struct  BooksInfo *pHead, *p, *q;
	char BookPress[30];
	printf("��������������ƣ�\n");                 //����ؼ���
	gets(BookPress);
	q = p = pHead = OpenFile2();                               //���鼮���ļ�
	int n = 0;
	while (q != NULL)
	{
		int t = 0;
		p = q;
		t = Compare(BookPress, p->print);                //�ȽϹؼ���
		if (1 == t)
		{
			Print(p);                             //��������Ϣ
			n++;
		}
		q = p->next;
	}
	if (n == 0)
	{
		printf("�޼������\n");
	}
	else printf("�ܹ���%d�����\n", n);
	int k;
	printf("����0������һ��\n");
	scanf("%d", &k);
	getchar();
	while (k != 0)
	{
		printf("��������ȷ��ָ��\n");
		scanf("%d", &k);
		getchar();
	}
	BookSearch(per);
}

void SearchClass(int per)
{
    system("cls");
	struct  BooksInfo *pHead, *p, *q;
	char BookClass[30];
	printf("��������������ƣ�\n");                 //����ؼ���
	gets(BookClass);
	p = q = pHead = OpenFile2();				 //���鼮���ļ�
	int n;
	n = 0;
	while (q != NULL)
	{
		int t = 0;
		p = q;
		t = Compare(BookClass, p->cate);                //�ȽϹؼ���
		if (1 == t)
		{
			Print(p);                             //��������Ϣ
			n++;
		}
		q = p->next;
	}

	if (n == 0)
	{
		printf("�޼������\n");
	}
	else printf("�ܹ���%d�����\n", n);
	int k;
	printf("����0������һ��\n");
	scanf("%d", &k);
	getchar();
	while (k != 0)
	{
		printf("��������ȷ��ָ��\n");
		scanf("%d", &k);
		getchar();
	}
	BookSearch(per);
}

void BookSearch(int per)
{
	int T3;
	printf("������������\n");
	printf("1���鼮����\n2���鼮���\n3������\n4��������\n5��ͼ�����\n0��������һ��\n");
	scanf("%d", &T3);
	getchar();
	while (T3 < 0 || T3>5)
	{
		printf("��������ȷ������\n");
		printf("1���鼮����\n2���鼮���\n3������\n4��������\n5��ͼ�����\n0��������һ��\n");
		scanf("%d", &T3);
		getchar();
	}
	switch (T3)
	{
	case 1: SearchName(per); break;
	case 2: SearchBianhao(per); break;
	case 3: SearchWriter(per); break;
	case 4: SearchPress(per); break;
	case 5: SearchClass(per); break;
	case 0: {if (per == 2)User(); else Commander(); break; }
	}
}

struct BooksInfo *SearchBianhao2(char BookBianhao[], struct  BooksInfo *pHead)
{
	struct BooksInfo*p, *q;
	q = p = pHead;                               //���鼮���ļ�
	int n = 0;
	while (q != NULL)
	{
		p = q;
		int t = 0;
		t = Compare(BookBianhao, p->BianHao);                //�ȽϹؼ���
		if (1 == t)
		{
			Print(p);                             //��������Ϣ
			n++;
		}
		q = p->next;
	}
	printf("�ܹ���%d�����\n", n);
	int k;
	printf("����0������һ�� ����1��������\n");
	scanf("%d", &k);
	getchar();
	while (k != 0 && k != 1)
	{
		printf("��������ȷ��ָ��\n");
		printf("����0������һ�� ����1��������\n");
		scanf("%d", &k);
		getchar();
	}
	if (k == 0)
	{
		Commander();
	}
	else if (k == 1)
	{
		while (n != 1)
		{
			printf("���ٴ�����ͼ������ȷ���޸�(�뾫ȷ��ĳһ���鼮)��\n");
			char BianHao[30];
			gets(BianHao);
			system("cls");
			p = q = pHead;
			int n = 0;
			while (q != NULL)
			{
				p = q;
				int t = 0;
				t = Compare(BianHao, p->BianHao);                //�ȽϹؼ���
				if (1 == t)
				{
					Print(p);                             //��������Ϣ
					n++;
				}
				q = p->next;
			}
			printf("�ܹ���%d�����\n", n);
			if (n == 1) return p;
			int g;
			printf("0��������һ�� 1������\n");
			scanf("%d", &g);
			getchar();
			if (0 == g)	Commander();
		}
		return p;       //����ͼ���ַ

	}

}
