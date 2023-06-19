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
	void setPositionOfPlace(int _positionx, int _positiony); // ���õص�λ��
	position getPositionOfPlace(); // �õ��ص�λ��

private:
	position positionOfPlace; 

	//positionOfPlace��¼���ǵ�һ����ҵĵ�ַ������Ƕ�����������ҵĻ���λ����Ҫ�����ı�
	//���һ�� positionOfPlace.x      , positionOfPlace.y 
	//��Ҷ��� positionOfPlace.x + 50 , positionOfPlace.y
	//������� positionOfPlace.x      , positionOfPlace.y + 50
	//����ģ� positionOfPlace.x + 50 , positionOfPlace.y + 50
};

#endif

