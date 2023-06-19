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
	IMAGE* playerImage; //���һ��IMAGE*���͵�ָ����ΪPlayer�ĳ�Ա��������ʾPlayer��Ϣ

	//���캯��
	Player(int _number, int _cash, int _positionx, int _positiony, int _place, const char* imagePath);

	//��ɫ�����
	void setNumber(int _number) { number = _number; }
	int getNumber() { return number; }

	//��ɫ�Ľ�Ǯ
	void setCash(int _cash) { cash = _cash;  }
	int getCash() { return cash; }

	//��ɫ�����ڵص������ܺ�
	void setTotalPlace(int _place) { totalPlace = _place; }
	int getTotalPlace() { return totalPlace; }

	//��ɫ��λ��
	void setPosition(int _positionx, int _positiony)
	{
		positionOfPlayer.x = _positionx;
		positionOfPlayer.y = _positiony;
	}

	position getPosition()
	{
		return positionOfPlayer;
	}
	
	//��ɫ�ƶ��ĺ���
	void gotoxy(int _positionx, int _positiony); //�ý�ɫ�ƶ���ָ��λ�õĺ���

	//�����ɫ�ĺ����������ԭ�е�λ�û���һ���뱳����ɫ��ͬ�ľ���
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

	void getBouns(); //�õ�����
	void payTax(); //֧��˰��
	string faceFate(); //ֱ������
	string chaseChance(); //���ջ���

	void purchase(House& house); //���򷿲�
	void update(House& house); //��������

	//��������
	~Player();

private:
	int number; // ��ҵ�Ͷ����˳��
	position positionOfPlayer;
	int cash; // ���ӵ�еĽ�Ǯ
	int totalPlace; //���Ͷ���ӵ��ܺͣ�����������Է������Ͷ����
};
