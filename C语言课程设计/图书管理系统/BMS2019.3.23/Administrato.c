#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "Chain.h"

//char loadingstu_id[10];
//char loadingper[15];

int SearchLogin(char*stu_id, char*code)
{
	struct User*pHead;
	struct User*p,*q;
	pHead = OpenFile1();
	q=p = pHead;
	int t = 1;
	printf("%d", t);
	while (q != NULL)
	{
		int x;
		p=q;
		x = strcmp(stu_id, p->user.stu_id);
		if (x == 0)
		{
			t = 1;
			break;
		}
		else
		{
			q = p->next;
			t = 0;
		}

	}
	printf("%d", t);
	if (t == 0)
	{
		printf(">>�˺Ų�����\n");
		return t;
		Freechain(pHead);
	}
	if (strcmp(code, p->user.password) != 0)
	{
		printf(">>�������\n");
		t = 0;
		return t;
		Freechain(pHead);
	}
	strcpy(loadingstu_id, p->user.stu_id);
	strcpy(loadingper, p->user.per);
	if (p->user.per[0] == 'a') t = 1;
	else t = 2;
	Freechain(pHead);
	return t;



}

void Commander()
{
	int C;                       //C2��Ϊ�����˵��ж�ֵ
	system("cls");
	printf(">>����Ա����ӭ��½\n\n");
	printf("����ѡ��\n\n");
	printf("(1)�鼮����\n(2)����¼��\n(3)�鼮��Ϣ�޸�\n");
	printf("(4)ɾ���鼮��Ϣ\n(5)����軹����\n(6)�û���Ϣ��ѯ�޸�\n");
	printf("(0)�˳�����\n>>");
	scanf("%d", &C);
	getchar();
	while (C != 1 && C != 2 && C != 3 && C != 4 && C != 5 && C != 6 && C != 0)             //����ָ��
	{
		system("cls");
		printf(">>����Ա����ӭ��½\n\n");
		printf(">>��������ȷ�Ĳ������\n\n");
		printf("����ѡ��\n\n");
        printf("(1)�鼮����\n(2)����¼��\n(3)�鼮��Ϣ�޸�\n");
        printf("(4)ɾ���鼮��Ϣ\n(5)����軹����\n(6)�û���Ϣ��ѯ�޸�\n");
        printf("(0)�˳�����\n>>");
		scanf("%d", &C);
		getchar();
	}
	if (1 == C)               //�鼮��ѯ
	{
		system("cls");
		BookSearch(1);
	}
	else if (2 == C)                   //�鼮¼��
	{
		system("cls");
		struct BooksInfo *pHead;
		pHead = OpenFile2();
		if (NULL == pHead) BooksRegister();
		else BooksInsert(pHead);
	}
	else if (3 == C)                //�鼮�༭
	{
		system("cls");
		BooksEdit();
	}
	else if (4 == C)              //�鼮ɾ��
	{
		system("cls");
		BooksDelete();
	}
	else if (5 == C)
	{
		system("cls");          //����軹
		BorrowAndReturn();
	}
	else if (6 == C)              //�û���Ϣ
	{
		system("cls");
		UserDate1();
	}
	else if (0 == C)              //������һ��
	{
		system("cls");
		Login();
	}
}                         //����Ա��������

void UserDate1()                 //����Ա��Ϣ
{
	printf(">>����Ա��Ϣ��\n\n");
	struct User *pHead, *p, *m;
	p = pHead = OpenFile1();
	printf(">>��ǰ��½id��");
	puts(loadingstu_id);
	printf("\n");                             //���ļ���������
	while (strcmp(loadingstu_id, p->user.stu_id) != 0)
	{
		p = p->next;
	}
	//printf("Find");
	PrintUserInfo(p);                     //��ӡ��ǰ�û���Ϣ
	int t = 9;
	while (t != 99999)
	{
		printf("(1)�޸ĵ�ǰ����Ա��Ϣ\n(2)��ѯ�����û���Ϣ\n(3)�޸������û���Ϣ\n(0)������һ��\n>>");               //����Ա����
		scanf("%d", &t);
		getchar();
		system("cls");
		while (t != 0 && t != 1 && t != 2 && t != 3)
		{
			printf(">>��������ȷ��ָ��\n\n");
			printf("(1)�޸ĵ�ǰ����Ա��Ϣ\n(2)��ѯ�����û���Ϣ\n(3)�޸������û���Ϣ\n(0)������һ��\n>>");
			scanf("%d", &t);
			getchar();
		}
		if (0 == t) Commander();
		else if (1 == t) Administratorchanges(p, pHead);
		else if (2 == t) { m = SearchUser(pHead); PrintUserInfo(m); }
		else if (3 == t) { m = SearchUser(pHead); Administratorchanges(m, pHead); }
		Freechain(pHead);
		printf(">>����0������һ��\n>>");
		scanf("%d", &t);
		getchar();
		system("cls");
	}

}

void Administratorchanges(struct User*d, struct User*pHead)        //����ԱȨ���޸��û���Ϣ��ǰ��Ҫ�����û��˺ţ�
{

	int t = 1;

	while (t != 0)
	{
	    printf(">>�޸���Ϣ\n\n");
		printf(">>�������޸���Ϣ\n\n(1)����\n(2)�ֻ���\n(3)ѧ��\n(4)���֤��\n(5)רҵ\n(6)Ȩ��\n(7)����\n>>");
		scanf("%d", &t);
		getchar();
		if (1 == t)
		{
			printf(">>ԭ������%s\n", d->user.name);
			printf(">>�޸�����Ϊ��");
			gets(d->user.name);
		}
		else if (2 == t)
		{
			printf(">>ԭ�ֻ��ţ� %s\n", d->user.tel);
			printf(">>�޸��ֻ���Ϊ��");
			gets(d->user.tel);
		}
		else if (3 == t)
		{
			printf(">>ԭѧ�ţ�  %s\n\n", d->user.stu_id);
			printf(">>�޸�ѧ��Ϊ��  ");
			gets(d->user.stu_id);
		}
		else if (4 == t)
		{
			printf(">>ԭ���֤���룺 %s\n\n", d->user.id);
			printf(">>�޸����֤����Ϊ�� ");
			gets(d->user.id);
		}
		else if (5 == t)
		{
			printf(">>ԭרҵ:   %s\n\n", d->user.major);
			printf(">>�޸�רҵΪ:   ");
			gets(d->user.major);
		}
		else if (6 == t)
		{
			printf(">>���з���Ȩ�ޣ�%s\n", d->user.per);
			printf(">>�޸ķ���Ȩ��Ϊ��");
			gets(d->user.per);
		}
		else if (7 == t)
		{
			printf(">>ԭ����:   %s\n", d->user.password);
			printf(">>�޸�����Ϊ��");
			gets(d->user.password);
		}

		printf("\n>>����0������������һ��\n>>���������0���ּ����޸�\n>>");
		scanf("%d", &t);
		getchar();
		system("CLS");

	}
	SaveFile1(pHead);
	printf(">>Ŀǰ��¼���ѽ�ͼ�鹲%d��\n", d->n);
	UserDate1();
}

void BorrowAndReturn()             //����Ա����軹����
{
	int t;
	printf(">>�軹����\n\n");
	printf("(1)�û��軹��Ϣ��ѯ\n(2)�軹����\n(0)������һ��\n>>");
	scanf("%d", &t);
	getchar();
	while (t != 1 && t != 2 && t != 0)
	{
		printf("��������ȷ��ָ��\n");
		printf("1���û��軹��Ϣ��ѯ\n2���軹����\n0��������һ��\n");
		scanf("%d", &t);
		getchar();
	}
	if (1 == t) AdBookBAR();
	else if (2 == t) BAR1();
	else if (0 == t) Commander();
}

void AdBookBAR()      //�û�ͼ��軹��¼
{
	struct User*pHead, *p;
	pHead = OpenFile1();
	p = SearchUser(pHead);
	int l;
	l = p->n;
	if (0 == l)
		printf("���κν��ļ�¼\n");
	int i;
	for (i = 0; i < l; i++)
	{
		printf("����:");
		puts(p->book[i].Bookname);
		printf("    ");
		printf("���:");
		puts(p->book[i].Bian_Hao);
		printf("    ");
		printf("��ȡʱ��:%d-%d-%d    ", p->book[i].borrowtime.year, p->book[i].borrowtime.mon, p->book[i].borrowtime.day);
		printf("��ֹʱ��:%d-%d-%d\n", p->book[i].returntime.year, p->book[i].returntime.mon, p->book[i].returntime.day);

	}
	Freechain(pHead);
	int t;
	printf("����0������һ��\n");
	scanf("%d", &t);
	getchar();
	while (t != 0)
	{
		printf("��������ȷָ��\n");
		printf("����0������һ��\n");
		scanf("%d", &t);
		getchar();
	}
	BorrowAndReturn();
}

void BAR1()           //�軹����
{
	int t;
	printf("1������\n2������\n0��������һ��\n");
	scanf("%d", &t);
	getchar();
	while (t != 1 && t != 2 && t != 0)
	{
		printf("��������ȷ��ָ��\n");
		printf("1������\n2������\n0��������һ��\n");
		scanf("%d", &t);
		getchar();
	}
	if (1 == t)  Borrow();
	else if (2 == t) ReturnBook();
	else if (0 == t) Commander();
	Commander();

}

int Check(struct User*p)
{
	int Rule(int a, int b, int c);
	int n = 0;
	if (p->n == 0) return 1;
	for (int i = 0; i < (p->n); i++)
	{
		int t = 1;
		t = Rule(p->book[i].returntime.year, p->book[i].returntime.mon, p->book[i].returntime.day);                    //�жϹ黹ʱ���Ƿ�ʱ��1Ϊû�г�ʱ��0Ϊ��ʱ
		if (0 == t) n++;
		p->next;
	}
	if (n == 0) return 1;
	else return 0;

}

void Borrow()           //����
{
	char studentid[10];
	char bianhao[30];
	struct User *pHead, *p;
	pHead = OpenFile1();
	p = SearchUser(pHead);
	//printf("FindUser!");
	int t = 1;
	t = Check(p);                       //����Ƿ����δ���鼮  1 ��  0��
	//printf("%d",t);
	if (t == 0)
	{
		printf("���Դ��н����ʱδ���鼮�����ȼ�ʱ�黹�������ɷ���\n�������������һ��\n");
		getchar();
		BAR1();
	}
	if (p->n == 10)
	{
		printf("���ѽ���10���鼮�����ȹ黹��\n");
		printf("���������������һ��");
		getchar();
		BAR1();
	}
	printf("ͼ����:");
	gets(bianhao);
	BookBORROWED(p, bianhao);
	SaveFile1(pHead);
	Freechain(pHead);
	BAR1();
}

struct BooksInfo *SearchBianhao1(char BookBianhao[30], struct BooksInfo*pHead)
{
	int Compare(char ino[], char org[]);
	struct  BooksInfo *q, *p, *use;
	int n = 0;
	use=NULL;
	q = p = pHead;
	while (q != NULL)
	{
		p = q;
		int t = 0;
		//puts(p->BianHao);
		t = Compare(BookBianhao, p->BianHao);                //�ȽϹؼ���
		//printf("t=%d",t);
		if (1 == t)
		{
			Print(p);                             //��������Ϣ
			n++;
			use = p;
		}
		q = p->next;
	}
	printf("�ܹ���%d�����\n", n);
	//while (n != 1)
	//{
	if (n != 1)
	{
		printf("���ٴ�����ͼ������ȷ������(�뾫ȷ��ĳһ���鼮)��\n");
		char BianHao[30];
		gets(BianHao);
		q = p = pHead;
		n = 0;
		while (q != NULL)
		{
			p = q;
			int t = 0;
			t = Compare(BianHao, p->BianHao);                //�ȽϹؼ���
			if (1 == t)
			{
				Print(p);
				printf("���Ҿ�ȷ�鼮�ɹ�\n");                            //��������Ϣ
				use=p;
				return use;
			}
			q = p->next;
		}
	}
	else return use;


	//}

	//return p;       //����ͼ���ַ ����



}

void PrintfBook(struct BooksInfo*p)      //��ӡͼ����Ϣ
{
	printf("����:");
	puts(p->name);
	printf("          ");
	printf("����:");
	puts(p->writer);
	printf("\n");
	printf("ISDN:");
	printf("%ld   ", p->ISBN);
	printf("     ");
	printf("���:");
	puts(p->BianHao);
	printf("����ʱ��:%d-%d-%d\n", p->PubTime.year, p->PubTime.mon, p->PubTime.day);
	printf("��������:");
	puts(p->print);
	printf("         ");
	printf("ͼ�����:");
	puts(p->cate);
	printf("\n");
}
int pdate[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };       //ƽ����·�
int rdate[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };       //������·�

int runnian(int n)       //�ж����꺯����0Ϊƽ�꣬1Ϊ����
{
	int run;
	if (n % 100 == 0)
	{
		if (n % 400 == 0)
			run = 1;
		else run = 0;
	}
	else {
		if (n % 4 == 0)
			run = 1;
		else run = 0;
	}
	return run;
}

void returntime(int a, int b, int c, int *d, int *e, int *f)          //����60����������,a,b,cΪ��ȡ��������,d,e,fΪ�黹ʱ���������
{
	int run;
	c = c + 61;
	run = runnian(a);
	if (run == 0)         //����Ϊƽ��
	{
		c = c - pdate[b - 1];
		if (c > pdate[b])
		{
			c = c - pdate[b];
			if (c > pdate[b + 1])
			{
				c = c - pdate[b + 1];
				b = b + 3;
			}
			else b = b + 2;
		}
		else b = b + 1;
	}
	else {                       //����Ϊ����
		c = c - rdate[b - 1];
		if (c > rdate[b])
		{
			c = c - rdate[b];
			if (c > rdate[b + 1])
			{
				c = c - rdate[b + 1];
				b = b + 3;
			}
			else b = b + 2;
		}
		else b = b + 1;
	}
	if (b > 12)
	{
		a = a + 1;
		b = b - 12;
	}
	*d = a;
	*e = b;
	*f = c;
}

void BookBORROWED(struct User*p, char bianhao[30])        //�û���ȡͼ������ļ�,nΪ��ȡͼ����
{
	struct BooksInfo*tushu, *pHead1;
	pHead1 = OpenFile2();
	tushu = SearchBianhao1(bianhao, pHead1);//���ݱ�ţ���ѯͼ���λ��ָ��   ע��
	printf("zt=%d", tushu->zt);
	if (tushu->zt == 0)       //���ͼ��δ�����������һ��
	{
		system("CLS");
		printf("��ȷ��ͼ����Ϣ");     //  ȷ��ͼ����Ϣ
		PrintfBook(tushu);
		printf("�����ȡ������0,���������һ��������1\n");
		int i;
		scanf("%d", &i);
		getchar();
		while (i != 1 && i != 0)
		{
			printf("��������ȷ��ָ��,����������\n");
			printf("�����ȡ������0,���������һ��������1\n");
			scanf("%d", &i);
			getchar();
		}
		if (i == 0)             //��ȡͼ��󣬽�ͼ����Ϣ��ѧ����Ϣ��
		{

			tushu->zt = 1;
			strcpy(tushu->BorrowStu_id, p->user.stu_id);           //��ͼ���ȡ�˴���
			strcpy(p->book[p->n].Bookname, tushu->name);         //���鼮�������û�����
			strcpy(p->book[p->n].Bian_Hao, tushu->BianHao);       ////���鼮��Ŵ����û�����
			int *ye, *mo, *da;                         //��ȡ��ȡʱ��
			ye = &(p->book[p->n].borrowtime.year);
			mo = &(p->book[p->n].borrowtime.mon);
			da = &(p->book[p->n].borrowtime.day);
			getstime(ye, mo, da);
			ye = &(p->book[p->n].returntime.year);       //����Ӧ�黹ʱ��
			mo = &(p->book[p->n].returntime.mon);
			da = &(p->book[p->n].returntime.day);
			returntime(p->book[p->n].borrowtime.year, p->book[p->n].borrowtime.mon, p->book[p->n].borrowtime.day, ye, mo, da);
			(p->n)++;
		}

	}
	else printf("ͼ���ѽ�������ѯ����ͼ��\n");
	printf("��ȡ�ɹ����������������һ����");
	getchar();
	SaveFile2(pHead1);
	Freechain2(pHead1);
}

int Rule(int a, int b, int c)          //�жϹ黹ʱ���Ƿ�ʱ��1Ϊû�г�ʱ��0Ϊ��ʱ
{
	int yea, mon, day;
	time_t temp;
	struct tm *t;
	time(&temp);
	t = localtime(&temp);
	yea = t->tm_year + 1900;
	mon = t->tm_mon + 1;
	day = t->tm_mday;
	if (a < yea)
		return 0;
	else if (b < mon)
		return 0;
	else if (c < day)
		return 0;
	else return 1;
}

void ReturnBook()     //����Ա�黹ͼ��
{
	char xuehao[10], bianhao[30];
	int i = 0, chao;
	printf("�������ѯ�û�ѧ��:");
	gets(xuehao);
	struct User*p, *head;   //�����û�ѧ��,pΪ�û���ָ��
	head = OpenFile1();
	p = head;
	while (strcmp(p->user.stu_id, xuehao) != 0)
	{
		p = p->next;
	}
	if (p->n == 0)
	{
		printf("���޽��ļ�¼,���س�������һ��\n");
		getchar();
		BAR1();
	}
	else
	{
		for (int i = 0; i < (p->n); i++)
		{
			printf("�����鼮:");
			puts(p->book[i].Bookname);
			printf("�鼮���:");
			puts(p->book[i].Bian_Hao);
			printf("\n");
			printf("����ʱ��:");
			printf("%d��%d��%d��    ", p->book[i].borrowtime.year, p->book[i].borrowtime.mon, p->book[i].borrowtime.day);
			printf("Ӧ�黹ʱ��:");
			printf("%d��%d��%d��\n", p->book[i].returntime.year, p->book[i].returntime.mon, p->book[i].returntime.day);
		}
	}
	printf("������黹ͼ����:");
	i=0;
	gets(bianhao);
	struct BooksInfo*tushu, *pHead;           //���ݱ�ţ���ѯͼ���λ��ָ��   ע��
	pHead = OpenFile2();
	tushu = SearchBianhao1(bianhao, pHead);
	int k=p->n;
	while (Compare(p->book[i].Bian_Hao, tushu->BianHao) != 1)
	{
	    i++;
		int bian[30];
		if ((i == k) && Compare(p->book[i-1].Bian_Hao, tushu->BianHao) != 1)
		{
			printf("�û���δ��ȡ���鼮�������������鼮���\n");
			int bian[30];
			gets(bian);
			tushu=SearchBianhao1(bian,pHead);
			i=0;
		}

	}
	/*
	while(strcmp(p->book[i].Bian_Hao,bianhao)!=0)
	{
		int bian[30];
		i++;
		if(i==(p->n)&&strcmp(p->book[i-1].Bian_Hao,bianhao)!=0)
		{
			printf("δ���ҵ��鼮�������������鼮���\n");
			gets(bian);
			i=0;
		}

	}      */          //����鼮��������������û�û�н�ȡ�Ȿ�飬�����ʾ����������������
	chao = Rule(p->book[i].returntime.year, p->book[i].returntime.mon, p->book[i].returntime.day);
	if (chao == 0) printf("δ���ڹ黹�鼮���뼰ʱ���ɷ���\n");
	tushu->BorrowStu_id[0] = '\0';             //�������鼮��ѧ����Ϣ����
	p->book[i].Bookname[0] = '\0';
	p->book[i].Bian_Hao[0] = '\0';
	tushu->zt = 0;
	if (i < p->n - 1)            //�黹ͼ�鲻���û��ѽ�ȡͼ������һ�������黹ͼ����Ϣ�Ժ���Դ�ǰ��
	{
		for (; i < p->n - 1; i++)
		{
			strcpy(p->book[i].Bookname, p->book[i + 1].Bookname);
			strcpy(p->book[i].Bian_Hao, p->book[i + 1].Bian_Hao);
			p->book[i].borrowtime.year = p->book[i + 1].borrowtime.year;
			p->book[i].borrowtime.mon = p->book[i + 1].borrowtime.mon;
			p->book[i].borrowtime.day = p->book[i + 1].borrowtime.day;
			p->book[i].returntime.year = p->book[i + 1].returntime.year;
			p->book[i].returntime.mon = p->book[i + 1].returntime.mon;
			p->book[i].returntime.day = p->book[i + 1].returntime.day;
		}
	}
	p->book[p->n - 1].Bookname[0] = '\0';        //���û���Ϣ�н�ȡͼ�����Ϣ���һ������
	p->book[p->n - 1].Bian_Hao[0] = '\0';
	p->n = p->n - 1;
	printf("����ɹ����������������һ��\n");
	SaveFile1(head);
	SaveFile2(pHead);
	Freechain(head);
	Freechain2(pHead);
	BAR1();

}

