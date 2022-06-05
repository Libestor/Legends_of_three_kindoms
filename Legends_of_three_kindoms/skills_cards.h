#pragma once
#include <malloc.h>
#include<stdlib.h>
enum all_warloads {
	ZhangFei=1,
	DianWei,
};
enum all_cards {
	Sha=1,
	Shan,
	Tao,
	juedou
};
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
CARDS* getcards(int i);//根据传入数据定向返回卡牌
CARDS* juedou();//定义决斗卡牌的点数和花色
int juedou_skill(WARLORD* A, WARLORD* B);//定义决斗的功能
CARDS* nanmanruqin();//定义南蛮入侵的点数和花色
int nanmanruqin_skill(WARLORD* A, WARLORD* B);//定义南蛮入侵的功能
CARDS* wanjianqifa();//定义万箭齐发的点数和花色
int wanjianqifa_skill(WARLORD* A, WARLORD* B);//定义万箭齐发的功能
