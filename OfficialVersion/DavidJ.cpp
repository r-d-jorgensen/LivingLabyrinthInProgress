/*David Jorgensen
 * lab 8:
 * Created new hooks and infrastructure
 *  The explore functionality, item system and thier hooks
 *  and reorganized the code to be easier to read
 * 
*/
#pragma once
#include <iostream>
#include "JasonJ.cpp"
#include "ScottK.cpp"
using namespace std;

//Declarations
void mainGameLoop();
int libraryChoices();
int bookRealmNPC();
void perkStore();
void settingsMenu();
void textFormat();
void difficultySetting();
int bookRealm();
void Armoury();
void generalStore();
void buyItem();
void questNPC();
void dialogueLong(string str, string startStr, int paddingLength, string padding);
void dialogue(string str, int msgType, string speaker);
void camp();
void explore();
void move(int trapChance, int majorChance, int monsterChance, int gambleChance);
void reward();
//End of Declarations

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

//not sure yet how it will be implemented, leaving hook for later
void camp()
{
    return;
}

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

void reward()
{
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
        monsterEncounter(1); // level of monster passed

        return;
    }
    else
    {
        gamblingEncounter();

        return;
    }
    return;
}

void dialogueLong(string str, string startStr = "", int paddingLength = 0, string padding = "")
{
    //parse
    string delimiter = " ";
    size_t pos = 0;
    int i = 0;
    string parsedStr[100];
    while ((pos = str.find(delimiter)) != string::npos)
    {
        parsedStr[i] = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        i++;
    }
    parsedStr[i] = str;

    //print
    int lineLength = startStr.length();
    cout << startStr;
    for (size_t i = 0; i < sizeof(parsedStr) / sizeof(parsedStr[0]); i++)
    {
        if (parsedStr[i] == "")
        {
            break;
        }
        lineLength += parsedStr[i].length() + 1;
        cout << parsedStr[i] + " ";
        if (lineLength + parsedStr[i + 1].length() > 80)
        {
            cout << endl
                 << padding;
            lineLength = paddingLength;
        }
    }
}

void dialogue(string str, int msgType = 0, string speaker = "Self")
{
    int textType = 0; //import from save file
    switch (textType)
    {
    //bare format
    case 0:
    {
        if (str.length() < 60)
        {
            cout << str;
        }
        else
        {
            dialogueLong(str);
        }
        break;
    }
    //simple format
    case 1:
        if (str.length() + speaker.length() + 2 < 60)
        {
            cout << speaker << ": " << str;
        }
        else
        {
            dialogueLong(str, speaker + ": ", 8, "\t");
        }
        break;
    //stylized format
    case 2:
    {
        string edge = "***";
        string internalSpace = "\t\t\t";
        string leftPadding = edge + internalSpace;
        string rightPadding = internalSpace + edge + "\n";
        cout << edge;
        switch (msgType)
        {
        //Self
        case 0:
            cout << "@@  " << str << "  @@";
            break;
        //Enviroment
        case 1:
            cout << "//  " << str << "  \\\\";
            break;
        //NPC
        case 2:
            cout << "&& " << speaker << ":\t" << str << "  &&";
            break;
        default:
            cout << "Something is wrong with the fuction this was called from.\n";
        }
        cout << "\t" + edge << endl
             << edge + internalSpace + internalSpace + internalSpace + edge;
        break;
    }
    default:
        cout << "Something is wrong with the save file textType.\n";
    }
    cout << endl;
    return;
}