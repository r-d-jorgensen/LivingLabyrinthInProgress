#include "JasonJ.cpp"
#include "DavidJ.cpp"
#include "ScottK.cpp"

using namespace std;
character player;
int location = 1;
//Currently being used to test the funcitonality of our code so far
void test()
{
	while (true)
	{
		cout << "\033[2J\033[1;1H";
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
			//character test1("TEST", 0, 10);
			player = loadIn();
			player.fillInv();
			player.name = "The Librarian";
			while (!player.inventory())
			{
			}
			/*
			test1.fillInv();
			test1.showStats();
			cout << "\n";
			saveOut(test1);
			character test2 = loadIn();
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
			*/
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
			tutorial();
			luckyEncounter();
			gamblingEncounter();
			trapEncounter();
			monsterEncounter();
			majorEncounter();
			finalEncounter();
			break;
		}
		default:
			cout << "That is not a valid test\n";
		}
	}
}

int main()
{
#ifdef TEST
	test();
#else
	gameEntrySaveCheck();
#endif
	return 0;
}
