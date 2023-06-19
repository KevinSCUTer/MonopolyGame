#pragma once
#include <iostream>
#include <easyx.h>
#include <graphics.h>
#include <string>
#include <cstring>
#include "Position.h"
#include "House.h"

using namespace std;

class Player
{
public:
	IMAGE* playerImage; //添加一个IMAGE*类型的指针作为Player的成员变量，显示Player信息

	//构造函数
	Player(int _number, int _cash, int _positionx, int _positiony, int _place, const char* imagePath);

	//角色的序号
	void setNumber(int _number) { number = _number; }
	int getNumber() { return number; }

	//角色的金钱
	void setCash(int _cash) { cash = _cash;  }
	int getCash() { return cash; }

	//角色的所在地点的里程总和
	void setTotalPlace(int _place) { totalPlace = _place; }
	int getTotalPlace() { return totalPlace; }

	//角色的位置
	void setPosition(int _positionx, int _positiony)
	{
		positionOfPlayer.x = _positionx;
		positionOfPlayer.y = _positiony;
	}

	position getPosition()
	{
		return positionOfPlayer;
	}
	
	//角色移动的函数
	void gotoxy(int _positionx, int _positiony); //让角色移动到指定位置的函数

	//清除角色的函数，在玩家原有的位置画上一个与背景颜色相同的矩形
	void clearPlayer()
	{
		int x = getPosition().x;
		int y = getPosition().y;
		int width = playerImage->getwidth();
		int height = playerImage->getheight();
		setbkcolor(WHITE);
		setfillcolor(WHITE);
		solidrectangle(x, y, x + width, y + height);
	}

	void getBouns(); //得到奖金
	void payTax(); //支付税款
	string faceFate(); //直面命运
	string chaseChance(); //把握机会

	void purchase(House& house); //购买房产
	void update(House& house); //升级房产

	//析构函数
	~Player();

private:
	int number; // 玩家的投骰子顺序
	position positionOfPlayer;
	int cash; // 玩家拥有的金钱
	int totalPlace; //玩家投骰子的总和，这个变量可以方便玩家投骰子
};
