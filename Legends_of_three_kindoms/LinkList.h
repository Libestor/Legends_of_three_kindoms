#pragma once
#include <stdio.h>
#include"skills_cards.h"
#define MAXSIZE  100//定义数组的默认大小
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status; //定义状态
typedef CARDS ElemType; //定义默认数据类型
typedef struct Node// 定义链表节点
{
    ElemType data;
    Node* next;
}Node;
typedef struct Head {
    int length;
    Node* next;
}Head;
Status InitList(Head* list); //初始化表
Status DeletList(Head* list, int cur);//删除数据表的元素,cur表示下标
Node* GetNum(Head list, int cur); //获得一个位置的结点, 返回这个位置的结点
Head* GetElem_Plus(Head list, ElemType e ); //可以获得所有的相同元素值
Node* GetElem(Head list,  ElemType e);//获得某个值所在的结点
Status AddList(Head* list, int cur, ElemType e);//e表示要被添加的元素
Status DestroyList(Head* list); //销毁表
//Status TextList();//测试函数
void PrintList(Head list);

