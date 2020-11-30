#pragma once
#include "bookRealm.cpp"
#include "textOutput.cpp"
using namespace std;

void mainGameLoop();
int libraryChoices();
int cheshireNPC();
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
    string menuStr[][2] = {
        {"1", "Talk to Cheshire"},
        {"2", "Go to perk store"},
        {"3", "Open char sheet"},
        {"4", "Settings Menu"},
        {"5", "Exit the game"}};

    while (true)
    {
        switch (menu("You are now in the Living Libary", menuStr, 5, 0))
        {
        case '1':
            return (cheshireNPC());
        case '2':
            perkStore();
            break;
        case '3':
            statsDisplay();
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

int cheshireNPC()
{
    dialogue("He gets up and looks at you", 1, "Cheshire");
    string menuStr[][2] = {
        {"1", "I would like to go to into the book now"},
        {"2", "what is special about Wonderland?"},
        {"3", "What has happened in Wonderland?"},
        {"4", "Walk away"}};

    while (true)
    {
        switch (menu("What can I do for you, old child?", menuStr, 4, 0))
        {
        case '1':
            return 2; //sends player to realm through main
        case '2':
            dialogue("Ah it is a magical place where reality is less well ... strict", 2, "Cheshire");
            //more words discribing the place
            break;
        case '3':
            dialogue("Wild creatures are abound causing havoc ... well more than is normal. I'd like it if you went and removed some of them hanging out in the forest.",
                     2, "Cheshire");
            break;
        case '4':
            return 1;
        default:
            cout << "Invalid entry please try again" << endl;
        }
    }
    return 0;
}

//IN PROGRESS
void perkStore()
{
    cout << "This store is under construction come back another time.";
    return;
    string menuStr[][2] = {
        {"1", "Look at Combat Perks"},
        {"2", "Look at Explore Perks"},
        {"3", "Look at Shop Perks"},
        {"4", "Look at Secret Perks"},
        {"5", "Exit the Store"}};

    while (true)
    {
        switch (menu("Welcome to the Perk Store", menuStr, 5, 0))
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
    string menuStr[][2] = {
        {"1", "Swap Menu Text Format"},
        {"2", "Change the difficulty"},
        {"3", "Exit the Settings"}};

    while (true)
    {
        switch (menu("Settings Menu", menuStr, 3, 0))
        {
        case '1':
            textFormat();
            break;
        case '2':
            difficultySetting();
            break;
        case '3':
            return;
        default:
            cout << "Invalid entry please try again" << endl;
        }
    }
}

void textFormat()
{
    string menuStr[][2] = {
        {"1", "Text Reader Mode"},
        {"2", "Brief Mode"},
        {"3", "Stylized Mode"},
        {"4", "Return to Settings menu"}};

    while (true)
    {
        int choice = menu("What Text Type would you like?", menuStr, 3, 0);
        switch (choice)
        {
        case 1:
        case 2:
            player.textType = choice - 1;
            return;
        case 3:
            cout << "Sorry this mode is still in development";
        case 4:
            return;
        default:
            cout << "Invalid entry please try again" << endl;
        }
    }
}

void difficultySetting()
{
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
        int choice = menu("Which Difficulty would you like?", menuStr, 4, 0);
        switch (choice)
        {
        case 0:
            return;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            //side effects to be implemented
            player.difficulty = choice;
            return;
        default:
            cout << "Invalid entry please try again" << endl;
        }
    }
}