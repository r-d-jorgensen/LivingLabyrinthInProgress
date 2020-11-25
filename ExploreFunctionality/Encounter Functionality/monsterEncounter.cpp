/* function receives an int which indicates level of the monster if received 
 * from majorEncounter. A 100  indicates that monsterEncounter was called 
 * from Explore. function adjusts monster using randomization and chaar's lvl */
void monsterEncounter(int level)
{
	int monsterLevel = 0;
	int charLevel = 1; // ### int charLevel = player.lvl;
	string rewardType; // sent to reward function with bounty to generate reward 
	int bounty = 0;
	/* receiving 100 as level means a random monster in the wilderness, less 
	 * difficult and less reward once killed */
	if (level == 100)
	{
		int randNum = ((rand() + time(0)) % 100);
		if (randNum < 100)
			monsterLevel = 1;
		if (randNum < 94)
			monsterLevel = 0;
		if (randNum < 87)
			monsterLevel = -1;
		if (randNum < 75)
			monsterLevel = -2;
		if (randNum < 50)
			monsterLevel = -3;
		bounty = monsterLevel + 5 + charLevel;
		rewardType = "wild";
	}
	else
	{
		int randNum = ((rand() + time(0)) % 3);
		monsterLevel = level + randNum - 1;
		monsterLevel += charLevel;
		bounty = charLevel;
		rewardType = "clue";
	}
	//###	 monster theMonster = new monster(monsterLevel);
	//monsterCombat();
	cout << "Monster sent to combat is level " << monsterLevel << endl;//###
	reward(rewardType, bounty); 
	return;
}
