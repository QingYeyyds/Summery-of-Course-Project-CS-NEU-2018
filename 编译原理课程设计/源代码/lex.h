#ifndef LEX_H_INCLUDED
#define LEX_H_INCLUDED
#pragma once
#include "all.h"
using namespace std;
char* TurnChar(string a);
struct Token {	//Token�ṹ
	string Word;	//����
	int Key;
};
class Lexical {
private:
	char *f_path;	//�ļ���ַ
	string article;		//����
	int len = 0;	//���ݳ���
	char ch = ' ';
	string word; //����ɨ��ĵ���
	int index = -1;	//��ǰ���λ��
	int state = 0;	//��ǰ�Զ���״̬
	vector<struct Token> token;	//Token����
	int len_tk = 0;
	vector<string> iT;	//��ʶ����
	int len_it = 0;
	vector<string> cT;	//�ַ���
	int len_ct = 0;
	vector<string> sT;	//�ַ�����
	int len_st = 0;
	vector<string> CT;	//������
	int len_CT = 0;
	vector<string> KT;	//�ؼ��ֱ�
	int len_kt = 0;
	vector<string> PT;	//�����
	int len_pt = 0;
public:
	//���캯��
	Lexical();
	Lexical(string path);
	//��ʼ��
	void SetPath(string path);  //�����ļ���ַ
	void SavePath(string path);//�����ַ����
	void ReadFile();//��ȡ�ļ�����
	void init();//���ע�ͺ��� ��ʼ��
	void init_KT();//�����ַ����ʼ��
	void init_PT();	//������ʼ��
	void add_it(string str);	//��ʶ�������
	void add_ct(string str);	//�ַ������
	void add_st(string str);	//�ַ��������
	void add_Ct(string str);	//���������
	void get_char();	//������һ���ַ�
	void get_ns();	//������һ���ǿ��ַ�
	bool letter();	//�жϵ�ǰ�Ƿ�Ϊ��ĸ
	bool digit();	//�жϵ�ǰ�Ƿ�Ϊ����
	//ɨ���
	int if_iT(string word);
	int if_cT(string word);
	int if_sT(string word);
	int if_CT(string word);
	int if_PT(string word);
	int if_KT(string word);
	int state_change(char ch, int now_state);	//�Զ���״̬ת������
	void Token();	//Token���ɺ���
	//��ӡ����
	void PrintArt();
	void PrintToken();
	void Print_iT();
	void Print_cT();
	void Print_sT();
	void Print_CT();
	//��Ҫ�ⲿ�ӿ�
	struct Token LastToken();	//������һ��Token
	struct Token NextToken();	//������һ��Token
	string GetStr(string table, int key);	//���ص�ǰ���ж�Ӧ�ַ���
	vector<struct Token> getToken();	//��������Token����
};


#endif // LEX_H_INCLUDED
