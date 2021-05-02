#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "Chain.h"
void  BooksRegister()//ͼ����Ϣ¼�뺯��������ָ������ͷ��ָ��
{
	struct BooksInfo* head;//����ͷ��ַ
	struct BooksInfo* p1, *p2;
	head = p1 = p2 = (struct BooksInfo*)malloc(LLL);//���ٶ�̬����ռ�
	int t = 1;
	while (t != 0)
	{
		p1 = p2;
		printf("������ͼ������:");
		gets(p1->name);
		printf("������ISBN:");
		gets(p1->ISBN);
		printf("������ͼ����:");
		gets(p1->BianHao);
		printf("�����붨��:");
		scanf("%f", &p1->price);
		getchar();
		//printf("������������:");
		//scanf("%d", &p1->num);
		printf("����������:");
		gets(p1->writer);
		printf("�����������:");
		gets(p1->print);
		printf("���������ʱ�䣨��.�£�:");
		scanf("%d.%d", &p1->PubTime.year, &p1->PubTime.mon);
		getchar();
		printf("�������鼮���ࣺ");
		gets(p1->cate);
		printf("\n");
		p1->zt = 0;//Ĭ��δ�����ͼ��״ֵ̬Ϊ0
		p2 = (struct BooksInfo*)malloc(LLL);
		p1->next = p2;
		printf("������0����������1����\n");
		scanf("%d", &t);
		getchar();
		system("cls");
	}
	p1->next = NULL;
	free(p2);
	SaveFile2(head);
	Freechain2(head);
	Commander();
};

void BooksInsert(struct BooksInfo *head)//��������
{
	struct BooksInfo*p1, *p2;
	//����ͷ��ַ

	int t = 1;
	while (t != 0)
	{
		p1 = (struct BooksInfo*)malloc(LLL);
		printf("������ͼ������:");
		gets(p1->name);
		printf("������ISBN:");
		gets(p1->ISBN);
		printf("������ͼ����:");
		gets(p1->BianHao);
		printf("�����붨��:");
		scanf("%f", &p1->price);
		getchar();
		//printf("������������:");
		//scanf("%d", &p1->num);
		printf("����������:");
		gets(p1->writer);
		printf("�����������:");
		gets(p1->print);
		printf("���������ʱ�䣨��.�£�:");
		scanf("%d.%d", &p1->PubTime.year, &p1->PubTime.mon);
		getchar();
		printf("�������鼮���ࣺ");
		gets(p1->cate);
		p1->zt = 0;//Ĭ��δ�����ͼ��״ֵ̬Ϊ0
		p1->next = head;
		head = p1;
		printf("������0����������1����\n");
		scanf("%d", &t);
		getchar();
	}
	SaveFile2(head);
	Freechain2(head);
	Commander();
};

void BooksEdit(void)
{
	char BookBianhao[30];
	printf("�������鼮��ţ�\n");                 //����ؼ���
	gets(BookBianhao);
	struct BooksInfo*p1, *head;
	head = OpenFile2();
	p1 = SearchBianhao2(BookBianhao, head);//�����鼮 ���ص�ַ
	int t = 1;
	while (t != 0)
	{
		int a;//�˵�����ȡѡ��
		printf("������༭ѡ�1�������޸�\n");
		printf("\t\t2���鼮ISBN�޸�\n");
		printf("\t\t3���鼮����޸�\n");
		printf("\t\t4���鼮�����޸�\n");
		printf("\t\t5���鼮��������޸�\n");
		printf("\t\t6���鼮�����޸�\n");
		printf("\t\t7���鼮�������޸�\n");
		printf("\t\t8���鼮����ʱ���޸�\n");
		printf("\t\t9���鼮���������޸�\n");
		printf("\t\t0��������һ��\n");
		scanf("%d", &a);
		getchar();
		while (a!=0&&a != 1 && a != 2 && a != 3 && a != 4 && a != 5 && a != 6 && a != 7 && a != 8 && a != 9)
		{
			printf("�������,����������\n");
			scanf("%d", &a);
		}
		switch (a)
		{
		case 1:printf("��������������"); scanf("%s", p1->name); break;
		case 2:printf("������ISBN:"); scanf("%s", p1->ISBN); break;
		case 3:printf("������ͼ����:"); scanf("%s", &p1->BianHao); break;
		case 4:printf("�����붨��:"); scanf("%f", &p1->price); break;
		case 6:printf("����������:"); scanf("%s", p1->writer); break;
		case 7:printf("�����������:"); scanf("%s", p1->print); break;
		case 8:printf("���������ʱ�䣨��.�£�:"); scanf("%d.%d", &p1->PubTime.year, &p1->PubTime.mon); break;
		case 9:printf("�������鼮����:"); scanf("%s", p1->cate); break;
		case 0:Commander();
		}
		printf("1�������޸�\n0��������һ��\n");
		scanf("%d", &t);
		getchar();
		system("cls");
		while (t != 1 && t != 0)
		{
			printf("����ָ���������������\n");
			printf("1�������޸�\n0��������һ��\n");
			scanf("%d", &t);
			getchar();
		}
	}
	SaveFile2(head);
	Commander();
};

void BooksDelete()
{
	char BookBianhao[30];
	printf("�������鼮��ţ�\n");                 //����ؼ���
	gets(BookBianhao);
	struct BooksInfo*q, *head, *p, *m;
	m = NULL;
	q = p = head = OpenFile2();
	int n = 0;
	while (q != NULL)
	{
		m = p;
		p = q;
		q = p->next;
		int t = 0;
		t = Compare(BookBianhao, p->BianHao);                //�ȽϹؼ���
		if (1 == t)
		{
			Print(p);                             //��������Ϣ
			n++;
		}
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
			printf("���ٴ�����ͼ������ȷ��ɾ��(�뾫ȷ��ĳһ���鼮)��\n");
			char BianHao[30];
			gets(BianHao);
			p = q = m = head;
			int n = 0;
			while (q != NULL)
			{
				m = p;
				p = q;
				q = p->next;
				int t = 0;
				t = Compare(BianHao, p->BianHao);                //�ȽϹؼ���
				if (1 == t)
				{
					Print(p);                             //��������Ϣ
					n++;
				}
			}
			printf("�ܹ���%d�����\n", n);
			int g;
			printf("0��������һ�� 1������\n");
			scanf("%d", &g);
			getchar();
			if (0 == g)	Commander();
			else if (n == 1) break;
		}
		int a;
		printf("���ҵ�ͼ�飬��ȷ���Ƿ�ɾ����1����\n2��������һ��");
		scanf("%d", &a);
		getchar();
		while (a != 1 && a != 2)
		{
			printf("�������������ȷ���Ƿ�ɾ����\n1����\n2��������һ��\n");
			scanf("%d", &a);
			getchar();
		}
		if (a == 1)
		{
			if (p == head)
			{
				head = q;
			}
			else
			{
				m->next = q;
			}
			free(p);
			printf("ɾ���鼮�ɹ�\n�������������\n");
			getchar();
			SaveFile2(head);
			Commander();
		}
		else
		{
			Commander();
		}
	}
}
