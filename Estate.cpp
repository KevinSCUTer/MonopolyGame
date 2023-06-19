#include "Estate.h"

Estate::Estate(int _positionx, int _positiony, int _price, int _level, int _processor, bool _isEmpty)
	: Place(_positionx, _positiony)
{
	setInfoOfHouse(_price, _level, _processor, 1);
}

void Estate::setInfoOfHouse(int _price, int _level, int _processor, bool _isEmpty)
{
	house.price = _price;
	house.level = _level;
	house.processor = _processor;
	house._isEmpty = _isEmpty;
}

House Estate::getInfoOfHouse()
{
	return house;
}

void Estate::PlaceFunction(Player& player)
{
	// 先清除之前的信息
	setbkcolor(RGB(160, 238, 225));
	outtextxy(300, 400, "                             ");
	outtextxy(300, 450, "                             ");
	outtextxy(300, 500, "                               ");
	
	// 再根据地产的状态执行操作
	// 如果这个地方的地产没有被购买
	if (this->getInfoOfHouse()._isEmpty == true)
	{
		// 如果该地产没有被购买，则询问用户是否购买该地产
		if (player.getCash() >= this->getInfoOfHouse().price)
		{
			// 如果用户的金钱足够购买该地产，则询问用户是否购买房产
			// 先获取窗口句柄
			HWND hnd = GetHWnd();
			// 弹出消息窗口，提示用户操作
			// 可能有窗口层级的问题
			int isOK = MessageBox(GetHWnd(), "你是否购买这里的地产？", "询问", MB_OKCANCEL);
			if (isOK == IDOK)
			{
				player.purchase(this->house);
				setbkcolor(RGB(160, 238, 225));
				settextcolor(BLACK);
				settextstyle(20, 0, "宋体");
				outtextxy(300, 500, "你购买了地产！");
				
				//然后根据该地点的位置改变当前房产格子的信息
				// 如果是北部地区
				if (this->getPositionOfPlace().y == 50)
				{
					string OWNER = "物主：";
					OWNER += to_string(player.getNumber());
					outtextxy(this->getPositionOfPlace().x, 180, OWNER.c_str());
					string LEVEL = "等级：0";
					outtextxy(this->getPositionOfPlace().x, 200, LEVEL.c_str());
				}
				// 如果是东部地区
				else if (this->getPositionOfPlace().x == 1050)
				{
					string OWNER = "物主：";
					OWNER += to_string(player.getNumber());
					outtextxy(950, this->getPositionOfPlace().y + 30, OWNER.c_str());
					string LEVEL = "等级：0";
					outtextxy(950, this->getPositionOfPlace().y + 50, LEVEL.c_str());
				}
				// 如果是南部地区
				else if (this->getPositionOfPlace().y == 650)
				{
					string OWNER = "物主：";
					OWNER += to_string(player.getNumber());
					outtextxy(this->getPositionOfPlace().x, 580, OWNER.c_str());
					string LEVEL = "等级：0";
					outtextxy(this->getPositionOfPlace().x, 600, LEVEL.c_str());
				}
				// 如果是西部地区
				else if (this->getPositionOfPlace().x == 50)
				{
					string OWNER = "物主：";
					OWNER += to_string(player.getNumber());
					outtextxy(150, this->getPositionOfPlace().y + 30, OWNER.c_str());
					string LEVEL = "等级：0";
					outtextxy(150, this->getPositionOfPlace().y + 50, LEVEL.c_str());
				}
			}
			else if (isOK == IDCANCEL)
			{
				setbkcolor(RGB(160, 238, 225));
				settextcolor(BLACK);
				settextstyle(20, 0, "宋体");
				outtextxy(300, 500, "取消购买地产！");
			}
		}
		else
		{
			setbkcolor(RGB(160, 238, 225));
			settextcolor(BLACK);
			settextstyle(20, 0, "宋体");
			outtextxy(300, 500, "无法购买地产！");
		}
	}

	// 否则的话，如果这个地产已经被购买了
	else
	{
		// 如果这个地产是玩家的
		if (this->getInfoOfHouse().processor == player.getNumber())
		{
			switch (this->getInfoOfHouse().level)
			{
			case 0:
			{
				if (player.getCash() < this->getInfoOfHouse().price / 5)
				{
					setbkcolor(RGB(160, 238, 225));
					settextcolor(BLACK);
					settextstyle(20, 0, "宋体");
					outtextxy(300, 500, "无法升级地产！");
				}
				else
				{
					// 先获取窗口句柄
					HWND hnd = GetHWnd();
					// 弹出消息窗口，提示用户操作
					// 可能有窗口层级的问题
					int isOK = MessageBox(GetHWnd(), "你是否升级这里的地产？", "询问", MB_OKCANCEL);
					if (isOK == IDOK)
					{
						player.update(this->house);
						setbkcolor(RGB(160, 238, 225));
						settextcolor(BLACK);
						settextstyle(20, 0, "宋体");
						outtextxy(300, 500, "你升级了地产！");

						//然后根据该地点的位置改变当前房产格子的信息
						// 如果是北部地区
						if (this->getPositionOfPlace().y == 50)
						{
							string LEVEL = "等级：";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(this->getPositionOfPlace().x, 200, LEVEL.c_str());
						}
						// 如果是东部地区
						else if (this->getPositionOfPlace().x == 1050)
						{
							string LEVEL = "等级：";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(950, this->getPositionOfPlace().y + 50, LEVEL.c_str());
						}
						// 如果是南部地区
						else if (this->getPositionOfPlace().y == 650)
						{
							string LEVEL = "等级：";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(this->getPositionOfPlace().x, 600, LEVEL.c_str());
						}
						// 如果是西部地区
						else if (this->getPositionOfPlace().x == 50)
						{
							string LEVEL = "等级：";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(150, this->getPositionOfPlace().y + 50, LEVEL.c_str());
						}
					}
					else if (isOK == IDCANCEL)
					{
						setbkcolor(RGB(160, 238, 225));
						settextcolor(BLACK);
						settextstyle(20, 0, "宋体");
						outtextxy(300, 500, "取消升级地产！");
					}
				}
				break;
			}
				
			case 1:
			{
				if (player.getCash() < this->getInfoOfHouse().price / 2)
				{
					setbkcolor(RGB(160, 238, 225));
					settextcolor(BLACK);
					settextstyle(20, 0, "宋体");
					outtextxy(300, 500, "无法升级地产！");
				}
				else
				{
					// 先获取窗口句柄
					HWND hnd = GetHWnd();
					// 弹出消息窗口，提示用户操作
					// 可能有窗口层级的问题
					int isOK = MessageBox(GetHWnd(), "你是否升级这里的地产？", "询问", MB_OKCANCEL);
					if (isOK == IDOK)
					{
						player.update(this->house);
						setbkcolor(RGB(160, 238, 225));
						settextcolor(BLACK);
						settextstyle(20, 0, "宋体");
						outtextxy(300, 500, "你升级了地产！");

						//然后根据该地点的位置改变当前房产格子的信息
						// 如果是北部地区
						if (this->getPositionOfPlace().y == 50)
						{
							string LEVEL = "等级：";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(this->getPositionOfPlace().x, 200, LEVEL.c_str());
						}
						// 如果是东部地区
						else if (this->getPositionOfPlace().x == 1050)
						{
							string LEVEL = "等级：";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(950, this->getPositionOfPlace().y + 50, LEVEL.c_str());
						}
						// 如果是南部地区
						else if (this->getPositionOfPlace().y == 650)
						{
							string LEVEL = "等级：";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(this->getPositionOfPlace().x, 600, LEVEL.c_str());
						}
						// 如果是西部地区
						else if (this->getPositionOfPlace().x == 50)
						{
							string LEVEL = "等级：";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(150, this->getPositionOfPlace().y + 50, LEVEL.c_str());
						}

					}
					else if (isOK == IDCANCEL)
					{
						setbkcolor(RGB(160, 238, 225));
						settextcolor(BLACK);
						settextstyle(20, 0, "宋体");
						outtextxy(300, 500, "取消升级地产！");
					}
				}
				break;
			}
			case 2:
			{
				if (player.getCash() < this->getInfoOfHouse().price)
				{
					setbkcolor(RGB(160, 238, 225));
					settextcolor(BLACK);
					settextstyle(20, 0, "宋体");
					outtextxy(300, 500, "无法升级地产！");
				}
				else
				{
					// 先获取窗口句柄
					HWND hnd = GetHWnd();
					// 弹出消息窗口，提示用户操作
					// 可能有窗口层级的问题
					int isOK = MessageBox(GetHWnd(), "你是否升级这里的地产？", "询问", MB_OKCANCEL);
					if (isOK == IDOK)
					{
						player.update(this->house);
						setbkcolor(RGB(160, 238, 225));
						settextcolor(BLACK);
						settextstyle(20, 0, "宋体");
						outtextxy(300, 500, "你升级了地产！");

						//然后根据该地点的位置改变当前房产格子的信息
						// 如果是北部地区
						if (this->getPositionOfPlace().y == 50)
						{
							string LEVEL = "等级：";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(this->getPositionOfPlace().x, 200, LEVEL.c_str());
						}
						// 如果是东部地区
						else if (this->getPositionOfPlace().x == 1050)
						{
							string LEVEL = "等级：";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(950, this->getPositionOfPlace().y + 50, LEVEL.c_str());
						}
						// 如果是南部地区
						else if (this->getPositionOfPlace().y == 650)
						{
							string LEVEL = "等级：";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(this->getPositionOfPlace().x, 600, LEVEL.c_str());
						}
						// 如果是西部地区
						else if (this->getPositionOfPlace().x == 50)
						{
							string LEVEL = "等级：";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(150, this->getPositionOfPlace().y + 50, LEVEL.c_str());
						}
					}
					else if (isOK == IDCANCEL)
					{
						setbkcolor(RGB(160, 238, 225));
						settextcolor(BLACK);
						settextstyle(20, 0, "宋体");
						outtextxy(300, 500, "取消升级地产！");
					}
				}
				break;
			}
			default:
				break;
			}
		}

		// 如果这个地产并不是玩家的，该玩家上交过路费
		else
		{
			player.setCash(player.getCash() - getInfoOfHouse().price * (getInfoOfHouse().level + 1) / 5);
			string PAYMENT = "请上交过路费";
			int payment = getInfoOfHouse().price * (getInfoOfHouse().level + 1) / 5;
			PAYMENT += to_string(payment);
			setbkcolor(RGB(160, 238, 225));
			settextcolor(BLACK);
			settextstyle(20, 0, "宋体");
			outtextxy(300, 500, PAYMENT.c_str());
		}
	}
}