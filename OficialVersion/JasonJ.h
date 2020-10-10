//Jason Jellie
#pragma once
#include <iostream>
#include <fstream>

using namespace std;

//******************************************************************************
//STATS
class stats
{
public:
	int lvl;
	int maxHP;
	int HP;
	int stat[5];

	stats();
};

class character : public stats
{
public:
	//item inv[25];
	//item eqpt[5];
	string name;

	character();
	character(string n);
	character(const character &in);
	//Enemy Constructor
	//character(...);
	void showStats();
};

class monster : public stats
{
};
//END STATS
//******************************************************************************
//SAVE
ostream &operator<<(ostream &out, const character &in);

istream &operator>>(istream &in, character &out);

void saveout(character &in, string txt);

character savein(string txt);
//END SAVE
//******************************************************************************
