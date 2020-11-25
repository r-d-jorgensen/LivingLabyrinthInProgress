/* camp function is called when player wants to rest. there is a 10% chance 
 * that a monster will ambush the player, so no rest is attained. Otherwise, if
 *  allowed to rest, then player increases hit points by a constant factor 
 *  based on constitution and a random number*/
void camp()
{
	int randEnc = ((rand() + time(0)) % 10);
	if (randEnc == 1)
	{
		dialogue("You hear a noise that wakes you from your slumber");
		dialogue("You prepare for some kind of attack.");
		monsterEncounter(); //call monsterEncounter function
	}
	else
	{
		int maxHP = 40;     // ###int maxHP = player.maxHP;
		int currentHP = 30; // ### int currentHP = player.HP;
		int diff = maxHP - currentHP;
		int constitution = 7; // ###int constitution = player.con;
		int randNum = ((rand() + time(0)) % (maxHP / 2));
		int conAdjustment = constitution * (maxHP / 20); // incorporates player con to heal
		int hpFactor = conAdjustment + randNum;
		currentHP = currentHP + ((diff * hpFactor) / maxHP);
		dialogue("You feel rested. You gained ");
		dialogue(to_string((diff * hpFactor) / maxHP) + "HP");
		dialogue("You have " + to_string(currentHP) + "HP");
		//### player.HP = currentHP + HP;
	}
	return;
}
