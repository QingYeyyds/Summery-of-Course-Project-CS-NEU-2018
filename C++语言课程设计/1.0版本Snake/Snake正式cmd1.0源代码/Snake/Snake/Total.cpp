#include "all_head.h"
Total total;
void printnum(int x, int y, int &n)//������ת��ΪTCHAR���ƶ�λ�����
{
	TCHAR s[20];
	outtextxy(x, y, _T("            "));
	_stprintf_s(s, _T("%d"), n);
	outtextxy(x, y, s);
}
char _mygetch()//��������ֵ����c�У�������ܵ�������λ�ֽڣ����������⴦��
{
	char c,d;
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
	return c;
}
void Total::addsocre(int _score/* = 5 */, int _nature /* = 0 */ )
{
	number++;
	score += _score;
}
void Total::init(Snake &snake)
{
	score = 0;
	number = 0;
	starttime = time(NULL);
	kinanatime = starttime;
	alltime = 0;
	past = 0;
	blood = snake.getblood();
	op = 0;
	outtextxy(510 + 30, 60, _T("�÷�"));
	outtextxy(510 + 30, 60 + 30, _T("Ѫ��"));
	outtextxy(510 + 10, 60 + 60, _T("��Ϸʱ��"));
	this->print(snake);
}
void Total::print(Snake &snake)
{
	blood = snake.getblood();
	BeginBatchDraw();
	printnum(510 + 30 + 60, 60, score);//����÷�
	printnum(510 + 30 + 60, 60 + 30, blood);//���Ѫ��
	printnum(510 + 10 + 80, 60 + 60, alltime);
	EndBatchDraw();
}
bool Total::iftime()
{
	past++;
	if (past >= 50)
	{
		past = 0;
		total.alltime++;
		return true;
	}
	return false;
}
void pause()
{
	TCHAR title[] = _T("��Ϸ�Ѿ���ͣ");
	TCHAR t1[] = _T("1������Ϸ");
	TCHAR t2[] = _T("2���¿�ʼ");
	TCHAR t3[] = _T("3�˳���Ϸ");
	TCHAR t4[] = _T("                        ");
	outtextxy(510 + 45, 510 - 120, title);
	outtextxy(510 + 60, 510 - 90, t1);
	outtextxy(510 + 60, 510 - 60, t2);
	outtextxy(510 + 60, 510 - 30, t3);
	bool ky = true;
	while (ky)
	{
		switch (_mygetch())
		{
		case '1':
		{
			ky = false;
			//total.alltime+=(time(NULL)-total.kinanatime)
			total.kinanatime = time(NULL);
			break;
		}
		case '2'://���¿�ʼ
		{
			system("start ./exe/Snake.exe");
			exit(0);//�ر���Ϸ���´�
		}
		case '3':
		{
			system("start ./GreedSnake.exe");//����Ϸ��ʼ����
			exit(0);//�ر���Ϸ
		}
		default:
			break;
		}
	}
	outtextxy(510 + 45, 510 - 120, t4);
	outtextxy(510 + 60, 510 - 90, t4);
	outtextxy(510 + 60, 510 - 60, t4);
	outtextxy(510 + 60, 510 - 30, t4);
}