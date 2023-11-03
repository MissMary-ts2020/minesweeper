#pragma once

//棋盘数据
#define WIDTH 10//棋盘宽度
#define HEIGHT 10//棋盘高度
#define BOMBS 2//雷数

int board[HEIGHT][WIDTH];//创建棋盘
//棋盘除了初始化以外，任何情况下都不准更改

char board_forgame[HEIGHT][WIDTH];//字符化的棋盘
char mengban[HEIGHT][WIDTH];//蒙版
static int flag_end = 1;//游戏继续标志
static int win_end = 0;//游戏结果标志

void game();



