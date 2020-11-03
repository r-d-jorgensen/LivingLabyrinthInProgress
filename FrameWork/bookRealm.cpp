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
    int menuOptions = 6;
    string menuStr[][2] = {
        {"1", "Explore"},
        {"2", "Go to the Armoury"},
        {"3", "Go to the General Store"},
        {"4", "Talk to Quest NPC"},
        {"5", "Go Back to the Library"},
        {"6", "Exit the Game"}};

    while (true)
    {
        switch (menu("Book Realm Menu", menuStr, menuOptions, 0))
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
    int menuOptions = 5;
    string menuStr[][2] = {
        {"1", "item 1"},
        {"2", "item 2"},
        {"3", "item 3"},
        {"4", "item 4"},
        {"5", "item 5"}};

    while (true)
    {
        switch (menu("Welcome to the Armory", menuStr, menuOptions, 0))
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
    int menuOptions = 5;
    string menuStr[][2] = {
        {"1", "item 1"},
        {"2", "item 2"},
        {"3", "item 3"},
        {"4", "item 4"},
        {"5", "Exit General Store"}};

    while (true)
    {
        switch (menu("Welcome to the General Store", menuStr, menuOptions, 0))
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
    int menuOptions = 3;
    string menuStr[][2] = {
        {"1", "quest line"},
        {"2", "Ask about background"},
        {"3", "Stop talking to quest NPC"}};

    while (true)
    {
        switch (menu("Intro words", menuStr, menuOptions, 0))
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