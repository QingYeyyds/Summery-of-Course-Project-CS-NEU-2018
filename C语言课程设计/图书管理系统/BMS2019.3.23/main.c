#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "Chain.h"
#include <windows.h>
void getstime(int *a, int *b, int *c)        //��ȡʱ�亯����aΪ��,bΪ��,cΪ��
{
	time_t temp;
	struct tm *t;
	time(&temp);
	t = localtime(&temp);
	*a = t->tm_year + 1900;
	*b = t->tm_mon + 1;
	*c = t->tm_mday;
}

int Login()                     //��½����
{
	int C1, Per;                        //C1��Ϊ��һ�������ж�ֵ1��2��0
	printf(">>��½����\n\n");
	printf("(1)��½\n(2)ע��\n(0)�˳�\n\n");
	printf(">>���������ָ��\n>>");
	scanf("%d", &C1);                    //������Ҫִ�еĲ���
	getchar();
	while (C1 != 1 && C1 != 2 && C1 != 0)
	{
		system("cls");
		printf(">>��½����\n\n");
		printf(">>ָ�����\n>>��������ȷ�Ĳ������\n");
		printf("(1)��½\n(2)ע��\n(0)�˳�\n>>");
		scanf("%d", &C1);
		getchar();
	}
	Per = Choice1(C1);
	while (Per == 9)                 //����ֵΪ9  �˺��������
	{
		system("cls");
		printf(">>��½����\n\n");
		printf(">>�˻����������\n");
		printf(">>�Ƿ����ע��\n\n");
		printf("(1)������½\n(2)ע��(0)�˳�\n>>");
		scanf("%d", &C1);
		getchar();
		Per = Choice1(C1);
	}
	if (Per == 1)                      //Per==1   ����Ա��½
	{
		Commander();
	}
	if (Per == 2)          //�û���������
	{
		User();
	}
	if (Per=0)
    {
        exit(0);
    }
	return Per;
}

int Choice1(int C)
{
	int Permission;
	if (1 == C)                                //C1==1  ��½
	{
		system("cls");
		Permission = SignIn();
	}
	else if (2 == C)                       //C1==2   ע����½
	{
		system("cls");
		Register();
		//Permission == SignIn();
		Login();
	}
	else if (0 == C)                 //C1==0    �˳�ϵͳ
	{
		system("cls");
		exit(0);
	}
	return Permission;
}                    //��һ���˵�

int main()
{
    system("color F0");
	Login();                          //�����½����
	return 0;

}                        //������
