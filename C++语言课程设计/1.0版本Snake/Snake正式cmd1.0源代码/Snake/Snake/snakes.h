#pragma once
#include "all_head.h"
//��������Ӧ�ñ�ע�͵�

const int losebase = 1;
extern int(*mapp)[34];
using namespace std;
//��ӵĶ��⺯��

class Snake
{
private:
	int len;
	list<pos> body;
	pos head;
	int speed;
	direction dir;
	int blood;
	int maxblood;
	int past;
	bool ifnext;//��һ���Ƿ���Ч,0��Ч,1��Ч
	pos next;//��һ��λ��
	int speedpast;
public:
	bool havebean;
	Snake(pos _head, int _blood, int _maxblood, list<pos> &_body, int _speed, int _len = 3, direction _dir = d);
	bool ifmove();//�Ƿ��ƶ�,�ƶ�ʱ�޸�ifnext����¼��һ��
	//���º�����Ҫ��ifmove����ʹ�ú�ʹ��
	void correctmove();//������һ��������ͼ��������������1�����򷵻�0
	void move();//�����ڵ�ͼ�����Ͻ����޸�
	bool died(int key = 0);//�ж��Ƿ�����������1����������0���
	//bool eatfood();//�ж��Ƿ�Ե�ʳ��Ե�����1��û�Ե�����0
	//void addlenth();//���ӳ��ȣ�����������������һ��ͷ��
	void eatfood();//�Զ��Ӻ�ı��ߵ���ѧ
	direction change_direction();//�Ӽ����Ͻ��ܰ������ı䷽��
	direction getdirection();//���������ڵķ���
	void changespeed(int ss = 0);//�ı��ٶȣ�δ����
	bool ifblood();//�ж��Ƿ�ײ���ɴݻ�ǽ�����۳�Ѫ�������ײ������1�����򷵻�0
	int getblood();//����Ѫ��
	int addblood(int i = 1);//����Ѫ��
	pos gethead();
	pos gettail();
	pos getfirstbody();
	list<pos> getbody();
	pos getnext();
	void changeblood(int bb);//�ı�Ѫ��
	void changemaxblood(int bb);//�ı����Ѫ��
};

//class Snake;
istream &operator>>(istream &in, list<pos> &a);
bool keyboardhit(char &c);//������ܵ�����������1�����򷵻�0����������ֵ����c�У�������ܵ�������λ�ֽڣ����������⴦��
bool operator ==(pos &p1, pos &p2);
void gameover();