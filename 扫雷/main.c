#include"game.h"
void main()
{
	int quit = 1;
	int select = 0;
	while (quit){
		Menu();
		printf("���������ѡ�� > ");
		scanf("%d", &select);
		switch (select){
		case 1:
			Game();
			break;
		case 2:
			quit = 0;
			break;
		default:
			printf("���������������������룡");
			break;
		}
	}
	system("pause");
}