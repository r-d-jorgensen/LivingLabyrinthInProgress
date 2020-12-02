#include "stats.cpp"
#include "items.cpp"

extern character player;

using namespace std;

/*
   New idea in order to easily carry information between turns/functions.
   Create an object and store neccessary vars of both teams
   and also use the functions already created 
 */

//Function is called battle in order to not be the same as the combat function
//but still have a similar enough name.
class battle
{
	public:
		//vars are damage. speed, accuracy, block%, dodge%
		//for both the player and the monster then 
		//for just the player potion damage and speed
		//also monter crit, player crit, the monster object
		//actual stat values, player weight, player weapon type stat
		int mdmg, mspd, macc;
		int pdmg, pspd, pacc;
		int pblk, pdge;
		int mblk, mdge;	
		int potdmg, potspd;
		bool mcrit, pcrit
		monster m();
		int mact[6], pact[6];
		int weight, wts;

		//constructor
		battle(monster m);

		//functions
		void takeTurn();
		void endCombat(bool win);
		void attack();
		int block();
		bool dodge();
		void use();		
};

/*
   A lot of this code was written late at night/with little sleep
   so some of the choices made may seem odd/not optimal but
   it is what I was able to come up with to do what I needed 
 */

/*
   Output to screen is placeholder for testing, will be modified to use
   the dialog functions.

   Have an idea to make returning work. Use a try catch block in order to return
   and choose your action again without needing to pass/return another option.

   If the player wants to return to an earlier choice, throw back to the catch block
   and show them the choices again.

   Will implement this in the future.
 */

void combat(monster m)
{
	int choice;
	//pgf = Player Goes First
	bool right = true;
	combat c(m);

	while (m.HP > 0 && player.HP > 0)
	{
		do
		{
			try {
				right = true;
				cout << "\033[2J\033[1;1H";
				cout << "1: Attack\n";
				cout << "2: Block\n";
				cout << "3: Dodge\n";
				cout << "4: Use Item\n";
				cout << ((right) ? "" : "Invalid choice, please select one of the options above\n");

				cin >> choice;

				switch (choice)
				{
					case 1: 
						c.attack();
						break;
					case 2: 
						c.block();
						break;
					case 3: 
						c.dodge();
						break;
					case 4: 
						c.use();
						break;
					default:
						right = false;
				}
			}
			catch (string e)
			{
				right = false;
			}
		} while (!right);

	}
}

battle::battle(monster in)
{
	m = in;
	mdmg = 0, mspd = 0, macc = 0;
	pdmg = 0, pspd = 0, pacc = 0;
	pblk = 0, pdge = 0;
	mblk = 0, mdge = 0;	
	potdmg = 0, potspd = 0;

	for (int i = 1; i < 4; i++)
	{
		weight += player.eqpt[i].subValue;
	}
	for (int i = 0; i < 6; i++)
	{
		act[i] = player.stat[i] * (.5 + (.25 * (player.stat[i] / 5))) * player.lvl;
	}
	switch (player.eqpt[0].subType)
	{
		case 1:
			wts = 3;
			break;
		case 2:
			wts = 1;
			break;
		case 3:
			wts = 2;
			break;
	}
}

void battle::takeTurn()
{
}

void battle::endCombat(bool win)
{
}

void battle::attack()
{
	int choice;
	bool right = true;
	string returning = "returning";

	do
	{
		if (right)
		{
			cout << "\n1: Light Attack\n";
			cout << "2. Medium Attack\n";
			cout << "3. Heavy Attack\n";
			cout << "4. Return\n";
		} else {
			cout << "Invalid choice, please select one of the options above\n";
		}

		cin >> choice;

		switch (choice)
		{
			case 1:
				pacc = (1.25 * (player.eqpt[0].subValue + player.stat[wts])) + (act[5] * .25);
				break;
			case 2:
				pacc = (1.0 * (player.eqpt[0].subValue + player.stat[wts])) + (act[5] * .25);
				break;
			case 3:
				pacc = (.75 * (player.eqpt[0].subValue + player.stat[wts])) + (act[5] * .25);
				break;
			case 4:
				throw returning;
				
			default:
				right = false;
		}
	} while (!right);
	pdmg = (player.eqpt[0].value + player.stat[wts]) * ((choice == 3) ? 1.25 : ((choice == 2) ? 1.0 : .75));
}

void battle::block()
{
	pblk = ((act[1] * .5) + weight + (act[4] * .1) + (act[5] * .1));
	pdmg = (weight * .5) + (act[1] * .25) + (act[5] * .05)
}

void battle::dodge()
{
	pdge = (act[4] * .5) + (act[2] * .1) + (act[5] & .25) - weight;
	// ((rand() % 100) + 1 <= dmgChance) true
}

void battle::heal(int val)
{
	val *= (int)((float)(val/100));
	player.HP += val;
	if (player.HP > player.maxHP)
	{
		player.HP = player.maxHp;
	}
}


/*
   The logic used in this function is complicated.

   It dynamically presents a number of choices and then allows the user 
   to pick any one of the available options

   I am almost certain this could be done better but this is what 
   I was able to figure out on my own.
 */

void battle::use(int & dmg, int & speed)
{
	int choice = 0;
	int j = 1;
	int pos[9] = {0};
	int items[9] = {0};
	bool right = false;
	string returning = "returning";
	
	for (int i = 0; i < 25; i++)
	{
		if (player.inv[i].type == 3)
		{
			if (items[player.inv[i].id - 301] == 0)
			{
				items[player.inv[i].id - 301] = 1;
				//cout << j << ". " << player.inv[i].name << "\n";
				pos[j] = i;
				j++;
			} else {
				items[player.inv[i].id - 301]++;
			}
		}
	}
	for (int i = 0; i < j; i++)
	{
		cout << i + 1 << ". " << player.inv[pos[i]].name << " x " << items[i] << "\n";
	}
	cout << "\n" << j << ". Return\n";
	
	while (!right)
	{
		cin >> choice;

		if (choice <= j && choice > 0)
		{
			if (choice == j)
			{
				throw "returning";
			}
			switch (player.inv[j].subType)
			{
				case 1: heal(player.inv[pos[choice - 1]].value);
					break;
				case 2: potdmg = player.inv[pos[choice -1]].value;
					break;
				case 3: potspd = player.inv[pos[choice -1]].value;
					break;
			}
			discard(player.inv[pos[choice - 1]]);
		}
	}
}
