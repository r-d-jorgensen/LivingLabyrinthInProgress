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
		int lvl, maxHP, HP, stat[6];

		stats();
};
/*
   lvl is the characters lvl, used to determine skill points and monster lvl

   maxHP is the maximum health (HP) a player can have

   HP is the players current HP, which cannot be higher than maxHP

   stat[6] is where the players stats are stored,
   1 CON effects HP
   2 STR mainly effects Dmg with str weapons, block % when blocking
   3 DEX mainly effects Dmg with dex weapons 
   4 INT mainly effects Dmg with int weapons
   5 AGL mainly effects player speed (who goes first in combat), and dogde % when dodging
   6 LCK has a small effect in almost everything in the game, from item 
     generation to combat %'s
*/

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
/*
   inv[25] is an array of items that hold the players inventory
   	of armor, weapons, and misc items

   name is the name of the player, default is Librarian

   gold is the games currency

   textType is for output, 
   0 is bare, only showing the minimum needed, good for speech readers
   1 is sparce, has limited visuals and positions text in different spots on screen
   2 is visual, is a much more visual mode with ascii "art" and more visual output
   	will most likely not be implemented in time, but is still documented
	because it was originally planned to be in.
*/

class monster : public stats
{
	public:
		string name;
		
		monster();
		monster(int lvl);
		monster(string n);
};
/*
   name is the name of the monster
*/

//******************************************************************************
//BEGINNING OF STATS

//Default constructor to create new Char/Monster w/ base stats
stats::stats()
{
	lvl = 1;
	maxHP = 100;
	HP = maxHP;
	for (int x = 0; x < 6; x++)
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
	const char *s[6] = {"CON","STR", "DEX", "INT", "AGL", "LCK"};
	cout << "Name: " << name << "\n";
	printf("LVL: %i\nMax HP: %i\nHP: %i\n", lvl, maxHP, HP);
	for (int x = 0; x < 6; x++)
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
		inv[i] = item(to_string((rand() % 3) + 1));
	}
}

monster::monster()
{
	name = "";
	lvl = 0;
	maxHP = 0;
	HP = 0;
	for (int x = 0; x < 6; x++)
	{
		stat[x] = 0;
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
		for (int x = 0; x < 6; x++)
		{
			in >> stat[x];
		}	
	}
}
//END OF STATS
//******************************************************************************
