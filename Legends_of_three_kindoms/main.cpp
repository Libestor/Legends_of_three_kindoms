#include"internet.h"
#include"easyx.h"
#include"skills_cards.h"
#include"main.h"
#define MAX_WARLOAD 2  
#define MAX_CARD 4
#define PORT 6666
int main()
{
	
	USER *people,*ai;
	init_all(people); 
	//初始化人物
	init_all(ai);
	//是进入游戏还是退出游戏

	while (true)
	{
		// 游戏开始
		while (true)
		{

			//人的回合
			state(people, ai);
			//给我几号牌
			int num = printf("a");
			if (!num)
			{
				break;
			}
			Node* p = people->shoupai->next;
			//int attack(USER * Our, USER * enemy, int card);
			int enemy_card = p->data->skill(people, ai);  //调用手牌函数
			int attack(USER * Our, USER * enemy, int card);
			//打印牌双方的牌
			if (ai->wj->PH_current==0) {
				GameOver();
			}

		}

		AI(people,ai);
	}
	
	return 0;
}
STATUS init_all(USER* user)
{
	user = (USER*)malloc(sizeof(USER));
	user->wj = search_wujiang();
	//初始化手牌函数
	if (!InitList(user->shoupai))
	{
		//打印错误
	}
	//抽取手牌
	for (int i = 1; i <= 4; i++)
	{
		if (!AddList(user->shoupai,i, *(search_pai())))
		{
			//打印错误
		}

	}
	return 0;
}
