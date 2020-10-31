
/* Scott Kurtz
 *majorEncounter Function. Incorporates a greeting, a riddle, a trivia
 * question, a random door game. The success of these games determines 
 * the difficulty level of the monster to face at the end. Ends with a letter
 * clue for the final solution to the game */
#include"majorEncounter.h"

string strLower(string n);
string strLower(string n) {
	for (size_t i=0;i<n.size();i++){
		n[i] = tolower(n[i]);
	}
	return n;
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
void majorEncounter() 
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
