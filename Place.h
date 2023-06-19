#ifndef PLACE_H
#define PLACE_H

#include <iostream>
#include "Player.h"
#include "Position.h"
using namespace std;

class Place
{
public:
	Place(int _positionx, int _positiony);
	virtual void PlaceFunction(Player& player) = 0;
	void setPositionOfPlace(int _positionx, int _positiony); // 设置地点位置
	position getPositionOfPlace(); // 得到地点位置

private:
	position positionOfPlace; 

	//positionOfPlace记录的是第一个玩家的地址，如果是二、三、四玩家的话，位置需要发生改变
	//玩家一： positionOfPlace.x      , positionOfPlace.y 
	//玩家二： positionOfPlace.x + 50 , positionOfPlace.y
	//玩家三： positionOfPlace.x      , positionOfPlace.y + 50
	//玩家四： positionOfPlace.x + 50 , positionOfPlace.y + 50
};

#endif

