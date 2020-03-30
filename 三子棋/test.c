#include<stdio.h>
#include<windows.h>
#include<time.h>
#define ROW 3
#define COL 3
#define COMPUTER 'X'
#define PERSON 'O'
void Init(char board[][3],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			board[i][j] = ' ';
		}
	}
}
int Guess()
{
	int m = 0;
	int x = rand() % 2;
	printf("请您猜数（0或1）> ");
	scanf_s("%d", &m);
	if (x == m){
		printf("恭喜，你猜对了，你先走！\n\n");
		return 1;
	}
	else{
		printf("不好意思，你猜错了，电脑先走！\n\n");
		return 0;
	}
}
void ComputerMove(char board[][COL], int row, int col)
{
	printf("电脑落子 > \n\n");
	while (1){
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' '){
			board[x][y] = COMPUTER;
			break;
		}
	}
}
void PersonMove(char board[][COL], int row, int col)
{
	while (1){
		printf("请落子（x ，y） > ");
		int x = 0;
		int y = 0;
		scanf_s("%d %d", &x, &y);
		if (x<=0 || x>3 || y<=0 || y>3){
			printf("您输入的位置有误，请重新输入！\n");
			continue;
		}
		else if (board[x - 1][y - 1] != ' '){
			printf("该位置已经被占了，请重新输入！\n");
			continue;
		}
		else {
			board[x - 1][y - 1] = PERSON;
			break;
		}
	}
}
void Show(char board[][COL], int row, int col)
{
	printf("    1 | 2 | 3\n");
	printf("---------------\n");
	int i = 0;
	int j = 0;
	for (i = 1; i <= row; i++){
		printf("%d |", i);
		for (j = 1; j <= col; j++){
			printf("%c  |", board[i - 1][j - 1]);
		}
		printf("\n");
		printf("---------------\n");
	}
	printf("\n");
}
char Judge(char board[][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++){
		if (board[i][0] != ' '&&board[i][0] == board[i][1] && board[i][1] == board[i][2]){
			return board[i][0];
		}
		if (board[0][i] != ' '&&board[0][i] == board[1][i] && board[1][i] == board[2][i]){
			return board[0][i];
		}
		if (board[1][1] != ' '&&board[0][0] == board[1][1] && board[1][1] == board[2][2]){
			return board[1][1];
		}
		if (board[1][1] != ' '&&board[0][2] == board[1][1] && board[1][1] == board[2][0]){
			return board[1][1];
		}
			for (j = 0; j < col; j++){
				if (board[i][j] == ' '){
					return 'N';
				}
			}
	}
	return 'F';
}
void Game()
{
	srand((unsigned)time(NULL));
	char result = 0;
	char board[ROW][COL];
	Init(board, ROW, COL);
	printf("棋盘是这样的 > \n");
	Show(board, ROW, COL);
	printf("游戏开始前先来个小游戏决定谁先走吧！\n\n");
	int a = Guess();
	do{
		switch (a){
		case 1:
		{
				  PersonMove(board, ROW, COL);
				  Show(board, ROW, COL);
				  a = 0;
				  break;
		}
		case 0:
		{

				  ComputerMove(board, ROW, COL);
				  Show(board, ROW, COL);
				  a = 1;
				  break;
		}
		default:
			break;
		}
		result = Judge(board, ROW, COL);
		if (result != 'N'){
			break;
		}
	} while (1);
	switch (result){
	case PERSON:
		printf("恭喜你，你赢了！\n");
		break;
	case COMPUTER:
		printf("真遗憾，你输了！\n");
		break;
	case 'F':
		printf("平局！\n");
		break;
	default:
		break;
	}
}
void Menu()
{
	printf("\t\t\t*******************************************************\n\n\n");
	printf("\t\t\t****************** 欢迎来到三子棋游戏 *****************\n\n\n");
	printf("\t\t\t****************** 1、Play   2、Exit ******************\n\n\n");
	printf("\t\t\t*******************************************************\n\n");
	printf("请输入您的选择 > \n");
}
void main()
{
	int quit = 1;
	int select = 1;
	do{
		Menu();
		scanf_s("%d", &select);
		switch (select){
		case 1:
			Game();
			break;
		case 2:
			quit = 0;
			break;
		default:
			printf("您的选择有误，请重新选择！");
			break;
		}
	} while (quit);
	system("pause");
}