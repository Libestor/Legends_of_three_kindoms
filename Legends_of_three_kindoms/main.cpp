//#include"skills_cards.h"
#include"main.h"
#include<stdio.h>
#include<stdlib.h>
#define MAX_WARLOAD 2  
#define MAX_CARD 4
#define PORT 6666
// statrt = ���Ƶ�ǰ״̬
//int get_card();
// attack 
// attacked
// conpetion 
// �غϽ��� �� �غϿ�ʼ�� ���ƽ׶Σ� ���ƽ׶Σ� ������ 
// ÿ�λ���ǰ������cleardevice(); ����һ��

int main()
{
	srand(GetTickCount());
	USER *people=init_all();
	USER *ai=init_all();
	 
	//��ʼ������
	
	//�ǽ�����Ϸ�����˳���Ϸ
	if (!start_game(people, ai))
	{
		exit(0);
	}
	while (true)
	{
		// ��Ϸ��ʼ
		while (true)
		{
			
			//�˵Ļغ�
			//state(people, ai);
			//���Ҽ�����
			BEGIN:
			int num = get_card(people,ai); // ����ȷ�������Ƿ���ڣ���Ҫ�жϡ�
			printf("%d", num);
			if (num == -1 )
			{
				if (people->wj->PH_current<people->shoupai->length)
				{
					losscard(people,ai);
				}
				end_huihe();
				break;
			}
			if (num == Sha || num == WuXieKeJi)
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
			int enemy_card = (p->data->skill)(people, ai);  //�������ƺ���
			//��ӡ��˫������
			
			if (ai->wj->PH_current==0) {
				GameOver();
			}
			state(people, ai);

		}
		AI(people,ai);
		end_huihe();
	}
	
	return 0;
}
USER* init_all()
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
	//��ʼ�����ƺ���
	if (!InitList(user->shoupai))
	{
		//��ӡ����
	}
	//��ȡ����
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
			//��ӡ����
		}

	}
	return user;
}
STATUS GameOver()
{
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

