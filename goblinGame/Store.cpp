#include "Store.h"



Store::Store()
{
	Item weapon[5];
	Item armor[5];

	weapon[0].name = "������";
	weapon[0].explain = "�������� ���̴�.";
	weapon[0].damage = 10;
	weapon[0].defence = 0;
	weapon[0].price = 1000;
	weapon[0].IsSold = false;
	weapon[0].number = 1;
	weapon[0].heal = 0;
	weapon[0].mp = 0;
	weapon[0].count = 1;
	weapon[0].type = static_cast<int>(TYPE::WEAPON);

	weapon[1].name = "ö��";
	weapon[1].explain = "�ܴ��� ö���̴�.";
	weapon[1].damage = 20;
	weapon[1].defence = 0;
	weapon[1].price = 2000;
	weapon[1].IsSold = false;
	weapon[1].number = 2;
	weapon[1].heal = 0;
	weapon[1].mp = 0;
	weapon[1].count = 1;
	weapon[1].type = static_cast<int>(TYPE::WEAPON);

	weapon[2].name = "�ռҵ�";
	weapon[2].explain = "���� �� ���̴�.";
	weapon[2].damage = 30;
	weapon[2].defence = 0;
	weapon[2].price = 3000;
	weapon[2].IsSold = false;
	weapon[2].number = 3;
	weapon[2].heal = 0;
	weapon[2].mp = 0;
	weapon[2].count = 1;
	weapon[2].type = static_cast<int>(TYPE::WEAPON);

	weapon[3].name = "��Ƽ��Ż �ҵ�";
	weapon[3].explain = "���� ����ũ�� ���̴�.";
	weapon[3].damage = 40;
	weapon[3].defence = 0;
	weapon[3].price = 4000;
	weapon[3].IsSold = false;
	weapon[3].number = 4;
	weapon[3].heal = 0;
	weapon[3].mp = 0;
	weapon[3].count = 1;
	weapon[3].type = static_cast<int>(TYPE::WEAPON);

	weapon[4].name = "�ƴٸ�Ƽ�� ��";
	weapon[4].explain = "���� �ְ� ���̴�.";
	weapon[4].damage = 50;
	weapon[4].defence = 0;
	weapon[4].price = 5000;
	weapon[4].IsSold = false;
	weapon[4].number = 5;
	weapon[4].heal = 0;
	weapon[4].mp = 0;
	weapon[4].count = 1;
	weapon[4].type = static_cast<int>(TYPE::WEAPON);
	//////////////////////////////////////////
	armor[0].name = "���� ��";
	armor[0].explain = "�������� ���̴�.";
	armor[0].defence = 10;
	armor[0].damage = 0;
	armor[0].price = 1000;
	armor[0].IsSold = false;
	armor[0].number = 1;
	armor[0].heal = 0;
	armor[0].mp = 0;
	armor[0].count = 1;
	armor[0].type = static_cast<int>(TYPE::ARMOR);

	armor[1].name = "ö��";
	armor[1].explain = "�ܴ��� ö �� �̴�.";
	armor[1].defence = 20;
	armor[1].damage = 0;
	armor[1].price = 2000;
	armor[1].IsSold = false;
	armor[1].number = 2;
	armor[1].heal = 0;
	armor[1].mp = 0;
	armor[1].count = 1;
	armor[1].type = static_cast<int>(TYPE::ARMOR);

	armor[2].name = "û��10���� ö��";
	armor[2].explain = "����������.";
	armor[2].defence = 30;
	armor[2].damage = 0;
	armor[2].price = 3000;
	armor[2].IsSold = false;
	armor[2].number = 3;
	armor[2].heal = 0;
	armor[2].mp = 0;
	armor[2].count = 1;
	armor[2].type = static_cast<int>(TYPE::ARMOR);

	armor[3].name = "��Ƽ��Ż ��";
	armor[3].explain = "���� ����ũ�� �� �̴�.";
	armor[3].defence = 40;
	armor[3].damage = 0;
	armor[3].price = 4000;
	armor[3].IsSold = false;
	armor[3].number = 4;
	armor[3].heal = 0;
	armor[3].mp = 0;
	armor[3].count = 1;
	armor[3].type = static_cast<int>(TYPE::ARMOR);

	armor[4].name = "�ƴٸ�Ƽ�� ��";
	armor[4].explain = "���� �ְ� ���̴�.";
	armor[4].defence = 50;
	armor[4].damage = 0;
	armor[4].price = 5000;
	armor[4].IsSold = false;
	armor[4].number = 5;
	armor[4].heal = 0;
	armor[4].mp = 0;
	armor[4].count = 1;
	armor[4].type = static_cast<int>(TYPE::ARMOR);
	
	

	for (int i = 0; i < 5; ++i)
	{
		vItem.push_back(weapon[i]);
	}
	for (int i = 0; i < 5; ++i)
	{
		vItem.push_back(armor[i]);
	}
	
}
void Store::printvItem(player* p,int input)//������ ����Ʈ
{
	system("cls");
	for (int i = 0; i < vItem.size(); ++i)
	{
		if (input == vItem[i].type)
		{
			vItem[i].printItem();
		}
	}
	cout << "������ �ִ� �� :" << p->money << endl;
}


void Store::addBuyItem(inventory* inven,player* p,int input,int type)//������ -> �κ��丮 �߰�
{
	for (int i = 0; i < vItem.size(); ++i)
	{
		if (vItem[i].type == type && vItem[i].number == input)
		{
			if (vItem[i].count == 0)
			{
				cout << "���� ��� �����ϴ�." << endl;
				Sleep(1000);
				break;
			}
			if (p->money < vItem[input].price)
			{
				cout << "���� �����մϴ�." << endl;
				Sleep(1000);
				break;
			}
			else
			{
				cout << "���� �Ϸ�!" << endl;
				inven->inventory.push_back(vItem[i]);
				inven->IsInventoryOpen = true;
				vItem[i].count -= 1;
				p->money -= vItem[i].price;
				Sleep(500);
				break;
			}
		}
	}
}

Store::~Store()
{
}
