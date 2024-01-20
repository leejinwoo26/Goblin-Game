#include "Skill.h"

void Skill::printSkills()
{
	const int number = static_cast<int>(EquipSkills.size());

	for (int i = 0; i < number; ++i)
	{
		cout << endl;
		cout <<"="<<i+1<<"." << EquipSkills[i].name << "= (현재 레벨 :" <<EquipSkills[i].currentSkill<<")" << endl;
		cout << endl;
	}
}

void Skill::initSkills()
{
	cout << "======나에게 주어진 기본적인 스킬이다======" << endl;
	cout << endl;
	cout << "이름 : " << skills[0].name << endl;
	cout << "설명 : " << skills[0].explain << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "이름 : " << skills[4].name << endl;
	cout << "설명 : " << skills[4].explain << endl;
	cout << endl;
	EquipSkills.push_back(skills[0]);//기본공격
	EquipSkills.push_back(skills[4]);//방패 쉴드
	EquipSkills.push_back(skills[5]);//철갑
}



Skill::Skill()
{

}

Skill::Skill(player* p)
{
	skills.resize(6);

	skills[0].name = "공격";
	skills[0].skillDamage = 1;
	skills[0].criticalDamage = static_cast<int>(std::round(1.6));
	skills[0].currentSkill = 1;
	skills[0].maxSkill = 5;
	skills[0].maxCount = 99;
	skills[0].order = 1;
	skills[0].skillType = static_cast<int>(SKILLTYPE::ATTACK);
	skills[0].explain = "공격 피해를" + to_string(skills[0].skillDamage*p->attack) + " 만큼 줍니다";

	skills[1].name = "출혈베기";
	skills[1].skillDamage = 3;
	skills[1].currentSkill = 1;
	skills[1].maxSkill = 5;
	skills[1].maxCount = 5;
	skills[1].order = 3;
	skills[1].LevelUpSkillDamage = 3;
	skills[1].skillType = static_cast<int>(SKILLTYPE::ATTACK);
	skills[1].explain = "출혈피해를 " + to_string(skills[1].skillDamage*p->attack) + " 만큼 줍니다";

	skills[2].name = "반격";
	skills[2].skillDamage = 1;
	skills[2].currentSkill = 1;
	skills[2].maxSkill = 5;
	skills[2].maxCount = 10;
	skills[2].order = 4;
	skills[2].skillType = static_cast<int>(SKILLTYPE::ATTACK);
	skills[2].explain = "상대방의 공격을 튕겨내어 적에게 " + to_string(skills[2].skillDamage*p->attack) + " 의 데미지를 돌려줍니다.";

	skills[3].name = "방패강타";
	skills[4].defence = p->defence;
	skills[3].skillDamage = 1;
	skills[3].currentSkill = 1;
	skills[3].maxSkill = 5;
	skills[3].maxCount = 10;
	skills[3].order = 5;
	skills[3].skillType = static_cast<int>(SKILLTYPE::ATTACK);
	skills[3].explain = "피해를 방어력 " + to_string(skills[3].skillDamage*p->defence) + " 만큼 줍니다";

	skills[4].name = "방패막기";
	skills[4].defence = static_cast<int>(std::round(2.5));
	skills[4].currentSkill = 1;
	skills[4].maxSkill = 5;
	skills[4].maxCount = 99;
	skills[4].order = 2;
	skills[4].skillType = static_cast<int>(SKILLTYPE::SHIELD);
	skills[4].explain = "방어도를 " + to_string(skills[4].defence*p->defence) + " 만큼 얻습니다.";



	skills[5].name = "철갑";
	skills[5].currentSkill =1;
	skills[5].maxSkill = 5;
	skills[5].order = 6;
	skills[5].defence = 2;
	skills[5].skillType = static_cast<int>(SKILLTYPE::ABILITY);
}

Skill::~Skill()
{
}
