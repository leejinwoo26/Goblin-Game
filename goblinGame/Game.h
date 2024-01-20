#pragma once
#include "Item.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "Skill.h"
#include "Store.h"
#include "inventory.h"

#define BLACK		0
#define DARKBLUE	1
#define DARKGREEN	2
#define DARKSKYBLUE 3
#define DARKRED  	4
#define DARKPURPLE	5
#define DARKYELLOW	6
#define GRAY		7
#define DARKGRAY	8
#define BLUE		9
#define GREEN		10
#define SKYBLUE		11
#define RED			12
#define PURPLE		13
#define YELLOW		14
#define WHITE		15

enum NORMALSKILL
{
	NONE,
	NORMALATTACK,
	SHIELD
};

class Game
{
private:


public:
	int turn = 1;//게임턴

	bool chapter[5] = { true , false, false, false,false}; //챕터
	bool chapterClear [5] = { false , false, false, false,false};

	void StartGame();//게임스타트(최종)

	void loadingScene(Game* game);//로딩씬

	void init(inventory* inven);//메인화면

	void inGame(enemy* e, Skill* skill, player* play,Game* game, int randomAttackNarration, int randomNarration, int chapter1, int chapter2);//전투


	void selectItem(string situation);//상점에서 아이템 종류 선택

	void printInventory(Store* store, player* _player, int input);//인벤토리 출력

	void PrintStoreItme(Store* store, player* _player, int input);//상점 출력


	//void choiceSkill(Skill* skill);


	void QuitChapter(Game* chapter, int input);//챕터 종료

	void EnterChapter(Game* chapter, int input);//챕터 입장

	void ChapterClear(Game* game, int input);//챕터 클리어 여부


	void shieldON(Skill* skill);//방패스킬 썻을경우

	void shieldoff(Skill* skill);//방패스킬 안썻을경우



	void printEnemy(enemy* _enemy);//적 출력(도트)

	void printPlayer(player* _player);//플레이어 출력(도트)

	void printSkills(Skill* skill);//스킬 출력(도트)

	void ChoiceSkills(Skill* skill);//스킬 고르기(도트)



	//도트
	void TextColor(int font, int backGround);

	void MakingColor(int color, int pixel);

	void gotoXY(int x, int y);//버퍼 이동


	void printLine(string line, int horizontal, int vertical, int newline);//게임 대사 출력

	void printGoblin(int x, int y);//고블린 도트

	void printAttackPicture(int x, int y);//공격스킬 도트

	void printShieldPicture(int x, int y);//방패스킬 도트

	void printShieldAttackPicture(int x, int y);//방패강타 도트

	void printBleedingPicture(int x, int y);//출혈공격 도트

	void printCounterattackPicture(int x, int y);//반격 도트

	void printIron(int x, int y);//철갑능력 도트

	void printChapter1Picture(int x, int y);//챕터1 적 도트

	void printChapter2Picture(int x, int y);//챕터2 적 도트

	void printChapter3Picture(int x, int y);//챕터3 적 도트

	void printChapter4Picture(int x, int y);//챕터4 적 도트

	void playerCriticalSituation(Skill* skill, enemy* _enemy, player* _player, int randomCriticalDamage, int& turn);//플레이어 치명타 적중시

	void playerNormalAttackSituation(Skill* skill, enemy* _enemy, player* _player, int randomDamage, int& turn);//플레이어 일반공격 적중시

	void playerSheildSituation(Skill* skill, player* _player, int& turn);//플레이어 방패스킬사용시

	void EnemyAttackSituation(Skill* skill, int EnemyTotaldamaged, int& turn, player* _player);//적이 공격할시

	void EnemyMinDamage(Skill* skill, int EnemyTotaldamaged, int EnemyrandomDamage, player* _player);//적의 최소데미지

	//챕터 초반 나레이션
	void printChapter1Start();
	void printChapter2Start();
	void printChapter3Start();
	void printChapter4Start();


	void PlayerDead(Game* game, enemy* _enemy, int chapter1);//플레이어 사망
	void EnemyDead(Game* game, enemy* _enemy, player* _player, Skill* skill, int chapter1, int chapter2);//적의 사망

	std::vector<string> printChapter1;
	std::vector<string> printChapter2;
	std::vector<string> printChapter3;
	std::vector<string> printChapter4;

	Game();
	~Game();


					
};

