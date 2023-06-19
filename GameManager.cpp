#include "GameManager.h"

GameManager::GameManager()
{
	// ��ʼ����Ϸ��ҵ�����
	Player player1(1, 3000, 50, 50, 0, "player1.jpg");
	playerArray.push_back(player1);
	Player player2(2, 3000, 100, 50, 0, "player2.jpg");
	playerArray.push_back(player2);
	Player player3(3, 3000, 50, 50, 0, "player3.jpg");
	Player player4(4, 3000, 100, 50, 0, "player4.jpg");
	
	// ��ʼ���ص������
	//�������� 10���ص� place0 ~ place9
	Place* place0 = new Bonus (50, 50); // 0�Ÿ���㣬�ӽ���
	placeArray.push_back(place0);
	Place* place1 = new Fates (150, 50); // 1�Ÿ�����
	placeArray.push_back(place1);
	Place* place2 = new Estate(250, 50, 300, 0, -1, 1); //2�Ÿ�C���Ƥ
	placeArray.push_back(place2);
	Place* place3 = new Estate(350, 50, 300, 0, -1, 1); //3�Ÿ�C���Ƥ
	placeArray.push_back(place3);
	Place* place4 = new Chances(450, 50); //4�Ÿ񣬻���
	placeArray.push_back(place4);
	Place* place5 = new Estate(550, 50, 600, 0, -1, 1); //5�Ÿ�B���Ƥ
	placeArray.push_back(place5);
	Place* place6 = new Estate(650, 50, 600, 0, -1, 1); //6�Ÿ�B���Ƥ
	placeArray.push_back(place6);
	Place* place7 = new Estate(750, 50, 1000, 0, -1, 1); //7�Ÿ�A���Ƥ
	placeArray.push_back(place7);
	Place* place8 = new Estate(850, 50, 300, 0, -1, 1); //8�Ÿ�C���Ƥ
	placeArray.push_back(place8);
	Place* place9 = new Chances(950, 50); //9�Ÿ񣬻���
	placeArray.push_back(place9);

	//�������� 6���ص� place10 ~ place15
	Place* place10 = new Taxes(1050, 50); //10�Ÿ񣬽�˰
	placeArray.push_back(place10);
	Place* place11 = new Fates(1050, 150); //11�Ÿ�����
	placeArray.push_back(place11);
	Place* place12 = new Estate(1050, 250, 1000, 0, -1, 1); //12�Ÿ�A���Ƥ
	placeArray.push_back(place12);
	Place* place13 = new Estate(1050, 350, 300, 0, -1, 1); //13�Ÿ�C���Ƥ
	placeArray.push_back(place13);
	Place* place14 = new Estate(1050, 450, 600, 0, -1, 1); //14�Ÿ�B���Ƥ
	placeArray.push_back(place14);
	Place* place15 = new Fates(1050, 550); //15�Ÿ�����
	placeArray.push_back(place15);

	//�ϲ����� 10���ص� place16 ~ place25
	Place* place16 = new Bonus(1050, 650); //16�Ÿ񣬽���
	placeArray.push_back(place16);
	Place* place17 = new Chances(950, 650); //17�Ÿ񣬻���
	placeArray.push_back(place17);
	Place* place18 = new Estate(850, 650, 300, 0, -1, 1); //18�Ÿ�C���Ƥ
	placeArray.push_back(place18);
	Place* place19 = new Estate(750, 650, 600, 0, -1, 1); //19�Ÿ�B���Ƥ
	placeArray.push_back(place19);
	Place* place20 = new Fates(650, 650); //20�Ÿ�����
	placeArray.push_back(place20);
	Place* place21 = new Estate(550, 650, 300, 0, -1, 1); //21�Ÿ�C���Ƥ
	placeArray.push_back(place21);
	Place* place22 = new Estate(450, 650, 1000, 0, -1, 1); //22�Ÿ�A���Ƥ
	placeArray.push_back(place22);
	Place* place23 = new Estate(350, 650, 600, 0, -1, 1); //23�Ÿ�B���Ƥ
	placeArray.push_back(place23);
	Place* place24 = new Estate(250, 650, 300, 0, -1, 1); //24�Ÿ�C���Ƥ
	placeArray.push_back(place24);
	Place* place25 = new Chances(150, 650); //25�Ÿ񣬻���
	placeArray.push_back(place25);

	//�������� 6���ص� place26 ~ place31
	Place* place26 = new Taxes(50, 650); //26�Ÿ�˰��
	placeArray.push_back(place26);
	Place* place27 = new Chances(50, 550); //27�Ÿ񣬻���
	placeArray.push_back(place27);
	Place* place28 = new Estate(50, 450, 300, 0, -1, 1); //28�Ÿ�C�෿��
	placeArray.push_back(place28);
	Place* place29 = new Estate(50, 350, 1000, 0, -1, 1); //29�Ÿ�A�෿��
	placeArray.push_back(place29);
	Place* place30 = new Estate(50, 250, 300, 0, -1, 1); //30�Ÿ�C�෿��
	placeArray.push_back(place30);
	Place* place31 = new Fates(50, 150); //31�Ÿ�����
	placeArray.push_back(place31);
}

// �������ӵ�ͼƬ
void GameManager::loadDiceImages() {
	loadimage(&dice[0], "RollDice1.jpg");
	loadimage(&dice[1], "RollDice2.jpg");
	loadimage(&dice[2], "RollDice3.jpg");
	loadimage(&dice[3], "RollDice4.jpg");
	loadimage(&dice[4], "RollDice5.jpg");
	loadimage(&dice[5], "RollDice6.jpg");
}

// �������ӵ�ͼƬ
void GameManager::drawDice(int x, int y, int value) {
	putimage(x, y, &dice[value - 1]);
}

// ��������ӣ����ؽ��
int GameManager::rollDice() {
	srand(time(0));
	return rand() % 6 + 1;
}

// ��ʾ���ӵĺ���
void GameManager::showDice(int value) {
	// �������ӵ�ͼƬ
	loadDiceImages();
	
	// ��������ӣ�����ʾ���
	int x = 320 - 40 + 500;
	int y = 240 - 40 + 80;

	do
	{
		// ѭ����������¼���ֱ���û��رմ���
		// �ȴ��û�������
		if (MouseHit()) {
			MOUSEMSG msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN) {
				// ��������ӣ�����ʾ���
				drawDice(x, y, value);
				break;
			}
		}
	} while (true);
	

}

// �ڵ�ͼ�ϲ�����Ϣ�������Ż����Ż������������õص��ʱ���õص��������Ϣ��
void GameManager::addInformation()
{
	//�ֶ������ض���һϵ�е������������Ϣ
	setbkcolor(RGB(160, 238, 225));
	settextcolor(BLACK);
	settextstyle(18, 0, "����");

	outtextxy(250, 160, "300$");
	
	outtextxy(350, 160, "300$");
	
	outtextxy(550, 160, "600$");

	outtextxy(650, 160, "600$");
	
	outtextxy(750, 160, "1000$");

	outtextxy(850, 160, "300$");

	outtextxy(950, 260, "1000$");
	
	outtextxy(950, 360, "300$");
	
	outtextxy(950, 460, "600$");
	
	outtextxy(850, 560, "300$");
	
	outtextxy(750, 560, "600$");
	
	outtextxy(550, 560, "300$");
	
	outtextxy(450, 560, "1000$");

	outtextxy(350, 560, "600$");

	outtextxy(250, 560, "300$");

	outtextxy(150, 460, "300$");

	outtextxy(150, 360, "1000$");

	outtextxy(150, 260, "300$");
	

	//����
	setbkcolor(WHITE);
	settextcolor(RED);
	settextstyle(80, 0, "Times New Romans");
	outtextxy(180, 60, "?");
	outtextxy(80, 160, "?");
	outtextxy(680, 660, "?");
	outtextxy(1080, 160, "?");
	outtextxy(1080, 560, "?");

	//����
	setbkcolor(WHITE);
	settextcolor(RGB(225, 180, 0));
	settextstyle(80, 0, "Times New Romans");
	outtextxy(480, 60, "!");
	outtextxy(980, 60, "!");
	outtextxy(980, 660, "!");
	outtextxy(180, 660, "!");
	outtextxy(80, 560, "!");

	setbkcolor(WHITE);
	settextcolor(RGB(225, 118, 128));
	settextstyle(55, 0, "Arial Black");
	outtextxy(1055, 75, "TAX");
	outtextxy(50, 675, "TAX");
}


void GameManager::playGames()
{
	cleardevice();
	closegraph(); //���ԭ�е���Ļ
	initgraph(1200, 800, SHOWCONSOLE);

	setbkcolor(WHITE);
	cleardevice();

	setlinecolor(WHITE);

	int startX = 50; // ��ͼ���Ͻ���ʼ������
	int startY = 50; // ��ͼ���Ͻ���ʼ������
	int width = 1100; // ��ͼ���
	int height = 700; // ��ͼ�߶�
	int colNum = 11; // ����
	int rowNum = 7; // ����

	int lineWidth = 2; // ��ͼ�������

	// ���Ʒ��ε�ͼ
	for (int i = 0; i < rowNum; i++) {
		for (int j = 0; j < colNum; j++) {
			int x = startX + j * (width / colNum);
			int y = startY + i * (height / rowNum);
			// �ж��Ƿ�������Ȧ
			if (i == 0 || i == rowNum - 1 || j == 0 || j == colNum - 1) {
				// ����ǳɫ����
				setfillcolor(WHITE);
				fillrectangle(x, y, x + (width / colNum), y + (height / rowNum));
				// ���ư�ɫ���α߿�
				setlinestyle(PS_SOLID | PS_GEOMETRIC, lineWidth);
				setlinecolor(RGB(160, 238, 225));
				rectangle(x, y, x + (width / colNum), y + (height / rowNum));
			}
			//ÿһ�����ӵĺ��岻һ������ʾ������Ϣ�ĺ�����Ҫ�����ó���
			else {
				// ����ǳɫ����
				setfillcolor(RGB(160, 238, 225));
				fillrectangle(x, y, x + (width / colNum), y + (height / rowNum));
				// ����ǳɫ�߿�
				setlinecolor(RGB(160, 238, 225));
				rectangle(x, y, x + (width / colNum), y + (height / rowNum));
			}
		}
	}

	addInformation();

	bool continueGame = true;

	while (continueGame) {

		for (auto iter = playerArray.begin(); iter != playerArray.end(); iter++) {
			
			// ��ʾ��ǰ��ҵ���Ϣ�ͶԻ���
			putimage(playerArray[0].getPosition().x, playerArray[0].getPosition().y, playerArray[0].playerImage->getwidth(), playerArray[0].playerImage->getheight(), playerArray[0].playerImage, 0, 0);
			putimage(playerArray[1].getPosition().x, playerArray[1].getPosition().y, playerArray[1].playerImage->getwidth(), playerArray[1].playerImage->getheight(), playerArray[1].playerImage, 0, 0);

			setbkcolor(RGB(160, 238, 225));
			settextcolor(BLACK);
			settextstyle(40, 0, "����");
			outtextxy(300, 300, "��ǰ���:");
			putimage(500, 300, (*iter).playerImage->getwidth(), (*iter).playerImage->getheight(), (*iter).playerImage, 0, 0);
			outtextxy(300, 350, "���Ǯ��:");
			outtextxy(500, 350, "          ");
			char Money[20];
			sprintf_s(Money, "%d", (*iter).getCash());
			outtextxy(500, 350, Money);
			settextstyle(40, 0, "����");
			outtextxy(300, 400, "�����Ͷ����");
			
			// ���ȣ����Ͷ����
			int diceNum = rollDice();
			showDice(diceNum);

			// Ȼ�󣬸������λ��
			(*iter).clearPlayer();
			
			int alreadyWalked = (*iter).getTotalPlace();
			(*iter).setTotalPlace(alreadyWalked + diceNum);
			int newSubscriptOfPlace = (*iter).getTotalPlace() % 32;
			
			// ��ͬ����Ҽ�ʹ��ͬһ���ص�Ҳ���в�ͬ��λ��
			int newX, newY;
			switch ((*iter).getNumber())
			{
			case 1:
				newX = placeArray[newSubscriptOfPlace]->getPositionOfPlace().x;
				newY = placeArray[newSubscriptOfPlace]->getPositionOfPlace().y;
				(*iter).setPosition(newX, newY);
				putimage(newX, newY, (*iter).playerImage);
				break;
			case 2:
				newX = placeArray[newSubscriptOfPlace]->getPositionOfPlace().x + 50;
				newY = placeArray[newSubscriptOfPlace]->getPositionOfPlace().y;
				(*iter).setPosition(newX, newY);
				putimage(newX, newY, (*iter).playerImage);
				break;
			case 3:
				newX = placeArray[newSubscriptOfPlace]->getPositionOfPlace().x;
				newY = placeArray[newSubscriptOfPlace]->getPositionOfPlace().y + 50;
				(*iter).setPosition(newX, newY);
				putimage(newX, newY, (*iter).playerImage);
				break;
			case 4:
				newX = placeArray[newSubscriptOfPlace]->getPositionOfPlace().x + 50;
				newY = placeArray[newSubscriptOfPlace]->getPositionOfPlace().y + 50;
				(*iter).setPosition(newX, newY);
				putimage(newX, newY, (*iter).playerImage);
				break;
			default:
				break;
			}
			
			//ִ�ж�Ӧ�ĵص㺯��
			placeArray[newSubscriptOfPlace]->PlaceFunction((*iter));
			
			//�����������ҵ��˱��˵ĵ��̣���ô�Ǹ��ط��ķ����������ֽ�
			//����������п��ܾ��ǵ�ʱԽ��ĺ���
			Place* currentPlacePtr = placeArray[newSubscriptOfPlace];
			Estate* estatePtr = dynamic_cast<Estate*>(currentPlacePtr);
			if (estatePtr != nullptr) //����ص��ָ�벻�ǿ�ָ��Ļ�
			{
				if (estatePtr->getInfoOfHouse()._isEmpty == false && estatePtr->getInfoOfHouse().processor != (*iter).getNumber())
				{
					int fee = estatePtr->getInfoOfHouse().price * (estatePtr->getInfoOfHouse().level + 1) / 5;
					playerArray[estatePtr->getInfoOfHouse().processor - 1].setCash(playerArray[estatePtr->getInfoOfHouse().processor - 1].getCash() + fee);
				}
			}

			//���ִ������Ӧ�ĺ�������һ����ҵ�MoneyΪ0����Ϸ����
			if ((*iter).getCash() < 0)
			{
				continueGame = false;
				break;
			}

			Sleep(3000);
		}
	}
	endGame();

	getchar();
}

void GameManager::endGame()
{
	string ENDGAME = "��Ϸ��������ʤ������ǣ�";
	int max = -9999;
	int winner = 0;
	for (auto iter = playerArray.begin(); iter != playerArray.end(); iter++)
	{
		if ((*iter).getCash() > max)
		{
			max = (*iter).getCash();
			winner = (*iter).getNumber();
		}
	}
	ENDGAME += to_string(winner);
	// �Ȼ�ȡ���ھ��
	HWND hnd = GetHWnd();
	// ������Ϣ���ڣ���ʾ�û�����
	int isOK = MessageBox(GetHWnd(), ENDGAME.c_str(), "��ʾ", MB_OK);
	if (isOK == IDOK)
	{
		exit(0);
	}
}

GameManager::~GameManager()
{
	//������new�������ڴ�delete��
	for (auto iter = placeArray.begin(); iter != placeArray.end(); iter++)
	{
		delete* iter;
	}
}
