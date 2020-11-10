/* function receives an int which indicates level of the monster if received 
 * from majorEncounter. A 100  indicates that monsterEncounter was called 
 * from Explore. function adjusts monster using randomization and cahar's lvl */ 
#include<iostream>
using namespace std;
void monsterEncounter(int level);
void monsterEncounter(int level)
{ 
	int monsterLevel = 0;
	if (level == 100) {
		int randNum = ((rand() + time(0)) % 100);
		if (randNum < 100)
			monsterLevel = 1;
		if (randNum <94)
			monsterLevel = 0;
		if (randNum < 87)
			monsterLevel = -1;
		if (randNum < 75)
			monsterLevel = -2;
		if (randNum < 50)
			monsterLevel = -3;
	} else {
		int randNum = ((rand() + time(0)) % 3);
		monsterLevel = level + randNum -1;
	}
	int charLevel = 1; // call char.lvl();
	monsterLevel += charLevel;
//	 monster = new monster(monsterLevel);
	//monsterCombat();
	cout << monsterLevel << endl;
}
/*
int main() {
	int i;
	for (i = 0; i<10;i++)
		monsterEncounter(2);
	for (i = 0; i<10;i++)
		monsterEncounter(100);
}
*/
