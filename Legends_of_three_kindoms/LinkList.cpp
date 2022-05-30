#include"LinkList.h"
#include<stdlib.h>
//int main()
//{
//	TextList();
//	return 0;
//}
Status InitList(Head* list) //初始化链表头节点，节点的存储位置叫做头指针，
							//我们传入一个头指针，然后初始化指针信息，默认头指针内容时链表长度
							//我们把尾指针加入，然后就初始化成功
{
	list->length = 0;//头节点位置是1号位置
	//创建一个节点p,它是一个结点指针，指向下一个节点，该结点的指针域为NULL
	Node* p;
	p = (Node*)malloc(sizeof(Node));
	if (p == NULL) return ERROR;
	list->next = p;
	p->data = NULL;
	p->next = NULL;
	return OK;
}
Node* GetElem(Head list, ElemType e)//查找某个元素所在的指针, 此算法有问题，如果又两个值一样的话就只能查找一次
{
	if (list.length == 0) return ERROR; //链表要存在, 感觉可有可无
	Node* p;
	p = list.next;//取出头指针
	while (p->next)
	{
		if (p->data == e)
		{
			//node = p;
			return p;
		}
		p = p->next;
	}
	return ERROR;
}
Head* GetElem_Plus(Head list, ElemType e) {
	//只能在数字类型下使用
	Head *pass;
	pass = (Head*)malloc(sizeof(Head));
	InitList(pass);//初始化所需要的链表
	Node* p;
	p = list.next;
	int stat = ERROR;
	int i = 1;
	while (p->next)
	{
		if (p->data == e)
		{
			stat = OK;
			AddList(pass, pass->length + 1, i);
		}
		p = p->next;
		i++;
	}
	if (stat)
	{
		return pass;
	}
	else
	{
		return NULL;
	}
	
}
Node* GetNum(Head list, int cur)// 查找某个位置上的结点
{
	if (list.length = 0 || list.length < cur || cur == 0) //如果是空表或者查找有误就报错
	{
		return NULL;
	}
	Node* p = NULL;
	p = list.next;//第一次，指向头结点
	for(int i = 1; i < cur;i++)//从第二次,第一个结点,如果i=1，那么说明需要第一个结点，第一个结点已经获得了，所以不能进入循环
	{
		p = p->next;
	}
	//*node = p;
	return  p;
}
Status AddList(Head* list, int cur, ElemType e)// 在某个位置上加入结点（数据）
{
	//创建一个结点，然后放入数据，最后让它连接到合适的位置
	if (list->length + 1 < cur || cur < 0) //确保插入的位置是有效的
	{
		return ERROR;
	}
	//寻找要插入的前一个位置p
	if (cur - 1 == 0) //如果前一个位置是头,说明是往头插入数据
	{
		//创建新的结点
		Node* n;//创建一个用于存储新节点的指针
		n = (Node*)malloc(sizeof(Node));//给这个结点以空间,使其真实存在
		n->data = e;
		n->next = list->next; //新节点指向原来的结点，
		list->next = n; //上一个结点指向这个新节点
		list->length++; // 长度加1
		return OK;
	}
	Node x{
		5,
	};
	Node* p ;
//	*p = &x;
	p = GetNum(*list, cur - 1);
	if (p ==NULL)// 寻找失败就返回失败
	{
		return ERROR;
	}
	//寻找前一个位置q
	
	//创建新的结点
	Node* n;//创建一个用于存储新节点的指针
	n = (Node*)malloc(sizeof(Node));//给这个结点以空间,使其真实存在
	n->data = e;
	n->next = p->next; //新节点指向原来的结点，
	p->next = n; //上一个结点指向这个新节点
	list->length++; // 长度加1
	return OK;

}

Status DeletList(Head* list, int cur) //删除某个结点
{
	if (cur < 0 || list->length < cur || list->length <0) //排除错误
	{
		return ERROR;
	}
	// 寻找要删除点的前一个点
	if (cur - 1 == 0) //如果前一个位置是头,说明是删除头结点
	{
		Node *p = list->next; //  取出头节点 
		list->next = p->next; //头指针指向新的结点
		free(p); //释放这个结点
		list->length--; // 长度减1
		return OK;
	}
	else
	{
		Node* p = NULL;
		p = GetNum(*list, cur - 1); //获得前一个结点
		if (p == NULL)
			return ERROR;
		//p = p->next;
		Node* n = p->next; //获得要删除的结点
		p->next = n->next; //执行删除操作
		free(n);//释放这个结点
		return OK;
	}
}
Status DestroyList(Head* list) //销毁整个表
{
	Node* p = list->next; //取出头指针
	while (p->next)
	{
		Node* n = p;
		p = p->next;//取出下一个结点
		free(n);//释放当前结点
	}
	return OK;
}

