#include"game.h"
void Menu()
{
	printf("\t\t\t*******************************************************\n\n\n");
	printf("\t\t\t******************* 欢迎来到扫雷游戏 ******************\n\n\n");
	printf("\t\t\t****************** 1、Play   2、Exit ******************\n\n\n");
	printf("\t\t\t*******************************************************\n\n");
}
void Setmine(char mine[][COL], int row, int col)
{
	int count = NUM;
	while (count > 0){
		int x = rand() % (row - 2) + 1;
		int y = rand() % (col - 2) + 1;
		if (mine[x][y] == '0'){
			mine[x][y] = '1';
			count--;
		}
	}
}
void Show(char show[][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("    ");
	for (i = 1; i <= 10; i++){
		printf("  %d ", i);
	}
	printf("\n");
	for (i = 1; i <= 10; i++){
		printf("----");
	}
	printf("----\n");
	for (i = 1; i <= 10; i++){
		printf(" %2d |", i);
		for (j = 1; j <= 10; j++){
			printf(" %c |", show[i][j]);
		}
		printf("\n");
		int k = 0;
		for (k = 1; k <= 10; k++){
			printf("----");
		}
		printf("----\n");
	}
}
int Getmine(char mine[][COL], int x, int y){ 
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1]\
		+ mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] \
		+ mine[x + 1][y] + mine[x + 1][y + 1]-8*'0';
}
void Openmine(char mine[ROW][COL], char show[ROW][COL], int row, int col, int x, int y)
{
	int m = 0;
	m = Getmine(mine, x, y);
	if (m == 0){
		show[x][y] = '0';
		if (x - 1 > 0 && y - 1 > 0 && show[x - 1][y - 1] == '*'){
			Openmine(mine, show, row, col, x - 1, y - 1);
		}
		if (x - 1 > 0 && y  > 0 && show[x - 1][y] == '*'){
			Openmine(mine, show, row, col, x - 1, y );
		}
		if (x - 1 > 0 && y + 1 > 0 && show[x - 1][y + 1] == '*'){
			Openmine(mine, show, row, col, x - 1, y + 1);
		}
		if (x > 0 && y - 1 > 0 && show[x][y - 1] == '*'){
			Openmine(mine, show, row, col, x , y - 1);
		}
		if (x  > 0 && y + 1 > 0 && show[x ][y + 1] == '*'){
			Openmine(mine, show, row, col, x , y + 1);
		}
		if (x + 1 > 0 && y - 1 > 0 && show[x + 1][y - 1] == '*'){
			Openmine(mine, show, row, col, x + 1, y - 1);
		}
		if (x + 1 > 0 && y > 0 && show[x + 1][y ] == '*'){
			Openmine(mine, show, row, col, x + 1, y );
		}
		if (x + 1 > 0 && y + 1 > 0 && show[x + 1][y + 1] == '*'){
			Openmine(mine, show, row, col, x + 1, y + 1);
		}
	}
	else{
		show[x][y] = Getmine(mine, x, y)+'0';
	}
}
void Game()
{
	srand((unsigned)time(NULL));
	char mine[ROW][COL];
	char show[ROW][COL];
	int x = 0;
	int y = 0;
	int times = ROW*COL - NUM;
	memset(mine, '0', sizeof(mine));
	memset(show, '*', sizeof(show));
	Setmine(mine, ROW, COL);
	Show(mine, ROW, COL);
	do{
		Show(show, ROW, COL);
		printf("请输入坐标(x,y) > ");
		scanf("%d %d", &x, &y);
		if (x<1 || x>10 || y<1 || y>10){
			printf("你输入的坐标有误，请重新输入坐标！\n");
			continue;
		}
		if (show[x][y] != '*'){
			printf("该位置已经排过了，请重新输入坐标！\n");
			continue;
		}
		if (mine[x][y] == '1'){
			if (times == ROW*COL - NUM){
				mine[x][y] = '0';
				int i = rand() % (ROW - 2) + 1;
				int j = rand() % (COL - 2) + 1;
				if (mine[i][j] == '0'){
					times--;
					mine[i][j] = '1';
				}
			}
			else{
				printf("真遗憾，你踩到雷了，游戏结束\n");
				printf("雷的分布图如下 > \n");
				Show(mine, ROW, COL);
				break;
			}
		}
		int mine_num = Getmine(mine, x, y);
		show[x][y] = mine_num + '0';
		Openmine(mine, show, ROW, COL, x, y);
		times--;
		
	} while (time > 0);
	if (times == 0){
		printf("恭喜，你赢了！\n");
		printf("雷的分布图如下 > \n");
		Show(mine, ROW, COL);
	}
}