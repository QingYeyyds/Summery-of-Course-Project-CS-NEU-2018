#pragma once
#include "all_head.h"
using namespace std;
void printnum(int x, int y, int &n);
class Total
{
private:
	int number;
	
	int starttime;//��ʼʱ��
	int endtime;//����ʱ��
	int kinanatime;//��һ����ͣʱ�䣬��ʼ��Ϸʱ��ֵΪ��Ϸ��ʼʱ��
	int alltime;//��Ϸʱ��
	int blood;//Ѫ��
	int op;//��������
	int past;//�ж��Ƿ���Ҫ����
public:
	int score;//�÷�
	void addsocre(int _score = 5, int _nature = 0);//���ӷ���
	void print(Snake &snake);//��ʾ
	void init(Snake &snake);//��ʼ��
	bool iftime();
	friend void pause();
	friend void SignInRank();
	friend direction Snake::change_direction();
};
extern Total total;
void pause();