#include "bookRealm.h"

int bookRealm()
{
    char choice;
    cout << endl
         << "Menu" << endl
         << endl;
    cout << "1: Explore" << endl;
    cout << "2: Go to the Armoury" << endl;
    cout << "3: Go to the General Store" << endl;
    cout << "4: Talk to Quest NPC" << endl;
    cout << "5: Go Back to the Library" << endl;
    cout << "6: Exit the Game" << endl;
    cin >> choice;

    bool choiceNotMade = true;
    while (choiceNotMade)
    {
        switch (choice)
        {
        case '1':
            //explore function
            break;
        case '2':
            //Armoury
            break;
        case '3':
            //General Store
            break;
        case '4':
            questNPC();
            break;
        case '5':
            return 1;
        case '6':
            return 0;
        default:
            cout << "Invalid entry please try again" << endl;
        }
    }
    return 0;
}

void questNPC()
{
    char choice;
    cout << endl
         << "Intro words" << endl
         << endl;
    cout << "1: quest line" << endl;
    cout << "2: Ask about background" << endl;
    cout << "3: Stop talking to quest NPC" << endl;
    cin >> choice;

    bool choiceNotMade = true;
    while (choiceNotMade)
    {
        switch (choice)
        {
        case '1':
            //quest line implement
            break;
        case '2':
            //background words
            break;
        case '3':
            return;
        default:
            cout << "Invalid entry please try again" << endl;
        }
    }
}