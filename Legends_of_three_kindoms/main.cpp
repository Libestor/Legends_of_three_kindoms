#include"skills_cards.h"
#include"main.h"
#include<stdio.h>
#define MAX_WARLOAD 2  
#define MAX_CARD 4
#define PORT 6666

int main()
{
	
	USER *people=NULL,*ai=NULL;
	init_all(people); 
	//��ʼ������
	init_all(ai);
	//�ǽ�����Ϸ�����˳���Ϸ

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
STATUS init_all(USER* user)
{
	user = (USER*)malloc(sizeof(USER));
	user->wj = NULL;
	user->wj = search_wujiang();
	//��ʼ�����ƺ���
	if (!InitList(user->shoupai))
	{
		//��ӡ����
	}
	//��ȡ����
	for (int i = 1; i <= 4; i++)
	{
		if (!AddList(user->shoupai,i,(search_pai())))
		{
			//��ӡ����
		}

	}
	return 0;
}
STATUS GameOver()
{
	game_over();
	return 1;
}
