//Jason Jellie
#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>

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
	subValue = 0;
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
	string txt = "./Items/";
	int lines = 0;
	string temp, idtemp;

	if (t == "0") { t = (rand() % 3) + 1; }

	switch(stoi(t))
	{
		case 1: txt += "armor.txt"; type = 1; break;
		case 2: txt += "weapons.txt"; type = 2; break;
		case 3: txt += "misc.txt"; type = 3; break;
		default: txt += "failed.txt"; break;
	}

	ifstream in;
	in.open(txt);
	while(!in.eof())
	{
		getline(in, temp);
		lines++;
	}
	in.clear();
	in.seekg(0);

	int i = (rand() % (lines/2)) * 2;
	while (i > 0) { getline(in, temp); i--; }
	in >> name;
	//Item names are stored int a text file using underscores so names are one "word"
	//This block replaces the underscore with a space
	for (size_t i = 0; i < temp.length(); i++) 
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
	string txt = "./Items/";

	/*Item id's contain what type of item they are, with the first digit being
	important one. The next line rounds the number to the nearest hundredth,
	then divides the number by 100 to find the first digit. */
	switch((i - (i % 100)) / 100)
	{
		case 1: txt += "armor.txt"; type = 1; break;
		case 2: txt += "weapons.txt"; type = 2; break;
		case 3: txt += "misc.txt"; type = 3; break;
		default: txt += "failed.txt"; break;
	}

	ifstream in(txt);
	if (in.is_open())
	{
		while (!in.eof())
		{
			/*Items are stored with a / at the beginning of them in order to 
			  easily differenciate them from other item values. It is simple
			  deal with this / by comparing the token to the wanted id with
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
}

void item::showItem()
{
	if (type != 0)
	{
		cout.setf(ios::left);
		cout << setw(23) << "Name: " + name;
		cout << setw(10) << "ID: " + to_string(id);
		
		switch(type)
		{ 
			case 1: 
				cout << setw(15) << "Type: Armor"; 
				switch(subType)
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
				switch(subType)
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
				switch(subType)
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
