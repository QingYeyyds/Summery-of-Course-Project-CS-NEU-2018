#pragma once
#include "all_head.h"
using namespace std;
//��ӵĶ��⺯��
//int mapp[510 / _proportion][510 / _proportion];
int(*mapp)[34];
istream &operator>>(istream &in, list<pos> &a)
{
	if (!a.empty())
	{
		cout << "���ǿյģ�" << endl;
		return in;
	}
	cout << "�����볤��" << endl;
	int n;
	in >> n;
	pos p;
	for (int i = 0; i < n; i++)
	{
		cout << "�������" << i << "��" << endl;
		in >> p.x >> p.y;
		a.push_back(p);
	}
	return in;
}
bool keyboardhit(char &c)//������ܵ�����������1�����򷵻�0����������ֵ����c�У�������ܵ�������λ�ֽڣ����������⴦��
{
	char d;
	if (_kbhit())
	{
		c = _getch();
		if ((c == 0) || (c == 0xE0) || (c == -32))//������ܵ���λ�ֽڵİ���
		{
			d = _getch();
			if (c == -32)
				switch (d)
				{
				case 72:
					c = 'w';
					break;
				case 80:
					c = 's';
					break;
				case 75:
					c = 'a';
					break;
				case 77:
					c = 'd';
					break;
				default:
					c = 0;
					break;
				}
		}
		//�������ת��ΪСд��wasd
		if ((c >= 'A') && (c <= 'Z'))
			c = c - ('A' - 'a');
		return 1;
	}
	else return 0;
}
bool operator ==(pos &p1, pos &p2)
{
	if ((p1.x == p2.x) && (p1.y == p2.y))
		return 1;
	else return 0;
}
/*
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
	bool havebean;
public:
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
	pos gethead();
	pos gettail();
	pos getfirstbody();
	list<pos> getbody();
	pos getnext();
};
*/
Snake::Snake(pos _head, int _blood, int _maxblood, list<pos> &_body, int _speed, int _len/* = 3*/, direction _dir/* = d*/)
{
	head = _head;
	blood = _blood;
	maxblood = _maxblood;
	body = _body;
	speed = _speed;
	len = _len;
	dir = _dir;
	past = 0;
	ifnext = 0;
	havebean = 0;
	speedpast = 0;
}
bool Snake::ifmove()
{
	past++;
	if (past >= speed)
	{
		past = 0;
		ifnext = 1;
		switch (dir)
		{
		case w:
			next.x = head.x;
			next.y = head.y - 1;//����һ��
			break;
		case a:
			next.x = head.x - 1;
			next.y = head.y;//����һ��
			break;
		case s:
			next.x = head.x;
			next.y = head.y + 1;//����һ��
			break;
		case d:
			next.x = head.x + 1;
			next.y = head.y;//����һ��
			break;
		default:
			break;
		}
		(*this).correctmove();
		return 1;
	}
	else return 0;
}
void Snake::correctmove()
{
	next.x = (next.x + (510 / _proportion)) % (510 / _proportion);
	next.y = (next.y + (510 / _proportion)) % (510 / _proportion);
}
void Snake::move()
{
	if (ifnext)
	{
		if (havebean)//�Ե�����~
		{
			mapp[head.x][head.y] = 1;//ԭ��ͷ��λ�ñ������
			body.push_front(head);
			head = next;
			mapp[head.x][head.y] = 2;//ͷ���ƶ�
			havebean = 0;
			speedpast++;
			this->changespeed();
		}
		else
		{
			body.push_front(head);
			mapp[body.back().x][body.back().y] = 0;
			body.pop_back();//ɾ��β��
			mapp[head.x][head.y] = 1;//ͷ���������
			head = next;
			mapp[head.x][head.y] = 2;//ͷ���ƶ�
		}
	}
	ifnext = 0;
}
bool Snake::died(int key/*=0*/)
{
	bool ifdied = 0;
	if (ifnext)
	{
		if (key)//���ɴݻ�ǽ
			return 1;
		else if (blood <= 0)//Ѫ������0
			return 1;
	}
	return 0;
}
/*bool Snake::eatfood()
{
	if (ifnext)
	{
		if (mapp[next.x][next.y] == 3)
		{
			return 1;
		}
	}
	return 0;
}
void Snake::addlenth()
{
	len++;
	body.push_front(head);
}*/
void Snake::eatfood()
{
	havebean = 1;
	len++;
	body.push_front(head);
}
direction Snake::getdirection()
{
	return dir;
}
direction Snake::change_direction()
{
	char c;
	pos p = body.front();
	if (keyboardhit(c))
	{
		switch (c)
		{
		case 'w':
			if (!((head.x == p.x) && ((head.y - 1) == p.y)))
				dir = w;
			break;
		case 'a':
			if (!(((head.x - 1) == p.x) && (head.y == p.y)))
				dir = a;
			break;
		case 's':
			if (!((head.x == p.x) && ((head.y + 1) == p.y)))
				dir = s;
			break;
		case 'd':
			if (!(((head.x + 1) == p.x) && (head.y == p.y)))
				dir = d;
			break;
		case (char)27:
			pause();
			break;
		default:
			break;
		}
	}
	return dir;
}
bool Snake::ifblood()
{
	if (ifnext)
	{
		blood = blood - losebase;
		return 1;
	}
	return 0;
}
int Snake::getblood()
{
	return blood;
}
void Snake::changespeed(int ss/* =0 */)
{
	if (ss == 0)
	{
		if ((speedpast >= 5) && (speed >5))
		{
			speed = speed - 4;
			speedpast = 0;
		}
	}
	else
	{
		speed = ss;
	}
}
pos Snake::gethead()
{
	return head;
}
pos Snake::gettail()
{
	return body.back();
}
pos Snake::getfirstbody()
{
	return body.front();
}
list<pos> Snake::getbody()
{
	return body;
}
pos Snake::getnext()
{
	return next;
}
void gameover()
{
	TCHAR t4[] = _T("Game over");
	outtextxy(510 + 45, 510 - 120, t4);
	SignInRank();
	outtextxy(510 + 45, 510 - 90, _T("1���¿�ʼ"));
	outtextxy(510 + 5, 510 - 60, _T("���������ؿ�ʼ����"));
	if (_mygetch() == '1')
	{
		system("start ./exe./Snake.exe");
		exit(0);//�ر���Ϸ���´�
	}
	else
	{
		system("start ./GreedSnake.exe");//����Ϸ��ʼ����
		exit(0);
	}
}
int Snake::addblood(int i/*=1*/)//����Ѫ��
{
	blood += i;
	if (blood > maxblood)
		blood = maxblood;
	return blood;
}
void Snake::changeblood(int bb)//�ı�Ѫ��
{
	blood = bb;
}
void Snake::changemaxblood(int bb)//�ı����Ѫ��
{
	maxblood = bb;
}
