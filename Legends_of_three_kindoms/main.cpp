#include"internet.h"
#include"easyx.h"
#include"skills_cards.h"
#include"main.h"
#define MAX_WARLOAD 2  
#define MAX_CARD 4
#define PORT 6666
int main()
{
	
	USER user;
	init_all(&user); //��ʼ������
	int flag; //�涨�Ƿ���˻��ǿͻ��� 
	// �����ʼ��
	BEGIN:  //����������
	if (connect_local() == server)//�ж��ǿͻ��˻��Ƿ����
	{							//�����
		if (!get_ip((user.ip))) //��ö˿�
		{
			//��ȡipʧ��
		}
		while (true)
		{

		}

		flag =server;

	}
	else if (connect_local() == client)
	{
		if (!get_server_ip(user.ip) != NULL)
		{
			goto  BEGIN;
		}
		
		if (!connect_ip(user.ip))
		{
			//���Ӵ���
		}
		flag = client;
		
		
	}
	else
	{
		//��ӡ����
	}

	// ��Ϸ��ʼ
	while (true)
	{
		if (flag == server)
		{

		}
		else if (flag == client)
		{
			
		}
		else {
			// ��ӡ������
			goto BEGIN;
		}
	}
	return 0;
}
int init_all()
{
	if (!init_connect())
	{
		//��ӡ�������Ӵ���
	}


	return 0;
}