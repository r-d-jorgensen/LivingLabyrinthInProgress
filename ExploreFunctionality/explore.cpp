#pragma once
#include <iostream>
#include "camp.cpp"
#include "reward.cpp"
#include "gamblingEncounter.cpp"
#include "luckyEncounter.cpp"
#include "majorEncounter.cpp"
#include "monsterEncounter.cpp"
#include "trapEncounter.cpp"
using namespace std;

void camp();
void explore();
void move(int trapChance, int majorChance, int monsterChance, int gambleChance);
void reward();

//explore to hook realms with encounters
void explore()
{
    char choice;
    cout << endl
         << "Explore the area?" << endl
         << endl;
    cout << "1: Camp" << endl;
    cout << "2: Move North" << endl;
    cout << "3: Move West" << endl;
    cout << "4: Move East" << endl;
    cout << "5: Move South" << endl;
    cout << "6: Look at Character Sheet" << endl;
    cout << "7: Stop exploring";
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
        case '7':
            return;
        default:
            cout << "Invalid entry please try again" << endl;
        }
    }
    return;
}

void move(int trapChance, int majorChance, int monsterChance, int gambleChance)
{
    int nothing = 15;
    int luck = 5; //pull from character sheet
    int roll = (rand() + time(NULL)) % 100;
    if (roll < nothing - luck)
    {
        //nothing
        cout << "You walk down the path but there is nothing but another crossroads.\n";
        return;
    }
    else if (roll < nothing)
    {
        luckyEncounter();
        return;
    }
    else if (roll < nothing + trapChance)
    {
        trapEncounter();
        return;
    }
    else if (roll < nothing + trapChance + majorChance)
    {
        majorEncounter();
        return;
    }
    else if (roll < nothing + trapChance + majorChance + monsterChance)
    {
        monsterEncounter();

        return;
    }
    else
    {
        gamblingEncounter();

        return;
    }
    return;
}
