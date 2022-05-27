#include"skills_cards.h"
WARLORD *zhangfei()//张飞的初始化
{
	WARLORD* zhangfei;
	zhangfei = (WARLORD*)malloc(sizeof(WARLORD));
	zhangfei->PH = 4;
	zhangfei->PH_current = 4;
	zhangfei->sha_num = 999;
	return zhangfei;
}
WARLORD* dianwei()//典韦的初始化
{
	WARLORD* dianwei;
	dianwei = (WARLORD*)malloc(sizeof(WARLORD));
	dianwei->PH = 4;
	dianwei->PH_current = 4;
	dianwei->sha_num = 1;
	dianwei->skills = dianwei_skill;
}
int dianwei_skill(WARLORD* A, WARLORD* B)//典韦技能的初始化
{
	A->PH_current--;
	B->PH_current--;
	return 0;
}
CARDS* kill()//定义杀的花色和点数
{
	CARDS* kill;
	kill = (CARDS*)malloc(sizeof(CARDS));
	kill->color = rand() % 4;
	kill->points = rand() % 13;//A 2 3 4 5 6 7 8 9 10 J Q K
	kill->skill = kill_skill;
	return kill;
}
int kill_skill(WARLORD* A, WARLORD* B)//杀的功能
{
	B->PH_current--;
	B->sha_num--;
	return 0;
}
CARDS* shan()//定义闪的花色和点数
{
	CARDS* shan;
	shan = (CARDS*)malloc(sizeof(CARDS));
	shan->color = rand() % 4;
	shan->points = rand() % 13;
	shan->skill = shan_skill;
	return shan;
}
int shan_skill(WARLORD* A, WARLORD* B)//闪的功能
{
	;
}
CARDS* tao()//定义桃的花色和点数
{
	CARDS* tao;
	tao = (CARDS*)malloc(sizeof(CARDS));
	tao->color = rand() % 4;
	tao->points = rand() % 13;
	tao->skill = tao_skill;
}
int tao_skill(WARLORD* A, WARLORD* B)//桃的功能
{
	if (A->PH_current < A->PH)
	{
		A->PH_current++;
	}
	return 0;
}
WARLORD* search_wujiang()
{
	int n;
	n = rand() % 2;//1：张飞 2：典韦
	if (n == 1)
	{
		return zhangfei();
	}
	else if (n == 2)
	{
		return dianwei();
	}
}
CARDS* search_pai()
{
	int n;
	n = rand() % 3;//1：杀 2：闪 3：桃
	if (n == 1)
	{
		return kill();
	}
	else if (n == 2)
	{
		return shan();
	}
	else if (n == 3)
	{
		return tao();
	}
}