/* gambling encounter, is called by encounterType function
 * gives player an opportunity to make some money, if lucky, then places new 
 * gold amount back to character's item*/
#include<string>
#include<iostream>
#include"textOutput.cpp"
using namespace std;

void gamblingEncounter();
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
		dialogue("Great! Here is how you play. You pick the number of shells and how much money you want to bet.", 2, "Dealer");
		dialogue("The more shells you want to use, the more money you win with a correct selection", 2, "Dealer");
		dialogue("Of course, if you lose, I get your wager.", 2, "Dealer");
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
			cin.ignore();	
			cin >> bet;
			/* loop to catch letters or bets > than gold character hass */
			while ((cin.fail()) || (!((bet > 0) && (bet <= goldCarried)))) {
				cin.clear();
				//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				cin.ignore();
				dialogue("Your response is invalid. You cannot bet more than you have.", 2, "Dealer");				
				cin >> bet;
			}
			cin.ignore();
			shell = (rand() + time(0)) % odds;
			/* need to convert int odds to string to print with dialogue*/ 
			dialogue("Okay, which shell do you choose 1 to " + to_string(odds), 2, "Dealer");
			cin >> shellChoice;
			/* checking for validity of user's shell choice */
			while ((cin.fail()) || (!((shellChoice > 0) && (shellChoice <=  odds)))) {
				cin.clear();
				//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				cin.ignore();
				dialogue("bad entry, try again. ", 2, "Dealer");
				cin >> shellChoice;
			}
			cin.ignore();
			dialogue("The winning shell is: " + to_string(shell + 1), 2, "Dealer");
			if (shellChoice == (shell + 1))
			{
				goldPieces = goldPieces + bet * (odds - 1);
				dialogue("Good job! you won " + to_string(bet*(odds-1))+ " gold pieces ", 2, "Dealer");
				goldCarried = goldCarried + bet*(odds-1);
				dialogue("Your current balance is " + to_string(goldPieces) + " gold pieces");
			}			else {
				goldPieces = goldPieces - bet;
				dialogue("Sorry, you lost " + to_string(bet) + "gold pieces.", 2, "Dealer");
				dialogue("Your current balance is " +to_string(goldPieces) + " gold Pieces");
				goldCarried = goldCarried - bet;
			}
			dialogue("Would you like to play again? ", 2, "Dealer");
			cin >> play;
			cin.ignore();
		}
		dialogue("Your total gold after playing is " + to_string(goldCarried)); // send to character gold
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
