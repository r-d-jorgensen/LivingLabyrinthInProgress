// update for the encounter function
// changed  encounter class to a function and changed name to majorencounter

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

void friendlyencounter();
void storeencounter();
void monsterencounter();
void gamblingencounter();
void luckyencounter();
void majorencounter();
int encountertype(int gamelevel, int count);
void Printgreeting(); // Accessor
int Printriddle();
int Printquestion();
int Doorgame();
void Monstercombat(int level);
string strLower(string n);

int encountertype(int gamelevel, int count)
{
	int num = (rand() + time(0)) % 10;
	if (count % 10 == 0)
		num = 0;
	if ((num == 1) || (num == 2))
		friendlyencounter();
	else if ((num == 3) || (num == 4))
		storeencounter();
	else if ((num == 5) || (num == 6))
		monsterencounter();
	else if ((num == 7) || (num == 8))
		gamblingencounter();
	else if (num == 9)
		luckyencounter();
	else
	{
		if (count % 10 > 0)
			count = 10 * (count / 10 + 1); // formula needed to employ correct number of majorencounters
		majorencounter();
	}
	count++;
	return count;
}
void friendlyencounter()
{
	cout << "this is a friendly encounter" << endl;
}
void storeencounter()
{
	cout << "this is a storeencounter" << endl;
}
void monsterencounter()
{
	cout << "this is a monsterencounter" << endl;
}
void gamblingencounter()
{
	cout << "this is a gamvling encounter" << endl;
}
void luckyencounter()
{
	cout << "this is a lucky encounter" << endl;
}
void majorencounter()
{
	int monster = 0;
	Printgreeting();
	monster = monster + Printriddle();
	monster = monster + Printquestion();
	monster = monster + Doorgame();
	Monstercombat(monster);
	/* after successfully killing monster find an object/letter something */
	cout << "In the back of the room you see a golden letter 'S'" << endl;
}

void Printgreeting()
{
	string greeting[5] = {
		"Hello, here is a riddle for you.",
		"It is good to see you. I have a riddle for you.",
		"I have been waiting for you. Here is a mind bender for you.",
		"If you answer this question correctly, I will help you pick the best door.",
		"There you are! Answer this."};
	int num = (rand() + time(0)) % 5;
	cout << greeting[num] << endl
		 << endl;
}
/* function returns 0 if answer correct and 1 if answer is wrong making the monster more difficult */

int Printriddle()
{
	string riddle[5][2] = {
		{"Mr. and Mrs. Mustard have six daughters and each daughter has one brother. How many people are in the Mustard family?", "9"},
		{"I am something people love or hate. I change peoples appearances and thoughts. If a person takes care of them self I will go up even higher. To some people I will fool them. To others I am a mystery. Some people might want to try and hide me but I will show. No matter how hard people try I will Never go down. What am I?", "age"},
		{"Only one color, but not one size, Stuck at the bottom, yet easily flies. Present in sun, but not in rain, Doing no harm, and feeling no pain. What is it?", "shadow"},
		{"Who is that with a neck and no head, two arms and no hands?  What is it?", "shirt"},
		{"If eleven plus two equals one, what does nine plus five equal?", "2"}};
	string guess;
	int monsterlevel; //int returned by function to determine monster difficulty
	int num = ((rand() + time(0)) % 5);
	cout << riddle[num][0] << endl;
	cin >> guess;
	guess = strLower(guess);
	cout << endl;
	/* if wrong then get more difficult monster otherwise no monster or easier monster */
	if (guess == riddle[num][1])
	{
		cout << "Good job. You have just made your life a little easier. Go through that door andd meet my friend." << endl;
		monsterlevel = 0;
	}
	else
	{
		cout << "Sorry, that is incorrect but go ahead through that door and talk to my friend." << endl;
		monsterlevel = 1;
	}
	cout << endl;
	return monsterlevel;
} // end Printriddle function

/* another function to determine difficulty level of monster */
int Printquestion()
{
	string question[5][2] = {
		{"How many bits in a byte?", "8"},
		{"Who is president of the United States of America? (last Name)", "trump"},
		{"How many bits in a kilobyte?", "8192"},
		{"What is the capital of Canada?", "ottawa"},
		{"How long does it take for the sun's light to get to Earth?(nearest minute)", "8"}};
	string guess;
	int monsterlevel; //int returned by function to determine monster difficulty
	int num = ((rand() + time(0)) % 5);
	cout << question[num][0] << endl;
	cin >> guess;
	guess = strLower(guess);
	cout << endl;
	/* if wrong then get more difficult monster otherwise no monster or easier monster */
	if (guess == question[num][1])
	{
		cout << "Good job. You have just made your life a little easier. Go through that door and meet my friend for a game of chance." << endl;
		monsterlevel = 0;
	}
	else
	{
		cout << "Sorry, that is incorrect but it is time to try your luck at a game of chance. Go through that door." << endl;
		monsterlevel = 1;
	}
	cout << endl;
	return monsterlevel;
} // end Printquestion function
/* random chance for which monster to battle */
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
void Monstercombat(int level)
{
	cout << "There is a combat with  a monster at level " << level << endl;
	return;
}

string strLower(string n)
{
	for (size_t i = 0; i < n.size(); i++)
	{
		n[i] = tolower(n[i]);
	}
	return n;
}

int main()
{
	int level;
	int maxencounters;
	int encountercount = 1;
	cout << "What level do you want to play?";
	cin >> level;
	maxencounters = level * 10;
	while (encountercount < maxencounters)
	{
		encountercount = encountertype(level, encountercount);

		//cout << encountercount << endl;
	}
	return 0;
}
