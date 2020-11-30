#pragma once
#include "explore.cpp"
using namespace std;

int bookRealm();
void Armoury();
void generalStore();
void buyItem();
void aliceNPC();

int bookRealm()
{
    string menuStr[][2] = {
        {"1", "Explore"},
        {"2", "Go to the Armoury"},
        {"3", "Go to the General Store"},
        {"4", "Talk to Alice"},
        {"5", "Go Back to the Library"},
        {"6", "Exit the Game"}};

    while (true)
    {
        switch (menu("Book Realm Menu", menuStr, 6, 0))
        {
        case '1':
            explore();
            break;
        case '2':
            Armoury();
            break;
        case '3':
            cout << "This building is under construction";
            //generalStore();
            break;
        case '4':
            aliceNPC();
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
    string menuStr[][2] = {
        {"1", "item 1"},
        {"2", "item 2"},
        {"3", "item 3"},
        {"4", "item 4"},
        {"5", "item 5"}};

    while (true)
    {
        switch (menu("Welcome to the Armory", menuStr, 5, 0))
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

//IN PROGRESS
void generalStore()
{
    cout << "This store is under construction come back another time.";
    return;
    string menuStr[][2] = {
        {"1", "item 1"},
        {"2", "item 2"},
        {"3", "item 3"},
        {"4", "item 4"},
        {"5", "Exit General Store"}};

    while (true)
    {
        switch (menu("Welcome to the General Store", menuStr, 5, 0))
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

void aliceNPC()
{
    string menuStr[][2] = {
        {"1", "What has been happaning in the forest?"},
        {"2", "Anything special that I need to know about the forest?"},
        {"3", "Stop talking to Alice"}};

    while (true)
    {
        switch (menu("Intro words", menuStr, 3, 0))
        {
        case '1':
            dialogue("You must help me get rid of those beasties in the forest and hills", 2, "Alice");
            //more words about what she wants player to do if statments if objectives completed
            break;
        case '2':
            dialogue("Well the creatures in there are very bad, but I'm not sure what is causing it. " +
                         "I dont think it is the RED QUEEN but it has " +
                         "something to do with the letters they are carrying",
                     2, "Alice");
            //more stuff about what is going on
            break;
        case '3':
            return;
        default:
            cout << "Invalid entry please try again" << endl;
        }
    }
}