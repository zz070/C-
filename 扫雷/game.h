#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<string.h>

#define ROW 12
#define COL 12
#define NUM 20
#pragma warning(disable:4996)

void Menu();
void Setmine(char show[][COL], int row, int col);
void Show(char show[][COL], int row, int col);
int Getmine(char mine[][COL], int row, int col);
void Openmine(char mine[ROW][COL], char show[ROW][COL], int row, int col, int x, int y);
void Game();

#endif