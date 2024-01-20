#include "Item.h"



Item::Item()
{
	
}

void Item::printItem()
{
	if (type == static_cast<int>(TYPE::WEAPON))
	{
		cout << "=====================================" << endl;
		cout << "번호 : " << number << endl;
		cout << "이름 : " << name << endl;
		cout << "데미지 : " << damage << endl;
		cout << "설명 : " << explain << endl;
		cout << "가격 : " << price << endl;
		cout << "갯수 : " << count << endl;
	}
	else if (type == static_cast<int>(TYPE::ARMOR))
	{
		cout << "=====================================" << endl;
		cout << "번호 : " << number << endl;
		cout << "이름 : " << name << endl;
		cout << "방어력 : " << defence << endl;
		cout << "설명 : " << explain << endl;
		cout << "가격 : " << price << endl;
		cout << "갯수 : " << count << endl;
	}
	
}

Item::~Item()
{
}
