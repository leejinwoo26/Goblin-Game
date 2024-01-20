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
	int turn = 1;//������

	bool chapter[5] = { true , false, false, false,false}; //é��
	bool chapterClear [5] = { false , false, false, false,false};

	void StartGame();//���ӽ�ŸƮ(����)

	void loadingScene(Game* game);//�ε���

	void init(inventory* inven);//����ȭ��

	void inGame(enemy* e, Skill* skill, player* play,Game* game, int randomAttackNarration, int randomNarration, int chapter1, int chapter2);//����


	void selectItem(string situation);//�������� ������ ���� ����

	void printInventory(Store* store, player* _player, int input);//�κ��丮 ���

	void PrintStoreItme(Store* store, player* _player, int input);//���� ���


	//void choiceSkill(Skill* skill);


	void QuitChapter(Game* chapter, int input);//é�� ����

	void EnterChapter(Game* chapter, int input);//é�� ����

	void ChapterClear(Game* game, int input);//é�� Ŭ���� ����


	void shieldON(Skill* skill);//���н�ų �������

	void shieldoff(Skill* skill);//���н�ų �ț������



	void printEnemy(enemy* _enemy);//�� ���(��Ʈ)

	void printPlayer(player* _player);//�÷��̾� ���(��Ʈ)

	void printSkills(Skill* skill);//��ų ���(��Ʈ)

	void ChoiceSkills(Skill* skill);//��ų ����(��Ʈ)



	//��Ʈ
	void TextColor(int font, int backGround);

	void MakingColor(int color, int pixel);

	void gotoXY(int x, int y);//���� �̵�


	void printLine(string line, int horizontal, int vertical, int newline);//���� ��� ���

	void printGoblin(int x, int y);//��� ��Ʈ

	void printAttackPicture(int x, int y);//���ݽ�ų ��Ʈ

	void printShieldPicture(int x, int y);//���н�ų ��Ʈ

	void printShieldAttackPicture(int x, int y);//���а�Ÿ ��Ʈ

	void printBleedingPicture(int x, int y);//�������� ��Ʈ

	void printCounterattackPicture(int x, int y);//�ݰ� ��Ʈ

	void printIron(int x, int y);//ö���ɷ� ��Ʈ

	void printChapter1Picture(int x, int y);//é��1 �� ��Ʈ

	void printChapter2Picture(int x, int y);//é��2 �� ��Ʈ

	void printChapter3Picture(int x, int y);//é��3 �� ��Ʈ

	void printChapter4Picture(int x, int y);//é��4 �� ��Ʈ

	void playerCriticalSituation(Skill* skill, enemy* _enemy, player* _player, int randomCriticalDamage, int& turn);//�÷��̾� ġ��Ÿ ���߽�

	void playerNormalAttackSituation(Skill* skill, enemy* _enemy, player* _player, int randomDamage, int& turn);//�÷��̾� �Ϲݰ��� ���߽�

	void playerSheildSituation(Skill* skill, player* _player, int& turn);//�÷��̾� ���н�ų����

	void EnemyAttackSituation(Skill* skill, int EnemyTotaldamaged, int& turn, player* _player);//���� �����ҽ�

	void EnemyMinDamage(Skill* skill, int EnemyTotaldamaged, int EnemyrandomDamage, player* _player);//���� �ּҵ�����

	//é�� �ʹ� �����̼�
	void printChapter1Start();
	void printChapter2Start();
	void printChapter3Start();
	void printChapter4Start();


	void PlayerDead(Game* game, enemy* _enemy, int chapter1);//�÷��̾� ���
	void EnemyDead(Game* game, enemy* _enemy, player* _player, Skill* skill, int chapter1, int chapter2);//���� ���

	std::vector<string> printChapter1;
	std::vector<string> printChapter2;
	std::vector<string> printChapter3;
	std::vector<string> printChapter4;

	Game();
	~Game();


					
};

