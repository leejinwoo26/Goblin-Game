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
	cout << "체력 = " << currentHp << "/" << hp << endl;
	cout << "공격력 = " << attack << endl;
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

	farmerNarrations.push_back("적이 무기를 양옆으로 휘두른다. 어떻게 하겠는가?");
	farmerNarrations.push_back("적이 뒤로 돌아가 급소를 노린다. 어떻게 하겠는가?");
	farmerNarrations.push_back("적이 허리춤을 만지작 거린다 . 어떻게 하겠는가?");
	farmerNarrations.push_back("적이 품속에 있는 단검을 꺼낸다 . 어떻게 하겠는가?");
	
	farmerAttackNarrations.push_back("적이 낫으로 옆구리를 공격했다.");
	farmerAttackNarrations.push_back("적이 플레이어의 급소를 찔렀다.	");
	farmerAttackNarrations.push_back("적이 허리춤에 있는 호미를 들고 던졌다.");
	farmerAttackNarrations.push_back("적이 단검을 전광석화로 날렸다.");
	//용병
	MercenaryNarrations.push_back("적이 무기를 양옆으로 휘두른다. 어떻게 하겠는가?");
	MercenaryNarrations.push_back("적이 뒤로 돌아가 급소를 노린다. 어떻게 하겠는가?");
	MercenaryNarrations.push_back("적이 무기를 들고 뛰어 오른다. 어떻게 하겠는가?");
	MercenaryNarrations.push_back("적이 품속에 있는 망치를 던질려고한다. 어떻게 하겠는가?");

	MercenaryAttackNarrations.push_back("적이 검으로 옆구리를 공격했다.");
	MercenaryAttackNarrations.push_back("적이 플레이어의 급소를 찔렀다.");
	MercenaryAttackNarrations.push_back("적이 무기에 체중을 실어 찍었다.");
	MercenaryAttackNarrations.push_back("적이 망치를 전광석화로 날렸다.");
	//기사
	knightNarrations.push_back("적이 창을꺼내 준비를 한다. 어떻게 하겠는가?");
	knightNarrations.push_back("적이 말을 타고 뒤로 돌아가 급소를 노린다. 어떻게 하겠는가?");
	knightNarrations.push_back("적이 허리에 있는 예리한 검을 꺼낸다 . 어떻게 하겠는가?");
	knightNarrations.push_back("적이 단단히 준비를 하고 몸통을 부딫칠려고 한다. 어떻게 하겠는가?");

	knightAttackNarrations.push_back("적이 창으로 나의 배를 찔렀다");
	knightAttackNarrations.push_back("적이 말로 몸을 짓뭉갰다.");
	knightAttackNarrations.push_back("적이 날카로운 칼로 몸을 벤다.");
	knightAttackNarrations.push_back("마치 한마리의 황소같이 몸을 부딫힌다.");

}

enemy::~enemy()
{
}
