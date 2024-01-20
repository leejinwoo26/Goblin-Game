#pragma once
#include "Item.h"
#include "character.h"

enum class CHAPTERTYPE
{
	ONE=1,
	TWO=2,
	THREE=3,
	FOUR=4
};
class enemy : public character
{
private:
	



public:

	std::vector<string> farmerNarrations;
	std::vector<string> farmerAttackNarrations;

	std::vector<string> MercenaryNarrations;
	std::vector<string> MercenaryAttackNarrations;

	std::vector<string> knightNarrations;
	std::vector<string> knightAttackNarrations;
	int chapterType;

	bool isBleeding = false;

	void settingState(string _name, int _hp, int _currentHp, int _attack, int _critical, int _miss, int type);
	void printEnemyState();
	void printNarrations(int random, int type);
	void printAttackNarrations(int random, int type);
	//이름,체력,공격력,크리티컬,크리뎀,회피
	enemy();
	~enemy();


};

