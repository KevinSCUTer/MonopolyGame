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
	// �����֮ǰ����Ϣ
	setbkcolor(RGB(160, 238, 225));
	outtextxy(300, 400, "                             ");
	outtextxy(300, 450, "                             ");
	outtextxy(300, 500, "                               ");
	
	// �ٸ��ݵز���״ִ̬�в���
	// �������ط��ĵز�û�б�����
	if (this->getInfoOfHouse()._isEmpty == true)
	{
		// ����õز�û�б�������ѯ���û��Ƿ���õز�
		if (player.getCash() >= this->getInfoOfHouse().price)
		{
			// ����û��Ľ�Ǯ�㹻����õز�����ѯ���û��Ƿ��򷿲�
			// �Ȼ�ȡ���ھ��
			HWND hnd = GetHWnd();
			// ������Ϣ���ڣ���ʾ�û�����
			// �����д��ڲ㼶������
			int isOK = MessageBox(GetHWnd(), "���Ƿ�������ĵز���", "ѯ��", MB_OKCANCEL);
			if (isOK == IDOK)
			{
				player.purchase(this->house);
				setbkcolor(RGB(160, 238, 225));
				settextcolor(BLACK);
				settextstyle(20, 0, "����");
				outtextxy(300, 500, "�㹺���˵ز���");
				
				//Ȼ����ݸõص��λ�øı䵱ǰ�������ӵ���Ϣ
				// ����Ǳ�������
				if (this->getPositionOfPlace().y == 50)
				{
					string OWNER = "������";
					OWNER += to_string(player.getNumber());
					outtextxy(this->getPositionOfPlace().x, 180, OWNER.c_str());
					string LEVEL = "�ȼ���0";
					outtextxy(this->getPositionOfPlace().x, 200, LEVEL.c_str());
				}
				// ����Ƕ�������
				else if (this->getPositionOfPlace().x == 1050)
				{
					string OWNER = "������";
					OWNER += to_string(player.getNumber());
					outtextxy(950, this->getPositionOfPlace().y + 30, OWNER.c_str());
					string LEVEL = "�ȼ���0";
					outtextxy(950, this->getPositionOfPlace().y + 50, LEVEL.c_str());
				}
				// ������ϲ�����
				else if (this->getPositionOfPlace().y == 650)
				{
					string OWNER = "������";
					OWNER += to_string(player.getNumber());
					outtextxy(this->getPositionOfPlace().x, 580, OWNER.c_str());
					string LEVEL = "�ȼ���0";
					outtextxy(this->getPositionOfPlace().x, 600, LEVEL.c_str());
				}
				// �������������
				else if (this->getPositionOfPlace().x == 50)
				{
					string OWNER = "������";
					OWNER += to_string(player.getNumber());
					outtextxy(150, this->getPositionOfPlace().y + 30, OWNER.c_str());
					string LEVEL = "�ȼ���0";
					outtextxy(150, this->getPositionOfPlace().y + 50, LEVEL.c_str());
				}
			}
			else if (isOK == IDCANCEL)
			{
				setbkcolor(RGB(160, 238, 225));
				settextcolor(BLACK);
				settextstyle(20, 0, "����");
				outtextxy(300, 500, "ȡ������ز���");
			}
		}
		else
		{
			setbkcolor(RGB(160, 238, 225));
			settextcolor(BLACK);
			settextstyle(20, 0, "����");
			outtextxy(300, 500, "�޷�����ز���");
		}
	}

	// ����Ļ����������ز��Ѿ���������
	else
	{
		// �������ز�����ҵ�
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
					settextstyle(20, 0, "����");
					outtextxy(300, 500, "�޷������ز���");
				}
				else
				{
					// �Ȼ�ȡ���ھ��
					HWND hnd = GetHWnd();
					// ������Ϣ���ڣ���ʾ�û�����
					// �����д��ڲ㼶������
					int isOK = MessageBox(GetHWnd(), "���Ƿ���������ĵز���", "ѯ��", MB_OKCANCEL);
					if (isOK == IDOK)
					{
						player.update(this->house);
						setbkcolor(RGB(160, 238, 225));
						settextcolor(BLACK);
						settextstyle(20, 0, "����");
						outtextxy(300, 500, "�������˵ز���");

						//Ȼ����ݸõص��λ�øı䵱ǰ�������ӵ���Ϣ
						// ����Ǳ�������
						if (this->getPositionOfPlace().y == 50)
						{
							string LEVEL = "�ȼ���";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(this->getPositionOfPlace().x, 200, LEVEL.c_str());
						}
						// ����Ƕ�������
						else if (this->getPositionOfPlace().x == 1050)
						{
							string LEVEL = "�ȼ���";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(950, this->getPositionOfPlace().y + 50, LEVEL.c_str());
						}
						// ������ϲ�����
						else if (this->getPositionOfPlace().y == 650)
						{
							string LEVEL = "�ȼ���";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(this->getPositionOfPlace().x, 600, LEVEL.c_str());
						}
						// �������������
						else if (this->getPositionOfPlace().x == 50)
						{
							string LEVEL = "�ȼ���";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(150, this->getPositionOfPlace().y + 50, LEVEL.c_str());
						}
					}
					else if (isOK == IDCANCEL)
					{
						setbkcolor(RGB(160, 238, 225));
						settextcolor(BLACK);
						settextstyle(20, 0, "����");
						outtextxy(300, 500, "ȡ�������ز���");
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
					settextstyle(20, 0, "����");
					outtextxy(300, 500, "�޷������ز���");
				}
				else
				{
					// �Ȼ�ȡ���ھ��
					HWND hnd = GetHWnd();
					// ������Ϣ���ڣ���ʾ�û�����
					// �����д��ڲ㼶������
					int isOK = MessageBox(GetHWnd(), "���Ƿ���������ĵز���", "ѯ��", MB_OKCANCEL);
					if (isOK == IDOK)
					{
						player.update(this->house);
						setbkcolor(RGB(160, 238, 225));
						settextcolor(BLACK);
						settextstyle(20, 0, "����");
						outtextxy(300, 500, "�������˵ز���");

						//Ȼ����ݸõص��λ�øı䵱ǰ�������ӵ���Ϣ
						// ����Ǳ�������
						if (this->getPositionOfPlace().y == 50)
						{
							string LEVEL = "�ȼ���";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(this->getPositionOfPlace().x, 200, LEVEL.c_str());
						}
						// ����Ƕ�������
						else if (this->getPositionOfPlace().x == 1050)
						{
							string LEVEL = "�ȼ���";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(950, this->getPositionOfPlace().y + 50, LEVEL.c_str());
						}
						// ������ϲ�����
						else if (this->getPositionOfPlace().y == 650)
						{
							string LEVEL = "�ȼ���";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(this->getPositionOfPlace().x, 600, LEVEL.c_str());
						}
						// �������������
						else if (this->getPositionOfPlace().x == 50)
						{
							string LEVEL = "�ȼ���";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(150, this->getPositionOfPlace().y + 50, LEVEL.c_str());
						}

					}
					else if (isOK == IDCANCEL)
					{
						setbkcolor(RGB(160, 238, 225));
						settextcolor(BLACK);
						settextstyle(20, 0, "����");
						outtextxy(300, 500, "ȡ�������ز���");
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
					settextstyle(20, 0, "����");
					outtextxy(300, 500, "�޷������ز���");
				}
				else
				{
					// �Ȼ�ȡ���ھ��
					HWND hnd = GetHWnd();
					// ������Ϣ���ڣ���ʾ�û�����
					// �����д��ڲ㼶������
					int isOK = MessageBox(GetHWnd(), "���Ƿ���������ĵز���", "ѯ��", MB_OKCANCEL);
					if (isOK == IDOK)
					{
						player.update(this->house);
						setbkcolor(RGB(160, 238, 225));
						settextcolor(BLACK);
						settextstyle(20, 0, "����");
						outtextxy(300, 500, "�������˵ز���");

						//Ȼ����ݸõص��λ�øı䵱ǰ�������ӵ���Ϣ
						// ����Ǳ�������
						if (this->getPositionOfPlace().y == 50)
						{
							string LEVEL = "�ȼ���";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(this->getPositionOfPlace().x, 200, LEVEL.c_str());
						}
						// ����Ƕ�������
						else if (this->getPositionOfPlace().x == 1050)
						{
							string LEVEL = "�ȼ���";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(950, this->getPositionOfPlace().y + 50, LEVEL.c_str());
						}
						// ������ϲ�����
						else if (this->getPositionOfPlace().y == 650)
						{
							string LEVEL = "�ȼ���";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(this->getPositionOfPlace().x, 600, LEVEL.c_str());
						}
						// �������������
						else if (this->getPositionOfPlace().x == 50)
						{
							string LEVEL = "�ȼ���";
							LEVEL += to_string(this->getInfoOfHouse().level);
							outtextxy(150, this->getPositionOfPlace().y + 50, LEVEL.c_str());
						}
					}
					else if (isOK == IDCANCEL)
					{
						setbkcolor(RGB(160, 238, 225));
						settextcolor(BLACK);
						settextstyle(20, 0, "����");
						outtextxy(300, 500, "ȡ�������ز���");
					}
				}
				break;
			}
			default:
				break;
			}
		}

		// �������ز���������ҵģ�������Ͻ���·��
		else
		{
			player.setCash(player.getCash() - getInfoOfHouse().price * (getInfoOfHouse().level + 1) / 5);
			string PAYMENT = "���Ͻ���·��";
			int payment = getInfoOfHouse().price * (getInfoOfHouse().level + 1) / 5;
			PAYMENT += to_string(payment);
			setbkcolor(RGB(160, 238, 225));
			settextcolor(BLACK);
			settextstyle(20, 0, "����");
			outtextxy(300, 500, PAYMENT.c_str());
		}
	}
}