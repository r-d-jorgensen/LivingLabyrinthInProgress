#pragma once
#include <iostream>

class character {
	public:
		//item inv[25];
		//item eqpt[5];
		std::string name;
		int lvl;
		int maxHP;
		int HP;
		int stats[5];	//Stats in order are Str, Int, Dex, Agl, Lck

		character();
		character(std::string n);
		character(const character & in);
		//Enemy Constructor
		//character(...);
		void showStats();
};
