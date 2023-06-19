#pragma once
#include "Position.h"
#include "Place.h"
using namespace std;

class Bonus : public Place
{
public:
	Bonus(int _positionx, int _positiony);
	virtual void PlaceFunction(Player& player);
};