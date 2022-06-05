#pragma once
#include <malloc.h>
#include<stdlib.h>
#include"easyx.h"
//#include"LinkList.h"
typedef int Status; //����״̬
typedef CARDS ElemType; //����Ĭ����������
typedef struct Node// ��������ڵ�
{
	ElemType data;
	Node* next;
}Node;
typedef struct Head {
	int length;
	Node* next;
}Head;
enum all_warloads {
	ZhangFei=1,
	DianWei,
};
enum all_cards {
	Sha=1,
	Shan,
	Tao,
	JueDou,
	WanJianQiFa,
	NanManRuQin,
	WuXieKeJi,
};
typedef struct USER {
	WARLORD* wj;
	Head* shoupai;
};
typedef struct WARLORD//�佫
{
	int name;
	int PH;//����ֵ����
	int PH_current;//ʵʱ����ֵ
	int sha_num;//��ɱ������
	int (* skills)(WARLORD* A, WARLORD* B);
};
enum clolr {
	rad_peach=1, //����
	black_peach, // ����
	square, //����
	plum //÷��
};
typedef struct CARDS
{
	int color;//1������ 2������ 3������ 4��÷��
	int points;
	int (* skill)(USER* A, USER* B);
	int name;//���Ƶ�����
};
WARLORD* zhangfei();//�ŷɵĳ�ʼ��
WARLORD* dianwei();//��Τ�ĳ�ʼ��
int dianwei_skill(WARLORD* A, WARLORD* B);
CARDS* kill();//���廨ɫ�������
int kill_skill(USER* A, USER* B);//ɱ�Ĺ���
CARDS* shan();//�������Ļ�ɫ�͵���
int shan_skill(USER* A, USER* B);//���Ĺ���
CARDS* tao();//�����ҵĻ�ɫ�͵���
int tao_skill(USER* A);//�ҵĹ���
WARLORD* search_wujiang();//�����ȡ�佫
CARDS* search_pai();//�����ȡ����
WARLORD* mustzhangfei();//�����ȡ�ŷ�
WARLORD* mustdianwei();//�����ȡ��Τ
CARDS* getcards(int i);//���ݴ������ݶ��򷵻ؿ���
CARDS* juedou();//����������Ƶĵ����ͻ�ɫ
int juedou_skill(USER* A, USER* B);//��������Ĺ���
CARDS* nanmanruqin();//�����������ֵĵ����ͻ�ɫ
int nanmanruqin_skill(USER* A, USER* B);//�����������ֵĹ���
CARDS* wanjianqifa();//��������뷢�ĵ����ͻ�ɫ
int wanjianqifa_skill(USER* A, USER* B);//��������뷢�Ĺ���
int delatenodelocate(Head* head, int n);//ָ��λ��ɾ���ڵ�