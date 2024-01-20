#include "inventory.h"

void inventory::printInventory(int input,player* p)
{
	cout << "===========인벤토리==========" << endl;
	if (inventory.empty())
	{
		system("cls");
		cout << "텅빔" << endl;
		Sleep(500);
	}
	else
	{
		system("cls");
		for (int i = 0; i < inventory.size(); ++i)
		{
			if (input == inventory[i].type)
			{
				inventory[i].printItem();
			}
		}
		int Playerinput;
		cout << "어떤 아이템을 착용하시겠습니까?" << endl;
		cout << "선택 : ";
		cin >> Playerinput;
		equipItem(Playerinput,input,p);
	}
}

void inventory::equipItem(int playerInput,int type,player* p)
{
	if (type == 1)//무기
	{
		for (int i = 0; i < inventory.size(); ++i)
		{
			if (playerInput == inventory[i].number && inventory[i].type == static_cast<int>(TYPE::WEAPON))
			{
				if (p->IsWeaponEquip == false)
				{
					cout << inventory[i].name << "을 착용하였습니다." << endl;
					cout << endl;
					p->attack += inventory[i].damage;
					cout << "현재 공격력 : " << p->attack << endl;
					equipInventory.push_back(inventory[i]);
					inventory.erase(inventory.begin() + i);
					p->IsWeaponEquip = true;
					Sleep(1000);
					break;
				}
				else
				{
					cout << "기존의 장비를 해제 합니다." << endl;
					cout << endl;
					cout << inventory[i].name << "을 착용하였습니다." << endl;
					cout << endl;
					p->attack += inventory[i].damage - equipInventory[0].damage;
					cout << "현재 공격력 : " << p->attack << endl;
					for (int j = 0; j < equipInventory.size(); ++j)
					{
						if (equipInventory[j].type == static_cast<int>(TYPE::WEAPON))
						{
							inventory.push_back(equipInventory[j]);
							equipInventory.erase(equipInventory.begin() + j);
							break;
						}
					}
					equipInventory.push_back(inventory[i]);
					inventory.erase(inventory.begin() + i);
					Sleep(1000);
					break;
				}
			}
			else
			{
				continue;
			}
		}
	}
	else if (type == 2)//방어구
	{
		for (int i = 0; i < inventory.size(); ++i)
		{
			if (playerInput == inventory[i].number && inventory[i].type == static_cast<int>(TYPE::ARMOR))
			{
				if (p->IsArmorEquip == false)
				{
					cout << inventory[i].name << "을 착용하였습니다." << endl;
					cout << endl;
					cout << "현재 방어력 : " << p->defence << endl;
					equipInventory.push_back(inventory[i]);
					inventory.erase(inventory.begin() + i);
					p->IsArmorEquip = true;
					Sleep(500);
					break;
				}
				else
				{
					cout << "기존의 장비를 해제 합니다." << endl;
					cout << endl;
					cout << inventory[i].name << "을 착용하였습니다." << endl;
					cout << endl;
					p->defence += inventory[i].defence - equipInventory[i].defence;
					cout << "현재 방어력 : " << p->defence << endl;
					for (int j = 0; j < equipInventory.size(); ++j)
					{
						if (equipInventory[j].type == static_cast<int>(TYPE::ARMOR))
						{
							inventory.push_back(equipInventory[j]);
							equipInventory.erase(equipInventory.begin() + j);
							break;
						}
					}
					equipInventory.push_back(inventory[i]);
					inventory.erase(inventory.begin() + i);
					Sleep(500);
					break;
				}
			}
			else
			{
				continue;
			}
		}
	}
}
