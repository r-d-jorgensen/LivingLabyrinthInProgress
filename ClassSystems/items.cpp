//Jason Jellie
#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class item
{
public:
	int id;
	int type;
	int value;
	string name;

	item();
	item(string n);
	//item(int t);
	item(int id);
	item(const item &in);

	void showItem();
};

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

/*
   item::item(int t)
   {
   int lines;
   string temp, idtemp;
   ifstream in;
   in.open("./Items/items.txt");
   while(!in.eof())
   {
   getline(in, temp);
   lines++;
   }
   in.seekg(0);
   in.clear();

   int i = (rand() % lines/2) * 2;
   while (i > 0) { getline(in, temp); i--; }
   in >> name;
   in >> idtemp;
   in >> type;
   in >> value;
   }*/

item::item(int i)
{
	string token;
	string temp;

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
