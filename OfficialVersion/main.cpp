#include "DavidJ.cpp"
#include "JasonJ.cpp"
#include "ScottK.cpp"

using namespace std;

void test()
{
	string test;
	//Currently being used to test the funcitonality of our code so far
	cout << "Testing the save and load functions\n";
	character test1("TEST");
	test1.showStats();
	cout << "\n";
	saveout(test1, "save1.txt");
	character test2 = savein("save1.txt");
	test2.showStats();
	cout << "If the two results appear the same then the process was successful\n";

	cout << "\nPress enter to continue to encounter testing\n";
	//cin.ignore();
	getline(cin, test);

	cout << "Testing the encounter function,\n";
	//Following code taken from the main of Scott's encounter function
	int level;
	int maxEncounters;
	int encounterCount = 1;
	cout << "What level do you want to play? \n";
	cin >> level;
	/* calculate max number  of encounters, 
	 * majorEncounters = level +2, letters in anagram) */
	maxEncounters = (level + 2) * 10;
	while (encounterCount <= maxEncounters)
	{
		/* passes level and current count, returns new count which is either count+1 
		 * or increased to next multiple of 10 +1, if majorEncounter randomly picked*/
		encounterCount = encounterType(level, encounterCount);
	}
}

int main()
{
	char choice;
	cout << "Would you like to run the test or main game loop?\n";
	cout << "T for test and R for main game loop\n";
	cout << "Enter anything else to exit\n";
	cin >> choice;

	if (choice == 't' || choice == 'T')
	{
		test();
	}
	if (choice == 'r' || choice == 'R')
	{
		mainGameLoop();
	}

	return 0;
}
