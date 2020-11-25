#pragma once
#include "bookRealm.cpp"
#include "textOutput.cpp"
using namespace std;

void mainGameLoop();
int libraryChoices();
int bookRealmNPC();
void perkStore();
void settingsMenu();
void textFormat();
void difficultySetting();

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
            bookRealm();
        }
    }
}

int libraryChoices()
{
    int menuOptions = 5;
    string menuStr[][2] = {
        {"1", "Talk to book NPC"},
        {"2", "Go to perk store"},
        {"3", "Open char sheet"},
        {"4", "Settings Menu"},
        {"5", "Exit the game"}};

    while (true)
    {
        switch (menu("Living Libary Menu", menuStr, menuOptions, 0))
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
    int menuOptions = 4;
    string menuStr[][2] = {
        {"1", "Go to bookRealm"},
        {"2", "Ask about the book"},
        {"3", "Ask about the problems"},
        {"4", "Walk away"}};

    while (true)
    {
        switch (menu("NPC Name", menuStr, menuOptions, 0))
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
    int menuOptions = 5;
    string menuStr[][2] = {
        {"1", "Look at Combat Perks"},
        {"2", "Look at Explore Perks"},
        {"3", "Look at Shop Perks"},
        {"4", "Look at Secret Perks"},
        {"5", "Exit the Store"}};

    while (true)
    {
        switch (menu("Welcome to the Perk Store", menuStr, menuOptions, 0))
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
    int menuOptions = 3;
    string menuStr[][2] = {
        {"1", "Swap Menu Text Format"},
        {"2", "Change the difficulty"},
        {"3", "Exit the Settings"}};

    while (true)
    {
        switch (menu("Settings Menu", menuStr, menuOptions, 0))
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
    int menuOptions = 4;
    string menuStr[][2] = {
        {"1", "Text Reader Mode"},
        {"2", "Brief Mode"},
        {"3", "Stylized Mode"},
        {"4", "Return to Settings menu"}};

    while (true)
    {
        string choice = menu("Text Types", menuStr, menuOptions, 0);
        switch (choice)
        {
        case '1':
        case '2':
        case '3':
            player.textType = (int)choice - 1;
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
    int menuOptions = 4;
    string menuStr[][2] = {
        {"0", "Return to Settings menu"},
        {"1", ""},
        {"2", ""},
        {"3", ""},
        {"4", ""},
        {"5", ""},
        {"6", ""},
        {"7", ""},
        {"8", ""},
        {"9", ""},
        {"10", ""}};

    while (true)
    {
        string choice = menu("Which Difficulty would you like?", menuStr, menuOptions, 0);
        switch (choice)
        {
        case '0':
            return;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '10':
            //side effects to be implemented
            player.difficulty = (int)choice;
            return;
        default:
            cout << "Invalid entry please try again" << endl;
        }
    }
}