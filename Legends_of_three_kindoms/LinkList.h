#pragma once
#include <stdio.h>
#define MAXSIZE  100//���������Ĭ�ϴ�С
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status; //����״̬
typedef int ElemType; //����Ĭ����������
typedef struct Node// ��������ڵ�
{
    ElemType data;
    Node* next;
}Node;
typedef struct Heard {
    int length;
    Node* next;
}Heard;
Status InitList(Heard* list); //��ʼ����
Status DeletList(Heard* list, int cur);//ɾ�����ݱ��Ԫ��,cur��ʾ�±�
Node* GetNum(Heard list, int cur); //���һ��λ�õĽ��, �������λ�õĽ��
Heard* GetElem_Plus(Heard list, ElemType e ); //���Ի�����е���ͬԪ��ֵ
Node* GetElem(Heard list,  ElemType e);//���ĳ��ֵ���ڵĽ��
Status AddList(Heard* list, int cur, ElemType e);//e��ʾҪ����ӵ�Ԫ��
Status DestroyList(Heard* list); //���ٱ�
Status TextList();//���Ժ���
void PrintList(Heard list);

