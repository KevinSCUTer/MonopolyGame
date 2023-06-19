#pragma once
#include "Place.h"
#include "Position.h"
#include "House.h"

class Estate : public Place
{

public:
    //Estate(250, 50, 300, 0, 1)
    Estate(int _positionx, int _positiony, int _price, int _level, int _processor, bool _isEmpty);
    void setInfoOfHouse(int _price, int _level, int _processor, bool _isEmpty); // 设置房产信息
    House getInfoOfHouse(); // 得到地点位置
    virtual void PlaceFunction(Player& player);
    
private:
    House house; //将房产和地皮分开来，便于PlaceFunction的书写
};


