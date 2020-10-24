#include "explore.h"

//explore to hook realms with encounters
void explore()
{
    char choice;
    cout << endl
         << "Menu" << endl
         << endl;
    cout << "1: Camp" << endl;
    cout << "2: Move North" << endl;
    cout << "3: Move West" << endl;
    cout << "4: Move East" << endl;
    cout << "5: Move South" << endl;
    cout << "6: Look at Character Sheet" << endl;
    cin >> choice;

    bool choiceNotMade = true;
    while (choiceNotMade)
    {
        switch (choice)
        {
        case '1':
            camp();
            break;
        case '2':
            move(25, 20, 20, 20);
            break;
        case '3':
            move(20, 25, 20, 20);
            break;
        case '4':
            move(20, 20, 25, 20);
            break;
        case '5':
            move(20, 20, 20, 25);
            break;
        case '6':
            //showStats();
            break;
        default:
            cout << "Invalid entry please try again" << endl;
        }
    }
    return;
}

void move(int trapChance, int majorChance, int monsterChance, int gambleChance)
{

    int luck = 5; //pull from character sheet
    int roll = (rand() + time(NULL)) % 100;
    if (roll < 15 - luck)
    {
        //nothing
        cout << "You walk down the path but there is nothing but another crossroads.\n";
        return;
    }
    else if (roll < 15)
    {
        //lucky

        return;
    }
    else if (roll < 15 + trapChance)
    {
        //trap

        return;
    }
    else if (roll < 15 + trapChance + monsterChance)
    {
        //monster

        return;
    }
    else
    {
        //gamble

        return;
    }
    return;
}