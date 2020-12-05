//Jason Jellie
#pragma once
#include <iostream>
#include <fstream>
#include "stats.cpp"

using namespace std;

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
	out << "\n" << in.textType
		<< " " << in.difficulty;
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

character loadIn(string txt)
{
	ifstream in;
	in.open(txt);
	character temp = character();
	if (in.is_open())
	{
		in >> temp;
		in.close();
	} else cout << "Unable to open file";
	return temp;
}

monster loadMonster()
{
	ifstream in;
	in.open("./Monsters/monsters.txt");
	monster temp = monster();
	if (in.is_open())
	{
		in >> temp;
		in.close();
	} else cout << "Unable to open file";
	return temp;
}
