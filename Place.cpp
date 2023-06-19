#include "Place.h"

Place::Place(int _positionx, int _positiony)
{
	setPositionOfPlace(_positionx, _positiony);
}


void Place::setPositionOfPlace(int _positionx, int _positiony)
{
	positionOfPlace.x = _positionx;
	positionOfPlace.y = _positiony;
}

position Place::getPositionOfPlace()
{
	return positionOfPlace;
}

