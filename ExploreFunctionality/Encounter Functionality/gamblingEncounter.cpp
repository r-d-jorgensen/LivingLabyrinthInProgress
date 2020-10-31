/* gambling encounter, is called by encounterType function
 * gives player an opportunity to make some money, if lucky, then places new 
 * gold amount back to character's item*/
#include<string>
#include<iostream>
#include"textOutput.cpp"
using namespace std;
void gamblingEncounter()
{
	string play;
	int odds = 0;
	int bet = 0;
	int goldPieces = 0;
	int shellChoice = 0;
	int shell = 0;
	int goldCarried = 100; // call from items or stats etc
	dialogue("Welcome, you have found us. Would you like to play a game of shells? y or n", 2, "Dealer");
	cin >> play;
	cout << endl;
	cin.ignore();
	if ((play == "Y") || (play == "y") || (play == "Yes") ||
		(play == "yes") || (play == "YES")) {
		/* dialogue function formats the output and telss who/what is talking */
		dialogue("Great! Here is how we play. You can choose", 2, "Dealer");
		dialogue("	how many shells to play with and how ", 2, "Dealer");
		dialogue("much gold to bet. The more shells the more money you get back with a ", 2, "Dealer");
		dialogue("correct selection. ", 2, "Dealer");
		dialogue("Of course, if you lose, I get your wager. ",2 , "Dealer");
		/* loop to continue gambling as long as player wants */
		while ((play == "Y") || (play == "y") || (play == "Yes") ||
				(play == "yes") || (play == "YES")) {
			/* shells determin odds, thus, payback upon winning */
			dialogue("How many shells do you want to use? 2-10", 2, "Dealer");
			cin >> odds;
			/* loop taken if a letter is typed or shells not between 2 and 10 */
			while ((cin.fail()) || (!((odds > 1) && (odds < 11)))) {
				cin.clear();
				//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				cin.ignore();
				dialogue("bad entry, try again. ", 2, "Dealer");
				cin >> odds;
			}
			dialogue("What is your bet?", 2, "Dealer");
			cout << endl;
			cin.ignore();	
			cin >> bet;
			/* loop to catch letters or bets > than gold character hass */
			while ((cin.fail()) || (bet > goldCarried)) {
				cin.clear();
				//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				cin.ignore();
				dialogue("Your response is invalid. You cannot bet more than you have.", 2, "Dealer");				
				cin >> bet;
			}
			cout << endl;
			cin.ignore();
			shell = (rand() + time(0)) % odds;
			dialogue("Okay, which shell do you choose? " , 2, "Dealer");
			cout << "1 to " << odds << endl;
			cin >> shellChoice;
			cout << endl;
			cin.ignore();
			cout << "The winning shell is: " << shell +1 << endl;
			if (shellChoice == (shell + 1))
			{
				goldPieces = goldPieces + bet * (odds - 1);
				cout << "Good job! you won " << bet*(odds-1)<< "gold pieces " << endl;
				goldCarried = goldCarried + bet*(odds-1);
				cout << "Your current balance is " << goldPieces << " gold pieces" << endl;
			}			else {
				goldPieces = goldPieces - bet;
				cout << "Sorry, you lost " << bet << "gold pieces." << endl;
				cout << "Your current balance is " << goldPieces << " gold Pieces" << endl;
				goldCarried = goldCarried - bet;
			}
			dialogue("Would you like to play again? ", 2, "Dealer");
			cin >> play;
			cin.ignore();
		}
		cout << "gold carried = " << goldCarried << endl; // send to character gold
	}
}
/*
int main()
{
	gamblingEncounter();
	cout << " " << endl;
	return 0;
} 
*/
