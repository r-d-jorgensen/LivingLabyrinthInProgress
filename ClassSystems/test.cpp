#include "items.cpp"
#include "save.cpp"
#include "stats.cpp"

using namespace std;

int main()
{
	string test;
	//Currently being used to test the funcitonality of our code so far
	cout << "Testing the save and load functions\n";
	character test1("TEST");
	test1.fillInv();
	test1.showStats();
	test1.showInv();
	cout << "\n";
	saveOut(test1, "save1.txt");
	character test2 = loadIn("save1.txt");
	test2.showStats();
	test2.showInv();
	cout << "If the two results appear the same then the process was successful\n";
	return 0;
}
