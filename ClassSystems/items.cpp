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

   name is the name of the item, exists simply for the player
*/

item::item()
{
	name = "";
	id = 0;
	type = 0;
	subType = 0;
	value = 0;
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
	in >> idtemp;
	in >> subType;
	in >> value;
	idtemp = idtemp.substr(1, idtemp.size() - 1);
	id = stoi(idtemp);
	in.close();
}

item::item(int i)
{
	string token;
	string temp;
	string txt = "./Items/";

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
			in >> token;
			if (token == "/" + to_string(i))
			{
				id = i;
				name = temp;
				in >> subType;
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
	subType = in.subType;
	value = in.value;
}

void item::showItem()
{
	cout.setf(ios::left);
	cout << setw(20) << "Name: " + name;
	cout << setw(10) << "ID: " + to_string(id);
	cout << setw(10) << "Type: " + to_string(type);
	cout << setw(12) << "Subtype: " + to_string(subType);
	cout << setw(10) << "Value: " + to_string(value);
	cout << "\n";
}
