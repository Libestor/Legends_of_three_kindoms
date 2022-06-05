#pragma once
#include <stdio.h>
#define ElemType CARDS 
//定义默认数据类型
//#include"skills_cards.h"
#define MAXSIZE  100//定义数组的默认大小
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
//typedef int Status; //定义状态
//typedef CARDS ElemType; //定义默认数据类型
//typedef struct Node// 定义链表节点
//{
//    ElemType data;
//    Node* next;
//}Node;
//typedef struct Head {
//    int length;
//    Node* next;
//}Head;
typedef int Status; //定义状态

typedef struct USER USER;
typedef struct WARLORD//武将
{
	int name;
	int PH;//生命值上限
	int PH_current;//实时生命值
	int sha_num;//出杀的数量
	int (*skills)(WARLORD* A, WARLORD* B);
}WARLOAD;
typedef struct CARDS
{
	int color;//1：红桃 2：黑桃 3：方块 4：梅花
	int points;
	int (*skill)(USER* A, USER* B);
	int name;//卡牌的名字
}CARDS;
typedef struct Node// 定义链表节点
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
Status InitList(Head* list); //初始化表
Status DeletList(Head* list, int cur);//删除数据表的元素,cur表示下标
Node* GetNum(Head list, int cur); //获得一个位置的结点, 返回这个位置的结点
Head* GetElem_Plus(Head list, ElemType e ); //可以获得所有的相同元素值
Node* GetElem(Head list,  ElemType e);//获得某个值所在的结点
Status AddList(Head* list, int cur, ElemType e);//e表示要被添加的元素
Status DestroyList(Head* list); //销毁表
//Status TextList();//测试函数
void PrintList(Head list);

