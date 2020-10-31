#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
void luckyEncounter();
int gamblingEncounter();
void trapEncounter();
void majorEncounter(int gameLevel);
int riddle();
int question();
void monsterEncounter(int level);
int encounterType(int gameLevel, int count);
void Printgreeting();
int Doorgame();
using namespace std;
/* function receives a string. It returns the same string with all 
 * lowercase letters, so when comparing guess to answer, 
 * capitalization doesn't matter */
string strLower(string n)
{
	for (size_t i = 0; i < n.size(); i++)
	{
		n[i] = tolower(n[i]);
	}
	return n;
}
/* trap encounter  function selects a random trap which may cause harm */
void trapEncounter()
{
	cout << "Oh no, there is a trap" << endl;
}
/* gambling encounter, is called by encounterType function
 * gives player an opportunity to make some money, if lucky, then returns
 * an integer representing the los or gain of gold pieces while gambling. */
int gamblingEncounter()
{
	string play;
	int odds;
	int bet;
	int goldPieces = 0;
	int shellChoice = 0;
	int shell = 0;
	cout << "Welcome, you have found us. Would you like to play a game ";
	cout << "of shells? y or n";
	cin >> play;
	cout << endl;
	cin.ignore();
	if ((play == "Y") || (play == "y") || (play == "Yes") ||
		(play == "yes") || (play == "YES"))
	{
		cout << "Great! Here is how we play." << endl;
		cout << "You can choose how many shells to play with and how many gold" << endl;
		cout << "pieces you would like to wager. If you pick the correct shell then you multiply your bet" << endl;
		cout << "by the number of shells used in the game and that is how many " << endl;
		cout << "gold pieces you get back. for example: " << endl;
		cout << "if you use 2 shells and bet 10 gold pieces you get 20 pieces back." << endl;
		cout << "Your original 10 pieces + 10 more." << endl;
		cout << "if you choose 10 shells and wager 10 pieces, you get 100." << endl;
		cout << "Your original 10 + 90 more for winning." << endl;
		cout << "Of course, if you lose, I get your wager." << endl;
		while ((play == "Y") || (play == "y") || (play == "Yes") ||
			   (play == "yes") || (play == "YES"))
		{
			cout << "How many shells do you want to use?";
			cin >> odds;
			cout << endl;
			cin.ignore();
			cout << "What is your bet?";
			cin >> bet;
			cout << endl;
			cin.ignore();
			/* random number which uses odds chosen by player */
			shell = (rand() + time(0)) % odds;
			cout << "Okay, which shell do you choose? 1-" << odds;
			cin >> shellChoice;
			cout << endl;
			cin.ignore();
			cout << "The winning shell is: " << shell + 1 << endl;
			if (shellChoice == (shell + 1))
			{
				goldPieces = goldPieces + bet * (odds - 1);
				cout << "Nice work! You now have  " << goldPieces << " gold pieces" << endl;
			}
			else
			{
				goldPieces = goldPieces - bet;
				cout << "Sorry, you lost " << bet << "gold pieces." << endl;
				cout << "You now have " << goldPieces << " gold Pieces" << endl;
			}
			cout << "Would you like to play again?";
			cin >> play;
			cin.ignore();
		}
	}
	return goldPieces;
}
int riddle()
{
	ifstream riddleFile;
	/* opens riddle.txt file to access riddles */
	riddleFile.open("InfoFiles/Riddles/riddles.txt");
	string randomRiddle;
	string guess;
	string answer;
	/* int returned by function to help determine monster difficulty */
	int monsterlevel;
	/* randomizer to select riddle from txt file */
	int num = ((rand() + time(0)) % 63);
	num = 2 * num;
	for (int i = 0; i < num + 1; i++)
		getline(riddleFile, randomRiddle);
	cout << randomRiddle << endl;
	getline(riddleFile, answer);
	answer = strLower(answer);
	answer.erase(answer.find_last_not_of("\n\r") + 1);
	getline(cin, guess);
	/* erase call needed to erase potential last char that may be \n 
				 * which could cause an incorrect false comparison */
	guess.erase(guess.find_last_not_of("\n\r") + 1);
	/* function call to convert all letters to 
				 * lowercase, so simple capitalization doesn't cause a wrong answer */
	guess = strLower(guess);
	cout << endl;
	/* if wrong then get more difficult monster otherwise no monster or easier monster */
	if (guess.compare(answer) == 0)
	{
		cout << "Good job. Go through that door andd meet my friend." << endl;
		monsterlevel = 0;
	}
	else
	{
		cout << "Sorry, that is incorrect but";
		cout << "	 go ahead  and talk to my friend." << endl;
		monsterlevel = 1;
	}
	cout << endl;
	riddleFile.close();
	return monsterlevel;
} // end riddle function
/* another function to help determine monster level */
int question()
{
	ifstream questionFile;
	questionFile.open("InfoFiles/Questions/questions.txt");
	string randomQuestion;
	string guess;
	string answer;
	int monsterlevel; //int returned by function to determine monster difficulty
	int num = ((rand() + time(0)) % 5);
	/* calculation needed to select correct line for question in txt file */
	num = 2 * num;
	for (int i = 0; i < num + 1; i++)
		getline(questionFile, randomQuestion);
	cout << randomQuestion << endl;
	/* answer is first line following question in txt file */
	getline(questionFile, answer);
	answer = strLower(answer);
	answer.erase(answer.find_last_not_of("\n\r") + 1);
	getline(cin, guess);
	guess.erase(guess.find_last_not_of("\n\r") + 1);
	/* function call to convert all letters to lowercase, so simple capitalization doesn't cause a wrong answer */
	guess = strLower(guess);
	cout << endl;
	/* if wrong then get more difficult monster otherwise no monster or easier monster */
	if (guess.compare(answer) == 0)
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
	questionFile.close();
	return monsterlevel;
} // end question function
/* lucky encounter  function selects a random lucky find
 * gold, weapon, armor, or artifact */
void luckyEncounter()
{
	cout << "It is your lucky day, you see a bunch of gold" << endl;
}
/* monster function selects monster */
void monsterEncounter(int level)
{
	cout << "there is a monster at level " << level << endl;
	/* I think that maybe we use this function to find a monster from the  monster.txt file,
	 * create the armor class, hp and everything and then pass those attributes on  to
	 * the monstercombat function with all of the parameters passes to it. not sure */
	// call to monsterCombat function?
}
/*majorEncounter Function. Incorporates a greeting, a riddle, a trivia
 * question, a random door game. The success of these games determines 
 * the difficulty level of the monster to face at the end. Ends with a letter
 * clue for the final solution to the game */
/* greeting function produces a few different greetings for variety */
void Printgreeting()
{
	string greeting[5] = {
		"Hello, here is a riddle for you.",
		"It is good to see you. I have a riddle for you.",
		"I have been waiting for you. Here is a mind bender for you.",
		"If you answer this question correctly, I will help you pick the best door.",
		"There you are! Answer this."};
	/* random selection of 5 possible greetings for variety */
	int num = (rand() + time(0)) % 5;
	cout << greeting[num] << endl
		 << endl;
}
/* random chance for which monster to battle  depending on door selected */
int Doorgame()
{
	string door[3] = {"left", "middle", "right"};
	string guess;
	int monsterlevel = 0;
	int num = (rand() + time(0)) % 3;
	cout << "Choose a door: Left, Middle, or Right" << endl;
	cin >> guess;
	guess = strLower(guess);
	cout << endl;
	if (guess == door[num])
	{
		monsterlevel = 0;
	}
	else
	{
		monsterlevel = 2;
	}
	cout << "Good Luck" << endl
		 << endl;
	return monsterlevel;
}
/* calls thr riddle, question, and door functions to get level of monster,
 * then calss monsterEncounter for battle */
void majorEncounter(int level)
{
	int monster = 0;
	Printgreeting();
	monster = monster + riddle();
	monster = monster + question();
	monster = monster + Doorgame();
	monsterEncounter(monster);
	//after successfully killing monster find an object/letter something
	cout << "In the back of the room you see a golden letter 'S'" << endl;
}
/* This function randomly chooses which type of encounter will
 * occur next and then calls the function. If 10 encounters occur
 * without a major encounter, thena major encounter is called automatically */
int encounterType(int gameLevel, int count)
{
	int num = (rand() + time(0)) % 10;
	/* count is set at 1 and is then incremented, if count % 10
	 *yields 0 then num set to 0 and majorEncounter is called*/
	if (count % 10 == 0)
		num = 0;
	/* the easiest monster is called */
	if ((num == 1) || (num == 2))
		monsterEncounter(1);
	else if ((num == 3) || (num == 4))
		/* a monster equal to the game level is selected */
		monsterEncounter(gameLevel);
	else if ((num == 5) || (num == 6))
		luckyEncounter();
	else if ((num == 7) || (num == 8))
	{
		/* creat gold data but may need to call gold from character class 
		 * or just return +or - to character  gold */
		int gold;
		gold = gamblingEncounter();
		cout << "Your gambling excursion yielded you " << gold << "gold pieces.";
		cout << " " << endl;
	}
	else if (num == 9)
		trapEncounter();
	else
	{
		if (count % 10 > 0)
			count = 10 * (count / 10 + 1); // formula needed to employ correct number of majorEncounters
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
//	 calculate number of major encounter to collect letters for anagram solution letters is level +2
maxEncounters = (level+2)*10;
while (encounterCount<=maxEncounters) {
// passes level, current count, and  count
encounterCount = encounterType(level, encounterCount); 
}
return 0;
}
*/
