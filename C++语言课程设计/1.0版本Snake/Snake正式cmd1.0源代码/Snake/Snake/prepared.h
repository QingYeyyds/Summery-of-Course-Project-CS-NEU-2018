#pragma once
#include "all_head.h"
using namespace std;
const int _proportion = 15;//��������
struct pos//�߼�����
{
	int x;
	int y;
};
COORD postocoord(pos p);//�߼����굽ʵ������
enum direction//����
{
	w, a, s, d
};
void print(COLORREF photo[][_proportion], pos p);//��p���ӡͼ��
void savephoto(COLORREF photo[][_proportion], string load);
void savephoto(COLORREF photo[][_proportion], char load[]);//��load·�����Զ����ƴ洢ͼ��
void loadphoto(COLORREF photo[][_proportion], string load);
void loadphoto(COLORREF photo[][_proportion], char load[]);//��ȡload·���µĶ������ļ�����ͼ���洢��photo��
//��TCHARתΪchar   
//*tchar��TCHAR����ָ�룬*_char��char����ָ��   
void TcharToChar(const TCHAR * tchar, char * _char);
//ͬ��   
void CharToTchar(const char * _char, TCHAR * tchar);
