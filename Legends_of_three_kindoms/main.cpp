//#include"skills_cards.h"
#include"main.h"
#include<stdio.h>
#define MAX_WARLOAD 2  
#define MAX_CARD 4
#define PORT 6666

int main()
{
	
	USER *people=init_all();
	USER *ai=init_all();
	 
	//��ʼ������
	
	//�ǽ�����Ϸ�����˳���Ϸ
	start_game(people, ai);
	while (true)
	{
		// ��Ϸ��ʼ
		while (true)
		{
			for (int i = 0; i < 2; i++)
			{
				
			}
			//�˵Ļغ�
			state(people, ai);
			//���Ҽ�����
			int num = zhucaidan();;
			if (!num)
			{
				end_huihe();
				break;
			}
			attack(people, ai, Sha);
			Node* p = people->shoupai->next;
			//int attack(USER * Our, USER * enemy, int card);
			int enemy_card = (p->data->skill)(people, ai);  //�������ƺ���
			//��ӡ��˫������
			
			if (ai->wj->PH_current==0) {
				GameOver();
			}

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
