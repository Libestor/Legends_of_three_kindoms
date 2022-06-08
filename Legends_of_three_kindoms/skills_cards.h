#pragma once
//#include <malloc.h>
#include<stdlib.h>
#include<time.h>
#define ElemType CARDS* 
//#include"easyx.h"
//#include"LinkList.h"
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
	int (*skill)(USER* A, USER* B, int cur);
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
enum all_warloads {
	ZhangFei = 1,
	DianWei,
};
enum clolr {
	rad_peach = 1, //红桃
	black_peach, // 黑桃
	square, //方块
	plum //梅花
};
enum all_cards {
	Sha = 1,
	Shan,
	Tao,
	JueDou,
	WanJianQiFa,
	NanManRuQin,
	WuXieKeJi,
	GuoHeChaiQiao,
};
WARLORD* zhangfei();//张飞的初始化
WARLORD* dianwei();//典韦的初始化
int dianwei_skill(WARLORD* A, WARLORD* B);
CARDS* kill();//定义花色定义点数
int kill_skill(USER* A, USER* B,int cur);//杀的功能
CARDS* shan();//定义闪的花色和点数
int shan_skill(USER* A, USER* B,int cur);//闪的功能
CARDS* tao();//定义桃的花色和点数
int tao_skill(USER* A,USER* B, int cur);//桃的功能
WARLORD* search_wujiang();//随机抽取武将
CARDS* search_pai();//随机抽取手牌
WARLORD* mustzhangfei();//定向抽取张飞
WARLORD* mustdianwei();//定向抽取典韦
CARDS* getcards(int i);//根据传入数据定向返回卡牌
CARDS* juedou();//定义决斗卡牌的点数和花色
int juedou_skill(USER* A, USER* B, int cur);//定义决斗的功能
CARDS* nanmanruqin();//定义南蛮入侵的点数和花色
int nanmanruqin_skill(USER* A, USER* B, int cur);//定义南蛮入侵的功能
CARDS* wanjianqifa();//定义万箭齐发的点数和花色
int wanjianqifa_skill(USER* A, USER* B, int cur);//定义万箭齐发的功能
int delatenodelocate(Head* head, int n);//指定位置删除节点
//int (*shanchu)(USER* Our, USER* enemy, int card);
CARDS* guohechaiqiao();//定义过河拆桥的花色和点数
int guohechaiqiao_skill(USER* A, USER* B, int cur);//定义过河拆桥的功能
CARDS* wuxiekeji();//定义无懈可击的花色和点数