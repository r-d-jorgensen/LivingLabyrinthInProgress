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
		//vars are damage, accuracy, block%, dodge%
		//for both the player and the monster then 
		//for just the player potion damage and speed
		//also monter crit, player crit, the monster object
		//actual stat values, player weight, player weapon type stat
		int mdmg, macc;
		int pdmg, pacc;
		int mdge, pdge;
		bool mblk, pblk;	
		int potdmg, potspd;
		bool mcrit, pcrit;
		bool matk, patk;
		monster m;
		int mact[6], act[6];
		int weight, wts;

		//Used to see if the fight is over.
		bool done;

		//constructor
		battle(monster m);

		//functions
		void takeTurn();
		void monsterTurn();
		void endCombat(bool win);
		void attack();
		void block();
		void dodge();
		void use();		
		void heal(int val);
};

/*
   A lot of this code was written late at night/with little sleep
   so some of the choices made may seem odd/not optimal but
   it is what I was able to come up with to do what I needed 
 */

/*
   This comment is outdated, another solution was found but I decided to 
   leave this one in to allow anyone reading to see my thought process 
   throughout the codes progress.


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
	battle c(m);

	while (!c.done)
	{
		do
		{
			try {
				cin.clear();
				choice = 0;
				right = true;
				cout << "\033[2J\033[1;1H";
				cout << c.m.name << " Level: " << c.m.lvl;
				cout << " Health: " << c.m.HP << "/" << c.m.maxHP;
				cout << "\n" << player.name << " Level: " << player.lvl;
				cout << " Health: " << player.HP << "/" << player.maxHP;
				cout << "\n\n";
				cout << "1: Attack\n";
				cout << "2: Block\n";
				cout << "3: Dodge\n";
				cout << "4: Use Item\n";

				cin >> choice;
				if (!cin.good()) 
				{ 
					cin.clear(); 
					cin.ignore(); 
					right = false; 
				} else {

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
			}
			catch (char const* e)
			{
				right = false;
			}
		} while (!right);
		c.takeTurn();
	}
}

battle::battle(monster in)
{
	m = in;
	mdmg = 0, macc = 0;
	pdmg = 0, pacc = 0;
	pblk = false, pdge = 0;
	mblk = false, mdge = 0;	
	potdmg = 0, potspd = 0;
	matk = false, patk = false;

	done = false;

	for (int i = 1; i < 4; i++)
	{
		weight += player.eqpt[i].subValue;
	}

	for (int i = 0; i < 6; i++)
	{
		act[i] = (player.stat[i] * (.5 + (.25 * (player.stat[i] / 5))) * player.lvl);
	}

	if (player.maxHP < 5)
	{
		player.maxHP = 5;
	}
	player.HP = player.maxHP;

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
		default:
			wts = 1;
	}

	//Get monsters leveled stats and then convert to actual.
	//Idea for more weighted stats if there's time, add totals of all
	//base stats then make rand between 1-total, then choose based on
	//what it rolls, ie 1-con, con+1-con+str, con+str+1-con+str+dex ect.
	int points = 0;
	for (int i = 0; i < m.lvl; i++)
	{
		points += (4 - (player.difficulty/3));
	}
	for (int i = 0; i < m.lvl; i++)
	{
		int x = (rand() % 6);
		if (m.stat[x] == 0)
		{
			i--;
		}
		else {
			m.stat[x]++;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		mact[i] = (m.stat[i] * (.5 + (.25 * (((float)m.stat[i]) / 5))) * m.lvl);
	}
	if (m.maxHP < 5)
	{
		m.maxHP = 5;
	}

	m.HP = m.maxHP;
}

void battle::takeTurn()
{
	monsterTurn();
	//Check to see who goes first, will be true if player goes first
	//In order to counter-act weight, mosnters agility is less valueable
	bool FA = (((act[4] * .25) + (act[5] * .1) - weight) * (((float)potspd) / 100)) >= ((mact[4] * .15) + (mact[5] * .1));
	bool mhit, phit, mcrit, pcrit;
	//Player and monster damage taken
	int ptaken = 0, mtaken = 0;
	if ((pacc - ((mact[4] * .1) + (mact[5] * .1) > 0)) && ((rand() % 100) > mdge))
	{
		phit = true;
		if ((rand() % 100) < (player.eqpt[0].percent + act[5] * .5))
		{
			pcrit = true;
			pdmg *= 2;
		}
	}
	if ((macc - ((act[4] * .1) + (act[5] * .1) > 0)) && ((rand() % 100) > pdge))
	{
		mhit = true;
		if ((rand() % 100) < (10 + (act[5] * .5)))
		{
			mcrit = true;
			mdmg *= 2;
		}
	}

	if (FA && pcrit)
	{
		mhit = false;
		mcrit = false;
	}
	if (!FA && mcrit)
	{
		phit = false;
		pcrit = false;
	}

	if (phit && patk)
	{
		//mtaken = 1 + ((pdmg * (((float)(100 - mblk)) / 100.0)) * (((float)potdmg)));
		mtaken = pdmg;
		mtaken -= mtaken * ((mblk) ? .5 : 1);
		if (mtaken < 1)
		{
			mtaken = 1;
		}
		mtaken += mtaken * (((float) potdmg) / 100.0);
		potdmg = 0;
		potspd = 0;
	}
	if (mhit && matk)
	{
		//ptaken = (((float)mdmg) * ((float)(100 - pblk) / 100.0));
		ptaken = mdmg;
		ptaken -= ptaken * ((pblk) ? .5 : 1);
		if (ptaken < 1)
		{
			ptaken = 1;
		}
	}

	if (FA)
	{
		m.HP -= mtaken;
		cout << "You deal " << mtaken << " damage\n";
		if (m.HP < 1)
		{
			cout << "The monster dies\n";
			endCombat(true);
			return;
		}
		player.HP -= ptaken;
		cout << "The monster deals " << ptaken << " damage\n";
		if(player.HP < 1)
		{
			cout << "You died\n";
			endCombat(false);
			return;
		}
	} else {
		player.HP -= ptaken;
		cout << "The monster deals " << ptaken << " damage\n";
		if(player.HP < 1)
		{
			cout << "You died\n";
			endCombat(false);
			return;
		}
		m.HP -= mtaken;
		cout << "You deal " << mtaken << " damage\n";
		if (m.HP < 1)
		{
			cout << "The monster dies\n";
			endCombat(true);
			return;
		}
	}


	/*
	((FA) ? (m.HP -= mtaken) : (player.HP -= ptaken));
	cout << ((FA) ? "You " : "The monster ") << "deal" << ((FA) ? " " : "s ");
        cout << ((FA) ? mtaken : ptaken) << " damage\n"; 
	if (player.HP <= 0 || m.HP <= 0)
	{
		cout << ((m.HP <= 0) ? "The monster " : "You ") << "died\n";
		endCombat((m.HP <= 0));
		return;
	}
	((!FA) ? (m.HP -= ptaken) : (player.HP -= ptaken));
	cout << ((!FA) ? "You " : "The monster ") << "deal" << ((!FA) ? " " : "s ");
        cout << ((!FA) ? mtaken : ptaken) << " damage\n"; 
	if (player.HP <= 0 || m.HP <= 0)
	{
		cout << ((m.HP <= 0) ? "The monster " : "You ") << "died\n";
		endCombat((m.HP <= 0));
		return;
	}
	*/

	//resetting variable for next turn
	mdmg = 0, macc = 0;
	pdmg = 0, pacc = 0;
	pblk = false, pdge = 0;
	mblk = false, mdge = 0;	
	matk = false, patk = false;



	string wait;
	cout << "Press Enter to continue\n";
	cin.clear();
	cin.ignore();
	getline(cin, wait);
}

void battle::monsterTurn()
{
	int move = ((rand() % 100) + 1);

	//1-70 Attack, 71-85 Block, 86-100 Dodge
	if (move <= 70)
	{
		//attack
		matk = true;
		/*
		   1-23 Light, 24-47 Medium, 48-70 Heavy
		   Gives very slight preference to medium attacks
		   These calculations are kinda guesswork, probably need to be
		   tweaked to be fair but I made them up of the top of my head
		   to account for the lack of weapon usage. Better solution
		   would be to have each monster have their own base damage
		   value and then just scale it for level but its a little late
		   to totally overhall monsters and this section of combat.
		 */
		if (move <= 23)
		{
			//light
			macc = 90;
			mdmg = ((((float)mact[1]) * .1) + (((float)mact[2]) * .15) + (((float)mact[4]) * .1));
		}
		else if (move <= 47)
		{
			//medium
			macc = 75;
			mdmg = ((((float)mact[2]) * .1) + (((float)mact[4]) * .15) + (((float)mact[1]) * .1));
		}
		else
		{
			//heavy
			macc = 50;
			mdmg = ((((float)mact[4]) * .1) + (((float)mact[1]) * .15) + (((float)mact[2]) * .1));
		}
	}
	else if (move <= 85)
	{
		//block

		//Slightly better formulas to account for no armor,
		//the amounts wont cause much of an affect at low level,
		//making the earlier game easier
		//mblk = ((mact[1] * .55) + (mact[4] * .15) + (mact[5] * .15));
		mblk = true;
		matk = true;

		//Monsters "shield bash" is more of a retaliation, it is 
		//based on strength due to no armor ergo no weight like
		//what the players shield bash is based on. Also slightly
		//higher luck addition
		mdmg = ((mact[1] * .30) + (mact[5] * .1));
	}
	else
	{
		//dodge
		//Flat debuff to account for no armor, more valuable
		//early game, making it easier
		mdge = ((mact[4] * .5) + (mact[2] * .1) - 15);
	}
}

void battle::endCombat(bool win)
{
	done = true;
	if (win) 
	{
		player.giveXP((player.lvl * m.diff) + 1);
		//give gold??
		return;
	}
	player.die();
}

void battle::attack()
{
	int choice;
	bool right = true;

	cout << "\n1: Light Attack\n";
	cout << "2. Medium Attack\n";
	cout << "3. Heavy Attack\n";
	cout << "4. Return\n";
	do
	{
		right = true;

		cin >> choice;

		if (!cin.good()) 
		{ 
			cin.clear(); 
			cin.ignore(); 
			right = false;
		} else {	
			switch (choice)
			{
				case 1:
					pacc = 30 + (1.25 * (player.eqpt[0].subValue + act[wts] * .25)) + (act[5] * .25);
					patk = true;
					break;
				case 2:
					pacc = 30 + (1.0 * (player.eqpt[0].subValue + act[wts] * .25)) + (act[5] * .25);
					patk = true;
					break;
				case 3:
					pacc = 30 + (.75 * (player.eqpt[0].subValue + act[wts] * .25)) + (act[5] * .25);
					patk = true;
					break;
				case 4:
					throw "returning";

				default:
					right = false;
			}
		}
	} while (!right);
	pdmg = (player.eqpt[0].value + act[wts] * .5) * ((choice == 3) ? 1.25 : ((choice == 2) ? 1.0 : .75));
}

void battle::block()
{
	//pblk = ((act[1] * .5) + weight + (act[4] * .1) + (act[5] * .1));
	pblk = true;
	patk = true;
	pdmg = (weight * .5) + (act[1] * .25) + (act[5] * .05);
}

void battle::dodge()
{
	pdge = 0;
	pdge = (int)((act[4] * .35) + (act[2] * 2) + (act[5] * 1));
	// ((rand() % 100) + 1 <= dmgChance) true
}

void battle::heal(int val)
{
	float healVal = (((float)val)/100);
	player.HP += player.maxHP * healVal;
	if (player.HP > player.maxHP)
	{
		player.HP = player.maxHP;
	}
}


/*
   The logic used in this function is complicated.

   It dynamically presents a number of choices and then allows the user 
   to pick any one of the available options

   I am almost certain this could be done better but this is what 
   I was able to figure out on my own on not much sleep.
 */

void battle::use()
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
				cout << j << ". " << player.inv[i].name << "\n";
				pos[j-1] = i;
				j++;
				//} else {
				//items[player.inv[i].id - 301]++;
		}
		}
	}
	/*
	   for (int i = 0; i < j; i++)
	   {
	   cout << i + 1 << ". " << player.inv[pos[i]].name << " x " << items[i] << "\n";
	   }
	 */
	cout << "\n" << j << ". Return\n";

	while (!right)
	{
		right = true;
		cin >> choice;
		if (!cin.good()) 
		{ 
			cin.clear(); 
			cin.ignore(); 
			right = false;
		} else {	

			if (choice <= j && choice > 0)
			{
				if (choice == j)
				{
					throw "returning";
				}
				switch (player.inv[pos[choice - 1]].subType)
				{
					case 1: heal(player.inv[pos[choice - 1]].value);
						cout << "You heal " << ((int)(player.maxHP * (((float)(player.inv[pos[choice - 1]].value))/100))) << " health\n";
						break;
					case 2: potdmg = player.inv[pos[choice -1]].value;
						break;
					case 3: potspd = player.inv[pos[choice -1]].value;
						break;
				}
				player.discard(player.inv[pos[choice - 1]]);
			} else {
				choice = false;
			}
		}
	}
}
