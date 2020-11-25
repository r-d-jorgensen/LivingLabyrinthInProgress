/* trap encounter  function selects a random trap which may cause harm */
void trapEncounter()
{
	int luck = 10;     //###int luck = player.luck pulled from stats
	int agility = 9;   //### int agility = player.ag; from stats
	int dexterity = 8; //###int dexterity = player.dex; from stats
	int hitPoints = 100; // ###player.HP;
	int HPLost = 0;
	ifstream trapFile;
	trapFile.open("./txtFiles/traps.txt");
	string randomTrap;
	int randNum = 0;
	randNum = ((rand() + time(0)) % 5);
	randNum = 3 * randNum; // calculation to move to each different trap
	for (int i = 0; i < randNum + 1; i++)
		getline(trapFile, randomTrap);
	dialogue((randomTrap));
	/* pause for result of trap */
	dialogue("Press 'enter' to continue. ");
	string enter;
	getline(cin, enter);
	/* move to next line in trap.txt file */
	getline(trapFile, randomTrap);
	/* print this line if player is able to avoid trap and move 1 more line if not
	   in order to display the correct message */
	int randGetHurt = ((rand() + time(0)) % 100);
	randGetHurt += agility + dexterity + luck;
	if (randGetHurt > 65)
		dialogue((randomTrap));
	else
	{
		getline(trapFile, randomTrap);
		dialogue((randomTrap));
		/* damage is 1 to 30% of current HP*/
		int randPercent = ((rand() + time(0)) % 30);
		HPLost = hitPoints * randPercent / 100;
		hitPoints = hitPoints - HPLost;
		//### player.HP = hitPoints;
		dialogue("You lost " + to_string(HPLost) + " hit points");
	}
	trapFile.close();
	return;
} // end trap function
