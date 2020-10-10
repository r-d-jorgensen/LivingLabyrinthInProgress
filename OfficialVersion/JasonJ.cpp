//Jason Jellie
#include <iostream>
#include <fstream>

using namespace std;

class stats
{
	public:
		int lvl, maxHP, HP, stat[5];

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
		void showStats();
};

class monster : public stats
{
};

ostream &operator<<(ostream &out, const character &in);

istream &operator>>(istream &in, character &out);

void saveout(character &in, string txt);

character savein(string txt);


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
}

//Copy Constructor
character::character(const character &in)
{
	name = in.name;
	lvl = in.lvl;
	maxHP = in.maxHP;
	HP = in.HP;
	for (int x = 0; x < 5; x++)
	{
		stat[x] = in.stat[x];
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

//END OF STATS
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
	return out;
}

istream &operator>>(istream &in, character &out)
{
	in >> out.name;
	in >> out.lvl;
	in >> out.maxHP;
	in >> out.HP;
	for (int x = 0; x < 5; x++)
	{
		in >> out.stat[x];
	}
	return in;
}

//Saving to file
void saveout(character &in, string txt)
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
character savein(string txt)
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
