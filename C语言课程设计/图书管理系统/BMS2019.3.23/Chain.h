#ifndef CHAIN_H
#define CHAIN_H

struct time
{
	int year;
	int mon;
	int day;
};
struct BooksInfo
{
	char name[30];//����
	char ISBN[23];//ͼ���ʮλisbn���
	char BianHao[30];//ͼ����ڱ�ţ�ÿ���鶼��һ������ʹ��һ������
	float price;//����
	char writer[30];//����
	//int num;//���ʣ������
	char print[30];//��������
	struct time PubTime;//����ʱ��
	char cate[30];//ͼ�����
	int zt;//ͼ���Ƿ�����Ĭ��Ϊ0δ���
	char BorrowStu_id[10];
	struct BooksInfo*next;
};
struct inform        //�û���Ϣ
{
	char name[20];   //����
	char tel[13];    //�ֻ���        11λ
	char stu_id[10];   //ѧ���˺�           8λ
	char id[20];     //��ݺ�              18λ
	char major[10];  //רҵ
	char per[15];    //����Ȩ��           1 ����Ա   2 ��ͨ�û�
	char password[17];   //����                ʮ��λ
};

struct Book          //��ȡ�鼮��Ϣ
{
	char Bookname[30];
	char Bian_Hao[30];
	struct time borrowtime;
	struct time returntime;
};
struct User
{
	struct inform user;            //�û�
	//struct time Time;
	int n;                         //������
	struct Book book[10];
	struct node*next;             //��һ�ڵ�
};

char loadingstu_id[10];
char loadingper[15];

#define LLL sizeof(struct BooksInfo)

#endif

