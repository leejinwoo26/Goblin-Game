#include "Game.h"

void Game::loadingScene(Game* game)
{
	while (true)
	{
		game->gotoXY(60, 10);
		cout << "LOADING.." << endl;
		game->gotoXY(60, 12);
		cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
		game->printLine("■■■■■■■■■■■■■■■■■", 60, 12, 60);
		return;
	}
}

void Game::init(inventory* inven)
{
	system("cls");
	gotoXY(60, 1);
	cout << "===========고블린키우기게임===========" << endl;
	if (chapter[0] == true)
	{
		gotoXY(60, 3);
		cout << "1.챕터1:노예해방" << endl;
		gotoXY(60, 5);
		cout << "2.상점(챕터1 이후 해금)" << endl;
		gotoXY(60, 7);
		cout << "3.인벤토리(상점구매시 해금)" << endl;
	}
	else if(chapter[1]==true)
	{
		gotoXY(60, 3);
		cout << "1.챕터2:나쁜 노예상인 참교육" << endl;
		gotoXY(60, 5);
		cout << "2.상점" << endl;
		if (inven->IsInventoryOpen)
		{
			gotoXY(60, 7);
			cout << "3.인벤토리" << endl;
		}
		else
		{
			gotoXY(60, 7);
			cout << "3.인벤토리(상점구매시 해금)" << endl;
		}
	}
	else if (chapter[2] == true)
	{
		gotoXY(60, 3);
		cout << "1.챕터3:탐욕스러운 용병" << endl;
		gotoXY(60, 5);
		cout << "2.상점" << endl;
		if (inven->IsInventoryOpen)
		{
			gotoXY(60, 7);
			cout << "3.인벤토리" << endl;
		}
		else
		{
			gotoXY(60, 7);
			cout << "3.인벤토리(상점구매시 해금)" << endl;
		}
	}
	else if (chapter[3] == true)
	{
		gotoXY(60, 3);
		cout << "1.챕터4:부패한 기사" << endl;
		gotoXY(60, 5);
		cout << "2.상점" << endl;
		if (inven->IsInventoryOpen)
		{
			gotoXY(60, 7);
			cout << "3.인벤토리" << endl;
		}
		else
		{
			gotoXY(60, 7);
			cout << "3.인벤토리(상점구매시 해금)" << endl;
		}
	}
	else if (chapter[4] == true)
	{
		gotoXY(60, 3);
		cout << "고생하셨습니다." << endl;
		gotoXY(60, 5);
		cout << "마지막입니다." << endl;
		Sleep(1000);
		return;
	}

	gotoXY(60, 9);
	cout << "4.EXIT" << endl;

	gotoXY(60, 11);
	cout << "선택 :";
}

void Game::selectItem(string situation)
{
	system("cls");
	gotoXY(60, 0);
	cout << "=========="<< situation<<"=========="<< endl;
	gotoXY(60, 2);
	cout << "1.무기" << endl;
	gotoXY(60, 4);
	cout << "2.방어구" << endl;
	gotoXY(60, 6);
	cout << "선택(나가기 4번) :";
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
	cout << "가지고 있는 돈 :" << _player->money << endl;
	cout << "어떤 아이템을 사시겠습니까??" << endl;
	cout << "선택 :";
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
	cout << "가지고 있는 돈 :" << _player->money << endl;
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
	cout << "플레이어가 " << skill->EquipSkills[0].name << "을 사용했다." << endl;
	gotoXY(55, 14);
	cout << _enemy->name << "이 " << randomCriticalDamage << " 의 크리티컬 데미지를 입었다." << endl;
	gotoXY(55, 16);
	_enemy->currentHp -= randomCriticalDamage ;
	turn++;
	Sleep(1000);
}
void::Game::playerNormalAttackSituation(Skill* skill, enemy* _enemy,player* _player, int randomDamage, int& turn)
{
	gotoXY(55, 12);
	cout << "플레이어가 " << skill->EquipSkills[0].name << "을 사용했다." << endl;
	gotoXY(55, 14);
	cout << _enemy->name << "이 " << randomDamage << "의 데미지를 입었다." << endl;
	gotoXY(55, 16);
	_enemy->currentHp -= randomDamage ;
	turn++;
	Sleep(1000);
}
void::Game::playerSheildSituation(Skill* skill, player* _player, int& turn)
{
	gotoXY(55, 12);
	cout << "플레이어가 " << skill->EquipSkills[1].name << "을 사용했다." << endl;
	gotoXY(55, 14);
	cout << "플레이어가 방어력을 " << skill->EquipSkills[1].defence*_player->defence << " 만큼 얻었다." << endl;
	gotoXY(55, 16);
	turn++;
	Sleep(1000);
}
void::Game::EnemyAttackSituation(Skill* skill, int EnemyTotaldamaged,int& turn,player* _player)
{
	gotoXY(55, 12);
	cout << "플레이어가 " << EnemyTotaldamaged << "의 데미지를 받았다." << endl;
	gotoXY(55, 14);
	cout << "(철갑 " << skill->skills[5].defence << " 감소)" << endl;
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
		while (_kbhit())  // 키 입력이 있는 동안 반복
		{
			char input = _getch();
			if (input == 32)  // 스페이스바를 누르면
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
				return;  // 반복문을 빠져나가고 함수 종료
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
	cout << "적이 사망했습니다." << endl;
	cout << endl;
	gotoXY(65, 4);
	cout <<randomMoney <<"원을 획득하셨습니다."<<endl;
	gotoXY(65, 6);
	cout << "현재 가지고 있는돈 : " << _player->money << "원" << endl;
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
	cout << "고생했어..." << endl;
	gotoXY(65, 12);
	cout << "다시 도전해보자!" << endl;
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
		while (_kbhit())  // 키 입력이 있는 동안 반복
		{
			char input = _getch();
			if (input == 32)  // 스페이스바를 누르면
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
				return;  // 반복문을 빠져나가고 함수 종료
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
		while (_kbhit())  // 키 입력이 있는 동안 반복
		{
			char input = _getch();
			if (input == 32)  // 스페이스바를 누르면
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
				return;  // 반복문을 빠져나가고 함수 종료
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
		while (_kbhit())  // 키 입력이 있는 동안 반복
		{
			char input = _getch();
			if (input == 32)  // 스페이스바를 누르면
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
				return;  // 반복문을 빠져나가고 함수 종료
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
	//챕터1 
	printChapter1.push_back("나는 고블린... 하루하루가 지옥같은날들이다.");
	printChapter1.push_back("인간들이 하루도 멀다하고 나의 생기를 쥐어짜낸다.");
	printChapter1.push_back("아... 언제쯤 이 상황을 벗어날수있을까?");
	printChapter1.push_back("번쩍!!!");
	printChapter1.push_back("못먹어 가녀리고 가녀린 나의 몸에 활력이 깃돌기 시작했다.");
	printChapter1.push_back("너에게 힘을 주마... 너를 괴롭게 하는 인간들을 다 죽여라");
	printChapter1.push_back("고블린의 눈에 태양과도 같은 열망이 끓어 올랐다.");
	printChapter1.push_back("저기 저 보이는 인간을 먼저 잡아야겠어...");
	//챕터2
	printChapter2.push_back("농민을 처치하고 지옥같은 집을 벗어났다.");
	printChapter2.push_back("하지만 얼마 지나지 않아 악마같은눈과 채찍을 가지고 있는 사람을 만났다.");
	printChapter2.push_back("이런 배은망덕한 놈!! 어딜 도망칠려고");
	printChapter2.push_back("고블린의 몸에는 수많은 채찍자국이 있었다.");
	printChapter2.push_back("바로 저기 저놈이 나에게 채찍질을 가했다.");
	printChapter2.push_back("용서하지 못한다...");
	printChapter2.push_back("자 이제 복수를 시작해 볼까?");
	//챕터3
	printChapter3.push_back("악덕스러운 노예상인을 결국 죽였다...");
	printChapter3.push_back("아주 강한 놈이였어..");
	printChapter3.push_back("이런 노에상인이 마음대로 활개를 펼치는건 용병때문이다,");
	printChapter3.push_back("나에게 고통을 준 용병을 꼭 찾아야 겠어..");
	printChapter3.push_back("그렇게 나는 용병이 자주 있는 한 술집에 찾아갔다.");
	printChapter3.push_back("잊을수 없는 익숙한 얼굴이 햇빛을 받아 반짝거렸다.");
	printChapter3.push_back("바로 저놈이다..(씨익)");
	//챕터4
	printChapter4.push_back("이 용병또한 많이 강해서 죽을뻔 하였다..");
	printChapter4.push_back("나를 처절하게 짓밟고 유린한 기사놈을 잡을 차례이다.");
	printChapter4.push_back("지금은 능력도 있고 충분히 승산가치가 있다고 생각한다.");
	printChapter4.push_back("이제 거의 다왔다.. 나를 잡아서 감옥에 가둔 기사놈을 잡을때가");
	printChapter4.push_back("마을의 성으로 가니 은색의 갑옷을 입은 기사가 나타났다.");
	printChapter4.push_back("자 마지막 파티다...");


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
		PlaySound(TEXT("bgm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//사운드 재생
		game->init(inven);
		if (game->chapter[4]) return;
		cin >> input;
		if (input == static_cast<int>(Choice::ADVENTURE))
		{
			PlaySound(TEXT("battle.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//사운드 재생
			if (game->chapter[0])//챕터 1
			{
				game->printChapter1Start();
				system("cls");
				skill->initSkills();// 기본 스킬 2개 획득
				game->printAttackPicture(50, 0);
				game->printShieldPicture(80, 0);
				game->gotoXY(0, 12);
				cout << "==   PRESS SPACEBAR   ==" << endl;
				game->gotoXY(50, 12);
				cout << "공격(" << skill->skills[0].currentSkill << "Lv)";
				game->gotoXY(80, 12);
				cout << "방패막기(" << skill->skills[4].currentSkill << "Lv)";
				game->gotoXY(0, 14);
				while (true)
				{
					if (_kbhit())
					{
						char key;
						key = _getch();
						if (key == 32)
						{
							cout << "스킬을 획득하셨습니다." << endl;
							cout << endl;
							Sleep(1000);
							cout << skill->skills[5].name << " 특성이 추가 됩니다. (철갑 + Lv 2 , 레벨별로 데미지 추가감소)" << endl;
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
				farmer->settingState("폭력이 심한 농민", 70, 70, 20, 9, 5, static_cast<int>(CHAPTERTYPE::ONE));
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
			else if (game->chapter[1])//챕터 2
			{
				_player->currentHp = 170;
				game->printChapter2Start();
				enemy* SlaveTrader = new enemy;
				SlaveTrader->settingState("노예상인", 150, 150, 25, 10, 7, static_cast<int>(CHAPTERTYPE::TWO));
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
			else if (game->chapter[2])//챕터 3
			{
				_player->currentHp = 170;
				game->printChapter3Start();
				enemy* Mercenary = new enemy;
				Mercenary->settingState("탐욕스러운 용병", 250, 250, 35, 20, 10, static_cast<int>(CHAPTERTYPE::THREE));
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
			else if (game->chapter[3])//챕터 4 보스
			{
				_player->currentHp = 170;
				game->printChapter4Start();
				enemy* knight = new enemy;
				knight->settingState("창기사", 500, 500, 60, 25, 15, static_cast<int>(CHAPTERTYPE::FOUR));
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
		else if (input == static_cast<int>(Choice::STORE) && game->chapterClear[0] == true)//상점
		{

			while (true)
			{
				game->selectItem("상점");
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
		else if (input == static_cast<int>(Choice::INVENTORY) && game->chapterClear[0] && inven->IsInventoryOpen)//인벤토리
		{
			while (true)
			{
				game->selectItem("인벤토리");
				cin >> input;//무기 , 방어구 , 포션 선택
				if (input == 4) break;
				if (input > 2 && input<4) continue;
				inven->printInventory(input, _player);
			}
		}
		else if (input == static_cast<int>(Choice::EXIT))//나가기
		{
			break;
		}
		else
		{
			cout << "잘못 입력하셨습니다." << endl;
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
		cout << "사망..." << endl;
		turn = 1;
		EnterChapter(game, chapter1);
		delete _enemy;
		Sleep(1000);
		return;
	}
	
	
	if (turn % 2 != 0)//플레이어 턴
	{
		while (true)
		{
			_player->IsCounterattack = false;
			skill->isShield = false;
			gotoXY(55, 1);
			cout << "플레이어 턴" << endl;
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
						if (skill->EquipSkills[input].name == skill->skills[1].name)//출혈
						{
							gotoXY(55, 12);
							cout << "플레이어가 " << skill->EquipSkills[input].name << "을 사용했다." << endl;
							gotoXY(55, 14);
							cout << _enemy->name << "이 " << randomDamage << " 의 데미지를 입었다." << endl;
							gotoXY(55, 16);
							_enemy->currentHp -= randomDamage;
							Sleep(1000);
							if (_enemy->currentHp <= 0)
							{
								_enemy->isBleeding = false;
								cout << "적이 사망했습니다." << endl;
								Sleep(1000);
								break;
							}

							if (_enemy->isBleeding)
							{
								cout << "출혈 데미지 증가" << endl;
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
						else if (skill->EquipSkills[input].name == skill->skills[2].name)//반격
						{
							gotoXY(55, 12);
							cout << "플레이어가 " << skill->EquipSkills[input].name << " 을 사용했다." << endl;
							gotoXY(55, 14);
							_player->IsCounterattack = true;
							turn++;
							Sleep(1000);
							break;
						}
						else if (skill->EquipSkills[input].name == skill->skills[3].name)//방패밀기
						{
							gotoXY(55, 12);
							cout << "플레이어가 " << skill->EquipSkills[input].name << " 를 사용했다." << endl;
							cout << endl;
							gotoXY(55, 14);
							cout << _enemy->name << "이 " << skill->EquipSkills[input].skillDamage* skill->EquipSkills[input].defence << " 의 데미지를 입었다." << endl;
							gotoXY(55, 16);
							_enemy->currentHp -= skill->EquipSkills[input].skillDamage* skill->EquipSkills[input].defence;
							turn++;
							Sleep(1000);
							break;
						}
					}
					else
					{
						cout << "유효하지 않은 스킬입니다." << endl;
					}
				}
				else if (input == 4 && skill->EquipSkills.size() >= 5)
				{
					if (input < skill->EquipSkills.size())
					{
						if (skill->EquipSkills[input].name == skill->skills[1].name)//출혈
						{
							gotoXY(55, 12);
							cout << "플레이어가 " << skill->EquipSkills[input].name << "을 사용했다." << endl;
							gotoXY(55, 14);
							cout << _enemy->name << "이 " << randomDamage<< " 의 데미지를 입었다." << endl;
							gotoXY(55, 16);
							_enemy->currentHp -= randomDamage;
							Sleep(1000);
							if (_enemy->currentHp <= 0)
							{
								_enemy->isBleeding = false;
								cout << "적이 사망했습니다." << endl;
								Sleep(1000);
								break;
							}

							if (_enemy->isBleeding)
							{
								cout << "출혈 데미지 증가" << endl;
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
						else if (skill->EquipSkills[input].name == skill->skills[2].name)//반격
						{
							gotoXY(55, 12);
							cout << "플레이어가 " << skill->EquipSkills[input].name << " 을 사용했다." << endl;
							gotoXY(55, 14);
							_player->IsCounterattack = true;
							turn++;
							Sleep(1000);
							break;
						}
						else if (skill->EquipSkills[input].name == skill->skills[3].name)//방패밀기
						{
							gotoXY(55, 12);
							cout << "플레이어가 " << skill->EquipSkills[input].name << " 를 사용했다." << endl;
							gotoXY(55, 14);
							cout << _enemy->name << "이 " << skill->EquipSkills[input].skillDamage* skill->EquipSkills[input].defence << " 의 데미지를 입었다." << endl;
							gotoXY(55, 16);
							_enemy->currentHp -= skill->EquipSkills[input].skillDamage * skill->EquipSkills[input].defence;
							turn++;
							Sleep(1000);
							break;
						}
					}
					else
					{
						cout << "유효하지 않은 스킬입니다." << endl;
						Sleep(1000);
					}
				}
				else if (input == 5 && skill->EquipSkills.size() >= 6)
				{
					if (input < skill->EquipSkills.size())
					{
						if (skill->EquipSkills[input].name == skill->skills[1].name)//출혈
						{

							gotoXY(55, 12);
							cout << "플레이어가 " << skill->EquipSkills[input].name << "을 사용했다." << endl;
							gotoXY(55, 14);
							cout << _enemy->name << "이 " << randomDamage << " 의 데미지를 입었다." << endl;
							gotoXY(55, 16);
							_enemy->currentHp -= randomDamage;
							Sleep(1000);
							if (_enemy->currentHp <= 0)
							{
								_enemy->isBleeding = false;
								cout << "적이 사망했습니다." << endl;
								Sleep(1000);
								break;
							}
							if (_enemy->isBleeding)
							{
								cout << "출혈 데미지 증가" << endl;
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
						else if (skill->EquipSkills[input].name == skill->skills[2].name)//반격
						{

							gotoXY(55, 12);
							cout << "플레이어가 " << skill->EquipSkills[input].name << " 을 사용했다." << endl;
							gotoXY(55, 14);
							_player->IsCounterattack = true;
							Sleep(1000);
							turn++;
							break;
						}
						else if (skill->EquipSkills[input].name == skill->skills[3].name)//방패밀기
						{
							gotoXY(55, 12);
							cout << "플레이어가 " << skill->EquipSkills[input].name << " 를 사용했다." << endl;
							gotoXY(55, 14);
							cout << _enemy->name << "이 " << skill->EquipSkills[input].skillDamage * skill->EquipSkills[input].defence << " 의 데미지를 입었다." << endl;
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
						cout << "유효하지 않은 스킬입니다." << endl;
					}
				}
				else
				{
					continue;
				}
			}
		}
	}
	else//몬스터 턴일때
	{
		int EnemyTotaldamaged = 1;
		int EnemyrandomDamage = rand() % _enemy->attack + 6;
		
		gotoXY(55, 1);
		cout << "상대방의 턴" << endl;
		if (_enemy->isBleeding)
		{
			for (int i = 0; i < skill->EquipSkills.size(); ++i)
			{
				if (skill->EquipSkills[i].name == skill->skills[1].name)
				{
					gotoXY(55, 8);
					cout << "출혈때문에 적의 체력이 " << skill->EquipSkills[i].skillDamage << " 만큼 감소합니다." << endl;
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

			if (EnemyTotaldamaged <= 0)//방어력이 높아서 마이너스값이 나오면
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

		if (_player->IsCounterattack)//반격스킬 썻을경우
		{
			for (int i = 0; i < skill->EquipSkills.size(); ++i)
			{
				if (skill->EquipSkills[i].name == skill->skills[2].name)
				{
					int CounterDamage = EnemyrandomDamage - _player->defence;
					gotoXY(55, 12);
					cout << "플레이어가 " << skill->EquipSkills[i].skillDamage*_player->attack << " 데미지를 반격했다." << endl;
					if (CounterDamage < 0)//데미지 0이하일때 예외처리
					{
						CounterDamage = 0;
					}
					gotoXY(55, 14);
					cout << "적이 플레이어에게 " << EnemyrandomDamage - _player->defence << " 데미지를 입혔다." << endl;
					_player->currentHp -= EnemyrandomDamage - _player->defence;
					_enemy->currentHp -= skill->EquipSkills[i].skillDamage * _player->attack;
					if (_enemy->currentHp <= 0)
					{
						gotoXY(55, 16);
						cout << "반격으로 적을 잡았습니다." << endl;
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
		else//안썻을 경우
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
	cout << "체력 = " << _enemy->currentHp << "/" << _enemy->hp << endl;
	gotoXY(120, 4);
	cout << "공격력 = " << _enemy->attack << endl;
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
	cout << "========" << "플레이어" << "========" << endl;
	gotoXY(0, 2);
	cout << "체력 = " << _player->currentHp << "/" << _player->hp << endl;
	gotoXY(0, 4);
	cout << "공격력 = " << _player->attack<< endl;
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
	cout << "선택 :";
	cin >> input;
	if (input >= 1 && input <= 3)
	{
		for (int i = 0; i < skill->EquipSkills.size(); ++i)
		{
			if (skill->choicedSkills[input - 1].name == skill->EquipSkills[i].name)
			{
				gotoXY(70, 42);
				cout << skill->EquipSkills[i].name << " 업그레이드!!" << endl;
				if (skill->EquipSkills[i].skillType == static_cast<int>(SKILLTYPE::ATTACK))
				{
					skill->EquipSkills[i].skillDamage += 5;
					if (skill->EquipSkills[i].currentSkill == 5)
					{
						gotoXY(70, 42);
						cout << "최대 강화 입니다." << endl;
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
						cout << "최대 강화 입니다." << endl;
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
							cout << "최대 강화 입니다." << endl;
							return;
						}
						else
						{
							gotoXY(70, 42);
							cout << skill->EquipSkills[i].name << " 업그레이드!!" << endl;
							skill->EquipSkills[i].defence += 2;
							skill->EquipSkills[i].currentSkill++;
							return;
						}
					}
				}
			}	
		}
		gotoXY(70, 42);
		cout << "스킬 장착!" << endl;
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
		cout << "■";
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
	