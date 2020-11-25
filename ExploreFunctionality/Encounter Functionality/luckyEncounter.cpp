void luckyEncounter()
{
	int gold = 100; //###int gold = player.gold; pull gold from character stats or items etc
	int luck = 15;  //### luck = player.luck;  pulled from stats
	int goldFound = 0;
	/* first random generator is gold vs weapon vs armor */
	int randNum = ((rand() + time(0)) % 10);
	if (randNum < 7)
	{
		int randGold = ((rand() + time(0)) % 50);
		randGold = randGold + luck / 3;
		/* incorporates luck to determine how much gold found */
		if (randGold < 57)
			goldFound = 100;
		if (randGold < 54)
			goldFound = 50;
		if (randGold < 52)
			goldFound = 40;
		if (randGold < 48)
			goldFound = 25;
		if (randGold < 41)
			goldFound = 20;
		if (randGold < 31)
			goldFound = 15;
		if (randGold < 20)
			goldFound = 10;
		if (randGold < 10)
			goldFound = 5;
		dialogue("You see something glimmer in the sunlight");
		dialogue("You see " + to_string(goldFound) + " gold pieces!");
		gold += goldFound;
		//### player.gold = gold;  add gold to character's items.
	}
	else if ((randNum == 7) || (randNum == 8))
	{
		int randWeapon = ((rand() + time(0)) % 5);
		string weapon[5] = {
			"dagger", "short sword", "long sword", "two handed sword", "mace"};
		dialogue("You see a " + weapon[randWeapon]);
		// ### player.addItem(weapon[randWeapon]);
	}
	else
	{
		int randArmor = ((rand() + time(0)) % 5);
		string armor[5] = {
			"plate mail", "chain mail", "leather mail", " helmet", "shield"};
		dialogue("You see a " + armor[randArmor]);
		// pass to character items 
		//###player.addItem(armor[randArmor];
	}
}
