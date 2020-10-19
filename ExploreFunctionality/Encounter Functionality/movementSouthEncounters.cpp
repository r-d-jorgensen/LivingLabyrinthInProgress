#include<iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "luckyEncounter.cpp"
#include"gamblingEncounter.cpp"
#include"trapEncounter.cpp"
#include "majorEncounter.cpp"
using namespace std;
/* for the movementSouth(any direction)Encounter function, I was
 * receiving the game level when called so that the monster level could be 
 * increased and the correct number of majorEncounters would be called, since
 *after each major encounter you receive a letter clue. level 1 has 
 * 3  ME's  and level 7 has 9 ME'S. the count variable is passed to keep track
 *  
 * of the encounters. When we talked a few weeks ago we talked about having 
 * random encounters but after 10 encounters we should have a major encounter,
 * so the game doesn't go on forever. */

int encounterType(int gameLevel, int count);
int encounterType(int gameLevel,int count) 
{
	int num = (rand()+time(0))%10;
	/* David, I think this is the varaible that you were laughing at this morning. 
	 * I know that it looks stupid and should have commented it. Anyway,
	 * count is used to make sure that only 10 encounters occur before a major 
	 * encounter takes place. it is originally set in main at 1, before calling 
	 * encounter. I had to set it to 1 because if major encounter was randomly 
	 * called first then there would be 1 too many majorEncounters, messing 
	 * up the game.*/

	if (count%10 ==0)
		num = 0;
	if ((num == 1) || (num == 2))
		monsterEncounter(1);
	else if ((num == 3) || (num == 4))
		monsterEncounter(gameLevel);
	else if ((num == 5) || (num == 6))
		luckyEncounter();
	else if ((num == 7) || (num == 8)) {
		/* creat gold data but may need to call gold from character class 
		 * or just return +or - to character  gold */
		int gold;
		gold =gamblingEncounter();
		cout << "Your gambling excursion yielded you " << gold << "gold pieces.";
		cout << " " << endl;
	}
	else if (num == 9) 
		trapEncounter();
	else {
		if (count%10 >0) 
			count = 10*(count/10+1); // formula needed to employ correct number of majorEncounters
		majorEncounter(gameLevel);
	}
	count++;
	return count;
}
int main() {
	int level;
	int maxEncounters;
	int encounterCount=1;
	cout << "What level do you want to play?";
	cin >> level;

	/* calculate number of major encounter to collect letters for anagram solution letters is level +2*/
	maxEncounters = (level+2)*10;
	while (encounterCount<=maxEncounters) {
		/* passes level, current count, and jumble returns int encounter count*/
		encounterCount = encounterType(level, encounterCount); 
		//cout << encounterCount << endl;
	}
	return 0;
}
