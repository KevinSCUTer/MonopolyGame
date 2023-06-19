#pragma once
#include "Position.h"
#include "Place.h"
using namespace std;

class Taxes : public Place
{
public:
	Taxes(int _positionx, int _positiony);
	virtual void PlaceFunction(Player& player);
private:

};

