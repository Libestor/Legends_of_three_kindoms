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
	//BeginBatchDraw();
	srand(GetTickCount());
	USER *people=init_User();
	USER *ai=init_User();
	int flag = 0;
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
			if (flag != 0)
			{
				//����
				for (int  i = 0; i < 2; i++)
				{
					if (!AddList(people->shoupai,people->shoupai->length+1,search_pai()))
					{

					}
				}
				in_card();
			}
			
			//�˵Ļغ�
			state(people, ai);
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
			int enemy_card = (p->data->skill)(people, ai,num);  //�������ƺ���
			//��ӡ��˫������
			
			if (ai->wj->PH_current==0) {
				GameOver(people,ai);
			}
			state(people, ai);

		}
	END:
		//����
		for (int i = 0; i < 2; i++)
		{
			if (!AddList(ai->shoupai, ai->shoupai->length + 1, search_pai()))
			{
				//����
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
STATUS GameOver(USER* people, USER* ai)
{
	EndBatchDraw();
	if (!DestroyList(people->shoupai))
	{
		//��ӡ����
	}
	if (!DestroyList(ai->shoupai))
	{
		//��ӡ����
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

