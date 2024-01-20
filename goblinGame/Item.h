#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <time.h>
#include <conio.h>
using namespace std;


enum class TYPE
{
	EXIT,
	WEAPON,
	ARMOR
};
enum class Choice
{
	NONE=0,
	ADVENTURE=1,
	STORE=2,
	INVENTORY=3,
	EXIT=4
};




class Item
{
private:

public:
	string name;
	string explain;
	int damage;
	int price;
	int number;
	int heal;
	int mp;
	int defence;
	int count;
	int type;
	bool IsSold;

	


	void printItem();
	Item();
	~Item();
};

