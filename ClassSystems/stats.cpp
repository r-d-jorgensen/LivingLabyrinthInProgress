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
   0 CON effects HP
   1 STR mainly effects Dmg with str weapons, block % when blocking
   2 DEX mainly effects Dmg with dex weapons 
   3 INT mainly effects Dmg with int weapons
   4 AGL mainly effects player speed (who goes first in combat), and dogde % when dodging
   5 LCK has a small effect in almost everything in the game, from item 
     generation to combat %'s
*/

class character : public stats
{
	public:
		item inv[25];
		item eqpt[4];
		string name;
		int gold;
		int textType;
		int difficulty;

		character();
		character(string n, int i, int d);
		character(const character &in);
		void equip(const item &i);
		void unequip(int eqp, const item &in);
		void discard(item i);
		void showStats();
		void showInv();
		//Following Function is for testing only,
		//Fills the characters inventory with items
		void fillInv();
};

extern character player;
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
		int diff;
		
		monster();
		monster(int lvl);
		monster(string n);
		monster(const monster &in);
};
/*
   name is the name of the monster
   diff is the monster difficulty, used when generating monsters to ensure 
   that the player doesnt run into a super hard monster early on
*/

//******************************************************************************
//BEGINNING OF STATS

//Default constructor to create new Char/Monster w/ base stats
stats::stats()
{
	lvl = 1;
	for (int x = 0; x < 6; x++)
	{
		stat[x] = 1;
	}
	maxHP = 100;
	HP = maxHP;
}

//Creating a new Char.
character::character(string n, int i, int d) : stats::stats()
{
	name = n;
	textType = i;
	gold = 0;
	difficulty = d;
	for (int i = 0; i < 4; i++)
	{
		eqpt[i] = item();
	}
	maxHP = (stat[1] * (.5 + (.25 * (stat[1] / 5))) * lvl) * difficulty;
	HP = maxHP;
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
	difficulty = in.difficulty;
	for (int i = 0; i < 5; i++)
	{
		stat[i] = in.stat[i];
	}
	for (int i = 0; i < 25; i++)
	{
		inv[i] = in.inv[i];
	}
}

//Default incase player doesn't input name.
character::character()
{
	character("Librarian", 0, 10);
}

void unequip(int eqp, const item &in)
{
	for (int i = 0; i < 25; i++)
	{
		if (player.inv[i].id == in.id)
		{
			item temp = player.eqpt[eqp];
			player.eqpt[eqp] = in;
			player.inv[i] = temp;
			break;
		}
	}
}

void equip(const item &i)
{
	switch (i.type)
	{
		case 1:
			switch(i.subType)
			{
				case 1: 
					unequip(2, i);
					break;
				case 2:
					unequip(3, i);
					break;
				case 3:
					unequip(4, i);
					break;
			}
			break;
		case 2:
			unequip(1, i);
			break;
	}
}

void character::showStats()
{
	const char *s[6] = {"CON","STR", "DEX", "INT", "AGL", "LCK"};
	cout << "Name: " << name << "\n";
	printf("LVL: %i\nMax HP: %i\nHP: %i\nDifficulty: %i\n", lvl, maxHP, HP, difficulty);
	for (int x = 0; x < 6; x++)
	{
		printf("%s: %i\n", s[x], stat[x]);
	}
}

void character::showInv()
{
	for (int i = 0; i < 25; i++)
	{
		if (inv[i].id != 0)
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
		in >> maxHP;
		in >> HP;
		for (int x = 0; x < 6; x++)
		{
			in >> stat[x];
		}
		in >> diff;
		lvl = (player.lvl + l) - diff;
		if (diff < 1) 
		{ 
			*this = monster(l); 
		}
	}
}

//Copy Constructor
monster::monster(const monster &in)
{
	name = in.name;
	maxHP = in.maxHP;
	HP = in.HP;
	for (int x = 0; x < 5; x++)
	{
		stat[x] = in.stat[x];
	}
	diff = in.diff;
}
//END OF STATS
//******************************************************************************
