#include "Player.h"

Player::Player(int _number, int _cash, int _positionx, 
	int _positiony, int _place, const char* imagePath)
{
	setNumber(_number);
	setCash(_cash);
	setPosition(_positionx, _positiony);
	setTotalPlace(_place);
	playerImage = new IMAGE;
	loadimage(playerImage, imagePath, 40, 40);
}

void Player::gotoxy(int _positionx, int _positiony)
{
	setPosition(_positionx, _positiony);
}

void Player::getBouns()
{
	setCash(getCash() + 2000); //�õ�2000Ԫ����
}

void Player::payTax()
{
	setCash(static_cast<int>(getCash() * 0.9)); //����10%��˰��
}

string Player::faceFate()
{
	srand(time(0));
	int fates = rand() % 14 + 1;
	string FATE;
	switch (fates)
	{
	case 1:
		FATE = "��ķ�����Ҫά�ޣ�����Ҫ֧��300Ԫ��ά�޷��á�";
		setCash(getCash() - 300);
		break;
	case 2:
		FATE = "��δ���������ڻ������ÿ�������Ҫ֧�������100Ԫ����Ϣ��";
		setCash(getCash() - 100);
		break;
	case 3:
		FATE = "���Ͷ��ʧ���ˣ���ʧȥ��500Ԫ��";
		setCash(getCash() - 500);
		break;
	case 4:
		FATE = "��ļ�ͥ��Ա�����ˣ�����Ҫ֧��500Ԫ��ҽ�Ʒ��á�";
		setCash(getCash() - 500);
		break;
	case 5:
		FATE = "��ķ�������ֶ���������Ҫ֧��600Ԫ���޸����á�";
		setCash(getCash() - 600);
		break;
	case 6:
		FATE = "�㲻С�����˹������Ҫ֧��500Ԫ���⳥���á�";
		setCash(getCash() - 500);
		break;
	case 7:
		FATE = "��Ĺ�˾��Ʊ�µ��ˣ���ʧȥ��200Ԫ��";
		setCash(getCash() - 200);
		break;
	case 8:
		FATE = "��ĳ���Ҫά�ޣ�����Ҫ֧��200Ԫ��ά�޷��á�";
		setCash(getCash() - 200);
		break;
	case 9:
		FATE = "��ķ��ݱ������ˣ�����Ҫ֧��500Ԫ���޸����á�";
		setCash(getCash() - 500);
		break;
	case 10:
		FATE = "��Ĺ�˾��Ʊ�����ˣ���ʧȥ��400Ԫ��";
		setCash(getCash() - 400);
		break;
	case 11:
		FATE = "��ķ�����Ϊ�������������Ҫ֧��800Ԫ���޸����á�";
		setCash(getCash() - 800);
		break;
	case 12:
		FATE = "������ÿ�������Ϊ���ڣ�����Ҫ֧��200Ԫ�������á�";
		setCash(getCash() - 200);
		break;
	case 13:
		FATE = "��İ�Ȯ�����ˣ�����Ҫ֧��300Ԫ����ҽ���á�";
		setCash(getCash() - 300);
		break;
	case 14:
		FATE = "����Ϊ����ʧ�󱻷�����200Ԫ��";
		setCash(getCash() - 200);
		break;
	case 15:
		FATE = "��ķ�����Ϊ̨�����������Ҫ֧��700Ԫ���޸����á�";
		setCash(getCash() - 700);
		break;
	default:
		FATE = " ";
		break;
	}
	return FATE;
}

string Player::chaseChance()
{
	srand(time(0));
	int chances = rand() % 14 + 1;
	string CHANCE;
	switch (chances)
	{
	case 1:
		CHANCE = "������һ�ݶ���Ĺ�������ö����200Ԫ��";
		setCash(getCash() + 200);
		break;
	case 2:
		CHANCE = "��Ĺ�˾�����һ�ݴ󶩵������ö����500Ԫ��";
		setCash(getCash() + 500);
		break;
	case 3:
		CHANCE = "��������˻�������ؿ��˷��ã�������500Ԫ�Ĳ�����";
		setCash(getCash() + 500);
		break;
	case 4:
		CHANCE = "���ڹ�˾�������ã�������400Ԫ�Ľ���";
		setCash(getCash() + 400);
		break;
	case 5:
		CHANCE = "��ķ�����Ϊ���������������1000Ԫ�ı����⳥��";
		setCash(getCash() + 1000);
		break;
	case 6:
		CHANCE = "��Ĺ�˾��Ʊ�����ˣ������˶����300Ԫ��";
		setCash(getCash() + 300);
		break;
	case 7:
		CHANCE = "��������˻�������ػ����˶�����ʽ�300Ԫ������Ա�����Щ�ʽ�";
		setCash(getCash() + 300);
		break;
	case 8:
		CHANCE = "��Ĺ�˾�����һ�ݴ󶩵��������˵�200Ԫ�Ľ�����";
		setCash(getCash() + 200);
		break;
	case 9:
		CHANCE = "��ķ�����Ϊ���������������500Ԫ���⳥���á�";
		setCash(getCash() + 500);
		break;
	case 10:
		CHANCE = "��Ĺ�˾��Ʊ�����ˣ������˶����200Ԫ��";
		setCash(getCash() + 200);
		break;
	case 11:
		CHANCE = "��μ���һ�γ齱��������100Ԫ�Ľ���";
		setCash(getCash() + 100);
		break;
	case 12:
		CHANCE = "������ÿ������Ϣ�������ˣ�������200Ԫ�Ļر���";
		setCash(getCash() + 200);
		break;
	case 13:
		CHANCE = "��ķ�����Ϊ̨������𣬵��㹺���˱��գ������800Ԫ���⳥��";
		setCash(getCash() + 800);
		break;
	case 14:
		CHANCE = "��Ĺ�˾��Ʊ�����ˣ������˶����500Ԫ��";
		setCash(getCash() + 500);
		break;
	case 15:
		CHANCE = "��ļ�ͥ��Ա���˲�Ʊ�����ǵõ���500Ԫ�Ľ���";
		setCash(getCash() + 500);
		break;
	default:
		break;
	}
	return CHANCE;
}

void Player::purchase(House& house)
{
	// �ȿ۳��ֽ�
	setCash(getCash() - house.price);
	// ��ȷ�ϸõز�������Ȩ
	house.processor = this->getNumber();
	house._isEmpty = false;
}

void Player::update(House& house)
{
	switch (house.level)
	{
	case 0:
	{
		setCash(getCash() - (house.price / 5));
		break;
	}
		
	case 1:
	{
		setCash(getCash() - (house.price / 2));
		break;
	}
	case 2:
	{
		setCash(getCash() - (house.price));
		break;
	}
	default:
		break;
	}

	house.level += 1;
}

Player::~Player()
{

}
