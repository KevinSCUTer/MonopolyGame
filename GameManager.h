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
	GameManager(); // ���캯��
	
	void loadDiceImages(); // չʾ����ͼƬ
	void drawDice(int x, int y, int value); // ��������ͼƬ
	int rollDice(); // ��������ӣ����ؽ��
	void showDice(int value); // չʾ����
	void addInformation(); // ������Ϣ
	void playGames(); // ������Ϸ
	void endGame(); // ������Ϸ

	IMAGE dice[6];
	vector <Player> playerArray;
	vector <Place*> placeArray;

	~GameManager(); // ��������
};

#endif