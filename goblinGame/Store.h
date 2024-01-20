#pragma once
#include "Item.h"
#include "inventory.h"
#include "player.h"


class Store
{
private:
public:
	std::vector<Item> buyItem;
	std::vector<Item> vItem;
	bool InventoryOpen = false;

	void printvItem(player* p,int input);
	void addBuyItem(inventory* inven, player* p, int input, int type);
	//std::vector<Item> getBuyItems() { return buyItem; }

	Store();
	~Store();


};

