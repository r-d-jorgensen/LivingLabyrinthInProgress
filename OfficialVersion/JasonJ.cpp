//Jason Jellie
#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
//rand is needed for fillInv()
#include <cstdlib>

using namespace std;

class item
{
public:
	int id;
	int type;
	int subType;
	int value;
	int subValue;
	int percent;
	string name;

	item();
	//item(string n);
	item(string t);
	item(int id);
	item(const item &in);

	void showItem();
};

//SCOTT'S CODE
//See comment at end of file for reasoning why its in my file.
class FinalPuzzle
{
	public:
		// default constructor
		FinalPuzzle();
		// constructor
		FinalPuzzle(string solution, string puzzle, int curRings, int ringSNeeded);
		void setFinalPuzzle(string finalPuzzle); // Mutator
		string getFinalPuzzle() const;           // Accessor
		void setFinalSolution(string finalSolution); // Mutator
		string getFinalSolution() const;             // Accessor
		void setTotalRingsNeeded(int totalRings);
		int getTotalRingsNeeded() const;
		void setCurrentRings(int totalRings);
		int getCurrentRings() const;
	private:
		string jumbledWord;
		string correctWord;
		int totalRingsNeeded;
		int ringsFound;
}; // end of class definition
//END OF SCOTT'S CODE

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
	FinalPuzzle thePuzzle;

	character();
	character(string n, int i, int d);
	character(const character &in);
	void addItem(item in);
	void equip(const item &i);
	void unequip(const item &in);
	void discard(item i);
	bool inventory();
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

//Function is called battle in order to not be the same as the combat function
//but still have a similar enough name.
class battle
{
public:
	//vars are damage, accuracy, block%, dodge%
	//for both the player and the monster then
	//for just the player potion damage and speed
	//also monter crit, player crit, the monster object
	//actual stat values, player weight, player weapon type stat
	int mdmg, macc;
	int pdmg, pacc;
	int mdge, pdge;
	bool mblk, pblk;
	int potdmg, potspd;
	bool mcrit, pcrit;
	bool matk, patk;
	monster m;
	int mact[6], act[6];
	int weight, wts;
	int maction, paction;
	int mtype;

	//Used to see if the fight is over.
	bool done;

	//constructor
	battle(monster m);

	//functions
	void takeTurn();
	void monsterTurn();
	void endCombat(bool win);
	void attack();
	void block();
	void dodge();
	void use();
	void heal(int val);
};

//Function Prototypes
void combat(monster m);

ostream &operator<<(ostream &out, const character &in);
istream &operator>>(istream &in, character &out);
istream &operator>>(istream &in, monster &out);
void saveOut(character &in);
character loadIn();
monster loadMonster();

#include "ScottK.cpp"
#include "DavidJ.cpp"
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
	points = 0;
	for (int i = 0; i < 4; i++)
	{
		eqpt[i] = item();
	}
	maxHP = (stat[0] * (.5 + (.25 * (stat[0] / 5))) * lvl);
	HP = maxHP;
	string questKey = questAnswer(11-difficulty);
	string jumble = anagram(questKey);
	thePuzzle = FinalPuzzle(questKey, jumble, 0, (11-difficulty) + 2);
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
	points = in.points;
	difficulty = in.difficulty;
	for (int i = 0; i < 6; i++)
	{
		stat[i] = in.stat[i];
	}
	for (int i = 0; i < 25; i++)
	{
		inv[i] = in.inv[i];
	}
	for (int i = 0; i < 4; i++)
	{
		eqpt[i] = in.eqpt[i];
	}
	thePuzzle.setFinalSolution(in.thePuzzle.getFinalSolution());
	thePuzzle.setFinalPuzzle(in.thePuzzle.getFinalPuzzle());
	thePuzzle.setCurrentRings(in.thePuzzle.getCurrentRings());
	thePuzzle.setTotalRingsNeeded(in.thePuzzle.getTotalRingsNeeded());
}

//Default
//As far as I know, there is no situation in which
//this would be called, but it is here just in case.
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
			dialogue("Item successfully added.");
			return;
		}
	}
	if (full == true)
	{
		string choice;
		int c = 0;
		dialogue("Your inventory is full. Would you like to discard an item? (y/n)");
		while (true)
		{
			cin >> choice;
			if (choice == "Y" || choice == "y" || choice == "N" || choice == "n")
			{
				break;
			}
			dialogue("Invalid choice, choose y or n");
		}
		if (choice == "Y" || choice == "y")
		{
			for (int i = 0; i < 24; i++)
			{
				dialogue(i + ". ");
				inv[i].showItem();
			}
			while (true)
			{
				cin >> c;
				if (c <= 25 && c > 1)
				{
					inv[c - 1] = in;
					break;
				}
				dialogue("Invalid choice, choose y or n");
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
			switch (in.type)
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
	dialogue("No room to unequip, discard an item first.");
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

bool character::inventory()
{
	int j, c1, c2;
	bool r1 = false, r2 = true;
	//while (true)
	//{
	balanceInv();
	dialogue("\033[2J\033[1;1H");
	j = 1;
	c1 = 0;
	dialogue("Equipped Items\nWeapon: " + player.eqpt[0].name);
	dialogue("Head: " + player.eqpt[1].name);
	dialogue("Chest: " + player.eqpt[2].name);
	dialogue("Legs: " + player.eqpt[3].name);
	for (int i = 0; i < 25; i++)
	{
		if (inv[i].id != 0)
		{
			dialogue(j + ". " + player.inv[i].name);
			j++;
		}
	}
	dialogue(j + ". Return");

	do
	{
		r1 = false;
		cin.clear();
		cin >> c1;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore();
			r1 = false;
		}
		else
		{
			if (c1 <= j && c1 > 0)
			{
				if (c1 == j)
				{
					return true;
				}
				r1 = true;
				dialogue(player.inv[c1 - 1].name);
				dialogue("1. Equip");
				dialogue("2. Discard");
				dialogue("3. Return");
				do
				{
					cin.clear();
					cin >> c2;
					if (!cin.good())
					{
						cin.clear();
						cin.ignore();
						r1 = false;
					}
					else
					{
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
					}
				} while (!r2);
			}
		}
	} while (!r1);
	return false;
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
	const char *s[6] = {"CON", "STR", "DEX", "INT", "AGL", "LCK"};
	dialogue("Name: " + name);
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
	while (player.xp > xpToNext)
	{
		int points = (difficulty / 3);
		player.xp -= xpToNext;
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

	while (true)
	{
		dialogue("\033[2J\033[1;1H");
		dialogue("Choose a stat to increase.");
		dialogue("Available points: " + player.points);

		for (int i = 0; i < 6; i++)
		{
			printf("%d. %s: %i\n", i + 1, s[i], stat[i]);
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
			}
			else if (c1 == 6)
			{
				return;
			}
			else
			{
				cout << "Choose amount to increase: ";
				do
				{
					r2 = true;
					cin >> c2;
					if (c2 > player.points || c2 < 0)
					{
						r2 = false;
					}
					else
					{
						player.stat[c1] += c2;
						player.points -= c2;
					}
				} while (!r2);
			}
		} while (!r1);
		maxHP = (stat[0] * (.5 + (.25 * (stat[0] / 5))) * lvl);
	}
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
	/*New Idea to help generate monsters
	  monsters are now ordered by difficulty within the
	  monsters.txt file, the result of rand can now be 
	  modified to ensure that it never generates a monster
	  that it cant use, which causes way too many calls and breaks
	  the function. Hopefully this works cause this is kinda a last
	  ditch effort before I just restart monsters.
	 */
	//Difficulties are 1-6
	//Difficulty 10 enemies have been temporarily removed, they still
	//exist within the file but will never be generated.
	//array containing the number of monsters at each difficulty
	int arr[6] = {1, 5, 5, 3, 3, 2};
	int maxDiff = player.lvl + l;
	int lines = 0;

	if (maxDiff > 6)
	{
		maxDiff = 6;
	}
	if (maxDiff < 1)
	{
		maxDiff = 1;
	}

	for (int i = 0; i < maxDiff; i++)
	{
		lines += arr[i];
	}
	int i = (rand() % lines) * 2;

	string token;
	srand(time(0));

	ifstream in("./txtFiles/monsters.txt");
	if (in.is_open())
	{
		while (i > 0)
		{
			getline(in, token);
			i--;
			cout << token << "\n";
		}
		//
		in >> name;
		cout << name << "\n";
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
			cout << stat[x] << " ";
		}
		cout << "\n";
		in >> diff;
		lvl = maxDiff;
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
//******************************************************************************
//BEGINNING OF ITEMS

/* 
   id is a unique number given to each item, the first digit is the item type,
   1 for armor, 2 for weapons, 3 for misc. The next two digits is the
   items number, each file starts at (type)-0-1, incrementing by
   one each item in the file

   type is the item type as described above

   subType is a number given to each item to separate subclasses of items
   within each type. i.e. for armor, 1 for helmet, 2 for chestpiece etc.
   these numbers are just examples  and might change in the future.

   value is the amount that each item modifies stats, each type changes
   different stats. i.e. armor = def, weapon = dmg, misc may be 
   HP, dmg, crit chance ect depending on the item

   subvalue is a special value for items, weapons are hit chance,
   armor is weight, unknown if misc will use this value

   percent is (for now) used exclusively for weapon crit%

   name is the name of the item, exists simply for the player
 */

item::item()
{
	name = "";
	id = 0;
	type = 0;
	subType = 0;
	value = 0;
	subValue = 1;
	percent = 0;
}
/* Taken out as key items aren't implemented as of yet
   and it is unknown how they will actually be used/stored

   item::item(string n)
   {
   n.erase(n.find_last_not_of("\n\r") + 1);
   string line;
   ifstream in("./Items/keyItems.txt");
   while (!in.eof())
   {
   in >> line;
   line.erase(n.find_last_not_of("\n\r") + 1);
   if (line == n)
   {
   name = line;
   in >> id;
   type = 0;
   in >> value;
   break;
   }
   }
   }
 */

item::item(string t)
{
	string txt = "./txtFiles/";
	int lines = 0, itype = stoi(t);
	string temp, idtemp;

	if (itype == 0)
	{
		itype = (rand() % 3) + 1;
	}

	switch (itype)
	{
	case 1:
		txt += "armor.txt";
		type = 1;
		break;
	case 2:
		txt += "weapons.txt";
		type = 2;
		break;
	case 3:
		txt += "misc.txt";
		type = 3;
		break;
	default:
		txt += "failed.txt";
		break;
	}

	ifstream in;
	in.open(txt);
	while (!in.eof())
	{
		getline(in, temp);
		lines++;
	}
	in.clear();
	in.seekg(0);

	int i = (rand() % (lines / 2)) * 2;
	while (i > 0)
	{
		getline(in, temp);
		i--;
	}
	in >> name;
	//Item names are stored int a text file using underscores so names are one "word"
	//This block replaces the underscore with a space
	for (size_t i = 0; i < name.length(); i++)
	{
		if (name[i] == '_')
		{
			name[i] = ' ';
		}
	}
	//Items id's are stored with a / at the beginning, this is explained in item(int i)
	in >> idtemp;
	idtemp = idtemp.substr(1, idtemp.size() - 1);
	id = stoi(idtemp);
	in >> subType;
	in >> value;
	in >> subValue;
	in >> percent;
	in.close();
}

item::item(int i)
{
	string token;
	string temp;
	string txt = "./txtFiles/";
	item empty;
	if (i == 0)
	{
		*this = empty;
	}

	/*Item id's contain what type of item they are, with the first digit being
	  important one. The next line rounds the number to the nearest hundredth,
	  then divides the number by 100 to find the first digit. */
	switch ((i - (i % 100)) / 100)
	{
	case 1:
		txt += "armor.txt";
		type = 1;
		break;
	case 2:
		txt += "weapons.txt";
		type = 2;
		break;
	case 3:
		txt += "misc.txt";
		type = 3;
		break;
	default:
		txt += "failed.txt";
		break;
	}

	ifstream in(txt);
	if (in.is_open())
	{
		while (!in.eof())
		{
			/*Id's are stored with a / at the beginning of them in order to 
			  easily differenciate them from other item values. It is simple
			  to deal with this / by comparing the token to the wanted id with
			  a / added to the beginning of it */
			in >> token;
			if (token == "/" + to_string(i))
			{
				id = i;
				name = temp;
				in >> subType;
				in >> value;
				in >> subValue;
				in >> percent;
				for (size_t i = 0; i < name.length(); i++)
				{
					if (name[i] == '_')
					{
						name[i] = ' ';
					}
				}
				return;
			}
			else
			{
				temp = token;
			}
		}
		in.close();
	}
}

item::item(const item &in)
{
	name = in.name;
	id = in.id;
	type = in.type;
	subType = in.subType;
	value = in.value;
	subValue = in.subValue;
	percent = in.percent;
}

void item::showItem()
{
	if (type != 0)
	{
		cout.setf(ios::left);
		cout << setw(33) << "Name: " + name;
		cout << setw(10) << "ID: " + to_string(id);

		switch (type)
		{
		case 1:
			cout << setw(15) << "Type: Armor";
			switch (subType)
			{
			case 1:
				cout << setw(17) << "Class: Head";
				break;
			case 2:
				cout << setw(17) << "Class: Chest";
				break;
			case 3:
				cout << setw(17) << "Class: Head";
				break;
			}
			cout << setw(9) << "Defense: " << setw(4) << to_string(value);
			cout << setw(8) << "Weight: " << setw(4) << to_string(subValue);
			//cout << setw(10) << "Percent: " + to_string(percent);
			break;
		case 2:
			cout << setw(15) << "Type: Weapon";
			switch (subType)
			{
			case 1:
				cout << setw(17) << "Class: INT";
				break;
			case 2:
				cout << setw(17) << "Class: STR";
				break;
			case 3:
				cout << setw(17) << "Class: DEX";
				break;
			}
			cout << setw(9) << "Damage: " << setw(4) << to_string(value);
			cout << setw(8) << "Hit%: " << setw(4) << to_string(subValue);
			cout << setw(10) << "Crit%: " + to_string(percent);
			break;
		case 3:
			cout << setw(15) << "Type: Misc";
			switch (subType)
			{
			case 1:
				cout << setw(17) << "Class: Healing";
				break;
			case 2:
				cout << setw(17) << "Class: Damage";
				break;
			case 3:
				cout << setw(17) << "Class: Speed";
				break;
			}
			cout << setw(9) << "Value: " << setw(4) << to_string(value);
			//cout << setw(14) << "Weight: " + to_string(subValue);
			//cout << setw(10) << "Percent: " + to_string(percent);
			break;
		}
		cout << "\n";
	}
}
//END OF ITEMS
//******************************************************************************
//******************************************************************************
//BEGINNING OF COMBAT
/*
   New idea in order to easily carry information between turns/functions.
   Create an object and store neccessary vars of both teams
   and also use the functions already created 
 */

/*
   A lot of this code was written late at night/with little sleep
   so some of the choices made may seem odd/not optimal but
   it is what I was able to come up with to do what I needed 
 */

/*
   This comment is outdated, another solution was found but I decided to 
   leave this one in to allow anyone reading to see my thought process 
   throughout the codes progress.


   Output to screen is placeholder for testing, will be modified to use
   the dialog functions.

   Have an idea to make returning work. Use a try catch block in order to return
   and choose your action again without needing to pass/return another option.

   If the player wants to return to an earlier choice, throw back to the catch block
   and show them the choices again.

   Will implement this in the future.
 */

void combat(monster m)
{
	int choice;
	//pgf = Player Goes First
	bool right = true;
	battle c(m);

	while (!c.done)
	{
		do
		{
			try
			{
				cin.clear();
				choice = 0;
				right = true;
				cout << "\033[2J\033[1;1H";
				dialogue(c.m.name + " Level: " + to_string(c.m.lvl));
				dialogue(" Health: " + to_string(c.m.HP) + "/" + to_string(c.m.maxHP));
				dialogue(player.name + " Level: " + to_string(player.lvl));
				dialogue("Health: " + to_string(player.HP) + "/" + to_string(player.maxHP));
				cout << "1: Attack\n";
				cout << "2: Block\n";
				cout << "3: Dodge\n";
				cout << "4: Use Item\n";

				cin >> choice;
				if (!cin.good())
				{
					cin.clear();
					cin.ignore();
					right = false;
				}
				else
				{
					switch (choice)
					{
					case 1:
						c.attack();
						break;
					case 2:
						c.paction = 3;
						c.block();
						break;
					case 3:
						c.paction = 4;
						c.dodge();
						break;
					case 4:

						c.use();
						break;
					default:
						right = false;
					}
				}
			}
			catch (char const *e)
			{
				right = false;
			}
		} while (!right);
		c.takeTurn();
	}
}

battle::battle(monster in)
{
	m = in;
	mdmg = 0, macc = 0;
	pdmg = 0, pacc = 0;
	pblk = false, pdge = 0;
	mblk = false, mdge = 0;
	potdmg = 0, potspd = 0;
	matk = false, patk = false;
	maction = 0, paction = 0;
	mtype = 0;

	done = false;

	for (int i = 1; i < 4; i++)
	{
		weight += player.eqpt[i].subValue;
	}

	for (int i = 0; i < 6; i++)
	{
		act[i] = (player.stat[i] * (.5 + (.25 * (player.stat[i] / 5))) * player.lvl);
	}

	if (player.maxHP < 5)
	{
		player.maxHP = 5;
	}
	player.HP = player.maxHP;

	switch (player.eqpt[0].subType)
	{
	case 1:
		wts = 3;
		break;
	case 2:
		wts = 1;
		break;
	case 3:
		wts = 2;
		break;
	default:
		wts = 1;
	}

	//Get monsters leveled stats and then convert to actual.
	//Idea for more weighted stats if there's time, add totals of all
	//base stats then make rand between 1-total, then choose based on
	//what it rolls, ie 1-con, con+1-con+str, con+str+1-con+str+dex ect.
	int points = 0;
	for (int i = 0; i < m.lvl; i++)
	{
		points += (4 - (player.difficulty / 3));
	}
	for (int i = 0; i < m.lvl; i++)
	{
		int x = (rand() % 6);
		if (m.stat[x] == 0)
		{
			i--;
		}
		else
		{
			m.stat[x]++;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		mact[i] = (m.stat[i] * (.5 + (.25 * (((float)m.stat[i]) / 5))) * m.lvl);
	}
	if (m.maxHP < 5)
	{
		m.maxHP = 5;
	}

	m.HP = m.maxHP;
}

void battle::takeTurn()
{
	monsterTurn();
	//Check to see who goes first, will be true if player goes first
	//In order to counter-act weight, mosnters agility is less valueable
	bool FA = (((act[4] * .25) + (act[5] * .1) - weight) * (((float)potspd) / 100)) >= ((mact[4] * .15) + (mact[5] * .1));
	bool mhit, phit, mcrit, pcrit;
	//Player and monster damage taken
	int ptaken = 0, mtaken = 0;
	if ((pacc - ((mact[4] * .1) + (mact[5] * .1) > 0)) && ((rand() % 100) > mdge))
	{
		phit = true;
		if ((rand() % 100) < (player.eqpt[0].percent + act[5] * .5))
		{
			pcrit = true;
			pdmg *= 2;
		}
	}
	if ((macc - ((act[4] * .1) + (act[5] * .1) > 0)) && ((rand() % 100) > pdge))
	{
		mhit = true;
		if ((rand() % 100) < (10 + (act[5] * .5)))
		{
			mcrit = true;
			mdmg *= 2;
		}
	}

	if (FA && pcrit)
	{
		mhit = false;
		mcrit = false;
	}
	if (!FA && mcrit)
	{
		phit = false;
		pcrit = false;
	}

	if (phit && patk)
	{
		//mtaken = 1 + ((pdmg * (((float)(100 - mblk)) / 100.0)) * (((float)potdmg)));
		mtaken = pdmg;
		mtaken -= mtaken * ((mblk) ? .5 : 1);
		if (mtaken < 1)
		{
			mtaken = 1;
		}
		mtaken += mtaken * (((float)potdmg) / 100.0);
		potdmg = 0;
		potspd = 0;
	}
	if (mhit && matk)
	{
		//ptaken = (((float)mdmg) * ((float)(100 - pblk) / 100.0));
		ptaken = mdmg;
		ptaken -= ptaken * ((pblk) ? .5 : 1);
		if (ptaken < 1)
		{
			ptaken = 1;
		}
	}

	if (FA)
	{
		m.HP -= mtaken;
		if (m.HP < 1)
		{
			combatText(paction, mtaken, pcrit, m.name, m.HP, 0, maction, mcrit, mtype, true);
			cout << "The monster dies\n";
			endCombat(true);
			return;
		}
		player.HP -= ptaken;
		combatText(paction, mtaken, pcrit, m.name, m.HP, ptaken, maction, mcrit, mtype, true);
		if (player.HP < 1)
		{
			cout << "You died\n";
			endCombat(false);
			return;
		}
	}
	else
	{
		player.HP -= ptaken;
		if (player.HP < 1)
		{
			combatText(paction, 0, pcrit, m.name, m.HP, ptaken, maction, mcrit, mtype, false);
			cout << "You died\n";
			endCombat(false);
			return;
		}
		m.HP -= mtaken;
		combatText(paction, mtaken, pcrit, m.name, m.HP, ptaken, maction, mcrit, mtype, false);
		if (m.HP < 1)
		{
			cout << "The monster dies\n";
			endCombat(true);
			return;
		}
	}

	/*
	((FA) ? (m.HP -= mtaken) : (player.HP -= ptaken));
	cout << ((FA) ? "You " : "The monster ") << "deal" << ((FA) ? " " : "s ");
        cout << ((FA) ? mtaken : ptaken) << " damage\n"; 
	if (player.HP <= 0 || m.HP <= 0)
	{
		cout << ((m.HP <= 0) ? "The monster " : "You ") << "died\n";
		endCombat((m.HP <= 0));
		return;
	}
	((!FA) ? (m.HP -= ptaken) : (player.HP -= ptaken));
	cout << ((!FA) ? "You " : "The monster ") << "deal" << ((!FA) ? " " : "s ");
        cout << ((!FA) ? mtaken : ptaken) << " damage\n"; 
	if (player.HP <= 0 || m.HP <= 0)
	{
		cout << ((m.HP <= 0) ? "The monster " : "You ") << "died\n";
		endCombat((m.HP <= 0));
		return;
	}
	*/

	//resetting variable for next turn
	mdmg = 0, macc = 0;
	pdmg = 0, pacc = 0;
	pblk = false, pdge = 0;
	mblk = false, mdge = 0;
	matk = false, patk = false;
	maction = 0, paction = 0;
	mtype = 0;

	string wait;
	dialogue("Press Enter to continue");
	cin.clear();
	cin.ignore();
	getline(cin, wait);
}

void battle::monsterTurn()
{
	int move = ((rand() % 100) + 1);

	//1-70 Attack, 71-85 Block, 86-100 Dodge
	if (move <= 70)
	{
		//attack
		matk = true;
		/*
		   1-23 Light, 24-47 Medium, 48-70 Heavy
		   Gives very slight preference to medium attacks
		   These calculations are kinda guesswork, probably need to be
		   tweaked to be fair but I made them up of the top of my head
		   to account for the lack of weapon usage. Better solution
		   would be to have each monster have their own base damage
		   value and then just scale it for level but its a little late
		   to totally overhall monsters and this section of combat.
		 */
		if (move <= 23)
		{
			//light
			macc = 90;
			maction = 0;
			mtype = 3;
			mdmg = ((((float)mact[1]) * .1) + (((float)mact[2]) * .15) + (((float)mact[3]) * .1));
		}
		else if (move <= 47)
		{
			//medium
			macc = 75;
			maction = 1;
			mtype = 1;
			mdmg = ((((float)mact[2]) * .1) + (((float)mact[3]) * .15) + (((float)mact[1]) * .1));
		}
		else
		{
			//heavy
			macc = 50;
			maction = 2;
			mtype = 2;
			mdmg = ((((float)mact[3]) * .1) + (((float)mact[1]) * .15) + (((float)mact[2]) * .1));
		}
	}
	else if (move <= 85)
	{
		//block

		//Slightly better formulas to account for no armor,
		//the amounts wont cause much of an affect at low level,
		//making the earlier game easier
		//mblk = ((mact[1] * .55) + (mact[4] * .15) + (mact[5] * .15));
		mblk = true;
		matk = true;

		//Monsters "shield bash" is more of a retaliation, it is
		//based on strength due to no armor ergo no weight like
		//what the players shield bash is based on. Also slightly
		//higher luck addition
		mdmg = ((mact[1] * .30) + (mact[5] * .1));
	}
	else
	{
		//dodge
		//Flat debuff to account for no armor, more valuable
		//early game, making it easier
		mdge = ((mact[4] * .5) + (mact[2] * .1) - 15);
	}
}

void battle::endCombat(bool win)
{
	done = true;
	if (win)
	{
		player.giveXP((player.lvl * m.diff) + 1);
		//give gold??
		return;
	}
	player.die();
}

void battle::attack()
{
	int choice;
	bool right = true;

	cout << "\n1: Light Attack\n";
	cout << "2. Medium Attack\n";
	cout << "3. Heavy Attack\n";
	cout << "4. Return\n";
	do
	{
		right = true;

		cin >> choice;

		if (!cin.good())
		{
			cin.clear();
			cin.ignore();
			right = false;
		}
		else
		{
			switch (choice)
			{
			case 1:
				paction = 0;
				pacc = 30 + (1.25 * (player.eqpt[0].subValue + act[wts] * .25)) + (act[5] * .25);
				patk = true;
				break;
			case 2:
				paction = 1;
				pacc = 30 + (1.0 * (player.eqpt[0].subValue + act[wts] * .25)) + (act[5] * .25);
				patk = true;
				break;
			case 3:
				paction = 2;
				pacc = 30 + (.75 * (player.eqpt[0].subValue + act[wts] * .25)) + (act[5] * .25);
				patk = true;
				break;
			case 4:
				throw "returning";

			default:
				right = false;
			}
		}
	} while (!right);
	pdmg = (player.eqpt[0].value + act[wts] * .5) * ((choice == 3) ? 1.25 : ((choice == 2) ? 1.0 : .75));
}

void battle::block()
{
	//pblk = ((act[1] * .5) + weight + (act[4] * .1) + (act[5] * .1));
	pblk = true;
	patk = true;
	pdmg = (weight * .5) + (act[1] * .25) + (act[5] * .05);
}

void battle::dodge()
{
	pdge = 0;
	pdge = (int)((act[4] * .35) + (act[2] * 2) + (act[5] * 1));
	// ((rand() % 100) + 1 <= dmgChance) true
}

void battle::heal(int val)
{
	float healVal = (((float)val) / 100);
	player.HP += player.maxHP * healVal;
	if (player.HP > player.maxHP)
	{
		player.HP = player.maxHP;
	}
}

/*
   The logic used in this function is complicated.

   It dynamically presents a number of choices and then allows the user 
   to pick any one of the available options

   I am almost certain this could be done better but this is what 
   I was able to figure out on my own on not much sleep.
 */

void battle::use()
{
	int choice = 0;
	int j = 1;
	int pos[9] = {0};
	int items[9] = {0};
	bool right = false;
	string returning = "returning";

	for (int i = 0; i < 25; i++)
	{
		if (player.inv[i].type == 3)
		{
			if (items[player.inv[i].id - 301] == 0)
			{
				items[player.inv[i].id - 301] = 1;
				cout << j << ". " << player.inv[i].name << "\n";
				pos[j - 1] = i;
				j++;
				//} else {
				//items[player.inv[i].id - 301]++;
			}
		}
	}
	/*
	   for (int i = 0; i < j; i++)
	   {
	   cout << i + 1 << ". " << player.inv[pos[i]].name << " x " << items[i] << "\n";
	   }
	 */
	cout << "\n"
		 << j << ". Return\n";

	while (!right)
	{
		right = true;
		cin >> choice;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore();
			right = false;
		}
		else
		{

			if (choice <= j && choice > 0)
			{
				if (choice == j)
				{
					throw "returning";
				}
				switch (player.inv[pos[choice - 1]].subType)
				{
				case 1:
					paction = 5;
					heal(player.inv[pos[choice - 1]].value);
					dialogue("You heal " + to_string(((int)(player.maxHP * (((float)(player.inv[pos[choice - 1]].value)) / 100)))) + " health");
					break;
				case 2:
					paction = 5;
					potdmg = player.inv[pos[choice - 1]].value;
					break;
				case 3:
					paction = 5;
					potspd = player.inv[pos[choice - 1]].value;
					break;
				}
				player.discard(player.inv[pos[choice - 1]]);
			}
			else
			{
				choice = false;
			}
		}
	}
}
//END OF COMBAT
//******************************************************************************
//******************************************************************************
//BEGINNING OF SAVE

//Item <<, used in Character <<
/* Removed because unnecessary
   Character << only needs item id
   ostream &operator<<(ostream &out, const item &in)
   {
   out << in.name << " "
   << in.id << " "
   << in.type << " "
   << in.value;
   return out;
   }
 */

//Character <<
ostream &operator<<(ostream &out, const character &in)
{
	//Basic character values
	out << in.name << "\n"
		<< in.lvl << " "
		<< in.xp << " "
		<< in.points << " "
		<< in.gold << " ";

	//Character Stats
	for (int x = 0; x < 6; x++)
	{
		out << in.stat[x] << " ";
	}
	out << "\n";

	//Characters equipped items
	for (int i = 0; i < 4; i++)
	{
		out << in.eqpt[i].id << " ";
	}
	out << "\n";

	//Characters inventory items
	for (int i = 0; i < 25; i++)
	{
		out << in.inv[i].id << " ";
	}

	//Other values
	out << "\n"
		<< in.textType
		<< " " << in.difficulty;
	out << "\n" 
		<< in.thePuzzle.getFinalSolution() << " "
		<< in.thePuzzle.getFinalPuzzle() << " "
		<< in.thePuzzle.getCurrentRings() << " "
		<< in.thePuzzle.getTotalRingsNeeded();
	return out;
}

//Character >>
istream &operator>>(istream &in, character &out)
{
	int temp = 0;

	//Basic character values
	in >> out.name;
	in >> out.lvl;
	in >> out.xp;
	in >> out.points;
	in >> out.gold;

	//Character Stats
	for (int x = 0; x < 6; x++)
	{
		in >> out.stat[x];
	}

	//Characters equipped items
	for (int i = 0; i < 4; i++)
	{
		in >> temp;
		out.eqpt[i] = item(temp);
	}

	//Characters inventory items
	for (int i = 0; i < 25; i++)
	{
		in >> temp;
		out.inv[i] = item(temp);
	}

	//Other values
	in >> out.textType;
	in >> out.difficulty;
	out.maxHP = (out.stat[0] * (.5 + (.25 * (out.stat[0] / 5))) * out.lvl);
	out.HP = out.maxHP;
	//Following code is used to store Scott's FinalPuzzle object
	string cword = out.thePuzzle.getFinalSolution(); 
	string jword = out.thePuzzle.getFinalPuzzle();
	int rfound = out.thePuzzle.getCurrentRings();
	int rneeded = out.thePuzzle.getTotalRingsNeeded();
	in >> cword;
	in >> jword;
	in >> rfound;
	in >> rneeded;
	return in;
}

//Monster >>
istream &operator>>(istream &in, monster &out)
{
	in >> out.name;
	in >> out.lvl;
	in >> out.maxHP;
	in >> out.HP;
	for (int x = 0; x < 6; x++)
	{
		in >> out.stat[x];
	}
	return in;
}

void saveOut(character &in)
{
	ofstream out;
	out.open("./saves/save1.txt");
	if (out.is_open())
	{
		out << in;
		out.close();
	}
	else
		cout << "Unable to open file";
}

character loadIn()
{
	ifstream in;
	in.open("./saves/save1.txt");
	character temp = character();
	if (in.is_open())
	{
		in >> temp;
		in.close();
	}
	else
		cout << "Unable to open file";
	return temp;
}

monster loadMonster()
{
	ifstream in;
	in.open("./txtFiles/monsters.txt");
	monster temp = monster();
	if (in.is_open())
	{
		in >> temp;
		in.close();
	}
	else
		cout << "Unable to open file";
	return temp;
}


//START OF SCOTT'S CODE
// default constructor
FinalPuzzle::FinalPuzzle()
{
	this->jumbledWord = "etts";
	this->correctWord = "test";
	this->totalRingsNeeded = 4;
	this->ringsFound = 0;
}
// constructor
FinalPuzzle::FinalPuzzle(string solution, string puzzle, int curRings, int ringsNeeded)
{
	this->correctWord = solution;
	this->jumbledWord = puzzle;
	this->ringsFound = curRings;
	this->totalRingsNeeded = ringsNeeded;
}
void FinalPuzzle::setFinalPuzzle(string finalPuzzle)
{
	jumbledWord = finalPuzzle;
	return;
}
string FinalPuzzle::getFinalPuzzle() const
{
	return jumbledWord;
}
void FinalPuzzle::setFinalSolution(string finalSolution)
{
	correctWord = finalSolution;
	return;
}
string FinalPuzzle::getFinalSolution() const
{
	return correctWord;
}
void FinalPuzzle::setTotalRingsNeeded(int totalRings)
{
	totalRingsNeeded = totalRings;
	return;
}
int FinalPuzzle::getTotalRingsNeeded() const
{
	return totalRingsNeeded;
}
void FinalPuzzle::setCurrentRings(int currentRings)
{
	ringsFound = currentRings;
	return;
}
int FinalPuzzle::getCurrentRings() const
{
	return ringsFound;
}; // end class definition
//END OF SCOTT'S CODE

// THIS CODE IS SCOTT'S
// It is placed here in my file because it has to be for
// scope/#include reasons. Due to the nature of only 3 files that
// all need to be included in different orders for different functions,
// this object is *required* to be in my file.
