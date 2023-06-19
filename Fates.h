#pragma once
#include "Position.h"
#include "Place.h"
using namespace std;

class Fates : public Place
{
public:
	Fates(int _positionx, int _positiony);
	virtual void PlaceFunction(Player& player);
};

