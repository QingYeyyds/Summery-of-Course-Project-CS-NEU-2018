#ifndef DAG_H_INCLUDED
#define DAG_H_INCLUDED
#include "all.h"
using namespace std;

struct quat_item{   //��Ԫʽ
    string w;   //������
    string op1; //������1
    string op2; //������2
    string t;   //���
};

struct dagNode {    //DAG�ڵ�
    int num;        //���
    int leftChild=-1; //����
    int rightChild=-1; //�Һ���
    string opt="";   //������
    vector<string> mark;//��� ����Ƿ��ڵ�һ��
};

extern vector <quat_item> QUATS;   //����Ԫʽ
void showQUATS();    //��ʾ��Ԫʽ
void optimizeQuats();   //�Ż�����

#endif // DAG_H_INCLUDED
