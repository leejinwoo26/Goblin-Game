#pragma once
#include "Item.h"
#include "player.h"
#include "Skill.h"


class inventory
{
private:

public:
	std::vector<Item> inventory;
	std::vector<Item> equipInventory;
	bool IsInventoryOpen = false;

	void printInventory(int input, player* p);
	void equipItem(int playerInput, int type, player* p);

};

