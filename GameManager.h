#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.h"
#include "Place.h"
#include "Bonus.h"
#include "Chances.h"
#include "Estate.h"
#include "Fates.h"
#include "Taxes.h"
#include "Position.h"
#include "House.h"
#include <iostream>
#include <Windows.h>
#include <easyx.h>
#include <graphics.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class GameManager
{
public:
	GameManager(); // 构造函数
	
	void loadDiceImages(); // 展示骰子图片
	void drawDice(int x, int y, int value); // 绘制骰子图片
	int rollDice(); // 随机掷骰子，返回结果
	void showDice(int value); // 展示骰子
	void addInformation(); // 补充信息
	void playGames(); // 进入游戏
	void endGame(); // 结束游戏

	IMAGE dice[6];
	vector <Player> playerArray;
	vector <Place*> placeArray;

	~GameManager(); // 析构函数
};

#endif