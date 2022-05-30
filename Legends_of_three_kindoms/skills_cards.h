#pragma once
#include <malloc.h>
#include<stdlib.h>
#include"main.h"
typedef struct WARLORD//武将
{
	int name;
	int PH;//生命值上限
	int PH_current;//实时生命值
	int sha_num;//出杀的数量
	int (* skills)(WARLORD* A, WARLORD* B);
};
enum clolr {
	rad_peach=1, //红桃
	black_peach, // 黑桃
	square, //方块
	plum //梅花
};
typedef struct CARDS
{
	int color;//1：红桃 2：黑桃 3：方块 4：梅花
	int points;
	int (* skill)(WARLORD* A, WARLORD* B);
};
WARLORD* zhangfei();//张飞的初始化
WARLORD* dianwei();//典韦的初始化
int dianwei_skill(WARLORD* A, WARLORD* B);
CARDS* kill();//定义花色定义点数
int kill_skill(WARLORD* A, WARLORD* B);//杀的功能
CARDS* shan();//定义闪的花色和点数
int shan_skill(WARLORD* A, WARLORD* B);//闪的功能
CARDS* tao();//定义桃的花色和点数
int tao_skill(WARLORD* A, WARLORD* B);//桃的功能
WARLORD* search_wujiang();//随机抽取武将
CARDS* search_pai();//随机抽取手牌
WARLORD* mustzhangfei();//定向抽取张飞
WARLORD* mustdianwei();//定向抽取典韦
CARDS* mustkill();//定向抽取杀
CARDS* mustshan();//定向抽取闪
CARDS* musttao();//定向抽取桃