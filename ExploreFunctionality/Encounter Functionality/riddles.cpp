#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include "strLower.cpp"

using namespace std;

int riddle()
{
	ifstream riddleFile;
	riddleFile.open("InfoFiles/Riddles/riddles.txt");
	string randomRiddle;
	string guess;
	string answer;
	int monsterlevel; //int returned by function to determine monster difficulty
	int num = ((rand() + time(0)) % 63);
	num = 2*num;
	cout << num << endl;

	for (int i=0;i<num+1;i++) 
		getline(riddleFile, randomRiddle);
	cout << randomRiddle << endl;
	getline(riddleFile, answer);
	cout << answer << endl;

	answer = strLower(answer);
	//    getline(cin,guess);
	getline(cin, guess);
	/* function call to convert all letters to lowercase, so simple capitalization doesn't cause a wrong answer */
	guess = strLower(guess);
	cout << endl;
	/* if wrong then get more difficult monster otherwise no monster or easier monster */
	cout << "guess = " << guess << " answer = " << answer << endl;
	if (guess.compare(answer))
	{
		cout << "Good job. Go through that door andd meet my friend." << endl;
		monsterlevel = 0;
	}
	else
	{
		cout << "Sorry, that is incorrect but go ahead through that door and talk to my friend." << endl;
		monsterlevel = 1;
	}
	cout << endl;
	riddleFile.close();
	return monsterlevel;
} // end riddle functio

int main () {
	int monster;
	monster = riddle();
	cout << monster << endl;
	return 0;
}
