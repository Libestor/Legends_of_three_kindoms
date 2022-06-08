#include"internet.h"
#include"skills_cards.h"
void AI(USER* people, USER* ai)
{
	int num = ai->shoupai->length;
	Node* p = ai->shoupai->next; //此处已经是第一张牌
	if (p->data->name == NanManRuQin)
	{
		nanmanruqin_skill(ai, people,1);
	}
	if (p->data->name == WanJianQiFa)
	{
		wanjianqifa_skill(ai, people,1);
	}
	if (p->data->name == GuoHeChaiQiao)
	{
		guohechaiqiao_skill(ai, people,1);
	}
	if (p->data->name == Tao)
	{
		if (ai->wj->PH_current < 4)
			tao_skill(ai, people, 1);
	}
	if (p->data->name == JueDou)
	{
		juedou_skill(ai, people, 1);
	}
	if (p->data->name == Sha)
	{
		kill_skill(ai, people, 1);
	}
	for (int i = 2; i <= num; i++)//出牌
	{
		p = p->next;
		if (p->data->name == NanManRuQin)
		{
			nanmanruqin_skill(ai, people, 1);
		}
		if (p->data->name == WanJianQiFa)
		{
			wanjianqifa_skill(ai, people, 1);
		}
		if (p->data->name == GuoHeChaiQiao)
		{
			guohechaiqiao_skill(ai, people, 1);
		}
		if (p->data->name == Tao)
		{
			if (ai->wj->PH_current < 4)
				tao_skill(ai, people, 1);
		}
		if (p->data->name == JueDou)
		{
			juedou_skill(ai, people, 1);
		}
		if (p->data->name == Sha)
		{
			kill_skill(ai, people, 1);
		}
		Sleep(100);
	} //现在就经获得牌了
	if (ai->shoupai->length > ai->wj->PH_current)//弃牌
	{
		Node* q = ai->shoupai->next;
		int n = ai->shoupai->length;
		int m = ai->wj->PH_current;
		int a, i;
		a = n - m;
		for (i = 0; i < a; i++)
		{
			if ((Shan != p->data->name || Tao != p->data->name) && p->next != NULL)
			{
				q = p;
				p = p->next;
			}
			if (Shan == p->data->name || Tao == p->data->name)
			{
				if (p == ai->shoupai->next)
				{
					ai->shoupai->next = p->next;
				}
				else
				{
					q->next = p->next;
				}
				free(p);
			}
		}

	}
	Sleep(100);
}