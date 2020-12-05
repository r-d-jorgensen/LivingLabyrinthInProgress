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
		int xp;
		int points;

		character();
		character(string n, int i, int d);
		character(const character &in);
		void addItem(item in);
		void equip(const item &i);
		void unequip(const item &in);
		void discard(item i);
		void inventory();
		void balanceInv();
		void showStats();
		void showInv();
		void giveXP(int xp);
		void levelUp();
		void die();
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
	maxHP = 5;
	HP = 5;
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
	maxHP = (stat[0] * (.5 + (.25 * (stat[0] / 5))) * lvl) * difficulty;
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

void character::addItem(item in)
{
	bool full = true;
	for (int i = 0; i < 25; i++)
	{
		if (inv[i].id == 0)
		{
			full = false;
			inv[i] = in;
			cout << "Item successfully added.\n";
			return;
		}
	}
	if (full == true)
	{
		string choice;
		int c = 0;
		cout << "Your inventory is full. Would you like to discard an item? (y/n)\n";
		while (true)
		{
			cin >> choice;
			if (choice == "Y" || choice == "y" || choice == "N" || choice == "n")
			{
				break;
			}
			cout << "Invalid choice, choose y or n\n";
		}
		if (choice == "Y" || choice == "y")
		{
			for (int i = 0; i < 24; i++)
			{
				cout << i << ". ";
				inv[i].showItem();
			}
			while (true)
			{
				cin >> c;
				if (c <= 25 && c > 1)
				{
					inv[c-1] = in;
					break;
				}
				cout << "Invalid choice, choose y or n\n";
			}

		}
		return;
	}
}

void character::unequip(const item &in)
{
	item temp;
	for (int i = 0; i < 25; i++)
	{
		if (inv[i].id == 0)
		{
			inv[i] = in;
			switch(in.type)
			{
				case 1:
					eqpt[in.subType] = temp;
					return;
				case 2:
					eqpt[0] = temp;
					return;
			}
		}
	}
	cout << "No room to unequip, discard an item first.\n";
}

void character::equip(const item &in)
{
	int eqp = in.subType;
	item temp;
	switch (in.type)
	{
		case 1:
			for (int i = 0; i < 25; i++)
			{
				if (inv[i].id == in.id)
				{
					temp = eqpt[eqp];
					eqpt[eqp] = in;
					inv[i] = temp;
				}
			}		
			break;
		case 2:
			for (int i = 0; i < 25; i++)
			{
				if (inv[i].id == in.id)
				{
					temp = eqpt[0];
					eqpt[0] = in;
					inv[i] = temp;
				}
			}
			break;
	}
	balanceInv();
}

void character::discard(item in)
{
	item temp;
	for (int i = 0; i < 25; i++)
	{
		if (inv[i].id == in.id)
		{
			inv[i] = temp;
			break;
		}
	}
	balanceInv();
}

void character::inventory()
{
	int j, c1, c2;
	bool r1 = false, r2 = true;
	while (true)
	{
		balanceInv();
		cout << "\033[2J\033[1;1H";
		j = 1;
		c1 = 0;
		cout << "Equipped Items\nWeapon: " << player.eqpt[0].name;
		cout << "\nHead: " << player.eqpt[1].name << "\nChest: ";
		cout << player.eqpt[2].name << "\nLegs: " << player.eqpt[3].name << "\n\n";
		for (int i = 0; i < 25; i++)
		{
			if (inv[i].id != 0)
			{
				cout << j << ". " << player.inv[i].name << "\n";
				j++;
			}
		}
		cout << "\n" << j << ". Return\n";
		cout << "\n";

		do
		{
			r1 = false;
			cin.clear();
			cin >> c1;

			if (c1 <= j && c1 > 0)
			{
				if (c1 == j)
				{
					return;
				}
				r1 = true;
				cout << player.inv[c1-1].name << "\n";
				cout << "1. Equip\n2. Discard\n3. Return\n";
				do
				{
					cin.clear();
					cin >> c2;
					switch (c2)
					{
						case 1: 
							equip(player.inv[c1 - 1]);
							break;
						case 2:
							discard(player.inv[c1 - 1]);
							break;
						case 3:
							break;
						default:
							r2 = false;
					}
					cin.clear();
				} while (!r2);
			}
		} while (!r1);
	}
}

void character::balanceInv()
{
	for (int i = 0; i < 25; i++)
	{
		if (inv[i].id == 0)
		{
			for (int j = 24; j > i; j--)
			{
				if (inv[j].id != 0)
				{
					item temp = inv[i];
					inv[i] = inv[j];
					inv[j] = temp;
				}
			}
		}
	}

	for (int i = 0; (inv[i].id != 0 && i < 25); i++)
	{
		int pos = i;
		for (int j = i; j < 25; j++)
		{
			if ((inv[j].id < inv[pos].id) && inv[j].id != 0)
			{
				pos = j;
			}
		}
		if (pos != i)
		{
			item temp = inv[i];
			inv[i] = inv[pos];
			inv[pos] = temp;
		}
	}

			
	/*
	   Old version left in for reference. This version appeared
	   to work but caused odd behavior when equipping items.

	int pos = -1;
	item temp[25];
	int used[25] = {0};

	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (pos < 0 && inv[j].id != 0 && used[j] == 0)
			{
				pos = j;
			}
			else if (pos > -1 && inv[j].id < inv[pos].id && used[j] == 0)
			{
				pos = j;
			}
		}
		if (pos > -1)
		{
			temp[i] = inv[pos];
			used[pos] = 1;
			pos = -1;
		} else {
			return;
		}
	}
	for (int i = 0; i < 25; i++)
	{
		inv[i] = temp[i];
	}
	*/
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

void character::giveXP(int x)
{
	int xpToNext = (((player.lvl) * (player.lvl)) * (player.lvl + 5));
	player.xp += x;
	if (player.xp > xpToNext)
	{
		int points = (difficulty / 3);
		player.xp = xp - xpToNext;
		player.lvl++;
		player.points += ((points < 1) ? 1 : points);
		player.HP = player.maxHP;
	}
}

void character::levelUp()
{
	const char *s[6] = {"CON", "STR", "DEX", "INT", "AGLE", "LCK"};
	bool r1 = true, r2 = true;
	int c1, c2;

	cout << "Choose Stat to increase.\n";

	for (int i = 0; i < 6; i++)
	{
		printf("%d. %s: %i", i+1, s[i], stat[i]);
	}
	cout << "7. Return\n";

	do
	{

		r1 = true;

		cin >> c1;
		c1 -= 1;

		if (c1 > 6 || c1 < 0)
		{
			r1 = false;
		} else if (c1 == 6) {
			return;
		} else {
			cout << "Available points: " << player.points << "\n";
			cout << "Choose amount to increase: ";
			do 
			{
				r2 = true;
				cin >> c2;
				if (c2 > player.points || c2 < 0)
				{
					r2 = false;
				} else {
					player.stat[c1] += c2;
					player.points -= c2;
					if (c2 == 0)
					{	
					maxHP = (stat[0] * (.5 + (.25 * (stat[0] / 5))) * lvl) * difficulty;
					}
				}
			} while (!r2);
		}
	} while (!r1);
}


void character::die()
{
	int penalty = (((player.gold * .25) > 30) ? (player.gold * 25) : 30);
	player.gold -= penalty;
	//send them back to the entrance of book
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
	if ((player.lvl + l) < 1)
	{
		l = 0;
	}
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
		in.clear();
		in.seekg(0);

		int i = (rand() % (lines/2)) * 2;
		while (i > 0) { getline(in, token); i--; }
		//
		in >> name;
		for (size_t i = 0; i < name.length(); i++)
		{
			if (name[i] == '_')
			{
				name[i] = ' ';
			}
		}
		for (int x = 0; x < 6; x++)
		{
			in >> stat[x];
		}
		in >> diff;
		lvl = player.lvl + l;
		maxHP = (stat[0] * (.5 + (.25 * (((float)stat[0]) / 5))) * lvl);
		HP = maxHP;
		//if (lvl < 1) 
		//{ 
		//	*this = monster(l); 
		//}
	}
}

//Copy Constructor
monster::monster(const monster &in)
{
	name = in.name;
	lvl = in.lvl;
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
