/* gambling encounter, is called by encounterType function
 * gives player an opportunity to make some money, if lucky, then returns
 * an integer representing the los or gain of gold pieces while gambling. */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int gamblingEncounter();
int gamblingEncounter()
{
    char play = '-';
    int odds;
    int bet;
    int goldPieces = 0;
    int shellChoice;
    int shell;
    cout << "Welcome, you have found us. Would you like to play a game ";
    cout << "of shells? y or n";
    cin >> play;
    cout << endl;
    cin.ignore();
    /* How do I fix this areia? it works unless someone types more
 * than one letter, i.e.  yes or no. Any thoughts?*/
    if (play == 'y')
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
        while (play == 'y')
        {
            cout << "How many shells do you want to use?";
            cin >> odds;
            cout << endl;
            cin.ignore();
            cout << "What is your bet?";
            cin >> bet;
            cout << endl;
            cin.ignore();
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

int main()
{
    int gold;
    gold = gamblingEncounter();
    cout << "Your gambling excursion yielded you " << gold << "gold pieces.";
    cout << " " << endl;
    return 0;
}
