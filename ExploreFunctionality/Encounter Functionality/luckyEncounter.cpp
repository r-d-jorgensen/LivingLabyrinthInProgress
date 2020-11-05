/* lucky encounter  function selects a random lucky find
 * gold, weapon, armor, or artifact */
#include<iostream>
#include"textOutput.cpp"
#include<string>
using namespace std;

//void luckyEncounter();
void luckyEncounter()
{int gold = 100; // pull gold from character stats or items etc  
	int luck = 15; // pulled from stats
	int goldFound = 0;
	/* first random generator is gold vs weapon vs armor */
	int randNum = ((rand() + time(0)) % 10);
	if (randNum < 7 ) {
		int randGold = ((rand() + time(0)) % 50);
		randGold = randGold + luck/3;
		/* incorporates luck to determine how much gold found */
		if (randGold < 57)
			goldFound = 100;
		if (randGold < 54)
			goldFound =50;
		if (randGold < 52)
			goldFound = 40;
		if (randGold< 48)
			goldFound = 25;
		if (randGold <41)
			goldFound = 20;
		if (randGold< 31)
			goldFound = 15;
		if (randGold <20)
			goldFound = 10;
		if (randGold <10)
			goldFound = 5;
		gold = gold + goldFound;
		dialogue("You see something glimmer in the sunlight");
		dialogue("You see " + to_string(goldFound) + " gold pieces!");
		// add gold to character's items.
	}
	else if ((randNum == 7) || (randNum == 8)) {
		int damage = 0;
		int randWeapon = ((rand() + time(0)) % 5);
		string weapon[5] = {
			"dagger", "short sword", "long sword", "two handed sword", "mace"
		};
		/* randomized increased damage per hit */ 
		int randDamage = ((rand() + time(0)) % 50);
		randDamage += luck/3;
		/* incorporates luck to determine increased damage  */
		if (randDamage < 57)
			damage = 5;
		if (randDamage < 52)
			damage =4;
		if (randDamage < 45)
			damage =3;
		if (randDamage <35 )
			damage =2;
		if (randDamage < 22)
			damage =1;
		dialogue("You see a " + weapon[randWeapon]);
		dialogue("it increases your damage by " + to_string(damage)); 
	} 
	else {
		int armorClassIncreased = 0;
		/* randomized increased armor class */ 
		int randArmorClass = ((rand() + time(0)) % 50);
		randArmorClass += luck/3;
		/* incorporates luck to determine increased damage  */
		if (randArmorClass < 57)
			armorClassIncreased = 5;
		if (randArmorClass < 52)
			armorClassIncreased =4;
		if (randArmorClass < 45)
			armorClassIncreased  =3;
		if (randArmorClass <35 )
			armorClassIncreased =2;
		if (randArmorClass < 22)
			armorClassIncreased =1;
		dialogue("You see plate armor");
		dialogue("it increases your armor class by " + to_string(armorClassIncreased)); 
		// pass to character items
	}
}
/*
   int main () {
   for (int i = 0;i<10;i++)
   luckyEncounter();
   return 0;
   } */
