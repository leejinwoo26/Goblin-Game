#pragma once
#include "Item.h"
#include "player.h"


enum class SKILLTYPE
{
	ATTACK =1,
	SHIELD =2,
	ABILITY =3
};

class Skill
{
private:


public:
	string name;
	string explain;

	int skillDamage;
	int LevelUpSkillDamage;
	int criticalDamage;
	int defence;
	int currentSkill=1;
	int maxSkill;
	int maxCount;
	int skillType;
	int order;
	


	bool isEquip = false;
	bool isCanUse = true;
	bool isDisable = false;
	bool isShield = false;


	std::vector<Skill> skills;
	std::vector<Skill> EquipSkills;
	std::vector<Skill> choicedSkills;

	void printSkills();
	void initSkills();


	Skill();
	Skill(player* p);
	~Skill();
};

