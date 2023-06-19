#include "GameManager.h"

GameManager::GameManager()
{
	// 初始化游戏玩家的数组
	Player player1(1, 3000, 50, 50, 0, "player1.jpg");
	playerArray.push_back(player1);
	Player player2(2, 3000, 100, 50, 0, "player2.jpg");
	playerArray.push_back(player2);
	Player player3(3, 3000, 50, 50, 0, "player3.jpg");
	Player player4(4, 3000, 100, 50, 0, "player4.jpg");
	
	// 初始化地点的数组
	//北部地区 10个地点 place0 ~ place9
	Place* place0 = new Bonus (50, 50); // 0号格，起点，加奖金
	placeArray.push_back(place0);
	Place* place1 = new Fates (150, 50); // 1号格，命运
	placeArray.push_back(place1);
	Place* place2 = new Estate(250, 50, 300, 0, -1, 1); //2号格，C类地皮
	placeArray.push_back(place2);
	Place* place3 = new Estate(350, 50, 300, 0, -1, 1); //3号格，C类地皮
	placeArray.push_back(place3);
	Place* place4 = new Chances(450, 50); //4号格，机会
	placeArray.push_back(place4);
	Place* place5 = new Estate(550, 50, 600, 0, -1, 1); //5号格，B类地皮
	placeArray.push_back(place5);
	Place* place6 = new Estate(650, 50, 600, 0, -1, 1); //6号格，B类地皮
	placeArray.push_back(place6);
	Place* place7 = new Estate(750, 50, 1000, 0, -1, 1); //7号格，A类地皮
	placeArray.push_back(place7);
	Place* place8 = new Estate(850, 50, 300, 0, -1, 1); //8号格，C类地皮
	placeArray.push_back(place8);
	Place* place9 = new Chances(950, 50); //9号格，机会
	placeArray.push_back(place9);

	//东部地区 6个地点 place10 ~ place15
	Place* place10 = new Taxes(1050, 50); //10号格，交税
	placeArray.push_back(place10);
	Place* place11 = new Fates(1050, 150); //11号格，命运
	placeArray.push_back(place11);
	Place* place12 = new Estate(1050, 250, 1000, 0, -1, 1); //12号格，A类地皮
	placeArray.push_back(place12);
	Place* place13 = new Estate(1050, 350, 300, 0, -1, 1); //13号格，C类地皮
	placeArray.push_back(place13);
	Place* place14 = new Estate(1050, 450, 600, 0, -1, 1); //14号格，B类地皮
	placeArray.push_back(place14);
	Place* place15 = new Fates(1050, 550); //15号格，命运
	placeArray.push_back(place15);

	//南部地区 10个地点 place16 ~ place25
	Place* place16 = new Bonus(1050, 650); //16号格，奖金
	placeArray.push_back(place16);
	Place* place17 = new Chances(950, 650); //17号格，机会
	placeArray.push_back(place17);
	Place* place18 = new Estate(850, 650, 300, 0, -1, 1); //18号格，C类地皮
	placeArray.push_back(place18);
	Place* place19 = new Estate(750, 650, 600, 0, -1, 1); //19号格，B类地皮
	placeArray.push_back(place19);
	Place* place20 = new Fates(650, 650); //20号格，命运
	placeArray.push_back(place20);
	Place* place21 = new Estate(550, 650, 300, 0, -1, 1); //21号格，C类地皮
	placeArray.push_back(place21);
	Place* place22 = new Estate(450, 650, 1000, 0, -1, 1); //22号格，A类地皮
	placeArray.push_back(place22);
	Place* place23 = new Estate(350, 650, 600, 0, -1, 1); //23号格，B类地皮
	placeArray.push_back(place23);
	Place* place24 = new Estate(250, 650, 300, 0, -1, 1); //24号格，C类地皮
	placeArray.push_back(place24);
	Place* place25 = new Chances(150, 650); //25号格，机会
	placeArray.push_back(place25);

	//西部地区 6个地点 place26 ~ place31
	Place* place26 = new Taxes(50, 650); //26号格，税收
	placeArray.push_back(place26);
	Place* place27 = new Chances(50, 550); //27号格，机会
	placeArray.push_back(place27);
	Place* place28 = new Estate(50, 450, 300, 0, -1, 1); //28号格，C类房产
	placeArray.push_back(place28);
	Place* place29 = new Estate(50, 350, 1000, 0, -1, 1); //29号格，A类房产
	placeArray.push_back(place29);
	Place* place30 = new Estate(50, 250, 300, 0, -1, 1); //30号格，C类房产
	placeArray.push_back(place30);
	Place* place31 = new Fates(50, 150); //31号格，命运
	placeArray.push_back(place31);
}

// 加载骰子的图片
void GameManager::loadDiceImages() {
	loadimage(&dice[0], "RollDice1.jpg");
	loadimage(&dice[1], "RollDice2.jpg");
	loadimage(&dice[2], "RollDice3.jpg");
	loadimage(&dice[3], "RollDice4.jpg");
	loadimage(&dice[4], "RollDice5.jpg");
	loadimage(&dice[5], "RollDice6.jpg");
}

// 绘制骰子的图片
void GameManager::drawDice(int x, int y, int value) {
	putimage(x, y, &dice[value - 1]);
}

// 随机掷骰子，返回结果
int GameManager::rollDice() {
	srand(time(0));
	return rand() % 6 + 1;
}

// 显示骰子的函数
void GameManager::showDice(int value) {
	// 加载骰子的图片
	loadDiceImages();
	
	// 随机掷骰子，并显示结果
	int x = 320 - 40 + 500;
	int y = 240 - 40 + 80;

	do
	{
		// 循环处理鼠标事件，直到用户关闭窗口
		// 等待用户点击鼠标
		if (MouseHit()) {
			MOUSEMSG msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN) {
				// 随机掷骰子，并显示结果
				drawDice(x, y, value);
				break;
			}
		}
	} while (true);
	

}

// 在地图上补充信息，可以优化（优化方法：在设置地点的时候让地点来输出信息）
void GameManager::addInformation()
{
	//手动地在特定的一系列地区输出房产信息
	setbkcolor(RGB(160, 238, 225));
	settextcolor(BLACK);
	settextstyle(18, 0, "宋体");

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
	

	//命运
	setbkcolor(WHITE);
	settextcolor(RED);
	settextstyle(80, 0, "Times New Romans");
	outtextxy(180, 60, "?");
	outtextxy(80, 160, "?");
	outtextxy(680, 660, "?");
	outtextxy(1080, 160, "?");
	outtextxy(1080, 560, "?");

	//机会
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
	closegraph(); //清除原有的屏幕
	initgraph(1200, 800, SHOWCONSOLE);

	setbkcolor(WHITE);
	cleardevice();

	setlinecolor(WHITE);

	int startX = 50; // 地图左上角起始横坐标
	int startY = 50; // 地图左上角起始纵坐标
	int width = 1100; // 地图宽度
	int height = 700; // 地图高度
	int colNum = 11; // 列数
	int rowNum = 7; // 行数

	int lineWidth = 2; // 地图线条宽度

	// 绘制方形地图
	for (int i = 0; i < rowNum; i++) {
		for (int j = 0; j < colNum; j++) {
			int x = startX + j * (width / colNum);
			int y = startY + i * (height / rowNum);
			// 判断是否在最外圈
			if (i == 0 || i == rowNum - 1 || j == 0 || j == colNum - 1) {
				// 绘制浅色矩形
				setfillcolor(WHITE);
				fillrectangle(x, y, x + (width / colNum), y + (height / rowNum));
				// 绘制白色矩形边框
				setlinestyle(PS_SOLID | PS_GEOMETRIC, lineWidth);
				setlinecolor(RGB(160, 238, 225));
				rectangle(x, y, x + (width / colNum), y + (height / rowNum));
			}
			//每一个格子的含义不一样，显示房产信息的函数需要单独拿出来
			else {
				// 绘制浅色矩形
				setfillcolor(RGB(160, 238, 225));
				fillrectangle(x, y, x + (width / colNum), y + (height / rowNum));
				// 绘制浅色边框
				setlinecolor(RGB(160, 238, 225));
				rectangle(x, y, x + (width / colNum), y + (height / rowNum));
			}
		}
	}

	addInformation();

	bool continueGame = true;

	while (continueGame) {

		for (auto iter = playerArray.begin(); iter != playerArray.end(); iter++) {
			
			// 显示当前玩家的信息和对话框。
			putimage(playerArray[0].getPosition().x, playerArray[0].getPosition().y, playerArray[0].playerImage->getwidth(), playerArray[0].playerImage->getheight(), playerArray[0].playerImage, 0, 0);
			putimage(playerArray[1].getPosition().x, playerArray[1].getPosition().y, playerArray[1].playerImage->getwidth(), playerArray[1].playerImage->getheight(), playerArray[1].playerImage, 0, 0);

			setbkcolor(RGB(160, 238, 225));
			settextcolor(BLACK);
			settextstyle(40, 0, "楷体");
			outtextxy(300, 300, "当前玩家:");
			putimage(500, 300, (*iter).playerImage->getwidth(), (*iter).playerImage->getheight(), (*iter).playerImage, 0, 0);
			outtextxy(300, 350, "玩家钱数:");
			outtextxy(500, 350, "          ");
			char Money[20];
			sprintf_s(Money, "%d", (*iter).getCash());
			outtextxy(500, 350, Money);
			settextstyle(40, 0, "楷体");
			outtextxy(300, 400, "请玩家投骰子");
			
			// 首先，玩家投骰子
			int diceNum = rollDice();
			showDice(diceNum);

			// 然后，更新玩家位置
			(*iter).clearPlayer();
			
			int alreadyWalked = (*iter).getTotalPlace();
			(*iter).setTotalPlace(alreadyWalked + diceNum);
			int newSubscriptOfPlace = (*iter).getTotalPlace() % 32;
			
			// 不同的玩家即使在同一个地点也会有不同的位置
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
			
			//执行对应的地点函数
			placeArray[newSubscriptOfPlace]->PlaceFunction((*iter));
			
			//新增，如果玩家到了别人的地盘，那么那个地方的房主将会获得现金
			//这个函数很有可能就是当时越界的函数
			Place* currentPlacePtr = placeArray[newSubscriptOfPlace];
			Estate* estatePtr = dynamic_cast<Estate*>(currentPlacePtr);
			if (estatePtr != nullptr) //如果地点的指针不是空指针的话
			{
				if (estatePtr->getInfoOfHouse()._isEmpty == false && estatePtr->getInfoOfHouse().processor != (*iter).getNumber())
				{
					int fee = estatePtr->getInfoOfHouse().price * (estatePtr->getInfoOfHouse().level + 1) / 5;
					playerArray[estatePtr->getInfoOfHouse().processor - 1].setCash(playerArray[estatePtr->getInfoOfHouse().processor - 1].getCash() + fee);
				}
			}

			//如果执行完相应的函数后，有一个玩家的Money为0，游戏结束
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
	string ENDGAME = "游戏结束，获胜的玩家是：";
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
	// 先获取窗口句柄
	HWND hnd = GetHWnd();
	// 弹出消息窗口，提示用户操作
	int isOK = MessageBox(GetHWnd(), ENDGAME.c_str(), "提示", MB_OK);
	if (isOK == IDOK)
	{
		exit(0);
	}
}

GameManager::~GameManager()
{
	//将所有new出来的内存delete掉
	for (auto iter = placeArray.begin(); iter != placeArray.end(); iter++)
	{
		delete* iter;
	}
}
