#pragma once
#include "Position.h"
#include "Place.h"
using namespace std;

class Chances : public Place
{
public:
	Chances(int _positionx, int _positiony);
	virtual void PlaceFunction(Player& player);
};

