#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "Chain.h"

void SaveFile1(struct User*pHead)                  //�����������ļ�
{
	struct User*p;
	p = pHead;
	FILE *fp;
	fp = fopen("UserDateOutput.txt", "w");
	if (NULL == fp)
	{
		//printf("���ļ�ʧ�ܣ�");
		return;
	}/*
	while(p!=NULL)
	{
		fwrite(p,LEN,1,fp);
		p=p->next;
	}*/
	while (p != NULL)
	{
		fprintf(fp, "%s\n", p->user.name);
		fprintf(fp, "%s\n", p->user.stu_id);
		fprintf(fp, "%s\n", p->user.id);
		fprintf(fp, "%s\n", p->user.tel);
		fprintf(fp, "%s\n", p->user.major);
		fprintf(fp, "%s\n", p->user.password);
		fprintf(fp, "%s\n", p->user.per);
		fprintf(fp, "%d\n", p->n);

		for (int j = 0; j < p->n; j++)
		{
			fprintf(fp, "%s\n", p->book[j].Bookname);
			fprintf(fp, "%s\n", p->book[j].Bian_Hao);
			fprintf(fp, "%d\n", p->book[j].borrowtime.year);
			fprintf(fp, "%d\n", p->book[j].borrowtime.mon);
			fprintf(fp, "%d\n", p->book[j].borrowtime.day);
			fprintf(fp, "%d\n", p->book[j].returntime.year);
			fprintf(fp, "%d\n", p->book[j].returntime.mon);
			fprintf(fp, "%d\n", p->book[j].returntime.day);
		}
		p = p->next;
	}
	fclose(fp);
	return;
}

struct User*OpenFile1()                                 //���ļ����������
{
	struct User*pHead;
	pHead = (struct User*)malloc(sizeof(struct User));
	int t;
	struct User*p, *q;
	p = pHead;
	FILE *fp;
	fp = fopen("UserDateOutput.txt", "r");
	if (fp == NULL)
	{
		//printf("���ļ�ʧ�ܣ�\n");
		return NULL;
	}
	int iCount1 = 0;
	/*while(feof(fp))
	{
		fread(p,LEN,1,fp);
		q=p;
		p=(struct User*)malloc(sizeof(struct User));
		q->next=p;
		iCount1++;
	}*/
	while (fscanf(fp, "%s", p->user.name) != EOF)
	{
		fscanf(fp, "%s", p->user.stu_id);
		fscanf(fp, "%s", p->user.id);
		fscanf(fp, "%s", p->user.tel);
		fscanf(fp, "%s", p->user.major);
		fscanf(fp, "%s", p->user.password);
		fscanf(fp, "%s", p->user.per);
		fscanf(fp, "%d", &p->n);
		for (int j = 0; j < p->n; j++)
		{
			fscanf(fp, "%s", p->book[j].Bookname);
			fscanf(fp, "%s", p->book[j].Bian_Hao);
			fscanf(fp, "%d", &p->book[j].borrowtime.year);
			fscanf(fp, "%d", &p->book[j].borrowtime.mon);
			fscanf(fp, "%d", &p->book[j].borrowtime.day);
			fscanf(fp, "%d", &p->book[j].returntime.year);
			fscanf(fp, "%d", &p->book[j].returntime.mon);
			fscanf(fp, "%d", &p->book[j].returntime.day);
		}

		iCount1++;
		q = p;
		p = (struct User*)malloc(sizeof(struct User));
		q->next = p;
	}
	fclose(fp);
	free(p);
	q->next = NULL;
	//if(iCount1==0)   return NULL;
	return pHead;
}

void Freechain(struct User*pHead)                              //�ͷ���������
{
	struct User*p, *q;
	p = pHead;
	q = p->next;
	while (q != NULL)
	{
		free(p);
		p = q;
		q = p->next;
	}

}
/*
void PrintUserInfo(struct User*p)                  //��ӡ�û���Ϣ
{
	printf("����:%s\n", p->user.name);
	printf("ѧ��:%s\n", p->user.stu_id);
	printf("���֤��:%s\n", p->user.id);
	printf("�绰:%s\n", p->user.tel);
	printf("רҵ:%s\n", p->user.major);
	printf("����:%s\n", p->user.password);
	for (int j = 0; j < p->n; j++)
	{
		printf("�����鼮����:%s\n", p->book[j].Bookname);
		printf("�鼮���:%s\n", p->book[j].Bian_Hao);
		printf("����ʱ��:%d��%d��%d��\n", p->book[j].borrowtime.year, p->book[j].borrowtime.mon, p->book[j].borrowtime.day);
		printf("�黹ʱ�䣨��ʾ0��δ�黹��:%d��%d��%d��\n", p->book[j].returntime.year, p->book[j].returntime.mon, p->book[j].returntime.day);
	}
}*/

