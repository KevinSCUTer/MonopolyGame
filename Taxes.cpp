#include "Taxes.h"

Taxes::Taxes(int _positionx, int _positiony)
	:Place(_positionx, _positiony)
{

}

void Taxes::PlaceFunction(Player& player)
{
	// �����֮ǰ����Ϣ
	setbkcolor(RGB(160, 238, 225));
	outtextxy(300, 400, "                             ");
	outtextxy(300, 450, "                             ");
	outtextxy(300, 500, "                               ");
	// ������µ���Ϣ
	setbkcolor(RGB(160, 238, 225));
	settextcolor(BLACK);
	settextstyle(20, 0, "����");
	outtextxy(300, 500, "����������ֽ�10%������˰��");
	player.payTax();
}