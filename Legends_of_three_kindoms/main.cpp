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
	//��ʼ������
	init_all(ai);
	//�ǽ�����Ϸ�����˳���Ϸ


	// ��Ϸ��ʼ
	while (true)
	{
		state(people, ai);
		//���Ҽ�����



	}
	return 0;
}
STATUS init_all(USER* user)
{
	user = (USER*)malloc(sizeof(USER));
	user->wj = search_wujiang();
	//��ʼ�����ƺ���
	if (!InitList(user->shoupai))
	{
		//��ӡ����
	}
	//��ȡ����
	for (int i = 1; i <= 4; i++)
	{
		if (!AddList(user->shoupai,i, *(search_pai())))
		{
			//��ӡ����
		}

	}




	return 0;
}