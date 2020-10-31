#pragma once
#include "explore.cpp"
using namespace std;

int bookRealm();
void Armoury();
void generalStore();
void buyItem();
void questNPC();

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
            explore();
            break;
        case '2':
            Armoury();
            break;
        case '3':
            generalStore();
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

//added a armoury shop for users to purchess from, items still not hooked in
void Armoury()
{
    char choice;
    cout << endl
         << "Welcome to the Armory" << endl
         << endl;
    cout << "1: item 1" << endl;
    cout << "2: item 2" << endl;
    cout << "3: item 3" << endl;
    cout << "4: item 4" << endl;
    cout << "5: Exit the Armory" << endl;
    cin >> choice;

    bool choiceNotMade = true;
    while (choiceNotMade)
    {
        switch (choice)
        {
        case '1':
            //send in item object or item number from index WIP
            buyItem();
            break;
        case '2':
            buyItem();
            break;
        case '3':
            buyItem();
            break;
        case '4':
            buyItem();
            break;
        case '5':
            return;
        default:
            cout << "Invalid entry please try again" << endl;
        }
    }
    return;
}

//added a general store for users to purchess from, items still not hooked in
void generalStore()
{
    char choice;
    cout << endl
         << "Menu" << endl
         << endl;
    cout << "1: item 1" << endl;
    cout << "2: item 2" << endl;
    cout << "3: item 3" << endl;
    cout << "4: item 4" << endl;
    cout << "5: Exit General Store" << endl;
    cin >> choice;

    bool choiceNotMade = true;
    while (choiceNotMade)
    {
        switch (choice)
        {
        case '1':
            //send in item object or item number from index WIP
            buyItem();
            break;
        case '2':
            buyItem();
            break;
        case '3':
            buyItem();
            break;
        case '4':
            buyItem();
            break;
        case '5':
            return;
        default:
            cout << "Invalid entry please try again" << endl;
        }
    }
    return;
}

//recive in item object or item number from index WIP
void buyItem()
{
    return;
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