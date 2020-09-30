#include "JasonJ.h"

std::ostream &operator<<(std::ostream &out, const character &in)
{
	out << in.name << "\n"
		<< in.lvl << "\n"
		<< in.maxHP << "\n"
		<< in.HP << "\n";
	for (int x = 0; x < 5; x++)
	{
		out << in.stats[x] << " ";
	}
	return out;
}

std::istream &operator>>(std::istream &in, character &out)
{
	in >> out.name;
	in >> out.lvl;
	in >> out.maxHP;
	in >> out.HP;
	for (int x = 0; x < 5; x++)
	{
		in >> out.stats[x];
	}
	return in;
}

void saveout(character &in, std::string txt)
{
	std::ofstream out;
	out.open(txt);
	if (out.is_open())
	{
		out << in;
		out.close();
	}
	else
		std::cout << "Unable to open file";
}

character savein(std::string txt)
{
	std::ifstream in;
	in.open(txt);
	character temp = character();
	if (in.is_open())
	{
		in >> temp;
		in.close();
	}
	else
		std::cout << "Unable to open file";
	return temp;
}
