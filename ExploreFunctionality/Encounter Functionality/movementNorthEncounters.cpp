/* update to encounterType function. changes likelihood of encounters
 * depending on the direction you take. north is less eventful slower */

#include<iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "luckyEncounter.cpp"
#include"gamblingEncounter.cpp"
#include"trapEncounter.cpp"
#include "majorEncounter.cpp"
using namespace std;

int movementNorthEncounters(int gameLevel, int count);
int movementNorthEncounters(int gameLevel,int count) 
{
	int num = (rand()+time(0))%100;
	if (count%50 ==0)
		num = 0;
	if ((num > 0) && (num< 50))
		cout << "you see mountains in the distance" << endl;
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
/*
   int main() {
   int level;
   int maxEncounters;
   int encounterCount=1;
   cout << "What level do you want to play?";
   cin >> level;

   note      calculate number of major encounter to collect letters for anagram solution letters is level +2
   maxEncounters = (level+2)*10;
   while (encounterCount<=maxEncounters) {
   encounterCount = encounterType(level, encounterCount); 
   }
   return 0;
   }

*/
