#include "char.h"

//Creating a new Char.
character::character(std::string n)
{
	name = n;
	lvl = 1;
	maxHP = 100;
	HP = maxHP;
	for (int x = 0; x < 5; x++)
	{
		stats[x] = 1;
	}
}

character::character(const character &in)
{
	name = in.name;
	lvl = in.lvl;
	maxHP = in.maxHP;
	HP = in.HP;
	for (int x = 0; x < 5; x++)
	{
		stats[x] = in.stats[x];
	}
}

//Enemy Constructor
//character::character(...) {

//Default incase player doesn't input name.
character::character()
{
	character("Librarian");
}

void character::showStats()
{
	const char *stat[5] = {"STR", "INT", "DEX", "AGL", "LCK"};
	std::cout << "Name: " << name << "\n";
	printf("LVL: %i\nMax HP: %i\nHP: %i\n", lvl, maxHP, HP);
	for (int x = 0; x < 5; x++)
	{
		printf("%s: %i\n", stat[x], stats[x]);
	}
}
