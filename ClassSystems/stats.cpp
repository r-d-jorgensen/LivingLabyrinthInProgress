//Jason Jellie
#pragma once
#include <iostream>
#include <fstream>
#include "items.cpp"
//rand is needed for fillInv()
#include <cstdlib>

using namespace std;

class stats
{
	public:
		int lvl, maxHP, HP, stat[5];

		stats();
};

class character : public stats
{
	public:
		item inv[25];
		//item eqpt[5];
		string name;
		int gold;
		int textType;

		character();
		character(string n, int i);
		character(const character &in);
		void showStats();
		void showInv();
		//Following Function is for testing only,
		//Fills the characters inventory with items
		void fillInv();
};

class monster : public stats
{
	public:
		string name;

		monster(int lvl);
		monster(string n);
};

//******************************************************************************
//BEGINNING OF STATS

//Default constructor to create new Char/Monster w/ base stats
stats::stats()
{
	lvl = 1;
	maxHP = 100;
	HP = maxHP;
	for (int x = 0; x < 5; x++)
	{
		stat[x] = 1;
	}
}

//Creating a new Char.
character::character(string n, int i) : stats::stats()
{
	name = n;
	textType = i;
	gold = 0;
}

//Copy Constructor
character::character(const character &in)
{
	name = in.name;
	textType = in.textType;
	gold = in.gold;
	lvl = in.lvl;
	maxHP = in.maxHP;
	HP = in.HP;
	for (int x = 0; x < 5; x++)
	{
		stat[x] = in.stat[x];
	}
	for (int i = 0; i < 25; i++)
	{
		inv[i] = in.inv[i];
	}
}

//Default incase player doesn't input name.
character::character()
{
	character("Librarian", 0);
}

void character::showStats()
{
	const char *s[5] = {"STR", "INT", "DEX", "AGL", "LCK"};
	cout << "Name: " << name << "\n";
	printf("LVL: %i\nMax HP: %i\nHP: %i\n", lvl, maxHP, HP);
	for (int x = 0; x < 5; x++)
	{
		printf("%s: %i\n", s[x], stat[x]);
	}
}

void character::showInv()
{
	for (int i = 0; i < 25; i++)
	{
		if (inv[i].name != "")
		{
			inv[i].showItem();
		}
	}
}

void character::fillInv()
{
	srand(time(0));
	for (int i = 0; i < 25; i++)
	{
		inv[i] = item((rand() % 3) + 1);
	}
}

monster::monster(int l)
{
	string token;
	int lines;
	srand(time(0));

	ifstream in("./Monsters/monsters.txt");
	if (in.is_open())
	{
		while (!in.eof())
		{
			getline(in, token);
			lines++;
		}
		in.seekg(0);
		in.clear();

		int i = (rand() % lines/2) * 2;
		while (i > 0) { getline(in, token); i--; }
		//
		in >> name;
		lvl = l;
		in >> maxHP;
		in >> HP;
		for (in x = 0; x < 5; x++)
		{
			in >> stat[x];
		}	
	}
}
//END OF STATS
//******************************************************************************
