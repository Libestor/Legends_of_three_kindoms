#pragma once
#include <stdio.h>
#define ElemType CARDS 
//����Ĭ����������
//#include"skills_cards.h"
#define MAXSIZE  100//���������Ĭ�ϴ�С
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
//typedef int Status; //����״̬
//typedef CARDS ElemType; //����Ĭ����������
//typedef struct Node// ��������ڵ�
//{
//    ElemType data;
//    Node* next;
//}Node;
//typedef struct Head {
//    int length;
//    Node* next;
//}Head;
typedef int Status; //����״̬

typedef struct USER USER;
typedef struct WARLORD//�佫
{
	int name;
	int PH;//����ֵ����
	int PH_current;//ʵʱ����ֵ
	int sha_num;//��ɱ������
	int (*skills)(WARLORD* A, WARLORD* B);
}WARLOAD;
typedef struct CARDS
{
	int color;//1������ 2������ 3������ 4��÷��
	int points;
	int (*skill)(USER* A, USER* B);
	int name;//���Ƶ�����
}CARDS;
typedef struct Node// ��������ڵ�
{
	ElemType data;
	Node* next;
}Node;
typedef struct Head {
	int length;
	Node* next;
}Head;
typedef struct USER {
	WARLORD* wj;
	Head* shoupai;
}USER;
Status InitList(Head* list); //��ʼ����
Status DeletList(Head* list, int cur);//ɾ�����ݱ��Ԫ��,cur��ʾ�±�
Node* GetNum(Head list, int cur); //���һ��λ�õĽ��, �������λ�õĽ��
Head* GetElem_Plus(Head list, ElemType e ); //���Ի�����е���ͬԪ��ֵ
Node* GetElem(Head list,  ElemType e);//���ĳ��ֵ���ڵĽ��
Status AddList(Head* list, int cur, ElemType e);//e��ʾҪ����ӵ�Ԫ��
Status DestroyList(Head* list); //���ٱ�
//Status TextList();//���Ժ���
void PrintList(Head list);

