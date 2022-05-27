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
	init_all(&user); //初始化人物
	int flag; //规定是服务端还是客户端 
	// 网络初始化
	BEGIN:  //返回主界面
	if (connect_local() == server)//判断是客户端还是服务端
	{							//服务端
		if (!get_ip((user.ip))) //获得端口
		{
			//获取ip失败
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
			//连接错误
		}
		flag = client;
		
		
	}
	else
	{
		//打印错误
	}

	// 游戏开始
	while (true)
	{
		if (flag == server)
		{

		}
		else if (flag == client)
		{
			
		}
		else {
			// 打印错误处理
			goto BEGIN;
		}
	}
	return 0;
}
int init_all()
{
	if (!init_connect())
	{
		//打印错误连接错误
	}


	return 0;
}