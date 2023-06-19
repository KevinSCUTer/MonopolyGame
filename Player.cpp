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
	setCash(getCash() + 2000); //得到2000元奖金
}

void Player::payTax()
{
	setCash(static_cast<int>(getCash() * 0.9)); //缴纳10%的税款
}

string Player::faceFate()
{
	srand(time(0));
	int fates = rand() % 14 + 1;
	string FATE;
	switch (fates)
	{
	case 1:
		FATE = "你的房屋需要维修，你需要支付300元的维修费用。";
		setCash(getCash() - 300);
		break;
	case 2:
		FATE = "你未能在期限内还清信用卡借款，你需要支付额外的100元的利息。";
		setCash(getCash() - 100);
		break;
	case 3:
		FATE = "你的投资失败了，你失去了500元。";
		setCash(getCash() - 500);
		break;
	case 4:
		FATE = "你的家庭成员生病了，你需要支付500元的医疗费用。";
		setCash(getCash() - 500);
		break;
	case 5:
		FATE = "你的房屋因火灾而受损，你需要支付600元的修复费用。";
		setCash(getCash() - 600);
		break;
	case 6:
		FATE = "你不小心损坏了公物，你需要支付500元的赔偿费用。";
		setCash(getCash() - 500);
		break;
	case 7:
		FATE = "你的公司股票下跌了，你失去了200元。";
		setCash(getCash() - 200);
		break;
	case 8:
		FATE = "你的车需要维修，你需要支付200元的维修费用。";
		setCash(getCash() - 200);
		break;
	case 9:
		FATE = "你的房屋被抢劫了，你需要支付500元的修复费用。";
		setCash(getCash() - 500);
		break;
	case 10:
		FATE = "你的公司股票暴跌了，你失去了400元。";
		setCash(getCash() - 400);
		break;
	case 11:
		FATE = "你的房屋因为地震而受损，你需要支付800元的修复费用。";
		setCash(getCash() - 800);
		break;
	case 12:
		FATE = "你的信用卡借款被误认为逾期，你需要支付200元的误解费用。";
		setCash(getCash() - 200);
		break;
	case 13:
		FATE = "你的爱犬生病了，你需要支付300元的兽医费用。";
		setCash(getCash() - 300);
		break;
	case 14:
		FATE = "你因为工作失误被罚款了200元。";
		setCash(getCash() - 200);
		break;
	case 15:
		FATE = "你的房屋因为台风而受损，你需要支付700元的修复费用。";
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
		CHANCE = "你获得了一份额外的工作，获得额外的200元。";
		setCash(getCash() + 200);
		break;
	case 2:
		CHANCE = "你的公司获得了一份大订单，你获得额外的500元。";
		setCash(getCash() + 500);
		break;
	case 3:
		CHANCE = "你的银行账户被错误地扣了费用，你获得了500元的补偿。";
		setCash(getCash() + 500);
		break;
	case 4:
		CHANCE = "你在公司表现良好，你获得了400元的奖金。";
		setCash(getCash() + 400);
		break;
	case 5:
		CHANCE = "你的房屋因为地震而受损，你获得了1000元的保险赔偿。";
		setCash(getCash() + 1000);
		break;
	case 6:
		CHANCE = "你的公司股票上涨了，你获得了额外的300元。";
		setCash(getCash() + 300);
		break;
	case 7:
		CHANCE = "你的银行账户被错误地汇入了额外的资金300元，你可以保留这些资金。";
		setCash(getCash() + 300);
		break;
	case 8:
		CHANCE = "你的公司获得了一份大订单，你获得了的200元的津贴。";
		setCash(getCash() + 200);
		break;
	case 9:
		CHANCE = "你的房屋因为地震而受损，你获得了500元的赔偿费用。";
		setCash(getCash() + 500);
		break;
	case 10:
		CHANCE = "你的公司股票上涨了，你获得了额外的200元。";
		setCash(getCash() + 200);
		break;
	case 11:
		CHANCE = "你参加了一次抽奖活动，获得了100元的奖金。";
		setCash(getCash() + 100);
		break;
	case 12:
		CHANCE = "你的信用卡借款利息被减免了，你获得了200元的回报。";
		setCash(getCash() + 200);
		break;
	case 13:
		CHANCE = "你的房屋因为台风而受损，但你购买了保险，获得了800元的赔偿。";
		setCash(getCash() + 800);
		break;
	case 14:
		CHANCE = "你的公司股票暴涨了，你获得了额外的500元。";
		setCash(getCash() + 500);
		break;
	case 15:
		CHANCE = "你的家庭成员中了彩票，你们得到了500元的奖金。";
		setCash(getCash() + 500);
		break;
	default:
		break;
	}
	return CHANCE;
}

void Player::purchase(House& house)
{
	// 先扣除现金
	setCash(getCash() - house.price);
	// 再确认该地产的所有权
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
