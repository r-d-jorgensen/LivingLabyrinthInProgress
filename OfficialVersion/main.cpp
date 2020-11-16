#include "JasonJ.cpp"
#include "ScottK.cpp"
#include "DavidJ.cpp"

using namespace std;

//Currently being used to test the funcitonality of our code so far
void test()
{
	while (true)
	{
		cout << "Which test would you like to run\n";
		cout << "0: Exit Testing\n";
		cout << "1: Jason's Tests\n";
		cout << "2: David's Tests\n";
		cout << "3: Scott's Tests\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 0:
			return;
		//Jasons Tests
		case 1:
		{
			string test;
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
			break;
		}
		//Davids Tests
		case 2:
		{
			dialogue("Hello world");
			dialogue("Rumble", 1, "Enviroment");
			dialogue("It cannot be seen, cannot be felt, cannot be heard, and cannot be smelt. It lies behind stars and under hills, And empty holes it fills. It comes first and follows after, Ends life, and kills laughter. What is it?", 2, "NPC");
			/*
			int menuOptions = 5;
			string menuStr[][2] =
				{
					{"1", "Talk to book NPC"},
					{"2", "Go to perk store"},
					{"3", "Open char sheet"},
					{"4", "Settings Menu"},
					{"5", "Exit the game"}};
			menu("Living Libary Menu", menuStr, menuOptions);

			statsDisplay();
			combatText(2, 10, true, "goblin", 20, 2, 1, 1, false, false);
			*/
			//size checker
			for (int i = 0; i < 8; i++)
				for (int j = 0; j < 10; j++)
					cout << j;
			break;
		}
		//Scotts Tests
		case 3:
		{
			cout << "Testing the encounter function,\n";
			//Following code taken from the main of Scott's encounter function
			gamblingEncounter();
			luckyEncounter();
			trapEncounter();
			monsterEncounter(3);
			majorEncounter();
		}
		default:
			cout << "That is not a valid test\n";
		}
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
