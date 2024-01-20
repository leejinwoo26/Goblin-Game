#include "player.h"


player::player()
{
	money = 100000;
	hp = 170;
	currentHp = 170;
	maxhp = 600;

	attack = 25;
	maxAttack = 60;

	defence = 10;
	currentdefence = 13;
	maxdefence = 60;

	critical=9;
	criticalDamage = static_cast<int>(std::round(1.6));
	maxCritical= 75;
	
	miss = 4;
	maxMiss = 75;
	IsWeaponEquip = false;
	IsArmorEquip = false;



}

player::~player()
{
}
