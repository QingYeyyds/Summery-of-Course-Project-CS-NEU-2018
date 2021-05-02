#pragma once
#include "all_head.h"
using namespace std;
/*struct pos//�߼�����
{
	int x;
	int y;
};*/
COORD postocoord(pos p)//�߼����굽ʵ������
{
	COORD coord;
	coord.X = p.x*_proportion;
	coord.Y = p.y*_proportion;
	return coord;
}
/*
enum direction//����
{
	w, a, s, d
};
*/
void print(COLORREF photo[][_proportion], pos p)//��p���ӡͼ��
{
	COORD coord = postocoord(p);
	int i, k;
	for (i = coord.X; i < coord.X + 15; i++)
	{
		for (k = coord.Y; k < coord.Y + 15; k++)
		{
			putpixel(i, k, photo[i - coord.X][k - coord.Y]);
		}
	}
}
void savephoto(COLORREF photo[][_proportion], string load)
{
	ofstream f(load, ios::out | ios::binary);
	f.write((char *)photo, sizeof(COLORREF) * _proportion * _proportion);
	f.close();
}
void savephoto(COLORREF photo[][_proportion], char load[])
{
	ofstream f(load, ios::out | ios::binary);
	f.write((char *)photo, sizeof(COLORREF) * _proportion * _proportion);
	f.close();
}//��load·�����Զ����ƴ洢ͼ��
void loadphoto(COLORREF photo[][_proportion], string load)
{
	ifstream f(load, ios::in | ios::binary);
	f.read((char *)photo, sizeof(COLORREF) * _proportion * _proportion);
	f.close();
}
void loadphoto(COLORREF photo[][_proportion], char load[])
{
	ifstream f(load, ios::in | ios::binary);
	f.read((char *)photo, sizeof(COLORREF) * _proportion * _proportion);
	f.close();
}//��ȡload·���µĶ������ļ�����ͼ���洢��photo��
//��TCHARתΪchar   
//*tchar��TCHAR����ָ�룬*_char��char����ָ��   
void TcharToChar(const TCHAR * tchar, char * _char)
{
	int iLength;
	//��ȡ�ֽڳ���   
	iLength = WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);
	//��tcharֵ����_char    
	WideCharToMultiByte(CP_ACP, 0, tchar, -1, _char, iLength, NULL, NULL);
}
//ͬ��   
void CharToTchar(const char * _char, TCHAR * tchar)
{
	int iLength;

	iLength = MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, NULL, 0);
	MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, tchar, iLength);
}