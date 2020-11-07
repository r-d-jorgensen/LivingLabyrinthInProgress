/* trap encounter  function selects a random trap which may cause harm */
#include<iostream>
#include"textOutput.cpp"
#include<string>
#include<fstream>
using namespace std;
void trapEncounter();
void trapEncounter()
{
	int luck = 10; // pulled from stats
	int agility = 9; // from stats
	int dexterity = 8; // from stats
	int hpLost = 0;
	ifstream trapFile;
		trapFile.open("traps.txt");
		string randomTrap;
		int randNum = 0;
	randNum = ((rand() + time(0)) % 5); // currently 5 different traps
		randNum = 3*randNum;// calculation to move to each different trap
	for (int i=0;i<randNum+1;i++) 
		getline(trapFile, randomTrap);
			dialogue((randomTrap));
	/* pause for result of trap */
	dialogue("Press 'enter' to continue. " );
	string enter;
	getline(cin, enter);
	/* move to next line in trap.txt file */
	getline(trapFile, randomTrap);
		/* print this line if player is able to avoid trap and move 1 more line if not
		   in order to display the correct message */
		int randGetHurt = ((rand() + time(0)) % 100);
	randGetHurt += agility + dexterity + luck;
	if (randGetHurt >65)
		dialogue((randomTrap));
	else {
		getline(trapFile, randomTrap);
			dialogue((randomTrap));
		/* damage is 2 10 sided dice */
		int randHPLost1 = ((rand() + time(0)) % 10);
		int randHPLost2 = ((rand() + time(0)) % 10);
		hpLost = randHPLost1 + randHPLost2;	
		dialogue("You lost " + to_string(hpLost) + " hit points");
	}
	trapFile.close();
		// send hp lost to character hp
} // end trap function
/*
int main() 
{
	trapEncounter();
	return 0;
}
*/
