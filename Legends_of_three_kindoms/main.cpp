//#include"skills_cards.h"
#include"main.h"
#include<stdio.h>
#include<stdlib.h>
#define MAX_WARLOAD 2  
#define MAX_CARD 4
#define PORT 6666
// statrt = 绘制当前状态
//int get_card();
// attack 
// attacked
// conpetion 
// 回合结束 ， 回合开始， 抽牌阶段， 弃牌阶段， 报错函数 
// 每次绘制前都调用cleardevice(); 函数一次

int main()
{
	//BeginBatchDraw();
	srand(GetTickCount());
	USER *people=init_User();
	USER *ai=init_User();
	int flag = 0;
	//初始化人物
	
	//是进入游戏还是退出游戏
	if (!start_game(people, ai))
	{
		exit(0);
	}
	while (true)
	{
		// 游戏开始
		while (true)
		{
			if (flag != 0)
			{
				//抽牌
				for (int  i = 0; i < 2; i++)
				{
					if (!AddList(people->shoupai,people->shoupai->length+1,search_pai()))
					{

					}
				}
				in_card();
			}
			
			//人的回合
			state(people, ai);
			//给我几号牌
			BEGIN:
			int num = get_card(people,ai); // 并不确定该牌是否存在，需要判断。
			printf("%d", num);
			if (num == -1 )
			{
				if (people->wj->PH_current<people->shoupai->length)
				{
					losscard(people,ai);
				}
				end_huihe();
				goto END;
			}
			if (num == Shan || num == WuXieKeJi)
			{
				goto BEGIN;
			}
			//attack(people, ai, num);
			Node* p = people->shoupai->next;
			for (int i = 1; i < num; i++)
			{
				p->next;
			}
			//int attack(USER * Our, USER * enemy, int card);
			int enemy_card = (p->data->skill)(people, ai,num);  //调用手牌函数
			//打印牌双方的牌
			
			if (ai->wj->PH_current==0) {
				GameOver(people,ai);
			}
			state(people, ai);

		}
	END:
		//抽牌
		for (int i = 0; i < 2; i++)
		{
			if (!AddList(ai->shoupai, ai->shoupai->length + 1, search_pai()))
			{
				//错误
			}
		}
		
		flag += 1;
		AI(people,ai);
		end_huihe();
	}
	
	return 0;
}
USER* init_User()
{
	USER* user;
	user = (USER*)malloc(sizeof(USER));
	WARLOAD* war= search_wujiang();
	user->wj = war;
	if (user->wj == NULL)
	{
		exit(0);
	}
	user->shoupai = (Head*)malloc(sizeof(Head));
	//初始化手牌函数
	if (!InitList(user->shoupai))
	{
		//打印错误
	}
	//抽取手牌
	for (int i = 1; i <= 4; i++)
	{
		Head* a = user->shoupai;
		CARDS* pai =   search_pai();
		if (pai ==NULL)
		{
			exit(0);
		}
		if (!AddList(a,i,pai))
		{
			exit(0);
			//打印错误
		}

	}
	return user;
}
STATUS GameOver(USER* people, USER* ai)
{
	EndBatchDraw();
	if (!DestroyList(people->shoupai))
	{
		//打印错误
	}
	if (!DestroyList(ai->shoupai))
	{
		//打印错误
	}
	game_over();
	return 1;
}
void losscard(USER* people,USER* ai) {
	int num = people->shoupai->length - people->wj->PH_current;
	int lost;
	for (int  i = 1; i <= num; i++)
	{
		lost = get_card(people,ai);
		attack(people, ai, lost);
	}
}

