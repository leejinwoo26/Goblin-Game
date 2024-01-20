#include "enemy.h"

void enemy::settingState(string _name, int _hp, int _currentHp, int _attack, int _critical, int _miss,int type)
{
	name = _name;
	hp = _hp;
	currentHp = _currentHp;
	attack = _attack;
	critical = _critical;
	miss = _miss;
	chapterType = type;
}

void enemy::printEnemyState()
{
	cout << "========" << name << "========" << endl;
	cout << "ü�� = " << currentHp << "/" << hp << endl;
	cout << "���ݷ� = " << attack << endl;
}
void enemy::printNarrations(int random,int type)
{
	if (type == static_cast<int>(CHAPTERTYPE::ONE))
	{
		cout << farmerNarrations[random] << endl;
	}
	else if (type == static_cast<int>(CHAPTERTYPE::TWO))
	{
		cout << farmerNarrations[random] << endl;
	}
	else if (type == static_cast<int>(CHAPTERTYPE::THREE))
	{
		cout << MercenaryNarrations[random] << endl;
	}
	else if (type == static_cast<int>(CHAPTERTYPE::FOUR))
	{
		cout << knightNarrations[random] << endl;
	}
}

void enemy::printAttackNarrations(int random,int type)
{
	if (type == static_cast<int>(CHAPTERTYPE::ONE))
	{
		cout << farmerAttackNarrations[random] << endl;
	}
	else if (type == static_cast<int>(CHAPTERTYPE::TWO))
	{
		cout << farmerAttackNarrations[random] << endl;
	}
	else if (type == static_cast<int>(CHAPTERTYPE::THREE))
	{
		cout << MercenaryAttackNarrations[random] << endl;
	}
	else if (type == static_cast<int>(CHAPTERTYPE::FOUR))
	{
		cout << knightAttackNarrations[random] << endl;
	}
}


enemy::enemy()
{
	maxhp = 600;
	maxAttack = 60;
	maxdefence = 60;
	maxCritical = 75;
	criticalDamage = static_cast<int>(attack * 1.6);
	maxMiss = 75;

	farmerNarrations.push_back("���� ���⸦ �翷���� �ֵθ���. ��� �ϰڴ°�?");
	farmerNarrations.push_back("���� �ڷ� ���ư� �޼Ҹ� �븰��. ��� �ϰڴ°�?");
	farmerNarrations.push_back("���� �㸮���� ������ �Ÿ��� . ��� �ϰڴ°�?");
	farmerNarrations.push_back("���� ǰ�ӿ� �ִ� �ܰ��� ������ . ��� �ϰڴ°�?");
	
	farmerAttackNarrations.push_back("���� ������ �������� �����ߴ�.");
	farmerAttackNarrations.push_back("���� �÷��̾��� �޼Ҹ� �񷶴�.	");
	farmerAttackNarrations.push_back("���� �㸮�㿡 �ִ� ȣ�̸� ��� ������.");
	farmerAttackNarrations.push_back("���� �ܰ��� ������ȭ�� ���ȴ�.");
	//�뺴
	MercenaryNarrations.push_back("���� ���⸦ �翷���� �ֵθ���. ��� �ϰڴ°�?");
	MercenaryNarrations.push_back("���� �ڷ� ���ư� �޼Ҹ� �븰��. ��� �ϰڴ°�?");
	MercenaryNarrations.push_back("���� ���⸦ ��� �پ� ������. ��� �ϰڴ°�?");
	MercenaryNarrations.push_back("���� ǰ�ӿ� �ִ� ��ġ�� ���������Ѵ�. ��� �ϰڴ°�?");

	MercenaryAttackNarrations.push_back("���� ������ �������� �����ߴ�.");
	MercenaryAttackNarrations.push_back("���� �÷��̾��� �޼Ҹ� �񷶴�.");
	MercenaryAttackNarrations.push_back("���� ���⿡ ü���� �Ǿ� �����.");
	MercenaryAttackNarrations.push_back("���� ��ġ�� ������ȭ�� ���ȴ�.");
	//���
	knightNarrations.push_back("���� â������ �غ� �Ѵ�. ��� �ϰڴ°�?");
	knightNarrations.push_back("���� ���� Ÿ�� �ڷ� ���ư� �޼Ҹ� �븰��. ��� �ϰڴ°�?");
	knightNarrations.push_back("���� �㸮�� �ִ� ������ ���� ������ . ��� �ϰڴ°�?");
	knightNarrations.push_back("���� �ܴ��� �غ� �ϰ� ������ �΋Hĥ���� �Ѵ�. ��� �ϰڴ°�?");

	knightAttackNarrations.push_back("���� â���� ���� �踦 �񷶴�");
	knightAttackNarrations.push_back("���� ���� ���� ��������.");
	knightAttackNarrations.push_back("���� ��ī�ο� Į�� ���� ����.");
	knightAttackNarrations.push_back("��ġ �Ѹ����� Ȳ�Ұ��� ���� �΋H����.");

}

enemy::~enemy()
{
}
