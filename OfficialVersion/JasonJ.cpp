//Jason Jellie
//Created the item class, Definition is on line 32, code starts on line 122

#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class item
{
public:
	//ID lets us know which item it is
	int id;
	//Type shows which type of item it is ie. weapon, armor, potion, key item etc.
	int type;
	//Value shows how the item modifies stats, ATK for weapons, DEF for armor ect.
	int value;
	//Name of the item for generating by name
	string name;

	//Default constructor of empty item
	item();
	//Creating item by name
	item(string n);
	//Creating Random item by type
	//item(int t);
	//Creating item by id
	item(int id);
	//Copy constructor
	item(const item &in);
	//For testing purposes
	void showItem();
};

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

	character();
	character(string n);
	character(const character &in);
	void showStats();
	void showInv();
	//Following Function is for testing only,
	//Fills the characters inventory with items
	void fillInv();
};

//New Class for Lab

class monster : public stats
{
};

ostream &operator<<(ostream &out, const character &in);

istream &operator>>(istream &in, character &out);

void saveOut(character &in, string txt);

character loadIn(string txt);

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
character::character(string n) : stats::stats()
{
	name = n;
	gold = 0;
}

//Copy Constructor
character::character(const character &in)
{
	name = in.name;
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
	character("Librarian");
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
//END OF STATS
//******************************************************************************
//BEGINNING OF ITEM
item::item()
{
	name = "";
	id = 0;
	type = 0;
	value = 0;
}

item::item(string n)
{
	n.erase(n.find_last_not_of("\n\r") + 1);
	string line;
	ifstream in("./itemFiles/keyItems.txt");
	while (!in.eof())
	{
		cin >> line;
		cout << line << "\n";
		line.erase(n.find_last_not_of("\n\r") + 1);
		if (line == n)
		{
			name = line;
			cin >> id;
			type = 0;
			cin >> value;
			break;
		}
	}
}
/*
item::item(int t)
{
	//Used to determine the # of lines in the specific file, used to generate random num
	//for now it will always be 0 until more items are added to the files
	//Code commented out is for adding the randomness in future
	//int lines = 0;
	ifstream in;
	if (t == 0)
	{
		t = (rand() % 3) + 1;
	}
	type = t;

	switch (type)
	{
	//Lines will be set in each case to match number of objects in each file
	case 1:
		in.open("itemFiles/weapons.txt");
		break;
	case 2:
		in.open("itemFiles/armor.txt");
		break;
	case 3:
		in.open("itemFiles/misc.txt");
		break;
	}

	//int i = (rand() % lines) * 2
	//while (i > 0) { in >> temp; i--; }
	in >> name;
	in >> id;
	in >> value;
}
*/

item::item(int i)
{
	string token, temp;

	ifstream in("./Items/items.txt");
	if (in.is_open())
	{
		while (!in.eof())
		{
			in >> token;
			if (token == "/" + to_string(i))
			{
				id = i;
				name = temp;
				in >> type;
				in >> value;
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
	value = in.value;
}

void item::showItem()
{
	cout << "Name: " << name;
	cout << "\nID: " << id;
	cout << "\nType: " << type;
	cout << "\nValue: " << value;
	cout << "\n";
}

//END OF ITEM
//******************************************************************************
//BEGINNING OF SAVE

//Overriding << & >> to allow passing character object
ostream &operator<<(ostream &out, const character &in)
{
	out << in.name << "\n"
		<< in.lvl << "\n"
		<< in.maxHP << "\n"
		<< in.HP << "\n";
	for (int x = 0; x < 5; x++)
	{
		out << in.stat[x] << " ";
	}
	for (int i = 0; i < 25; i++)
	{
		out << in.inv[i].id << " ";
	}
	return out;
}

istream &operator>>(istream &in, character &out)
{
	int temp = 0;
	in >> out.name;
	in >> out.lvl;
	in >> out.maxHP;
	in >> out.HP;
	for (int x = 0; x < 5; x++)
	{
		in >> out.stat[x];
	}
	for (int i = 0; i < 25; i++)
	{
		in >> temp;
		out.inv[i] = item(temp);
	}
	return in;
}

//Saving to file
void saveOut(character &in, string txt)
{
	ofstream out;
	out.open(txt);
	if (out.is_open())
	{
		out << in;
		out.close();
	}
	else
		cout << "Unable to open file";
}

//Loading from file
character loadIn(string txt)
{
	ifstream in;
	in.open(txt);
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
//END OF SAVE
//******************************************************************************
