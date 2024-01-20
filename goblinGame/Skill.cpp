#include "Skill.h"

void Skill::printSkills()
{
	const int number = static_cast<int>(EquipSkills.size());

	for (int i = 0; i < number; ++i)
	{
		cout << endl;
		cout <<"="<<i+1<<"." << EquipSkills[i].name << "= (���� ���� :" <<EquipSkills[i].currentSkill<<")" << endl;
		cout << endl;
	}
}

void Skill::initSkills()
{
	cout << "======������ �־��� �⺻���� ��ų�̴�======" << endl;
	cout << endl;
	cout << "�̸� : " << skills[0].name << endl;
	cout << "���� : " << skills[0].explain << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "�̸� : " << skills[4].name << endl;
	cout << "���� : " << skills[4].explain << endl;
	cout << endl;
	EquipSkills.push_back(skills[0]);//�⺻����
	EquipSkills.push_back(skills[4]);//���� ����
	EquipSkills.push_back(skills[5]);//ö��
}



Skill::Skill()
{

}

Skill::Skill(player* p)
{
	skills.resize(6);

	skills[0].name = "����";
	skills[0].skillDamage = 1;
	skills[0].criticalDamage = static_cast<int>(std::round(1.6));
	skills[0].currentSkill = 1;
	skills[0].maxSkill = 5;
	skills[0].maxCount = 99;
	skills[0].order = 1;
	skills[0].skillType = static_cast<int>(SKILLTYPE::ATTACK);
	skills[0].explain = "���� ���ظ�" + to_string(skills[0].skillDamage*p->attack) + " ��ŭ �ݴϴ�";

	skills[1].name = "��������";
	skills[1].skillDamage = 3;
	skills[1].currentSkill = 1;
	skills[1].maxSkill = 5;
	skills[1].maxCount = 5;
	skills[1].order = 3;
	skills[1].LevelUpSkillDamage = 3;
	skills[1].skillType = static_cast<int>(SKILLTYPE::ATTACK);
	skills[1].explain = "�������ظ� " + to_string(skills[1].skillDamage*p->attack) + " ��ŭ �ݴϴ�";

	skills[2].name = "�ݰ�";
	skills[2].skillDamage = 1;
	skills[2].currentSkill = 1;
	skills[2].maxSkill = 5;
	skills[2].maxCount = 10;
	skills[2].order = 4;
	skills[2].skillType = static_cast<int>(SKILLTYPE::ATTACK);
	skills[2].explain = "������ ������ ƨ�ܳ��� ������ " + to_string(skills[2].skillDamage*p->attack) + " �� �������� �����ݴϴ�.";

	skills[3].name = "���а�Ÿ";
	skills[4].defence = p->defence;
	skills[3].skillDamage = 1;
	skills[3].currentSkill = 1;
	skills[3].maxSkill = 5;
	skills[3].maxCount = 10;
	skills[3].order = 5;
	skills[3].skillType = static_cast<int>(SKILLTYPE::ATTACK);
	skills[3].explain = "���ظ� ���� " + to_string(skills[3].skillDamage*p->defence) + " ��ŭ �ݴϴ�";

	skills[4].name = "���и���";
	skills[4].defence = static_cast<int>(std::round(2.5));
	skills[4].currentSkill = 1;
	skills[4].maxSkill = 5;
	skills[4].maxCount = 99;
	skills[4].order = 2;
	skills[4].skillType = static_cast<int>(SKILLTYPE::SHIELD);
	skills[4].explain = "���� " + to_string(skills[4].defence*p->defence) + " ��ŭ ����ϴ�.";



	skills[5].name = "ö��";
	skills[5].currentSkill =1;
	skills[5].maxSkill = 5;
	skills[5].order = 6;
	skills[5].defence = 2;
	skills[5].skillType = static_cast<int>(SKILLTYPE::ABILITY);
}

Skill::~Skill()
{
}
