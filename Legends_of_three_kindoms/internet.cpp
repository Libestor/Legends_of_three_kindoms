#define TIME 750
#include"internet.h"
#include"skills_cards.h"
#include"LinkList.h"
#include"easyx.h"
;
; int AI_kill_skill(USER* A, USER* B)
{
	int cur;
	cur = search(B->shoupai, Sha);
	DeletList(B->shoupai, cur);
	attacked(A, B, Sha);
	int a;
	printf("进入到杀的寻找");
	a = search(A->shoupai, Shan);
	if (a == 0)
	{
		A->wj->PH_current--;
		killed();
	}
	else
	{
		DeletList(A->shoupai, a);
		attack(A, B, Shan);
	}
	return 0;
}
int AI_tao_skill(USER* A, USER* B)//人机杀的功能
{
	int cur;
	cur = search(B->shoupai, Tao);
	DeletList(B->shoupai, cur);
	B->wj->PH_current++;
	attacked(A, B, Tao);
	return 0;
}
int AI_juedou_skill(USER* A, USER* B)//人机决斗的功能
{
	int cur;
	int x;
	cur = search(B->shoupai, JueDou);
	DeletList(B->shoupai, cur);
	attacked(A, B, JueDou);
	x = search(A->shoupai, WuXieKeJi);
	if (x)
	{
		DeletList(A->shoupai, x);
		attack(A, B, WuXieKeJi);
		return 0;
	}
	for (;;)
	{
		int a;
		int b;
		a = search(A->shoupai, Sha);
		if (a == 0)
		{
			A->wj->PH_current--;
			killed();
			return 0;
		}
		DeletList(A->shoupai, a);
		attack(A, B, Sha);
		b = search(B->shoupai, Sha);
		if (b == 0)
		{
			B->wj->PH_current--;
			return 0;
		}
		DeletList(B->shoupai, b);
		attacked(A, B, Sha);
	}
}
int AI_nanmanruqin_skill(USER* A, USER* B)//人机南蛮入侵的功能
{
	int a;
	int x;
	int cur;
	cur = search(B->shoupai, NanManRuQin);
	DeletList(B->shoupai, cur);
	attacked(A, B, NanManRuQin);
	x = search(A->shoupai, WuXieKeJi);
	int len= A->shoupai->length;
	if (x)
	{
		if (!DeletList(B->shoupai, x))
		{
			printf("AI南蛮入侵无懈可击失败,x为%d,len为%d\n",x,len);
		}
		attack(A, B, WuXieKeJi);
		return 0;
	}
	a = search(A->shoupai, Sha);
	if (a == 0)
	{
		A->wj->PH_current--;
		killed();
		return 0;
	}
	else if (a)
	{
		DeletList(A->shoupai, a);
		attack(A, B, Sha);
	}
	return 0;
}
int AI_wanjianqifa_skill(USER* A, USER* B)//人机万箭齐发的功能
{
	int b;
	int x;
	int cur;
	cur = search(B->shoupai, WanJianQiFa);
	DeletList(B->shoupai, cur);
	attacked(A, B, WanJianQiFa);
	x = search(A->shoupai, WuXieKeJi);
	if (x)
	{
		if (!DeletList(A->shoupai, x))
		{
			printf("人机万箭齐发无懈可击失败，x为%x", x);
		}
		attack(A, B, WuXieKeJi);
		return 0;
	}
	b = search(A->shoupai, Shan);
	if (b == 0)
	{
		A->wj->PH_current--;
		killed();
		return 0;
	}
	else if (b)
	{
		if (!DeletList(A->shoupai, b))
		{
			printf("人机万箭齐发无懈可击失败，b为%x", b);
		}
		attack(A, B, Shan);
	}
	return 0;
}
int AI_guohechaiqiao_skill(USER* A, USER* B)//人机过河拆桥的功能
{
	int x;
	int temp;
	int cur;
	cur = search(B->shoupai, GuoHeChaiQiao);
	DeletList(B->shoupai, cur);
	attacked(A, B, GuoHeChaiQiao);
	x = search(A->shoupai, WuXieKeJi);
	if (x)
	{
		if(!DeletList(A->shoupai, x))
		{
			printf("人机过河拆桥无懈可击失败，x为%x", x);
		}
		attack(A, B, WuXieKeJi);
		return 0;
	}
	temp = A->shoupai->next->data->name;
	DeletList(A->shoupai, search(A->shoupai, temp));
	attack(A, B, temp);
	return 0;
}
int AI(USER* people, USER* ai)
{
	int num = ai->shoupai->length;
BEG:
	if (ai->shoupai->length >= 1)
	{
		Node* p = ai->shoupai->next; //此处已经是第一张牌
		if (p->data->name == NanManRuQin)//人机出南蛮入侵
		{
			AI_nanmanruqin_skill(people, ai);
			if (people->wj->PH_current == 0)
			{
				return 1;
			}
			else if (ai->wj->PH_current == 0)
			{
				return 2;
			}
			goto BEG;
		}
		if (p->data->name == WanJianQiFa)//人机出万箭齐发
		{
			AI_wanjianqifa_skill(people, ai);
			if (people->wj->PH_current == 0)
			{
				return 1;
			}
			else if (ai->wj->PH_current == 0)
			{
				return 2;
			}
			goto BEG;
		}
		if (p->data->name == GuoHeChaiQiao && people->shoupai->length>0)//人机出过河拆桥
		{
			AI_guohechaiqiao_skill(people, ai);
			if (people->wj->PH_current == 0)
			{
				return 1;
			}
			else if (ai->wj->PH_current == 0)
			{
				return 2;
			}
			goto BEG;
		}
		if (p->data->name == Tao && ai->wj->PH_current < 4)//人机出桃
		{
			AI_tao_skill(people, ai);
			if (people->wj->PH_current == 0)
			{
				return 1;
			}
			else if (ai->wj->PH_current == 0)
			{
				return 2;
			}
			goto BEG;
		}
		if (p->data->name == JueDou)//人机出决斗
		{
			AI_juedou_skill(people, ai);
			if (people->wj->PH_current == 0)
			{
				return 1;
			}
			else if (ai->wj->PH_current == 0)
			{
				return 2;
			}

			goto BEG;
		}
		if (p->data->name == Sha && ai->wj->sha_num > 0)//人机出杀
		{
			AI_kill_skill(people, ai);
			if (people->wj->PH_current == 0)
			{
				return 1;
			}
			else if (ai->wj->PH_current == 0)
			{
				return 2;
			}
			ai->wj->sha_num--;
			goto BEG;
		}for (int i = 2; i <= ai->shoupai->length; i++)
		{

			p = p->next;
			if (p->data->name == NanManRuQin)//人机出南蛮入侵
			{
				AI_nanmanruqin_skill(people, ai);
				if (people->wj->PH_current == 0)
				{
					return 1;
				}
				else if (ai->wj->PH_current == 0)
				{
					return 2;
				}
				goto BEG;
			}
			if (p->data->name == WanJianQiFa)//人机出万箭齐发
			{
				AI_wanjianqifa_skill(people, ai);
				if (people->wj->PH_current == 0)
				{
					return 1;
				}
				else if (ai->wj->PH_current == 0)
				{
					return 2;
				}
				goto BEG;
			}
			if (p->data->name == GuoHeChaiQiao&&people->shoupai->length>0)//人机出过河拆桥
			{
				AI_guohechaiqiao_skill(people, ai);
				if (people->wj->PH_current == 0)
				{
					return 1;
				}
				else if (ai->wj->PH_current == 0)
				{
					return 2;
				}
				goto BEG;
			}
			if (p->data->name == Tao && ai->wj->PH_current < 4)//人机出桃
			{
				AI_tao_skill(people, ai);
				if (people->wj->PH_current == 0)
				{
					return 1;
				}
				else if (ai->wj->PH_current == 0)
				{
					return 2;
				}
				goto BEG;
			}
			if (p->data->name == JueDou)//人机出决斗
			{
				AI_juedou_skill(people, ai);
				if (people->wj->PH_current == 0)
				{
					return 1;
				}
				else if (ai->wj->PH_current == 0)
				{
					return 2;
				}
				goto BEG;
			}
			if (p->data->name == Sha && ai->wj->sha_num > 0)//人机出杀
			{
				if (ai->wj->sha_num > 0)
				{
					AI_kill_skill(people, ai);
					if (people->wj->PH_current == 0) {
						return 1;
					}
					else if (ai->wj->PH_current == 0)
					{
						return 2;
					}
					ai->wj->sha_num--;
					goto BEG;
				}
			}

		}


	}
	Sleep(TIME);
	//} //现在就经获得牌了
	if (ai->shoupai->length > ai->wj->PH_current)//弃牌
	{
		Node* q = ai->shoupai->next;
		while (ai->shoupai->length - ai->wj->PH_current > 0)
		{
			DeletList(ai->shoupai, 1);
		}
		Sleep(TIME);
	}
	return 666;
}