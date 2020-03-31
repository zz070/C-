#include"game.h"
void main()
{
	int quit = 1;
	int select = 0;
	while (quit){
		Menu();
		printf("请输入你的选择 > ");
		scanf("%d", &select);
		switch (select){
		case 1:
			Game();
			break;
		case 2:
			quit = 0;
			break;
		default:
			printf("您的输入有误，请重新输入！");
			break;
		}
	}
	system("pause");
}