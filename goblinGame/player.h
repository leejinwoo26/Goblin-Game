#pragma once
#include "Item.h"
#include "enemy.h"
#include "character.h"


enum STATE
{
	IRON=1,
	BLOOD,
	STRENGTH
};

class player : public character
{
private:

public:
	int money;
	int skillLevelUP = 1;



	bool IsWeaponEquip;
	bool IsArmorEquip;

	bool IsCounterattack=false;
	bool isQuit = false;

	player();
	~player();


};

