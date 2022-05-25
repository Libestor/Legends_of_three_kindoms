#pragma once
#include <stdio.h>
#define MAXSIZE  100//定义数组的默认大小
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status; //定义状态
typedef int ElemType; //定义默认数据类型
typedef struct Node// 定义链表节点
{
    ElemType data;
    Node* next;
}Node;
typedef struct Heard {
    int length;
    Node* next;
}Heard;
Status InitList(Heard* list); //初始化表
Status DeletList(Heard* list, int cur);//删除数据表的元素,cur表示下标
Node* GetNum(Heard list, int cur); //获得一个位置的结点, 返回这个位置的结点
Heard* GetElem_Plus(Heard list, ElemType e ); //可以获得所有的相同元素值
Node* GetElem(Heard list,  ElemType e);//获得某个值所在的结点
Status AddList(Heard* list, int cur, ElemType e);//e表示要被添加的元素
Status DestroyList(Heard* list); //销毁表
Status TextList();//测试函数
void PrintList(Heard list);

