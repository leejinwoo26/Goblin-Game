#include "Item.h"



Item::Item()
{
	
}

void Item::printItem()
{
	if (type == static_cast<int>(TYPE::WEAPON))
	{
		cout << "=====================================" << endl;
		cout << "��ȣ : " << number << endl;
		cout << "�̸� : " << name << endl;
		cout << "������ : " << damage << endl;
		cout << "���� : " << explain << endl;
		cout << "���� : " << price << endl;
		cout << "���� : " << count << endl;
	}
	else if (type == static_cast<int>(TYPE::ARMOR))
	{
		cout << "=====================================" << endl;
		cout << "��ȣ : " << number << endl;
		cout << "�̸� : " << name << endl;
		cout << "���� : " << defence << endl;
		cout << "���� : " << explain << endl;
		cout << "���� : " << price << endl;
		cout << "���� : " << count << endl;
	}
	
}

Item::~Item()
{
}
