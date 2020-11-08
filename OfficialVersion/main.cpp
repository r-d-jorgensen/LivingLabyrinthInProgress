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
	test1.fillInv();
	test1.showStats();
	cout << "\n";
	saveOut(test1, "save1.txt");
	character test2 = loadIn("save1.txt");
	test2.showStats();
	cout << "If the two results appear the same then the process was successful\n";
	cout << "Test weapon creation & copying? (y/n)\n";
	cin >> test;
	if (test == "y" || test == "Y")
	{
		test1.showInv();
		cout << "\n\n";
		test2.showInv();
	}

	cout << "\nPress enter to continue to encounter testing\n";
	cin.ignore();
	getline(cin, test);

	cout << "Testing the encounter function,\n";
	//Following code taken from the main of Scott's encounter function
	gamblingEncounter();
luckyEncounter();
trapEncounter();
	monsterEncounter(3);
majorEncounter();
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
