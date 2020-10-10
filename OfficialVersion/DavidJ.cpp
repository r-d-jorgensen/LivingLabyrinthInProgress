//David Jorgensen
#include "DavidJ.h"

void mainGameLoop()
{
    //run game
    int location = 1;
    while (true)
    {
        if (location == 0)
        {
            cout << "Thank You For Playing" << endl;
            cout << "This was made by David Jorgensen, Jason Jellie, and Scott Kurtz " << endl;
            return;
        }
        else if (location == 1)
        {
            location = libraryChoices();
        }
        else if (location == 2)
        {
            //bookRealm();
        }
    }
}

int libraryChoices()
{
    char choice;
    cout << endl
         << "Living Libary Menu" << endl
         << endl;
    cout << "1: Talk to book NPC" << endl;
    cout << "2: Go to perk store" << endl;
    cout << "3: Open char sheet" << endl;
    cout << "4: Settings Menu" << endl;
    cout << "5: Exit the game" << endl;
    cin >> choice;

    bool choiceNotMade = true;
    while (choiceNotMade)
    {
        switch (choice)
        {
        case '1':
            return (bookRealmNPC()); //talk to book Realm NPC
        case '2':
            perkStore();
            break;
        case '3':
            //character sheet
            break;
        case '4':
            settingsMenu();
            break;
        case '5':
            return 0; //exit game though main
        default:
            cout << "Invalid entry please try again" << endl;
        }
    }
    return 0;
}

int bookRealmNPC()
{
    char choice;
    cout << endl
         << "NPC Name" << endl
         << endl;
    cout << "1: Go to bookRealm" << endl;
    cout << "2: Ask about the book" << endl;
    cout << "3: Ask about the problems" << endl;
    cout << "4: Walk away" << endl;
    cin >> choice;

    bool choiceNotMade = true;
    while (choiceNotMade)
    {
        switch (choice)
        {
        case '1':
            return 2; //sends player to realm through main
        case '2':
            //words about the book
            break;
        case '3':
            //words about the problems
            break;
        case '4':
            return 1;
        default:
            cout << "Invalid entry please try again" << endl;
        }
    }
    return 0;
}

void perkStore()
{
    char choice;
    cout << endl
         << "Welcome to the Perk Store" << endl
         << endl;
    cout << "1: Look at Combat Perks" << endl;
    cout << "2: Look at Explore Perks" << endl;
    cout << "3: Look at Shop Perks" << endl;
    cout << "4: Look at Secret Perks" << endl;
    cout << "5: Exit the Store" << endl;
    cin >> choice;

    bool choiceNotMade = true;
    while (choiceNotMade)
    {
        switch (choice)
        {
        case '1':
            //combat perks
            break;
        case '2':
            //explore perks
            break;
        case '3':
            //shop perks
            break;
        case '4':
            //secret perks
            break;
        case '5':
            return; //return to library menu
        default:
            cout << "Invalid entry please try again" << endl;
        }
    }
}

void settingsMenu()
{
    char choice;
    cout << endl
         << "Settings Menu" << endl
         << endl;
    cout << "1: Swap Menu Text Format" << endl;
    cout << "2: Change the difficulty" << endl;
    cout << "3: " << endl; //tbd
    cout << "4: " << endl; //tbd
    cout << "5: Exit the Settings" << endl;
    cin >> choice;

    bool choiceNotMade = true;
    while (choiceNotMade)
    {
        switch (choice)
        {
        case '1':
            textFormat();
            break;
        case '2':
            difficultySetting();
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            return;
            break;
        default:
            cout << "Invalid entry please try again" << endl;
        }
    }
}

void textFormat()
{
    char choice;
    cout << endl
         << "Text Types" << endl
         << endl;
    cout << "1: Default Mode" << endl;
    cout << "2: Brief Mode" << endl;
    cout << "3: Text Reader Mode" << endl;
    cout << "4: Return to Settings menu" << endl;
    cin >> choice;

    bool choiceNotMade = true;
    while (choiceNotMade)
    {
        switch (choice)
        {
        case '1':
            //normal mode
            return;
        case '2':
            //brief mode
            return;
        case '3':
            //text reader mode
            return;
        case '4':
            return;
        default:
            cout << "Invalid entry please try again" << endl;
        }
    }
}

void difficultySetting()
{
    char choice;
    cout << endl
         << "Which Difficulty would you like?" << endl
         << endl;
    cout << "1: Easy" << endl;
    cout << "2: Medium" << endl;
    cout << "3: Hard" << endl;
    cout << "4: Return to Settings menu" << endl;
    cin >> choice;

    bool choiceNotMade = true;
    while (choiceNotMade)
    {
        switch (choice)
        {
        case '1':
            //change difficulty to Easy
            return;
        case '2':
            //change difficulty to Medium
            return;
        case '3':
            //change difficulty to Hard
            return;
        case '4':
            return;
        default:
            cout << "Invalid entry please try again" << endl;
        }
    }
}

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