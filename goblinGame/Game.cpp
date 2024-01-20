#include "Game.h"

void Game::loadingScene(Game* game)
{
	while (true)
	{
		game->gotoXY(60, 10);
		cout << "LOADING.." << endl;
		game->gotoXY(60, 12);
		cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
		game->printLine("������������������", 60, 12, 60);
		return;
	}
}

void Game::init(inventory* inven)
{
	system("cls");
	gotoXY(60, 1);
	cout << "===========���Ű������===========" << endl;
	if (chapter[0] == true)
	{
		gotoXY(60, 3);
		cout << "1.é��1:�뿹�ع�" << endl;
		gotoXY(60, 5);
		cout << "2.����(é��1 ���� �ر�)" << endl;
		gotoXY(60, 7);
		cout << "3.�κ��丮(�������Ž� �ر�)" << endl;
	}
	else if(chapter[1]==true)
	{
		gotoXY(60, 3);
		cout << "1.é��2:���� �뿹���� ������" << endl;
		gotoXY(60, 5);
		cout << "2.����" << endl;
		if (inven->IsInventoryOpen)
		{
			gotoXY(60, 7);
			cout << "3.�κ��丮" << endl;
		}
		else
		{
			gotoXY(60, 7);
			cout << "3.�κ��丮(�������Ž� �ر�)" << endl;
		}
	}
	else if (chapter[2] == true)
	{
		gotoXY(60, 3);
		cout << "1.é��3:Ž�彺���� �뺴" << endl;
		gotoXY(60, 5);
		cout << "2.����" << endl;
		if (inven->IsInventoryOpen)
		{
			gotoXY(60, 7);
			cout << "3.�κ��丮" << endl;
		}
		else
		{
			gotoXY(60, 7);
			cout << "3.�κ��丮(�������Ž� �ر�)" << endl;
		}
	}
	else if (chapter[3] == true)
	{
		gotoXY(60, 3);
		cout << "1.é��4:������ ���" << endl;
		gotoXY(60, 5);
		cout << "2.����" << endl;
		if (inven->IsInventoryOpen)
		{
			gotoXY(60, 7);
			cout << "3.�κ��丮" << endl;
		}
		else
		{
			gotoXY(60, 7);
			cout << "3.�κ��丮(�������Ž� �ر�)" << endl;
		}
	}
	else if (chapter[4] == true)
	{
		gotoXY(60, 3);
		cout << "����ϼ̽��ϴ�." << endl;
		gotoXY(60, 5);
		cout << "�������Դϴ�." << endl;
		Sleep(1000);
		return;
	}

	gotoXY(60, 9);
	cout << "4.EXIT" << endl;

	gotoXY(60, 11);
	cout << "���� :";
}

void Game::selectItem(string situation)
{
	system("cls");
	gotoXY(60, 0);
	cout << "=========="<< situation<<"=========="<< endl;
	gotoXY(60, 2);
	cout << "1.����" << endl;
	gotoXY(60, 4);
	cout << "2.��" << endl;
	gotoXY(60, 6);
	cout << "����(������ 4��) :";
}
void Game::printInventory(Store* store,player* _player,int input)
{
	system("cls");
	for (int i = 0; i < store->vItem.size(); ++i)
	{
		if (input == store->vItem[i].type)
		{
			store->vItem[i].printItem();
		}
	}
	cout << "������ �ִ� �� :" << _player->money << endl;
	cout << "� �������� ��ðڽ��ϱ�??" << endl;
	cout << "���� :";
}

//void Game::choiceSkill(Skill* skill)
//{
//	skill->printSkills();
//}
void Game::PrintStoreItme(Store* store,player* _player,int input)
{
	system("cls");
	for (int i = 0; i < store->vItem.size(); ++i)
	{
		if (input == store->vItem[i].type)
		{
			gotoXY(60, 0);
			store->vItem[i].printItem();
		}
	}
	cout << "������ �ִ� �� :" << _player->money << endl;
}


void Game::QuitChapter(Game* game,int input)
{
	game->chapter[input] = false;
}
void Game::EnterChapter(Game* game, int input)
{
	game->chapter[input] = true;
}
void Game::ChapterClear(Game* game, int input)
{
	game->chapterClear[input] = true;
}


void Game::shieldON(Skill* skill)
{
	skill->isShield = true;
}
void Game::shieldoff(Skill* skill)
{
	skill->isShield = false;
}

void::Game::playerCriticalSituation(Skill* skill, enemy* _enemy,player* _player, int randomCriticalDamage, int& turn)
{
	gotoXY(55, 12);
	cout << "�÷��̾ " << skill->EquipSkills[0].name << "�� ����ߴ�." << endl;
	gotoXY(55, 14);
	cout << _enemy->name << "�� " << randomCriticalDamage << " �� ũ��Ƽ�� �������� �Ծ���." << endl;
	gotoXY(55, 16);
	_enemy->currentHp -= randomCriticalDamage ;
	turn++;
	Sleep(1000);
}
void::Game::playerNormalAttackSituation(Skill* skill, enemy* _enemy,player* _player, int randomDamage, int& turn)
{
	gotoXY(55, 12);
	cout << "�÷��̾ " << skill->EquipSkills[0].name << "�� ����ߴ�." << endl;
	gotoXY(55, 14);
	cout << _enemy->name << "�� " << randomDamage << "�� �������� �Ծ���." << endl;
	gotoXY(55, 16);
	_enemy->currentHp -= randomDamage ;
	turn++;
	Sleep(1000);
}
void::Game::playerSheildSituation(Skill* skill, player* _player, int& turn)
{
	gotoXY(55, 12);
	cout << "�÷��̾ " << skill->EquipSkills[1].name << "�� ����ߴ�." << endl;
	gotoXY(55, 14);
	cout << "�÷��̾ ������ " << skill->EquipSkills[1].defence*_player->defence << " ��ŭ �����." << endl;
	gotoXY(55, 16);
	turn++;
	Sleep(1000);
}
void::Game::EnemyAttackSituation(Skill* skill, int EnemyTotaldamaged,int& turn,player* _player)
{
	gotoXY(55, 12);
	cout << "�÷��̾ " << EnemyTotaldamaged << "�� �������� �޾Ҵ�." << endl;
	gotoXY(55, 14);
	cout << "(ö�� " << skill->skills[5].defence << " ����)" << endl;
	gotoXY(55, 16);
	_player->currentHp -= EnemyTotaldamaged;
	if (_player->currentHp > _player->hp)
	{
		_player->currentHp = _player->hp;
	}
	turn++;
	Sleep(1000);
}

void Game::printChapter1Start()
{
	int x = 53;
	int y = 10;
	system("cls");
	for (int i = 0; i < printChapter1.size(); ++i)
	{
		printLine(printChapter1[i], x, i+y, 80);
		y += 2;
		while (_kbhit())  // Ű �Է��� �ִ� ���� �ݺ�
		{
			char input = _getch();
			if (input == 32)  // �����̽��ٸ� ������
			{
				y = 10;
				system("cls");
				for (int i = 0; i < printChapter1.size(); ++i)
				{
					gotoXY(x, y);
					cout << printChapter1[i] << endl;
					y+=3;
				}
				gotoXY(x+10, y+3);
				cout << "==   PRESS SPACEBAR   ==" << endl;
				while (true)
				{
					char key = _getch();
					if (key == 32)
					{
						Sleep(1000);
						return;
					}
				}
				Sleep(1000);
				return;  // �ݺ����� ���������� �Լ� ����
			}
			else
			{
				continue;
			}
		}
	}
}
void Game::EnemyDead(Game* game, enemy* _enemy,player* _player, Skill* skill,int chapter1,int chapter2)
{
	int randomMoney=0;
	if (_enemy->chapterType == static_cast<int>(CHAPTERTYPE::ONE))
	{
		randomMoney = rand() % 3000 + 500;
		_player->money += randomMoney;
	}
	else if (_enemy->chapterType == static_cast<int>(CHAPTERTYPE::TWO))
	{
		randomMoney = rand() % 5000 + 2000;
		_player->money += randomMoney;
	}
	else if (_enemy->chapterType == static_cast<int>(CHAPTERTYPE::THREE))
	{
		randomMoney = rand() % 10000 + 5000;
		_player->money += randomMoney;
	}
	else if (_enemy->chapterType == static_cast<int>(CHAPTERTYPE::FOUR))
	{
		randomMoney = rand() % 20000 + 10000;
		_player->money += randomMoney;
	}
	system("cls");
	gotoXY(65, 2);
	cout << "���� ����߽��ϴ�." << endl;
	cout << endl;
	gotoXY(65, 4);
	cout <<randomMoney <<"���� ȹ���ϼ̽��ϴ�."<<endl;
	gotoXY(65, 6);
	cout << "���� ������ �ִµ� : " << _player->money << "��" << endl;
	game->turn = 1;
	game->QuitChapter(game, chapter1);
	game->ChapterClear(game, chapter1);
	game->EnterChapter(game, chapter2);
	game->ChoiceSkills(skill);
	delete _enemy;
	Sleep(1000);
}
void Game::PlayerDead(Game* game, enemy* _enemy, int chapter1)
{
	system("cls");
	gotoXY(65, 10);
	cout << "����߾�..." << endl;
	gotoXY(65, 12);
	cout << "�ٽ� �����غ���!" << endl;
	game->turn = 1;
	game->EnterChapter(game, chapter1);
	delete _enemy;
	Sleep(1500);
}



void Game::printChapter2Start()
{
	int x = 53;
	int y = 10;
	system("cls");
	for (int i = 0; i < printChapter2.size(); ++i)
	{
		printLine(printChapter2[i], x, i + y, 80);
		y += 2;
		while (_kbhit())  // Ű �Է��� �ִ� ���� �ݺ�
		{
			char input = _getch();
			if (input == 32)  // �����̽��ٸ� ������
			{
				y = 10;
				system("cls");
				for (int i = 0; i < printChapter2.size(); ++i)
				{
					gotoXY(x, y);
					cout << printChapter2[i] << endl;
					y += 3;
				}
				gotoXY(x + 10, y + 3);
				cout << "==   PRESS SPACEBAR   ==" << endl;
				while (true)
				{
					char key = _getch();
					if (key == 32)
					{
						Sleep(1000);
						return;
					}
				}
				Sleep(1000);
				return;  // �ݺ����� ���������� �Լ� ����
			}
			else
			{
				continue;
			}
		}
	}
}
void Game::printChapter3Start()
{
	int x = 53;
	int y = 10;
	system("cls");
	for (int i = 0; i < printChapter3.size(); ++i)
	{
		printLine(printChapter3[i], x, i + y, 80);
		y += 2;
		while (_kbhit())  // Ű �Է��� �ִ� ���� �ݺ�
		{
			char input = _getch();
			if (input == 32)  // �����̽��ٸ� ������
			{
				y = 10;
				system("cls");
				for (int i = 0; i < printChapter3.size(); ++i)
				{
					gotoXY(x, y);
					cout << printChapter3[i] << endl;
					y += 3;
				}
				gotoXY(x + 10, y + 3);
				cout << "==   PRESS SPACEBAR   ==" << endl;
				while (true)
				{
					char key = _getch();
					if (key == 32)
					{
						Sleep(1000);
						return;
					}
				}
				Sleep(1000);
				return;  // �ݺ����� ���������� �Լ� ����
			}
			else
			{
				continue;
			}
		}
	}
}

void Game::printChapter4Start()
{
	int x = 53;
	int y = 10;
	system("cls");
	for (int i = 0; i < printChapter4.size(); ++i)
	{
		printLine(printChapter4[i], x, i + y, 80);
		y += 2;
		while (_kbhit())  // Ű �Է��� �ִ� ���� �ݺ�
		{
			char input = _getch();
			if (input == 32)  // �����̽��ٸ� ������
			{
				y = 10;
				system("cls");
				for (int i = 0; i < printChapter4.size(); ++i)
				{
					gotoXY(x, y);
					cout << printChapter4[i] << endl;
					y += 3;
				}
				gotoXY(x + 10, y + 3);
				cout << "==   PRESS SPACEBAR   ==" << endl;
				while (true)
				{
					char key = _getch();
					if (key == 32)
					{
						Sleep(1000);
						return;
					}
				}
				Sleep(1000);
				return;  // �ݺ����� ���������� �Լ� ����
			}
			else
			{
				continue;
			}
		}
	}
}


Game::Game()
{
	//é��1 
	printChapter1.push_back("���� ���... �Ϸ��Ϸ簡 �������������̴�.");
	printChapter1.push_back("�ΰ����� �Ϸ絵 �ִ��ϰ� ���� ���⸦ ���¥����.");
	printChapter1.push_back("��... ������ �� ��Ȳ�� �����������?");
	printChapter1.push_back("��½!!!");
	printChapter1.push_back("���Ծ� ���ฮ�� ���ะ ���� ���� Ȱ���� �굹�� �����ߴ�.");
	printChapter1.push_back("�ʿ��� ���� �ָ�... �ʸ� ���Ӱ� �ϴ� �ΰ����� �� �׿���");
	printChapter1.push_back("����� ���� �¾���� ���� ������ ���� �ö���.");
	printChapter1.push_back("���� �� ���̴� �ΰ��� ���� ��ƾ߰ھ�...");
	//é��2
	printChapter2.push_back("����� óġ�ϰ� �������� ���� �����.");
	printChapter2.push_back("������ �� ������ �ʾ� �Ǹ��������� ä���� ������ �ִ� ����� ������.");
	printChapter2.push_back("�̷� ���������� ��!! ��� ����ĥ����");
	printChapter2.push_back("����� ������ ������ ä���ڱ��� �־���.");
	printChapter2.push_back("�ٷ� ���� ������ ������ ä������ ���ߴ�.");
	printChapter2.push_back("�뼭���� ���Ѵ�...");
	printChapter2.push_back("�� ���� ������ ������ ����?");
	//é��3
	printChapter3.push_back("�Ǵ������� �뿹������ �ᱹ �׿���...");
	printChapter3.push_back("���� ���� ���̿���..");
	printChapter3.push_back("�̷� �뿡������ ������� Ȱ���� ��ġ�°� �뺴�����̴�,");
	printChapter3.push_back("������ ������ �� �뺴�� �� ã�ƾ� �ھ�..");
	printChapter3.push_back("�׷��� ���� �뺴�� ���� �ִ� �� ������ ã�ư���.");
	printChapter3.push_back("������ ���� �ͼ��� ���� �޺��� �޾� ��¦�ŷȴ�.");
	printChapter3.push_back("�ٷ� �����̴�..(����)");
	//é��4
	printChapter4.push_back("�� �뺴���� ���� ���ؼ� ������ �Ͽ���..");
	printChapter4.push_back("���� ó���ϰ� ����� ������ ������ ���� �����̴�.");
	printChapter4.push_back("������ �ɷµ� �ְ� ����� �»갡ġ�� �ִٰ� �����Ѵ�.");
	printChapter4.push_back("���� ���� �ٿԴ�.. ���� ��Ƽ� ������ ���� ������ ��������");
	printChapter4.push_back("������ ������ ���� ������ ������ ���� ��簡 ��Ÿ����.");
	printChapter4.push_back("�� ������ ��Ƽ��...");


}

Game::~Game()
{
}
void Game::StartGame()
{
	system("mode.com con:cols=160 lines=50");
	srand(static_cast<unsigned int>(time(NULL)));

	Item* item = new Item;
	Store* store = new Store;
	inventory* inven = new inventory;
	player* _player = new player;
	Skill* skill = new Skill(_player);
	Game* game = new Game;
	int input;

	game->loadingScene(game);
	while (true)
	{
		PlaySound(TEXT("bgm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//���� ���
		game->init(inven);
		if (game->chapter[4]) return;
		cin >> input;
		if (input == static_cast<int>(Choice::ADVENTURE))
		{
			PlaySound(TEXT("battle.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//���� ���
			if (game->chapter[0])//é�� 1
			{
				game->printChapter1Start();
				system("cls");
				skill->initSkills();// �⺻ ��ų 2�� ȹ��
				game->printAttackPicture(50, 0);
				game->printShieldPicture(80, 0);
				game->gotoXY(0, 12);
				cout << "==   PRESS SPACEBAR   ==" << endl;
				game->gotoXY(50, 12);
				cout << "����(" << skill->skills[0].currentSkill << "Lv)";
				game->gotoXY(80, 12);
				cout << "���и���(" << skill->skills[4].currentSkill << "Lv)";
				game->gotoXY(0, 14);
				while (true)
				{
					if (_kbhit())
					{
						char key;
						key = _getch();
						if (key == 32)
						{
							cout << "��ų�� ȹ���ϼ̽��ϴ�." << endl;
							cout << endl;
							Sleep(1000);
							cout << skill->skills[5].name << " Ư���� �߰� �˴ϴ�. (ö�� + Lv 2 , �������� ������ �߰�����)" << endl;
							skill->skills[5].defence += 2;
							skill->skills[5].currentSkill;
							Sleep(1000);
							break;
						}
						else
						{
							continue;
						}
					}
				}
				enemy* farmer = new enemy;
				farmer->settingState("������ ���� ���", 70, 70, 20, 9, 5, static_cast<int>(CHAPTERTYPE::ONE));
				Sleep(1000);
				while (game->chapter[0])
				{
					if (farmer->currentHp <= 0)
					{
						game->EnemyDead(game, farmer, _player, skill, 0, 1);
						break;
					}
					if (_player->currentHp <= 0)
					{
						game->PlayerDead(game, farmer, 0);
						break;
					}
					system("cls");
					int randomNarration = rand() % 4;
					int randomAttackNarration = randomNarration;
					game->printEnemy(farmer);
					game->printPlayer(_player);
					game->printSkills(skill);
					game->inGame(farmer, skill, _player, game, randomAttackNarration, randomNarration, 0, 1);
				}
			}
			else if (game->chapter[1])//é�� 2
			{
				_player->currentHp = 170;
				game->printChapter2Start();
				enemy* SlaveTrader = new enemy;
				SlaveTrader->settingState("�뿹����", 150, 150, 25, 10, 7, static_cast<int>(CHAPTERTYPE::TWO));
				while (game->chapter[1])
				{
					if (SlaveTrader->currentHp <= 0)
					{
						game->EnemyDead(game, SlaveTrader, _player, skill, 1, 2);
						break;
					}
					if (_player->currentHp <= 0)
					{
						game->PlayerDead(game, SlaveTrader, 1);
						break;
					}
					system("cls");
					int randomNarration = rand() % 4;
					int randomAttackNarration = randomNarration;
					game->printEnemy(SlaveTrader);
					game->printPlayer(_player);
					game->printSkills(skill);
					game->inGame(SlaveTrader, skill, _player, game, randomAttackNarration, randomNarration, 1, 2);
				}
			}
			else if (game->chapter[2])//é�� 3
			{
				_player->currentHp = 170;
				game->printChapter3Start();
				enemy* Mercenary = new enemy;
				Mercenary->settingState("Ž�彺���� �뺴", 250, 250, 35, 20, 10, static_cast<int>(CHAPTERTYPE::THREE));
				while (game->chapter[2])
				{
					if (Mercenary->currentHp <= 0)
					{
						game->EnemyDead(game, Mercenary, _player, skill, 2, 3);
						break;
					}
					if (_player->currentHp <= 0)
					{
						game->PlayerDead(game, Mercenary, 2);
						break;
					}
					system("cls");
					int randomNarration = rand() % 4;
					int randomAttackNarration = randomNarration;
					game->printEnemy(Mercenary);
					game->printPlayer(_player);
					game->printSkills(skill);
					game->inGame(Mercenary, skill, _player, game, randomAttackNarration, randomNarration, 1, 2);
				}
			}
			else if (game->chapter[3])//é�� 4 ����
			{
				_player->currentHp = 170;
				game->printChapter4Start();
				enemy* knight = new enemy;
				knight->settingState("â���", 500, 500, 60, 25, 15, static_cast<int>(CHAPTERTYPE::FOUR));
				while (game->chapter[3])
				{
					if (knight->currentHp <= 0)
					{
						game->EnemyDead(game, knight, _player, skill, 3, 4);
						break;
					}
					if (_player->currentHp <= 0)
					{
						game->PlayerDead(game, knight, 3);
						break;
					}
					system("cls");
					int randomNarration = rand() % 4;
					int randomAttackNarration = randomNarration;
					game->printEnemy(knight);
					game->printPlayer(_player);
					game->printSkills(skill);
					game->inGame(knight, skill, _player, game, randomAttackNarration, randomNarration, 1, 2);
				}
			}
		}
		else if (input == static_cast<int>(Choice::STORE) && game->chapterClear[0] == true)//����
		{

			while (true)
			{
				game->selectItem("����");
				cin >> input;
				if (input == static_cast<int>(TYPE::WEAPON))
				{
					game->printInventory(store, _player, input);
					cin >> input;
					store->addBuyItem(inven, _player, input, static_cast<int>(TYPE::WEAPON));
				}
				else if (input == static_cast<int>(TYPE::ARMOR))
				{
					game->printInventory(store, _player, input);
					cin >> input;
					store->addBuyItem(inven, _player, input, static_cast<int>(TYPE::ARMOR));
				}
				else if (input == static_cast<int>(Choice::EXIT))
				{
					break;
				}
				else
				{
					continue;
				}
			}
		}
		else if (input == static_cast<int>(Choice::INVENTORY) && game->chapterClear[0] && inven->IsInventoryOpen)//�κ��丮
		{
			while (true)
			{
				game->selectItem("�κ��丮");
				cin >> input;//���� , �� , ���� ����
				if (input == 4) break;
				if (input > 2 && input<4) continue;
				inven->printInventory(input, _player);
			}
		}
		else if (input == static_cast<int>(Choice::EXIT))//������
		{
			break;
		}
		else
		{
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			continue;
		}
	}










}


void Game::inGame(enemy* _enemy,Skill* skill,player* _player,Game* game,int randomAttackNarration, int randomNarration,int chapter1,int chapter2)
{
	int input;
	if (_player->currentHp <= 0)
	{
		system("cls");
		cout << "���..." << endl;
		turn = 1;
		EnterChapter(game, chapter1);
		delete _enemy;
		Sleep(1000);
		return;
	}
	
	
	if (turn % 2 != 0)//�÷��̾� ��
	{
		while (true)
		{
			_player->IsCounterattack = false;
			skill->isShield = false;
			gotoXY(55, 1);
			cout << "�÷��̾� ��" << endl;
			gotoXY(55, 10);
			_enemy->printNarrations(randomAttackNarration,_enemy->chapterType);
			gotoXY(55, 12);
			cin >> input;

			
			int randomCritical = rand() % 100 + 1;

			int randomDamage = rand() % (skill->EquipSkills[0].skillDamage * _player->attack) + 8;
			int randomCriticalDamage = rand() % (skill->EquipSkills[0].criticalDamage * _player->attack) + 8;

			if (skill->EquipSkills.size() >= 2)
			{
				if (input == NORMALATTACK)
				{
					if (_player->critical > randomCritical)
					{
						playerCriticalSituation(skill, _enemy,_player, randomCriticalDamage, turn);
						if (_enemy->currentHp <= 0) _enemy->currentHp = 0;
						Sleep(1000);
						break;
					}
					else
					{
						playerNormalAttackSituation(skill, _enemy, _player, randomDamage, turn);
						if (_enemy->currentHp <= 0) _enemy->currentHp = 0;
						Sleep(1000);
						break;
					}
				}
				else if (input == SHIELD)
				{
					playerSheildSituation(skill, _player, turn);
					shieldON(skill);
					Sleep(1000);
					break;
				}
				else if (input == 3 && skill->EquipSkills.size() >= 4)
				{
					if (input < skill->EquipSkills.size())
					{
						if (skill->EquipSkills[input].name == skill->skills[1].name)//����
						{
							gotoXY(55, 12);
							cout << "�÷��̾ " << skill->EquipSkills[input].name << "�� ����ߴ�." << endl;
							gotoXY(55, 14);
							cout << _enemy->name << "�� " << randomDamage << " �� �������� �Ծ���." << endl;
							gotoXY(55, 16);
							_enemy->currentHp -= randomDamage;
							Sleep(1000);
							if (_enemy->currentHp <= 0)
							{
								_enemy->isBleeding = false;
								cout << "���� ����߽��ϴ�." << endl;
								Sleep(1000);
								break;
							}

							if (_enemy->isBleeding)
							{
								cout << "���� ������ ����" << endl;
								skill->EquipSkills[input].skillDamage += skill->EquipSkills[input].LevelUpSkillDamage;
								turn++;
								break;
							}
							else
							{
								_enemy->isBleeding = true;
								turn++;
								Sleep(1000);
								break;
							}
						}
						else if (skill->EquipSkills[input].name == skill->skills[2].name)//�ݰ�
						{
							gotoXY(55, 12);
							cout << "�÷��̾ " << skill->EquipSkills[input].name << " �� ����ߴ�." << endl;
							gotoXY(55, 14);
							_player->IsCounterattack = true;
							turn++;
							Sleep(1000);
							break;
						}
						else if (skill->EquipSkills[input].name == skill->skills[3].name)//���йб�
						{
							gotoXY(55, 12);
							cout << "�÷��̾ " << skill->EquipSkills[input].name << " �� ����ߴ�." << endl;
							cout << endl;
							gotoXY(55, 14);
							cout << _enemy->name << "�� " << skill->EquipSkills[input].skillDamage* skill->EquipSkills[input].defence << " �� �������� �Ծ���." << endl;
							gotoXY(55, 16);
							_enemy->currentHp -= skill->EquipSkills[input].skillDamage* skill->EquipSkills[input].defence;
							turn++;
							Sleep(1000);
							break;
						}
					}
					else
					{
						cout << "��ȿ���� ���� ��ų�Դϴ�." << endl;
					}
				}
				else if (input == 4 && skill->EquipSkills.size() >= 5)
				{
					if (input < skill->EquipSkills.size())
					{
						if (skill->EquipSkills[input].name == skill->skills[1].name)//����
						{
							gotoXY(55, 12);
							cout << "�÷��̾ " << skill->EquipSkills[input].name << "�� ����ߴ�." << endl;
							gotoXY(55, 14);
							cout << _enemy->name << "�� " << randomDamage<< " �� �������� �Ծ���." << endl;
							gotoXY(55, 16);
							_enemy->currentHp -= randomDamage;
							Sleep(1000);
							if (_enemy->currentHp <= 0)
							{
								_enemy->isBleeding = false;
								cout << "���� ����߽��ϴ�." << endl;
								Sleep(1000);
								break;
							}

							if (_enemy->isBleeding)
							{
								cout << "���� ������ ����" << endl;
								skill->EquipSkills[input].skillDamage += skill->EquipSkills[input].LevelUpSkillDamage;
								turn++;
								break;
							}
							else
							{
								_enemy->isBleeding = true;
								turn++;
								Sleep(1000);
								break;
							}
						}
						else if (skill->EquipSkills[input].name == skill->skills[2].name)//�ݰ�
						{
							gotoXY(55, 12);
							cout << "�÷��̾ " << skill->EquipSkills[input].name << " �� ����ߴ�." << endl;
							gotoXY(55, 14);
							_player->IsCounterattack = true;
							turn++;
							Sleep(1000);
							break;
						}
						else if (skill->EquipSkills[input].name == skill->skills[3].name)//���йб�
						{
							gotoXY(55, 12);
							cout << "�÷��̾ " << skill->EquipSkills[input].name << " �� ����ߴ�." << endl;
							gotoXY(55, 14);
							cout << _enemy->name << "�� " << skill->EquipSkills[input].skillDamage* skill->EquipSkills[input].defence << " �� �������� �Ծ���." << endl;
							gotoXY(55, 16);
							_enemy->currentHp -= skill->EquipSkills[input].skillDamage * skill->EquipSkills[input].defence;
							turn++;
							Sleep(1000);
							break;
						}
					}
					else
					{
						cout << "��ȿ���� ���� ��ų�Դϴ�." << endl;
						Sleep(1000);
					}
				}
				else if (input == 5 && skill->EquipSkills.size() >= 6)
				{
					if (input < skill->EquipSkills.size())
					{
						if (skill->EquipSkills[input].name == skill->skills[1].name)//����
						{

							gotoXY(55, 12);
							cout << "�÷��̾ " << skill->EquipSkills[input].name << "�� ����ߴ�." << endl;
							gotoXY(55, 14);
							cout << _enemy->name << "�� " << randomDamage << " �� �������� �Ծ���." << endl;
							gotoXY(55, 16);
							_enemy->currentHp -= randomDamage;
							Sleep(1000);
							if (_enemy->currentHp <= 0)
							{
								_enemy->isBleeding = false;
								cout << "���� ����߽��ϴ�." << endl;
								Sleep(1000);
								break;
							}
							if (_enemy->isBleeding)
							{
								cout << "���� ������ ����" << endl;
								skill->EquipSkills[input].skillDamage += skill->EquipSkills[input].LevelUpSkillDamage;
								turn++;
								break;
							}
							else
							{
								_enemy->isBleeding = true;
								turn++;
								Sleep(1000);
								break;
							}
						}
						else if (skill->EquipSkills[input].name == skill->skills[2].name)//�ݰ�
						{

							gotoXY(55, 12);
							cout << "�÷��̾ " << skill->EquipSkills[input].name << " �� ����ߴ�." << endl;
							gotoXY(55, 14);
							_player->IsCounterattack = true;
							Sleep(1000);
							turn++;
							break;
						}
						else if (skill->EquipSkills[input].name == skill->skills[3].name)//���йб�
						{
							gotoXY(55, 12);
							cout << "�÷��̾ " << skill->EquipSkills[input].name << " �� ����ߴ�." << endl;
							gotoXY(55, 14);
							cout << _enemy->name << "�� " << skill->EquipSkills[input].skillDamage * skill->EquipSkills[input].defence << " �� �������� �Ծ���." << endl;
							gotoXY(55, 16);
							_enemy->currentHp -= skill->EquipSkills[input].skillDamage * skill->EquipSkills[input].defence;
							turn++;
							Sleep(1000);
							break;
						}
						else
						{
							continue;
						}
					}
					else
					{
						cout << "��ȿ���� ���� ��ų�Դϴ�." << endl;
					}
				}
				else
				{
					continue;
				}
			}
		}
	}
	else//���� ���϶�
	{
		int EnemyTotaldamaged = 1;
		int EnemyrandomDamage = rand() % _enemy->attack + 6;
		
		gotoXY(55, 1);
		cout << "������ ��" << endl;
		if (_enemy->isBleeding)
		{
			for (int i = 0; i < skill->EquipSkills.size(); ++i)
			{
				if (skill->EquipSkills[i].name == skill->skills[1].name)
				{
					gotoXY(55, 8);
					cout << "���������� ���� ü���� " << skill->EquipSkills[i].skillDamage << " ��ŭ �����մϴ�." << endl;
					_enemy->currentHp -= skill->EquipSkills[i].skillDamage;
					Sleep(1000);
				}
				else
				{
					continue;
				}
			}
			
		}

		gotoXY(55, 10);
		_enemy->printAttackNarrations(randomNarration,_enemy->chapterType);


		if (skill->isShield == true)
		{
			EnemyTotaldamaged = _enemy->attack - static_cast<int>(_player->defence * 2.5);

			if (EnemyTotaldamaged <= 0)//������ ���Ƽ� ���̳ʽ����� ������
			{
				EnemyTotaldamaged = 0;
				EnemyAttackSituation(skill, EnemyTotaldamaged, turn, _player);
				if (_player->currentHp <= 0) _player->currentHp = 0;
				Sleep(1000);
				return;
			}
			else
			{
				EnemyAttackSituation(skill, EnemyTotaldamaged, turn, _player);
				if (_player->currentHp <= 0) _player->currentHp = 0;
				Sleep(1000);
				return;
			}
		}

		if (_player->IsCounterattack)//�ݰݽ�ų �������
		{
			for (int i = 0; i < skill->EquipSkills.size(); ++i)
			{
				if (skill->EquipSkills[i].name == skill->skills[2].name)
				{
					int CounterDamage = EnemyrandomDamage - _player->defence;
					gotoXY(55, 12);
					cout << "�÷��̾ " << skill->EquipSkills[i].skillDamage*_player->attack << " �������� �ݰ��ߴ�." << endl;
					if (CounterDamage < 0)//������ 0�����϶� ����ó��
					{
						CounterDamage = 0;
					}
					gotoXY(55, 14);
					cout << "���� �÷��̾�� " << EnemyrandomDamage - _player->defence << " �������� ������." << endl;
					_player->currentHp -= EnemyrandomDamage - _player->defence;
					_enemy->currentHp -= skill->EquipSkills[i].skillDamage * _player->attack;
					if (_enemy->currentHp <= 0)
					{
						gotoXY(55, 16);
						cout << "�ݰ����� ���� ��ҽ��ϴ�." << endl;
						Sleep(1000);
						return;
					}
					turn++;
					Sleep(1000);
					return;
				}
				else
				{
					continue;
				}
			}
		}
		else//�ț��� ���
		{
			EnemyAttackSituation(skill, EnemyrandomDamage, turn, _player);
			Sleep(1000);
			return;
		}
	}
}

void Game::printEnemy(enemy* _enemy)
{
	gotoXY(120, 0);
	cout << "========" << _enemy->name << "========" << endl;
	gotoXY(120, 2);
	cout << "ü�� = " << _enemy->currentHp << "/" << _enemy->hp << endl;
	gotoXY(120, 4);
	cout << "���ݷ� = " << _enemy->attack << endl;
	if (_enemy->chapterType == static_cast<int>(CHAPTERTYPE::ONE))
	{
		printChapter1Picture(120,6);
	}
	else if (_enemy->chapterType == static_cast<int>(CHAPTERTYPE::TWO))
	{
		printChapter2Picture(120, 6);
	}
	else if (_enemy->chapterType == static_cast<int>(CHAPTERTYPE::THREE))
	{
		printChapter3Picture(120, 6);
	}
	else if (_enemy->chapterType == static_cast<int>(CHAPTERTYPE::FOUR))
	{
		printChapter4Picture(120, 6);
	}

}
void Game::printPlayer(player* _player)
{
	gotoXY(0, 0);
	cout << "========" << "�÷��̾�" << "========" << endl;
	gotoXY(0, 2);
	cout << "ü�� = " << _player->currentHp << "/" << _player->hp << endl;
	gotoXY(0, 4);
	cout << "���ݷ� = " << _player->attack<< endl;
	printGoblin(0, 6);
	
}
void Game::printSkills(Skill* skill)
{
	int x = 0, y = 32;
	for (int i = 0; i < skill->EquipSkills.size(); ++i)
	{
		if (skill->EquipSkills[i].order == 1)
		{
			gotoXY(x+5, y-2);
			cout << skill->EquipSkills[i].name << "(" << skill->EquipSkills[i].currentSkill << "LV)" << endl;
			printAttackPicture(x, y);
			x += 30;
		}
		else if (skill->EquipSkills[i].order == 2)
		{
			gotoXY(x+5, y-2);
			cout << skill->EquipSkills[i].name << "(" << skill->EquipSkills[i].currentSkill << "LV)" << endl;
			printShieldPicture(x, y);
			x += 30;
		}
		else if (skill->EquipSkills[i].order == 3)
		{
			gotoXY(x + 5, y - 2);
			cout << skill->EquipSkills[i].name << "(" << skill->EquipSkills[i].currentSkill << "LV)" << endl;
			printBleedingPicture(x, y);
			x += 30;
		}
		else if (skill->EquipSkills[i].order == 4)
		{
			gotoXY(x + 5, y - 2);
			cout << skill->EquipSkills[i].name << "(" << skill->EquipSkills[i].currentSkill << "LV)" << endl;
			printCounterattackPicture(x, y);
			x += 30;
		}
		else if (skill->EquipSkills[i].order == 5)
		{
			gotoXY(x + 5, y - 2);
			cout << skill->EquipSkills[i].name << "(" << skill->EquipSkills[i].currentSkill << "LV)" << endl;
			printShieldAttackPicture(x, y);
			x += 30;
		}
	}

}
void Game::ChoiceSkills(Skill* skill)
{
	skill->choicedSkills.clear();

	const int numSkill = static_cast<int>(skill->skills.size());

	int x = 30, y = 15;
	int input;
	int random[3] = { rand() % numSkill, rand() % numSkill, rand() % numSkill };// 0 ~ 5

	if (random[0] == random[1])
	{
		for (int i = 0; i < 10; ++i)
		{
			random[1] = rand() % numSkill;
			if (random[1] != random[0])
			{
				break;
			}
			else
			{
				continue;
			}
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		if (skill->skills[random[i]].name == skill->skills[0].name)
		{
			gotoXY(x + 5, y - 2);
			cout << skill->skills[random[i]].name << "(" << skill->skills[random[i]].currentSkill << "LV)" << endl;
			printAttackPicture(x, y);
			x += 40;
		}
		else if (skill->skills[random[i]].name == skill->skills[4].name)
		{
			gotoXY(x + 5, y - 2);
			cout << skill->skills[random[i]].name << "(" << skill->skills[random[i]].currentSkill << "LV)" << endl;
			printShieldPicture(x, y);
			x += 40;
		}
		else if (skill->skills[random[i]].name == skill->skills[1].name)
		{
			gotoXY(x + 5, y - 2);
			cout << skill->skills[random[i]].name << "(" << skill->skills[random[i]].currentSkill << "LV)" << endl;
			printBleedingPicture(x, y);
			x += 40;
		}
		else if (skill->skills[random[i]].name == skill->skills[2].name)
		{
			gotoXY(x + 5, y - 2);
			cout << skill->skills[random[i]].name << "(" << skill->skills[random[i]].currentSkill << "LV)" << endl;
			printCounterattackPicture(x, y);
			x += 40;
		}
		else if (skill->skills[random[i]].name == skill->skills[3].name)
		{
			gotoXY(x + 5, y - 2);
			cout << skill->skills[random[i]].name << "(" << skill->skills[random[i]].currentSkill << "LV)" << endl;
			printShieldAttackPicture(x, y);
			x += 40;
		}
		else if (skill->skills[random[i]].name == skill->skills[5].name)
		{
			gotoXY(x + 5, y - 2);
			cout << skill->skills[random[i]].name << "(" << skill->skills[random[i]].currentSkill << "LV)" << endl;
			printIron(x, y);
			x += 40;
		}
		skill->choicedSkills.push_back(skill->skills[random[i]]);
	}
	gotoXY(70, 40);
	cout << "���� :";
	cin >> input;
	if (input >= 1 && input <= 3)
	{
		for (int i = 0; i < skill->EquipSkills.size(); ++i)
		{
			if (skill->choicedSkills[input - 1].name == skill->EquipSkills[i].name)
			{
				gotoXY(70, 42);
				cout << skill->EquipSkills[i].name << " ���׷��̵�!!" << endl;
				if (skill->EquipSkills[i].skillType == static_cast<int>(SKILLTYPE::ATTACK))
				{
					skill->EquipSkills[i].skillDamage += 5;
					if (skill->EquipSkills[i].currentSkill == 5)
					{
						gotoXY(70, 42);
						cout << "�ִ� ��ȭ �Դϴ�." << endl;
						return;
					}
					else
					{
						skill->EquipSkills[i].currentSkill++;
						return;
					}
				}
				else if (skill->EquipSkills[i].skillType == static_cast<int>(SKILLTYPE::SHIELD))
				{
					skill->EquipSkills[i].skillDamage += 20;
					skill->EquipSkills[i].defence += 10;
					if (skill->EquipSkills[i].currentSkill == 5)
					{
						gotoXY(70, 42);
						cout << "�ִ� ��ȭ �Դϴ�." << endl;
						return;
					}
					else
					{
						skill->EquipSkills[i].currentSkill++;
						return;
					}
				}
				Sleep(1000);
				return;
			}
			else if (skill->choicedSkills[input - 1].skillType == static_cast<int>(SKILLTYPE::ABILITY))
			{
				for (int i = 0; skill->EquipSkills.size(); ++i)
				{
					if (skill->choicedSkills[input - 1].name == skill->EquipSkills[i].name)
					{
						if (skill->EquipSkills[i].currentSkill == 5)
						{
							gotoXY(70, 42);
							cout << "�ִ� ��ȭ �Դϴ�." << endl;
							return;
						}
						else
						{
							gotoXY(70, 42);
							cout << skill->EquipSkills[i].name << " ���׷��̵�!!" << endl;
							skill->EquipSkills[i].defence += 2;
							skill->EquipSkills[i].currentSkill++;
							return;
						}
					}
				}
			}	
		}
		gotoXY(70, 42);
		cout << "��ų ����!" << endl;
		skill->EquipSkills.push_back(skill->choicedSkills[input - 1]);
		Sleep(1000);
	}
}


void Game::TextColor(int font, int backGround)
{
	int Color = font + backGround * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}
void Game::MakingColor(int color, int pixel)
{
	TextColor(color, color);
	for (int i = 0; i < pixel; ++i)
	{
		cout << "��";
	}
	TextColor(15, BLACK);
}
void Game::gotoXY(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
void Game::printLine(string line, int horizontal, int vertical, int newline)
{
	string a = line;
	int x = horizontal;
	int y = vertical;
	int z = newline;

	int i = 0;
	while (i < a.length())
	{
		if (i > z)
		{
			x = 0;
			y = y + 1;
			z = z + 42;
		}
		Sleep(70);
		gotoXY(x, y);

		if (line[i] & 0X80)
		{
			cout << a[i] << a[i + 1];
			i = i + 2;
			x = x + 2;
		}
		else
		{
			cout << a[i];
			i++;
			x++;
		}
	}
	cout << endl;

}

void Game::printAttackPicture(int x , int y)
{
	gotoXY(x, y);
	MakingColor(YELLOW, 12);
	gotoXY(x, y+1);
	MakingColor(YELLOW, 1);
	MakingColor(DARKGRAY, 5);
	MakingColor(YELLOW, 6);
	gotoXY(x, y+2);
	MakingColor(YELLOW, 1);
	MakingColor(RED, 1);
	MakingColor(DARKGRAY, 4);
	MakingColor(BLACK, 1);
	MakingColor(YELLOW, 5);
	gotoXY(x, y+3);
	MakingColor(YELLOW, 3);
	MakingColor(DARKGRAY, 3);
	MakingColor(BLACK, 2);
	MakingColor(YELLOW, 4);
	gotoXY(x, y+4);
	MakingColor(YELLOW, 1);
	MakingColor(RED, 1);
	MakingColor(YELLOW, 2);
	MakingColor(DARKGRAY, 3);
	MakingColor(BLACK, 2);
	MakingColor(YELLOW, 3);
	gotoXY(x, y+5);
	MakingColor(YELLOW, 4);
	MakingColor(RED, 1);
	MakingColor(DARKGRAY, 3);
	MakingColor(BLACK, 2);
	MakingColor(YELLOW, 2);
	gotoXY(x, y+6);
	MakingColor(YELLOW, 1);
	MakingColor(RED, 1);
	MakingColor(YELLOW, 4);
	MakingColor(DARKGRAY, 3);
	MakingColor(BLACK, 2);
	MakingColor(YELLOW, 1);
	gotoXY(x, y+7);
	MakingColor(YELLOW, 1);
	MakingColor(RED, 1);
	MakingColor(YELLOW, 2);
	MakingColor(RED, 1);
	MakingColor(YELLOW, 2);
	MakingColor(DARKGRAY, 3);
	MakingColor(BLACK, 2);
	gotoXY(x, y+8);
	MakingColor(YELLOW, 4);
	MakingColor(RED, 1);
	MakingColor(YELLOW, 3);
	MakingColor(DARKGRAY, 3);
	MakingColor(BLACK, 1);
	gotoXY(x, y+9);
	MakingColor(YELLOW, 9);
	MakingColor(DARKGRAY, 3);
	gotoXY(x, y+10);
	MakingColor(YELLOW, 4);
	MakingColor(RED, 1);
	MakingColor(YELLOW, 4);
	MakingColor(DARKGRAY, 3);
	gotoXY(x, y+11);
	MakingColor(YELLOW, 11);
	MakingColor(DARKGRAY, 1);

}
void Game::printShieldPicture(int x, int y)
{
	gotoXY(x, y);
	MakingColor(YELLOW, 12);
	gotoXY(x, y + 1);
	MakingColor(YELLOW, 1);
	MakingColor(BLACK, 1);
	MakingColor(YELLOW, 4);
	MakingColor(BLACK,3);
	MakingColor(YELLOW, 3);
	gotoXY(x, y + 2);
	MakingColor(BLACK, 1);
	MakingColor(WHITE, 1);
	MakingColor(BLACK, 1);
	MakingColor(YELLOW, 2);
	MakingColor(BLACK, 1);
	MakingColor(WHITE, 3);
	MakingColor(BLACK, 1);
	MakingColor(YELLOW, 2);
	gotoXY(x, y + 3);

	MakingColor(WHITE, 1);
	MakingColor(BLUE, 1);
	MakingColor(WHITE, 1);
	MakingColor(BLACK, 2);
	MakingColor(WHITE, 1);
	MakingColor(BLACK, 1);
	MakingColor(BLUE, 2);
	MakingColor(WHITE, 1);
	MakingColor(BLACK, 1);
	MakingColor(YELLOW, 1);

	gotoXY(x, y + 4);
	MakingColor(WHITE, 1);
	MakingColor(BLUE, 1);
	MakingColor(BLUE, 1);
	MakingColor(BLACK, 1);
	MakingColor(WHITE, 1);
	MakingColor(BLACK, 1);
	MakingColor(BLUE, 1);
	MakingColor(BLACK, 1);
	MakingColor(BLUE, 2);
	MakingColor(WHITE, 1);
	MakingColor(BLACK, 1);



	gotoXY(x, y + 5);
	MakingColor(WHITE, 1);
	MakingColor(BLUE, 1);
	MakingColor(BLACK, 1);
	MakingColor(WHITE, 1);
	MakingColor(BLACK, 1);
	MakingColor(BLUE,3);
	MakingColor(GREEN, 2);
	MakingColor(BLUE, 1);
	MakingColor(WHITE, 1);



	gotoXY(x, y + 6);
	MakingColor(BLACK, 1);
	MakingColor(BLUE, 1);
	MakingColor(BLACK, 2);
	MakingColor(WHITE, 1);
	MakingColor(BLUE, 3);
	MakingColor(GREEN, 2);
	MakingColor(BLUE, 1);
	MakingColor(WHITE, 1);



	gotoXY(x, y + 7);
	MakingColor(BLACK, 2);
	MakingColor(WHITE, 1);
	MakingColor(BLACK, 2);
	MakingColor(WHITE, 1);
	MakingColor(BLUE, 3);
	MakingColor(GREEN,1);
	MakingColor(BLUE, 1);
	MakingColor(WHITE, 1);



	gotoXY(x, y + 8);
	MakingColor(BLACK, 1);
	MakingColor(WHITE, 1);
	MakingColor(BLACK, 3);
	MakingColor(WHITE, 1);
	MakingColor(BLUE, 4);
	MakingColor(BLACK, 1);
	MakingColor(WHITE, 1);



	gotoXY(x, y + 9);
	MakingColor(BLACK, 2);
	MakingColor(BLUE, 2);
	MakingColor(WHITE, 1);
	MakingColor(BLACK, 1);
	MakingColor(WHITE, 1);
	MakingColor(BLUE,3);
	MakingColor(BLACK, 1);
	MakingColor(WHITE, 1);



	gotoXY(x, y + 10);
	MakingColor(BLACK,3);
	MakingColor(WHITE, 3);
	MakingColor(BLACK, 1);
	MakingColor(WHITE, 1);
	MakingColor(BLUE, 3);
	MakingColor(BLACK, 1);



	gotoXY(x, y + 11);
	MakingColor(BLACK, 4);
	MakingColor(WHITE, 3);
	MakingColor(BLACK, 1);
	MakingColor(WHITE, 4);



}

void Game::printShieldAttackPicture(int x, int y)
{
	gotoXY(x, y);

	MakingColor(BLACK, 12);
	gotoXY(x, y + 1);

	MakingColor(BLACK, 4);
	MakingColor(WHITE, 2);
	MakingColor(YELLOW, 2);
	MakingColor(BLACK, 4);

	gotoXY(x, y + 2);
	MakingColor(GRAY, 1);
	MakingColor(WHITE, 1);
	MakingColor(BLUE, 2);
	MakingColor(WHITE, 1);
	MakingColor(YELLOW,2);
	MakingColor(BLACK, 3);

	gotoXY(x, y + 3);

	MakingColor(GRAY, 1);
	MakingColor(BLACK, 2);
	MakingColor(GRAY, 4);
	MakingColor(WHITE, 2);
	MakingColor(YELLOW, 1);
	MakingColor(BLACK, 2);

	gotoXY(x, y + 4);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 1);
	MakingColor(BLACK, 5);
	MakingColor(GRAY, 1);
	MakingColor(BLUE, 1);
	MakingColor(WHITE, 1);
	MakingColor(YELLOW, 1);
	MakingColor(BLACK, 1);



	gotoXY(x, y + 5);
	MakingColor(BLACK, 1);
	MakingColor(WHITE, 1);
	MakingColor(GRAY, 1);
	MakingColor(BLACK, 4);
	MakingColor(GRAY, 1);
	MakingColor(BLUE, 2);
	MakingColor(WHITE, 2);
	MakingColor(YELLOW, 1);



	gotoXY(x, y + 6);
	MakingColor(BLACK, 1);
	MakingColor(WHITE, 1);
	MakingColor(BLUE, 1);
	MakingColor(GRAY, 1);
	MakingColor(BLACK, 3);
	MakingColor(GRAY, 1);
	MakingColor(BLUE, 1);
	MakingColor(WHITE, 1);
	MakingColor(YELLOW, 1);
	MakingColor(BLACK, 1);



	gotoXY(x, y + 7);
	MakingColor(BLACK, 2);
	MakingColor(YELLOW, 1);
	MakingColor(WHITE, 2);
	MakingColor(BLUE, 1);
	MakingColor(GRAY, 3);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 1);
	MakingColor(BLUE, 1);
	MakingColor(WHITE, 1);
	MakingColor(YELLOW, 1);
	MakingColor(BLACK, 2);



	gotoXY(x, y + 8);
	MakingColor(BLACK, 2);
	MakingColor(YELLOW, 1);
	MakingColor(WHITE, 1);
	MakingColor(BLUE, 1);
	MakingColor(GRAY, 1);
	MakingColor(BLUE, 2);
	MakingColor(WHITE, 1);
	MakingColor(YELLOW, 1);
	MakingColor(BLACK, 1);
	MakingColor(PURPLE, 1);



	gotoXY(x, y + 9);
	MakingColor(BLACK, 3);
	MakingColor(YELLOW, 1);
	MakingColor(WHITE, 1);
	MakingColor(BLUE, 2);
	MakingColor(WHITE, 1);
	MakingColor(YELLOW, 1);
	MakingColor(BLACK, 1);
	MakingColor(PURPLE, 1);
	MakingColor(BLACK, 1);



	gotoXY(x, y + 10);
	MakingColor(BLACK, 4);
	MakingColor(YELLOW, 1);
	MakingColor(WHITE, 2);
	MakingColor(YELLOW, 1);
	MakingColor(BLACK, 1);
	MakingColor(PURPLE, 1);
	MakingColor(BLACK, 2);



	gotoXY(x, y + 11);
	MakingColor(BLACK, 5);
	MakingColor(YELLOW, 2);
	MakingColor(BLACK, 1);
	MakingColor(WHITE, 1);
	MakingColor(BLACK, 3);



}
void Game::printBleedingPicture(int x, int y)
{
	gotoXY(x, y);

	MakingColor(YELLOW, 5);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 5);
	MakingColor(BLACK, 1);
	gotoXY(x, y + 1);

	MakingColor(YELLOW, 4);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 6);
	MakingColor(BLACK, 1);

	gotoXY(x, y + 2);
	MakingColor(YELLOW, 4);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 1);
	MakingColor(RED, 1);
	MakingColor(GRAY, 4);
	MakingColor(BLACK, 1);

	gotoXY(x, y + 3);

	MakingColor(YELLOW, 3);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 4);
	MakingColor(RED, 1);
	MakingColor(GRAY, 1);
	MakingColor(BLACK, 2);

	gotoXY(x, y + 4);

	MakingColor(YELLOW, 2);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 2);
	MakingColor(RED, 1);
	MakingColor(GRAY,4);
	MakingColor(BLACK, 1);
	MakingColor(YELLOW, 1);



	gotoXY(x, y + 5);
	MakingColor(YELLOW, 2);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 5);
	MakingColor(RED, 2);
	MakingColor(BLACK, 1);
	MakingColor(YELLOW, 1);



	gotoXY(x, y + 6);
	MakingColor(YELLOW, 2);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 4);
	MakingColor(RED, 1);
	MakingColor(GRAY, 1);
	MakingColor(BLACK, 2);
	MakingColor(YELLOW, 1);



	gotoXY(x, y + 7);
	MakingColor(YELLOW, 2);
	MakingColor(BLACK, 1);
	MakingColor(RED, 1);
	MakingColor(GRAY, 5);
	MakingColor(BLACK, 1);
	MakingColor(YELLOW, 2);



	gotoXY(x, y + 8);
	MakingColor(YELLOW, 2);
	MakingColor(BLACK, 2);
	MakingColor(RED, 1);
	MakingColor(GRAY, 2);
	MakingColor(RED, 1);
	MakingColor(BLACK, 1);
	MakingColor(YELLOW, 2);



	gotoXY(x, y + 9);
	MakingColor(YELLOW, 2);
	MakingColor(RED, 1);
	MakingColor(BLACK, 1);
	MakingColor(RED, 1);
	MakingColor(GRAY, 1);
	MakingColor(RED, 1);
	MakingColor(BLACK, 2);
	MakingColor(RED, 1);
	MakingColor(YELLOW, 2);



	gotoXY(x, y + 10);
	MakingColor(YELLOW, 1);
	MakingColor(RED, 2);
	MakingColor(BLACK, 1);
	MakingColor(RED, 1);
	MakingColor(GRAY, 1);
	MakingColor(RED, 1);
	MakingColor(BLACK , 1);
	MakingColor(YELLOW, 1);
	MakingColor(RED, 1);
	MakingColor(YELLOW, 2);



	gotoXY(x, y + 11);
	MakingColor(YELLOW, 1);
	MakingColor(RED, 1);
	MakingColor(YELLOW, 1);
	MakingColor(BLACK, 1);
	MakingColor(RED,2);
	MakingColor(BLACK, 2);
	MakingColor(RED, 1);
	MakingColor(YELLOW, 3);



}
void Game::printCounterattackPicture(int x, int y)
{
	gotoXY(x, y);

	MakingColor(YELLOW, 7);
	MakingColor(BLACK, 1);
	MakingColor(YELLOW, 4);
	gotoXY(x, y + 1);

	MakingColor(GRAY, 2);
	MakingColor(YELLOW, 2);
	MakingColor(BLACK, 1);
	MakingColor(YELLOW, 1);
	MakingColor(BLACK, 2);
	MakingColor(YELLOW, 4);

	gotoXY(x, y + 2);
	MakingColor(YELLOW, 1);
	MakingColor(GRAY, 2);
	MakingColor(YELLOW, 1);
	MakingColor(BLACK, 3);
	MakingColor(YELLOW, 1);
	MakingColor(BLACK, 1);
	MakingColor(YELLOW, 2);
	MakingColor(BLACK, 1);

	gotoXY(x, y + 3);

	MakingColor(YELLOW, 2);
	MakingColor(GRAY, 3);
	MakingColor(YELLOW, 1);
	MakingColor(BLACK, 3);
	MakingColor(YELLOW, 2);
	MakingColor(BLACK, 1);

	gotoXY(x, y + 4);

	MakingColor(YELLOW, 4);
	MakingColor(GRAY, 2);
	MakingColor(YELLOW, 4);
	MakingColor(BLACK, 2);



	gotoXY(x, y + 5);
	MakingColor(YELLOW, 1);
	MakingColor(WHITE, 3);
	MakingColor(YELLOW, 1);
	MakingColor(GRAY, 1);
	MakingColor(YELLOW, 2);
	MakingColor(BLACK, 3);
	MakingColor(YELLOW, 1);



	gotoXY(x, y + 6);
	MakingColor(YELLOW, 1);
	MakingColor(WHITE, 3);
	MakingColor(YELLOW, 1);
	MakingColor(WHITE, 1);
	MakingColor(GRAY, 2);
	MakingColor(YELLOW, 1);
	MakingColor(BLACK, 2);
	MakingColor(YELLOW, 1);



	gotoXY(x, y + 7);
	MakingColor(YELLOW, 1);
	MakingColor(WHITE, 3);
	MakingColor(YELLOW, 1);
	MakingColor(WHITE, 1);
	MakingColor(YELLOW, 1);
	MakingColor(GRAY, 1);
	MakingColor(YELLOW, 2);
	MakingColor(BLACK, 2);



	gotoXY(x, y + 8);
	MakingColor(YELLOW, 1);
	MakingColor(WHITE, 2);
	MakingColor(YELLOW, 2);
	MakingColor(WHITE, 1);
	MakingColor(YELLOW, 1);
	MakingColor(GRAY, 2);
	MakingColor(YELLOW, 3);



	gotoXY(x, y + 9);
	MakingColor(YELLOW, 1);
	MakingColor(WHITE, 5);
	MakingColor(YELLOW, 2);
	MakingColor(GRAY, 2);
	MakingColor(YELLOW, 2);



	gotoXY(x, y + 10);
	MakingColor(YELLOW, 1);
	MakingColor(WHITE, 5);
	MakingColor(YELLOW, 3);
	MakingColor(GRAY, 2);
	MakingColor(YELLOW, 1);



	gotoXY(x, y + 11);
	MakingColor(YELLOW, 1);
	MakingColor(WHITE, 2);
	MakingColor(YELLOW, 7);
	MakingColor(GRAY, 1);
	MakingColor(YELLOW, 1);


}
void Game::printIron(int x, int y)
{
	gotoXY(x, y);

	MakingColor(WHITE, 5);
	MakingColor(YELLOW, 2);
	MakingColor(WHITE, 5);
	gotoXY(x, y + 1);

	MakingColor(WHITE, 3);
	MakingColor(YELLOW, 2);
	MakingColor(BLACK, 2);
	MakingColor(YELLOW, 2);
	MakingColor(WHITE, 3);

	gotoXY(x, y + 2);
	MakingColor(WHITE, 1);
	MakingColor(BLACK, 1);
	MakingColor(YELLOW, 2);
	MakingColor(DARKGRAY, 4);
	MakingColor(YELLOW, 2);
	MakingColor(BLACK, 1);
	MakingColor(WHITE, 1);

	gotoXY(x, y + 3);

	MakingColor(YELLOW, 2);
	MakingColor(DARKGRAY, 3);
	MakingColor(YELLOW, 2);
	MakingColor(DARKGRAY, 3);
	MakingColor(YELLOW, 2);

	gotoXY(x, y + 4);

	MakingColor(YELLOW, 2);
	MakingColor(DARKGRAY, 1);
	MakingColor(YELLOW, 6);
	MakingColor(DARKGRAY, 1);
	MakingColor(YELLOW, 2);



	gotoXY(x, y + 5);
	MakingColor(YELLOW, 2);
	MakingColor(DARKGRAY, 1);
	MakingColor(BLUE, 1);
	MakingColor(YELLOW, 4);
	MakingColor(BLUE, 1);
	MakingColor(DARKGRAY, 1);
	MakingColor(YELLOW, 2);



	gotoXY(x, y + 6);
	MakingColor(BLACK, 1);
	MakingColor(YELLOW, 1);
	MakingColor(DARKGRAY, 1);
	MakingColor(YELLOW, 1);
	MakingColor(BLUE, 1);
	MakingColor(YELLOW, 2);
	MakingColor(BLUE, 1);
	MakingColor(YELLOW, 1);
	MakingColor(DARKGRAY, 1);
	MakingColor(YELLOW, 1);
	MakingColor(BLACK, 1);



	gotoXY(x, y + 7);
	MakingColor(YELLOW, 2);
	MakingColor(DARKGRAY, 1);
	MakingColor(YELLOW, 1);
	MakingColor(BLUE, 1);
	MakingColor(YELLOW, 2);
	MakingColor(BLUE, 1);
	MakingColor(YELLOW, 1);
	MakingColor(DARKGRAY, 1);
	MakingColor(YELLOW, 2);



	gotoXY(x, y + 8);
	MakingColor(WHITE, 1);
	MakingColor(YELLOW, 1);
	MakingColor(DARKGRAY, 1);
	MakingColor(YELLOW, 2);
	MakingColor(BLUE, 2);
	MakingColor(YELLOW, 2);
	MakingColor(DARKGRAY, 1);
	MakingColor(YELLOW, 1);
	MakingColor(WHITE, 1);



	gotoXY(x, y + 9);
	MakingColor(WHITE, 1);
	MakingColor(BLACK, 1);
	MakingColor(YELLOW, 1);
	MakingColor(DARKGRAY, 1);
	MakingColor(YELLOW, 4);
	MakingColor(DARKGRAY, 1);
	MakingColor(YELLOW, 1);
	MakingColor(BLACK, 1);
	MakingColor(WHITE, 1);



	gotoXY(x, y + 10);
	MakingColor(WHITE, 2);
	MakingColor(YELLOW, 2);
	MakingColor(DARKGRAY, 4);
	MakingColor(YELLOW, 2);
	MakingColor(WHITE, 2);



	gotoXY(x, y + 11);
	MakingColor(WHITE, 4);
	MakingColor(YELLOW, 1);
	MakingColor(BLACK, 2);
	MakingColor(YELLOW, 1);
	MakingColor(WHITE, 4);

}

void Game::printChapter1Picture(int x, int y)
{
	gotoXY(x, y);
	MakingColor(GRAY, 20);

	gotoXY(x, y + 1);
	MakingColor(GRAY, 20);

	gotoXY(x, y + 2);
	MakingColor(GRAY, 20);

	gotoXY(x, y + 3);

	MakingColor(GRAY, 11);
	MakingColor(BLACK, 3);
	MakingColor(GRAY, 6);

	gotoXY(x, y + 4);

	MakingColor(GRAY, 10);
	MakingColor(BLACK, 5);
	MakingColor(GRAY, 5);

	gotoXY(x, y + 5);
	MakingColor(GREEN, 7);
	MakingColor(GRAY, 2);
	MakingColor(BLACK, 7);
	MakingColor(GRAY, 4);


	gotoXY(x, y + 6);
	MakingColor(DARKGREEN, 2);
	MakingColor(GREEN, 7);
	MakingColor(DARKYELLOW, 7);
	MakingColor(GRAY,4);

	gotoXY(x, y + 7);
	MakingColor(DARKGREEN, 2);
	MakingColor(GREEN, 6);
	MakingColor(GRAY, 1);
	MakingColor(DARKYELLOW, 1);
	MakingColor(BLACK, 4);
	MakingColor(DARKYELLOW, 2);
	MakingColor(GRAY, 4);



	gotoXY(x, y + 8);
	MakingColor(DARKGREEN, 3);
	MakingColor(GREEN, 2);
	MakingColor(GRAY, 4);
	MakingColor(DARKYELLOW, 2);
	MakingColor(BLACK, 1);
	MakingColor(DARKYELLOW, 4);
	MakingColor(GRAY, 4);



	gotoXY(x, y + 9);
	MakingColor(DARKGREEN, 1);
	MakingColor(GREEN, 3);
	MakingColor(GRAY, 5);
	MakingColor(DARKYELLOW, 2);
	MakingColor(BLACK, 2);
	MakingColor(DARKYELLOW, 3);
	MakingColor(GRAY, 4);



	gotoXY(x, y + 10);
	MakingColor(DARKGREEN, 1);
	MakingColor(GREEN, 2);
	MakingColor(GRAY, 6);
	MakingColor(DARKYELLOW, 6);
	MakingColor(DARKGRAY, 1);
	MakingColor(GRAY, 4);



	gotoXY(x, y + 11);
	MakingColor(DARKGREEN, 2);
	MakingColor(GREEN, 3);
	MakingColor(GRAY, 4);
	MakingColor(DARKGRAY,1);
	MakingColor(DARKYELLOW, 4);
	MakingColor(DARKGRAY, 1);
	MakingColor(DARKYELLOW, 2);
	MakingColor(GRAY, 3);

	gotoXY(x, y + 12);
	MakingColor(DARKGREEN, 1);
	MakingColor(GRAY, 1);
	MakingColor(GREEN, 4);
	MakingColor(GRAY, 4);
	MakingColor(DARKGRAY, 1);
	MakingColor(DARKYELLOW, 1);
	MakingColor(DARKGRAY, 2);
	MakingColor(DARKYELLOW, 2);
	MakingColor(WHITE, 2);
	MakingColor(GRAY, 2);

	gotoXY(x, y + 13);
	MakingColor(GRAY, 3);
	MakingColor(DARKGREEN, 4);
	MakingColor(GRAY, 4);
	MakingColor(DARKYELLOW, 2);
	MakingColor(WHITE, 1);
	MakingColor(DARKYELLOW, 3);
	MakingColor(WHITE, 2);
	MakingColor(GRAY, 1);

	gotoXY(x, y + 14);
	MakingColor(GRAY, 4);
	MakingColor(DARKGREEN, 3);
	MakingColor(GRAY, 4);
	MakingColor(DARKYELLOW, 2);
	MakingColor(WHITE, 1);
	MakingColor(DARKYELLOW, 3);
	MakingColor(WHITE, 3);

	gotoXY(x, y + 15);
	MakingColor(GRAY, 4);
	MakingColor(DARKGREEN, 3);
	MakingColor(DARKYELLOW, 5);
	MakingColor(WHITE, 2);
	MakingColor(GRAY, 4);
	MakingColor(WHITE, 2);

	gotoXY(x, y + 16);
	MakingColor(GRAY , 5);
	MakingColor(DARKGREEN, 5);
	MakingColor(WHITE, 2);
	MakingColor(DARKGRAY, 6);
	MakingColor(WHITE, 2);

	gotoXY(x, y + 17);
	MakingColor(GRAY, 6);
	MakingColor(DARKGREEN, 4);
	MakingColor(DARKGRAY, 7);
	MakingColor(WHITE, 3);

	gotoXY(x, y + 18);
	MakingColor(GRAY, 7);
	MakingColor(DARKGRAY, 8);
	MakingColor(WHITE, 5);

	gotoXY(x, y + 19);
	MakingColor(GRAY, 7);
	MakingColor(DARKGRAY, 6);
	MakingColor(WHITE, 7);

}

void Game::printChapter2Picture(int x, int y)
{
	gotoXY(x, y);
	MakingColor(GRAY, 20);

	gotoXY(x, y + 1);
	MakingColor(GRAY, 20);

	gotoXY(x, y + 2);
	MakingColor(GRAY, 20);

	gotoXY(x, y + 3);

	MakingColor(GRAY, 12);
	MakingColor(DARKYELLOW, 3);
	MakingColor(GRAY, 6);

	gotoXY(x, y + 4);

	MakingColor(GRAY, 11);
	MakingColor(DARKYELLOW, 5);
	MakingColor(GRAY, 5);

	gotoXY(x, y + 5);
	MakingColor(GRAY, 10);
	MakingColor(DARKYELLOW, 7);
	MakingColor(GRAY, 3);
	MakingColor(BLUE, 1);


	gotoXY(x, y + 6);
	MakingColor(GRAY, 10);
	MakingColor(DARKYELLOW, 7);
	MakingColor(GRAY, 1);
	MakingColor(BLUE, 3);

	gotoXY(x, y + 7);
	MakingColor(GRAY, 10);
	MakingColor(DARKYELLOW, 1);
	MakingColor(BLACK, 4);
	MakingColor(DARKYELLOW, 2);
	MakingColor(BLUE, 2);
	MakingColor(GRAY, 1);
	MakingColor(RED, 1);



	gotoXY(x, y + 8);
	MakingColor(GRAY, 10);
	MakingColor(DARKYELLOW, 2);
	MakingColor(BLACK, 1);
	MakingColor(DARKYELLOW, 4);
	MakingColor(GRAY, 1);
	MakingColor(RED, 1);
	MakingColor(GRAY, 1);
	MakingColor(RED, 1);



	gotoXY(x, y + 9);
	MakingColor(GRAY, 10);
	MakingColor(DARKGRAY, 1);
	MakingColor(DARKYELLOW, 1);
	MakingColor(BLACK, 2);
	MakingColor(DARKYELLOW, 1);
	MakingColor(DARKGRAY, 1);
	MakingColor(DARKYELLOW, 1);
	MakingColor(GRAY, 1);
	MakingColor(RED, 1);
	MakingColor(GRAY, 1);
	MakingColor(RED, 1);



	gotoXY(x, y + 10);
	MakingColor(GRAY, 10);
	MakingColor(DARKYELLOW, 1);
	MakingColor(DARKGRAY, 4);
	MakingColor(DARKYELLOW, 1);
	MakingColor(DARKGRAY, 1);
	MakingColor(GRAY, 4);



	gotoXY(x, y + 11);
	MakingColor(GRAY, 9);
	MakingColor(BLUE, 1);
	MakingColor(DARKGRAY, 1);
	MakingColor(DARKYELLOW, 4);
	MakingColor(DARKGRAY, 1);
	MakingColor(DARKYELLOW, 2);
	MakingColor(GRAY, 3);

	gotoXY(x, y + 12);
	MakingColor(GRAY, 7);
	MakingColor(BLUE, 3);
	MakingColor(GRAY, 1);
	MakingColor(DARKGRAY, 4);
	MakingColor(DARKYELLOW, 2);
	MakingColor(WHITE, 2);
	MakingColor(GRAY, 2);

	gotoXY(x, y + 13);
	MakingColor(GRAY, 6);
	MakingColor(BLUE, 2);
	MakingColor(GRAY, 1);
	MakingColor(RED, 1);
	MakingColor(GRAY, 2);
	MakingColor(DARKYELLOW, 2);
	MakingColor(WHITE, 1);
	MakingColor(DARKYELLOW, 3);
	MakingColor(WHITE, 2);
	MakingColor(GRAY, 1);

	gotoXY(x, y + 14);
	MakingColor(GRAY, 6);
	MakingColor(BLUE, 2);
	MakingColor(GRAY, 4);
	MakingColor(DARKYELLOW, 2);
	MakingColor(WHITE, 1);
	MakingColor(DARKYELLOW, 3);
	MakingColor(WHITE, 3);

	gotoXY(x, y + 15);
	MakingColor(GRAY, 5);
	MakingColor(BLUE, 2);
	MakingColor(DARKYELLOW, 5);
	MakingColor(WHITE, 2);
	MakingColor(GRAY, 4);
	MakingColor(WHITE, 2);

	gotoXY(x, y + 16);
	MakingColor(GRAY, 5);
	MakingColor(BLUE, 5);
	MakingColor(WHITE, 2);
	MakingColor(DARKGRAY, 6);
	MakingColor(WHITE, 2);

	gotoXY(x, y + 17);
	MakingColor(GRAY, 5);
	MakingColor(BLUE, 5);
	MakingColor(DARKGRAY, 6);
	MakingColor(GRAY, 1);
	MakingColor(WHITE, 3);

	gotoXY(x, y + 18);
	MakingColor(GRAY, 6);
	MakingColor(BLUE, 1);
	MakingColor(DARKGRAY, 8);
	MakingColor(WHITE, 5);

	gotoXY(x, y + 19);
	MakingColor(GRAY, 6);
	MakingColor(BLUE, 1);
	MakingColor(DARKGRAY, 6);
	MakingColor(WHITE, 7);

}
void Game::printChapter3Picture(int x, int y)
{
	gotoXY(x, y);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 20);

	gotoXY(x, y + 1);
	MakingColor(GREEN, 1);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 7);
	MakingColor(DARKGRAY, 1);
	MakingColor(GRAY, 5);
	MakingColor(DARKGRAY, 2);
	MakingColor(GRAY, 3);

	gotoXY(x, y + 2);
	MakingColor(GREEN, 1);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 7);
	MakingColor(DARKGRAY, 3);
	MakingColor(GRAY, 1);
	MakingColor(DARKGRAY, 3);
	MakingColor(GRAY, 4);

	gotoXY(x, y + 3);

	MakingColor(GREEN, 2);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 8);
	MakingColor(DARKGRAY, 3);
	MakingColor(GRAY, 3);
	MakingColor(DARKGRAY, 1);
	MakingColor(GRAY, 2);

	gotoXY(x, y + 4);

	MakingColor(GREEN, 2);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 3);
	MakingColor(DARKGRAY, 12);
	MakingColor(GRAY, 2);

	gotoXY(x, y + 5);
	MakingColor(GREEN, 3);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 2);
	MakingColor(DARKGRAY, 1);
	MakingColor(GRAY, 1);
	MakingColor(DARKGRAY, 3);
	MakingColor(DARKYELLOW, 3);
	MakingColor(DARKGRAY, 2);
	MakingColor(GRAY, 4);


	gotoXY(x, y + 6);
	MakingColor(GREEN, 3);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 4);
	MakingColor(DARKGRAY, 2);
	MakingColor(DARKYELLOW, 5);
	MakingColor(DARKGRAY, 3);
	MakingColor(GRAY, 2);

	gotoXY(x, y + 7);
	MakingColor(GREEN, 4);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 2);
	MakingColor(DARKGRAY, 3);
	MakingColor(BLACK, 4);
	MakingColor(DARKYELLOW, 1);
	MakingColor(DARKGRAY, 1);
	MakingColor(GRAY, 1);
	MakingColor(DARKGRAY, 1);
	MakingColor(GRAY, 2);



	gotoXY(x, y + 8);
	MakingColor(GREEN, 4);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 1);
	MakingColor(DARKGRAY, 2);
	MakingColor(GRAY, 1);
	MakingColor(DARKYELLOW, 2);
	MakingColor(BLACK, 1);
	MakingColor(DARKYELLOW, 3);
	MakingColor(DARKGRAY, 1);
	MakingColor(GRAY, 1);
	MakingColor(DARKGRAY, 1);
	MakingColor(GRAY, 2);



	gotoXY(x, y + 9);
	MakingColor(GREEN, 5);
	MakingColor(BLACK, 1);
	MakingColor(DARKGRAY, 1);
	MakingColor(GRAY, 2);
	MakingColor(DARKGRAY, 1);
	MakingColor(DARKYELLOW, 1);
	MakingColor(BLACK, 2);
	MakingColor(DARKYELLOW, 1);
	MakingColor(DARKGRAY, 1);
	MakingColor(DARKYELLOW, 1);
	MakingColor(GRAY, 1);
	MakingColor(DARKGRAY, 1);
	MakingColor(GRAY, 2);



	gotoXY(x, y + 10);
	MakingColor(GREEN, 5);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 3);
	MakingColor(DARKYELLOW, 1);
	MakingColor(DARKGRAY, 4);
	MakingColor(DARKYELLOW, 1);
	MakingColor(DARKGRAY, 1);
	MakingColor(GRAY, 4);



	gotoXY(x, y + 11);
	MakingColor(GREEN, 6);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 2);
	MakingColor(DARKGRAY, 1);
	MakingColor(DARKYELLOW, 4);
	MakingColor(DARKGRAY, 1);
	MakingColor(DARKYELLOW, 2);
	MakingColor(GRAY, 3);

	gotoXY(x, y + 12);
	MakingColor(BLACK, 1);
	MakingColor(GREEN, 5);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 3);
	MakingColor(DARKGRAY, 4);
	MakingColor(DARKYELLOW, 2);
	MakingColor(WHITE, 2);
	MakingColor(GRAY, 2);

	gotoXY(x, y + 13);
	MakingColor(GRAY, 1);
	MakingColor(BLACK, 1);
	MakingColor(GREEN, 5);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 3);
	MakingColor(DARKYELLOW, 2);
	MakingColor(WHITE, 1);
	MakingColor(DARKYELLOW, 3);
	MakingColor(WHITE, 2);
	MakingColor(GRAY, 1);

	gotoXY(x, y + 14);
	MakingColor(GRAY, 2);
	MakingColor(BLACK, 1);
	MakingColor(GREEN, 4);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 3);
	MakingColor(DARKYELLOW, 2);
	MakingColor(WHITE, 1);
	MakingColor(DARKYELLOW, 3);
	MakingColor(WHITE, 3);

	gotoXY(x, y + 15);
	MakingColor(GRAY, 3);
	MakingColor(BLACK, 1);
	MakingColor(GREEN, 4);
	MakingColor(DARKYELLOW, 4);
	MakingColor(WHITE, 2);
	MakingColor(GRAY, 4);
	MakingColor(WHITE, 2);

	gotoXY(x, y + 16);
	MakingColor(GRAY, 3);
	MakingColor(DARKYELLOW, 2);
	MakingColor(GREEN, 2);
	MakingColor(DARKYELLOW, 2);
	MakingColor(WHITE, 2);
	MakingColor(DARKGRAY, 6);
	MakingColor(WHITE, 2);

	gotoXY(x, y + 17);
	MakingColor(GRAY, 5);
	MakingColor(DARKYELLOW, 1);
	MakingColor(GREEN, 3);
	MakingColor(DARKYELLOW, 1);
	MakingColor(DARKGRAY, 7);
	MakingColor(WHITE, 3);

	gotoXY(x, y + 18);
	MakingColor(GRAY, 5);
	MakingColor(DARKYELLOW, 1);
	MakingColor(BLACK, 1);
	MakingColor(DARKGRAY, 8);
	MakingColor(WHITE, 5);

	gotoXY(x, y + 19);
	MakingColor(GRAY, 6);
	MakingColor(BLACK, 1);
	MakingColor(DARKGRAY, 6);
	MakingColor(WHITE, 7);

}

void Game::printChapter4Picture(int x, int y)
{
	gotoXY(x, y);
	MakingColor(RED, 1);
	MakingColor(DARKRED, 19);

	gotoXY(x, y + 1);
	MakingColor(BLUE, 2);
	MakingColor(DARKRED, 18);

	gotoXY(x, y + 2);
	MakingColor(BLUE, 3);
	MakingColor(DARKRED, 5);
	MakingColor(DARKGRAY, 1);
	MakingColor(GRAY, 3);
	MakingColor(DARKGRAY, 1);
	MakingColor(DARKRED, 7);

	gotoXY(x, y + 3);

	MakingColor(BLUE, 1);
	MakingColor(RED, 1);
	MakingColor(BLUE, 2);
	MakingColor(DARKRED, 3);
	MakingColor(DARKGRAY, 1);
	MakingColor(GRAY, 5);
	MakingColor(DARKGRAY, 1);
	MakingColor(DARKRED, 6);

	gotoXY(x, y + 4);

	MakingColor(BLUE, 1);
	MakingColor(RED, 1);
	MakingColor(BLUE, 3);
	MakingColor(DARKRED, 2);
	MakingColor(GRAY, 7);
	MakingColor(DARKRED, 6);

	gotoXY(x, y + 5);
	MakingColor(BLUE, 1);
	MakingColor(RED, 2);
	MakingColor(BLUE, 1);
	MakingColor(RED, 1);
	MakingColor(DARKRED, 2);
	MakingColor(GRAY, 1);
	MakingColor(DARKGRAY, 5);
	MakingColor(GRAY, 1);
	MakingColor(DARKRED, 6);


	gotoXY(x, y + 6);
	MakingColor(BLUE, 4);
	MakingColor(RED, 1);
	MakingColor(DARKRED, 2);
	MakingColor(GRAY, 3);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 3);
	MakingColor(DARKRED, 6);

	gotoXY(x, y + 7);
	MakingColor(BLUE, 3);
	MakingColor(BLACK, 1);
	MakingColor(DARKRED, 3);
	MakingColor(GRAY, 3);
	MakingColor(DARKGRAY, 1);
	MakingColor(GRAY, 3);
	MakingColor(DARKRED, 3);
	MakingColor(DARKGRAY, 1);
	MakingColor(DARKRED, 2);



	gotoXY(x, y + 8);
	MakingColor(RED, 1);
	MakingColor(BLACK, 3);
	MakingColor(RED, 1);
	MakingColor(DARKRED, 2);
	MakingColor(GRAY, 3);
	MakingColor(DARKGRAY, 1);
	MakingColor(GRAY, 3);
	MakingColor(DARKRED, 2);
	MakingColor(GRAY, 1);
	MakingColor(DARKRED, 3);



	gotoXY(x, y + 9);
	MakingColor(RED, 1);
	MakingColor(DARKRED, 1);
	MakingColor(BLACK, 3);
	MakingColor(GRAY, 1);
	MakingColor(DARKRED, 1);
	MakingColor(DARKGRAY, 1);
	MakingColor(GRAY, 5);
	MakingColor(DARKGRAY, 1);
	MakingColor(DARKRED, 1);
	MakingColor(GRAY, 3);
	MakingColor(DARKRED, 2);



	gotoXY(x, y + 10);
	MakingColor(RED, 1);
	MakingColor(DARKRED, 1);
	MakingColor(BLACK, 3);
	MakingColor(GRAY, 3);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 3);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 5);
	MakingColor(DARKRED, 2);



	gotoXY(x, y + 11);
	MakingColor(DARKRED, 3);
	MakingColor(BLACK, 3);
	MakingColor(GRAY, 2);
	MakingColor(DARKGRAY, 5);
	MakingColor(GRAY, 3);
	MakingColor(DARKGRAY, 2);
	MakingColor(DARKRED, 2);

	gotoXY(x, y + 12);
	MakingColor(RED, 1);
	MakingColor(DARKRED, 1);
	MakingColor(GRAY, 1);
	MakingColor(BLACK, 3);
	MakingColor(GRAY, 1);
	MakingColor(DARKGRAY, 1);
	MakingColor(GRAY, 2);
	MakingColor(DARKGRAY, 1);
	MakingColor(GRAY, 2);
	MakingColor(DARKGRAY, 1);
	MakingColor(GRAY, 5);
	MakingColor(RED, 1);

	gotoXY(x, y + 13);
	MakingColor(DARKRED, 2);
	MakingColor(GRAY, 1);
	MakingColor(DARKGRAY, 1);
	MakingColor(BLACK, 2);
	MakingColor(GRAY, 1);
	MakingColor(DARKGRAY, 3);
	MakingColor(GRAY, 1);
	MakingColor(DARKGRAY, 3);
	MakingColor(GRAY, 2);
	MakingColor(DARKGRAY, 2);
	MakingColor(GRAY, 1);
	MakingColor(DARKRED, 1);

	gotoXY(x, y + 14);
	MakingColor(DARKRED, 3);
	MakingColor(GRAY, 1);
	MakingColor(BLACK, 3);
	MakingColor(DARKGRAY, 8);
	MakingColor(GRAY, 3);
	MakingColor(DARKRED, 2);

	gotoXY(x, y + 15);
	MakingColor(DARKRED, 2);
	MakingColor(GRAY, 2);
	MakingColor(BLACK, 3);
	MakingColor(DARKGRAY, 9);
	MakingColor(GRAY, 3);
	MakingColor(DARKRED, 1);

	gotoXY(x, y + 16);
	MakingColor(DARKRED, 3);
	MakingColor(DARKGRAY, 2);
	MakingColor(BLACK, 3);
	MakingColor(DARKGRAY, 2);
	MakingColor(GRAY, 1);
	MakingColor(DARKGRAY, 4);
	MakingColor(BLACK, 1);
	MakingColor(DARKGRAY, 2);
	MakingColor(DARKRED, 2);

	gotoXY(x, y + 17);
	MakingColor(DARKRED, 2);
	MakingColor(GRAY, 3);
	MakingColor(BLACK, 3);
	MakingColor(DARKGRAY, 7);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 3);
	MakingColor(DARKRED, 1);

	gotoXY(x, y + 18);
	MakingColor(DARKRED, 3);
	MakingColor(DARKGRAY, 2);
	MakingColor(BLACK, 4);
	MakingColor(DARKGRAY, 1);
	MakingColor(BLACK, 1);
	MakingColor(DARKGRAY, 4);
	MakingColor(BLACK, 1);
	MakingColor(DARKGRAY, 2);
	MakingColor(DARKRED, 2);

	gotoXY(x, y + 19);
	MakingColor(DARKRED, 3);
	MakingColor(GRAY, 3);
	MakingColor(BLACK, 3);
	MakingColor(DARKGRAY, 5);
	MakingColor(BLACK, 1);
	MakingColor(GRAY, 3);
	MakingColor(DARKRED, 2);

}
void Game::printGoblin(int x, int y)
{
	gotoXY(x, y);
	MakingColor(WHITE, 20);

	gotoXY(x, y + 1);
	MakingColor(WHITE, 6);
	MakingColor(BLUE, 7);
	MakingColor(WHITE, 7);

	gotoXY(x, y + 2);
	MakingColor(WHITE, 5);
	MakingColor(BLUE, 9);
	MakingColor(WHITE, 6);

	gotoXY(x, y + 3);

	MakingColor(WHITE, 4);
	MakingColor(BLUE, 11);
	MakingColor(WHITE, 5);

	gotoXY(x, y + 4);

	MakingColor(WHITE, 4);
	MakingColor(BLUE, 3);
	MakingColor(GREEN, 5);
	MakingColor(BLUE, 3);
	MakingColor(WHITE, 5);

	gotoXY(x, y + 5);
	MakingColor(WHITE, 4);
	MakingColor(BLUE, 2);
	MakingColor(GREEN, 7);
	MakingColor(BLUE, 2);
	MakingColor(WHITE, 5);


	gotoXY(x, y + 6);
	MakingColor(WHITE, 2);
	MakingColor(GREEN, 5);
	MakingColor(BLACK, 1);
	MakingColor(GREEN, 3);
	MakingColor(BLACK, 1);
	MakingColor(GREEN, 5);
	MakingColor(WHITE, 3);

	gotoXY(x, y + 7);
	MakingColor(WHITE, 1);
	MakingColor(GREEN, 2);
	MakingColor(WHITE, 1);
	MakingColor(GREEN, 2);
	MakingColor(BLACK, 1);
	MakingColor(WHITE, 1);
	MakingColor(BLACK, 1);
	MakingColor(GREEN, 1);
	MakingColor(BLACK, 1);
	MakingColor(WHITE, 1);
	MakingColor(BLACK, 1);
	MakingColor(GREEN, 2);
	MakingColor(WHITE, 1);
	MakingColor(GREEN, 2);
	MakingColor(WHITE, 2);



	gotoXY(x, y + 8);
	MakingColor(WHITE, 2);
	MakingColor(GREEN, 5);
	MakingColor(BLACK, 1);
	MakingColor(GREEN, 3);
	MakingColor(BLACK, 1);
	MakingColor(GREEN, 5);
	MakingColor(WHITE, 3);



	gotoXY(x, y + 9);
	MakingColor(WHITE, 4);
	MakingColor(GREEN, 11);
	MakingColor(WHITE, 5);



	gotoXY(x, y + 10);
	MakingColor(WHITE, 4);
	MakingColor(GREEN, 11);
	MakingColor(WHITE, 5);



	gotoXY(x, y + 11);
	MakingColor(WHITE, 5);
	MakingColor(GREEN, 2);
	MakingColor(RED, 5);
	MakingColor(GREEN, 2);
	MakingColor(WHITE, 6);

	gotoXY(x, y + 12);
	MakingColor(WHITE, 5);
	MakingColor(GREEN, 9);
	MakingColor(WHITE, 6);

	gotoXY(x, y + 13);
	MakingColor(WHITE, 6);
	MakingColor(DARKGREEN, 1);
	MakingColor(GREEN, 5);
	MakingColor(DARKGREEN, 1);
	MakingColor(WHITE,7);

	gotoXY(x, y + 14);
	MakingColor(WHITE, 5);
	MakingColor(GREEN, 2);
	MakingColor(DARKGREEN, 2);
	MakingColor(DARKGRAY, 1);
	MakingColor(DARKGREEN, 2);
	MakingColor(GREEN, 3);
	MakingColor(WHITE, 5);

	gotoXY(x, y + 15);
	MakingColor(WHITE, 2);
	MakingColor(GREEN, 7);
	MakingColor(DARKGREEN, 1);
	MakingColor(GREEN, 7);
	MakingColor(WHITE, 3);

	gotoXY(x, y + 16);
	MakingColor(WHITE, 1);
	MakingColor(GREEN, 7);
	MakingColor(PURPLE , 3);
	MakingColor(GREEN, 8);
	MakingColor(WHITE, 1);

	gotoXY(x, y + 17);
	MakingColor(GREEN, 7);
	MakingColor(PURPLE, 2);
	MakingColor(BLUE, 1);
	MakingColor(PURPLE, 2);
	MakingColor(GREEN, 8);

	gotoXY(x, y + 18);
	MakingColor(GREEN, 8);
	MakingColor(PURPLE, 3);
	MakingColor(GREEN, 9);

	gotoXY(x, y + 19);
	MakingColor(GREEN, 3);
	MakingColor(DARKGRAY, 1);
	MakingColor(GREEN, 5);
	MakingColor(PURPLE, 1);
	MakingColor(GREEN, 6);
	MakingColor(DARKGRAY, 1);
	MakingColor(GREEN, 3);

}
	