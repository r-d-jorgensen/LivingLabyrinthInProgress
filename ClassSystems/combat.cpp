#include "stats.cpp"
#include "items.cpp"

extern character player;

using namespace std;

int attack();
int block();
bool dodge();
void use();


/*
   Output to screen is placeholder for testing, will be modified to use
   the dialog function.
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
	bool right = true, dodge = false, pgf, crit;
	int dmg = 0;;

	while (m.HP > 0 && player.HP > 0)
	{
		do
		{
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
					dmg = attack();
					break;
				case 2: 
					block();
					break;
				case 3: 
					dodge = dodge();
					break;
				case 4: 
					use();
					break;
				default:
					right = false;
			}
		} while (!right);
	}
}

int attack()
{
	int choice;
	bool right = true;
	int dmg, hit, wts;
	int act[6];
	int weight = 0;
	for (int i = 1; i < 4; i++)
	{
		weight += player.eqpt[i].subValue;
	}
	//converting character lvls to "actual" lvls used in formulas
	for (int i = 0; i < 6; i++)
	{
		act[i] = player.stat[i] * (.5 + (.25 * (player.stat[i] / 5))) * player.lvl;
	}
	//wts = weapon type stat
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

	do
	{
		if (right)
		{
			cout << "\n1: Light Attack\n";
			cout << "2. Medium Attack\n";
			cout << "3. Heavy Attack\n";
		} else {
			cout << "Invalid choice, please select one of the options above\n";
		}

		cin >> choice;

		switch (choice)
		{
			case 1: 
				hit = (1.25 * (player.eqpt[0].subValue + player.eqpt[wts])) + (act[5] * .25);
				break;
			case 2: 
				hit = (1.0 * (player.eqpt[0].subValue + player.eqpt[wts])) + (act[5] * .25);
				break;
			case 3: 
				hit = (.75 * (player.eqpt[0].subValue + player.eqpt[wts])) + (act[5] * .25);
				break;
			default: 
				right = false;
				break;
		}
	} while (!right);
	if ((rand() % 100) + 1 <= hit)
	{
		dmg = (player.eqpt[0].value + player.eqpt[wts]) * ((choice == 3) ? 1.25 : ((choice == 2) ? 1.0 : .75)); 
	} else { 
		return 0;
	}
	if ((rand() % 100 ) + 1 <= (player.eqpt[0].percent + (act[5] * .1)))
	{
		dmg *= 2;
	}
	return dmg;
}

int block()
{
	//For now just returns 0 until implemented later
	return 0;
}

bool dodge()
{
	int dmgChance = (act[4] * .5) + (act[2] * .1) + (act[5] * .25) - weight;
	if ((rand() % 100) + 1 <= dmgChance)
	{
		return true;
	}
	return false;
}

/*The logic used in this function is complicated.
  It dynamically presents a number of choices and then allows the user 
  to pick any one of the available options
  I am almost certain this could be done better but this is what 
  I was able to figure out on my own.
 */

void use()
{
	int choice = 0;
	int j = 1;
	int arr[7] = {0};
	int items[7] = {0};
	bool right = true;
	item used;
	for (int i = 0; i < 25; i++)
	{
		if (player.inv[i].type == 3)
		{
			if (arr[7] != 0)
			{
				arr[player.inv[i].id - 300] = 1;
				cout << j << ". " << player.inv[i].name << "\n";
				items[j] = i;
				j++;
			}
		}
	}
	do
	{
		cin >> choice;

		if (choice > j || choice < 1 )
		{
			used = player.inv[items[j]];
			player.inv[items[j]] = new item();
		} else {
			right = false;
		}
	} while (!right);
	//Implement actually using the items
	//Not hard but getting tired of writing switch
	//statements tonight
}
