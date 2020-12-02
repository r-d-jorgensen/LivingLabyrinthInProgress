#include "items.cpp"
#include "stats.cpp"
#include "save.cpp"
#include "combat.cpp"

using namespace std;

//Declaring character as a global variable to allow access to it
//in all functions without needing to create a new one/pass it
character player;

int main()
{
	string test;
	//Currently being used to test the funcitonality of our code so far
	cout << "Testing the save and load functions\n";
	character test1("TEST", 0, 10);
	player = test1;
	player.fillInv();
	player.inventory();
	player.showStats();
	player.showInv();
	cout << "\n";
	saveOut(player, "save1.txt");
	character test2 = loadIn("save1.txt");
	test2.showStats();
	test2.showInv();
	cout << "\nIf the two results appear the same then the process was successful\n";

	//cout << "Random item by type test\n";
	//item titem("1");
	//titem.showItem();
	return 0;
}
