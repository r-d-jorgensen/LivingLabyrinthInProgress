/* reward function generates the reward depending on the type of monster
 * killed and where the monstr was met i.e. in wild or in major encounter */
void reward(string type, int amount)
{
	int gold = 0;
	if (type == "wild") {
		for (int i = 0;i<amount;i++) {
			int randNum = ((rand() + time(0)) % 5);
			gold += randNum;
		}
	}
	else if (type == "clue") {
		gold = amount * 100;
		for (int i = 0;i < amount;i++) {
			int randNum = ((rand() + time(0)) % 50);
			gold += randNum;
		}
	}
	else {
		gold =2;
	}	
	dialogue("You found " + to_string(gold) + "gold pieces after killing the enemy");
	// ### player.gold = gold;
	return;
}

