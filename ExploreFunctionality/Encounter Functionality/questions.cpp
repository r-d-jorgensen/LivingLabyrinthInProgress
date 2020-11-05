#include"encounters.h"
#include"textOutput.cpp"
int question()
{
	ifstream questionFile;
	questionFile.open("questions.txt");
	string randomQuestion;
	string guess;
	string answer;
	int monsterlevel; //int returned by function to determine monster difficulty
	int randNum = ((rand() + time(0)) % 5);
	randNum = 2*randNum;
	for (int i=0;i<randNum+1;i++) 
		getline(questionFile, randomQuestion);
	dialogue((randomQuestion) + " ",2, "Question Master");
	getline(questionFile, answer);
	answer = strLower(answer);
	answer.erase(answer.find_last_not_of("\n\r") + 1);
	getline(cin, guess);
	guess.erase(guess.find_last_not_of("\n\r") + 1);
	/* function call to convert all letters to lowercase, so simple capitalization doesn't cause a wrong answer */
	guess = strLower(guess);
	/* if wrong then get more difficult monster otherwise no monster or easier monster */
	if (guess.compare(answer) == 0) {
		dialogue("Good job. Go through that door andd meet the Door Master", 2, "Question Master");
		monsterlevel = 0;
	} else {
		dialogue("Sorry, that is incorrect.");
				dialogue("Go through that door and talk to the Door Master", 2,"Question Master");
				monsterlevel = 1;
				}
				questionFile.close();
				return monsterlevel;
				} // end question function
