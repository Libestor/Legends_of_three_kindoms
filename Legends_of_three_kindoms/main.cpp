//#include"skills_cards.h"
#include"main.h"
#include<stdio.h>
#include<stdlib.h>
#include"skills_cards.h"
#include"LinkList.h"
#define MAX_WARLOAD 2  
#define MAX_CARD 4
#define PORT 6666
#define TIME 1000

int main()
{
	//
	srand(GetTickCount());
	//
	USER *people=init_User();
	USER *ai=init_User();
	int con = 0;
	int game;
	//初始化人物
	
	//是进入游戏还是退出游戏
	if (!start_game(people, ai))
	{
		exit(0);
	}
	//BeginBatchDraw();
	while (true)
	{
		if (con) //摸牌阶段
		{
			in_card();
			//抽牌
			for (int i = 0; i < 2; i++)
			{
				if (!AddList(people->shoupai, people->shoupai->length + 1, search_pai()))
				{
					wrong();
					exit(0);
				}
			}
			state(people, ai);
			out_card();
			if (people->wj->name != ZhangFei)
			{
					people->wj->sha_num = 1;
			}
			
		}
		// 游戏开始
		while (true)
		{
			
			
			//人的回合
			state(people, ai);
			//给我几号牌
			BEGIN:
			int num = get_card(people,ai); // 并不确定该牌是否存在，需要判断。
			//printf("%d", num);
			if (num == -1 )
			{
				if (people->wj->PH_current<people->shoupai->length)
				{
					losscard(people,ai);
				}
				end_huihe(people,ai);
				goto END;
			}
			else if (num > people->shoupai->length)
			{
				goto BEGIN;
			}
			Node* q = (Node*)malloc(sizeof(Node));
			q = people->shoupai->next;
			
			for (int i = 1; i < num; i++)
			{
				q = q->next;
			}
			if (q->data->name == Shan || q->data->name == WuXieKeJi)
			{
				wrong_card();
				goto BEGIN;
				//printf("\nshan");
			}
			//attack(people, ai, num);
			
			//int attack(USER * Our, USER * enemy, int card);
			if (people->wj->sha_num < 1 && num == Sha)
			{
				wrong_card();
				goto BEGIN;
			}
			if (q->data->name == Sha)
			{
				
				people->wj->sha_num--;
			}
			if (q->data->name == GuoHeChaiQiao && ai->shoupai->length <=0)
			{
				wrong_card();
				goto BEGIN;
			}
			if (q->data->name == Tao && people->wj->PH_current >= people->wj->PH)
			{
				wrong_card();
				goto BEGIN;
			}
			int enemy_card = (q->data->skill)(people, ai,num);  //调用手牌函数
			//打印牌双方的牌
			
			if (ai->wj->PH_current==0) {
				GameOver(people,ai,2);
			}
			else if (people->wj->PH_current ==0)
			{
				GameOver(people, ai, 1);
			}
			
			state(people, ai);

		}
	END:
		
		//抽牌
		if (con )
		{
			//抽牌
			for (int i = 0; i < 2; i++)
			{
				if (!AddList(ai->shoupai, ai->shoupai->length + 1, search_pai()))
				{
					wrong();
					exit(0);
				}
			}
			state(people, ai);
			if (ai->wj->name != ZhangFei)
			{
				ai->wj->sha_num = 1;
			}
			//in_card();
		}
		
		con += 1;
		switch (AI(people, ai))
		{
		case 1: GameOver(people, ai, 1);
			break;

		case 2:GameOver(people, ai, 2);
			break;

		default:
			break;
		}
		;
		end_huihe(people,ai);
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
		wrong();
		exit(0);
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
			wrong();
			exit(0);
			
			//打印错误
		}

	}
	return user;
}
STATUS GameOver(USER* people, USER* ai,int flag)
{
	//EndBatchDraw();
	if (!DestroyList(people->shoupai))
	{
		wrong();
		exit(0);
		//打印错误
	}
	if (!DestroyList(ai->shoupai))
	{
		wrong();
		exit(0);
		//打印错误
	}
	if (flag == 1)
	{
		game_over_people();
	}
	else if (flag == 2)
	{
		game_over_ai();
	}
	
	Sleep(1000);
	exit(0);
	return 1;
}
void losscard(USER* people,USER* ai) {
	int num = people->shoupai->length - people->wj->PH_current;
	int lost;
	for (int  i = 1; i <= num; i++)
	{
		void abandon_card();

		lost = get_card(people,ai);
		attack(people, ai, lost);
		DeletList(people->shoupai, search(people->shoupai,lost));

	}
}

