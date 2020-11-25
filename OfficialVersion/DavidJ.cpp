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
void explore();
void move(int trapChance, int majorChance, int monsterChance, int gambleChance);
void dialogueLong(string str, string startStr, int paddingLength, string padding);
void dialogue(string str, int msgType, string speaker);
int menu(string menuName, string optionsStr[][2], int optionsNum, int menuType);
void statsDisplay();
string playerCombatString(int actionPlayer);
void combatText(int actionPlayer, int dmgPlayer, bool critPlayer, string nameMonster,
                int hpMonster, int dmgMonster, int actionMonster, bool critMonster);

#include "ScottK.cpp"
extern character player;
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
        {"1", "Default Mode"},
        {"2", "Brief Mode"},
        {"3", "Text Reader Mode"},
        {"4", "Return to Settings menu"}};

    while (true)
    {
        switch (menu("Text Types", menuStr, menuOptions, 0))
        {
        case '1':
            //bare mode
            return;
        case '2':
            //simple mode
            return;
        case '3':
            //stylized mode
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
        {"1", "Easy"},
        {"2", "Medium"},
        {"3", "Hard"},
        {"4", "Return to Settings menu"}};

    while (true)
    {
        switch (menu("Which Difficulty would you like?", menuStr, menuOptions, 0))
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

//explore to hook realms with encounters
void explore()
{
    while (true)
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

void dialogueLong(string str, string startStr = "", int paddingLength = 0, string padding = "")
{
    //parse
    string delimiter = " ";
    size_t pos = 0;
    int size = 0;
    string parsedStr[100];
    while ((pos = str.find(delimiter)) != string::npos)
    {
        parsedStr[size] = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        size++;
    }
    parsedStr[size] = str;

    //print
    int lineLength = startStr.length();
    cout << startStr;
    for (int i = 0; i < size + 1; i++)
    {
        if (parsedStr[i] == "")
        {
            break;
        }
        lineLength += parsedStr[i].length() + 1;
        cout << parsedStr[i] + " ";
        if (lineLength + parsedStr[i + 1].length() > 79)
        {
            cout << endl
                 << padding;
            lineLength = paddingLength;
        }
    }
}

void dialogue(string str, int msgType = 0, string speaker = "Self")
{
    switch (player.textType)
    {
    //bare format
    case 0:
        if (str.length() < 80)
        {
            cout << str;
        }
        else
        {
            dialogueLong(str);
        }
        break;
    //simple format
    case 1:
        if (str.length() + speaker.length() + 2 < 80)
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
            break;
        }
        cout << "\t" + edge << endl
             << edge + internalSpace + internalSpace + internalSpace + edge;
    }
    default:
        cout << "Something is wrong with the save file textType.\n";
    }
    cout << endl;
    return;
}

int menu(string menuName, string optionsStr[][2], int optionsNum, int menuType = 0)
{
    switch (player.textType)
    {
    //bare format
    case 0:
        cout << menuName << endl;
        for (int i = 0; i < optionsNum; i++)
        {
            cout << optionsStr[i][0] << ": " + optionsStr[i][1] << endl;
        }
        break;
    //simple format
    case 1:
        cout << "\t" << menuName << endl;
        cout << "================================================" << endl;
        for (int i = 0; i < optionsNum; i++)
        {
            cout << "\t" << optionsStr[i][0] << ": " + optionsStr[i][1] << endl;
        }
        cout << "================================================" << endl;
        break;
    //stylized format
    case 2:
        //not implemented yet
        break;
    }
    char choice;
    cin >> choice;
    return choice;
}

void statsDisplay()
{
    string statsStrings[] = {"STR: ", "INT: ", "DEX: ", "AGL: ", "LCK: "};
    switch (player.textType)
    {
    case 0:
        cout << "Name: " << player.name << endl
             << "Level: " << player.lvl << endl
             << "Health: " << player.HP << " / " << player.maxHP << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << statsStrings[i] << player.stat[i];
        }
        break;
    case 1:
        cout << "Name: " << character.name << "\t"
             << "Level: " << character.lvl << "\t"
             << "Health: " << character.hp << " / " << character.maxHp << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "\t" << statsStrings[i] << character.stat[i];
            if (i + 1 % 2 == 0)
            {
                cout << endl;
            }
        }
        break;
    //stylized is yet to be implemented
    case 2:
        break;
    default:
        cout << "Something is wrong with the save file textType.\n";
    }
    return;
}

string playerCombatString(int actionPlayer)
{
    switch (actionPlayer)
    {
    //Light Attack
    case 0:
        switch (player.eqpt[0].subType)
        {
        //STR
        case 0:
            return "You jab out shoving";
        //DEX
        case 1:
            return "You go in for a clean cut";
        //INT
        case 2:
            return "You target for a precise zap";
        default:
            return "Something is wrong with the player.eqpt[0].subType in the character Class";
        }
    //Medium Attack
    case 1:
        switch (player.eqpt[0].subType)
        {
        //STR
        case 0:
            return "You take a good swing";
        //DEX
        case 1:
            return "You go in for a stab";
        //INT
        case 2:
            return "You fire off a bolt";
        default:
            return "Something is wrong with the player.eqpt[0].subType in the character Class";
        }
    //Heavy Attack
    case 2:
        switch (player.eqpt[0].subType)
        {
        //STR
        case 0:
            return "You fully swing for a heavy blow";
        //DEX
        case 1:
            return "You get close and stab in a vitals";
        //INT
        case 2:
            return "You charge and let loose a large blast";
        default:
            return "Something is wrong with the player.eqpt[0].subType in the character Class";
        }
    //Block
    case 3:
        return "You try and block";
    //Dodge
    case 4:
        return "You try and dodge";
    default:
        return "Something is wrong with the combat selection where this was called from";
    }
    return "Should not be reachable";
}

string mosterCombatString(int monsterAction, int weaponType)
{
    switch (monsterAction)
    {
    //Light Attack
    case 0:
        switch (weaponType)
        {
        //STR
        case 0:
            return "Creature shoves at you";
        //DEX
        case 1:
            return "Creature goes in for a clean cut";
        //INT
        case 2:
            return "Creature targets for a precise zap";
        default:
            return "Something is wrong with the weaponType in the character Class";
        }
    //Medium Attack
    case 1:
        switch (weaponType)
        {
        //STR
        case 0:
            return "Creature takes a good swing";
        //DEX
        case 1:
            return "Creature goes in for a stab";
        //INT
        case 2:
            return "Creature fires off a bolt";
        default:
            return "Something is wrong with the weaponType in the character Class";
        }
    //Heavy Attack
    case 2:
        switch (weaponType)
        {
        //STR
        case 0:
            return "Creature fully swings for a heavy blow";
        //DEX
        case 1:
            return "Creature gets close and stabs at your vitals";
        //INT
        case 2:
            return "Creature charges and let loose a large blast";
        default:
            return "Something is wrong with the weaponType in the character Class";
        }
    //Block
    case 3:
        return "Creature trys to block";
    //Dodge
    case 4:
        return "Creature trys to dodge";
    default:
        return "Something is wrong with the combat selection where this was called from";
    }
    return "Should not be reachable";
}

void combatText(int actionPlayer, int dmgPlayer, bool critPlayer, string nameMonster,
                int hpMonster, int dmgMonster, int actionMonster, bool critMonster,
                int monsterWeapon, bool playerGoesFirst)
{
    string playerActionStr = playerCombatString(actionPlayer);
    string attackStrMonster = mosterCombatString(actionMonster, monsterWeapon);

    switch (player.textType)
    {
    case 0:
        cout << playerGoesFirst ? "You Go First In Combat" : "The Creature Goes First In Combat";
        cout << player.name << " HP: " << player.HP << endl
             << playerActionStr << endl;
        if (critPlayer)
        {
            cout << "YOU HAVE CRITICLY HIT" << endl;
        }
        cout << "You deal " << dmgPlayer << " damgage" << endl;
        cout << nameMonster << " HP: " << player.HP << endl
             << playerActionStr << endl;
        if (critMonster)
        {
            cout << "YOU HAVE BEEN CRITICLY HIT" << endl;
        }
        cout << "The creature deals " << dmgMonster << " damgage" << endl;
        break;
    //bare
    case 1:
    {
        string middlePadding = "\t\t\t";
        cout << playerGoesFirst ? "\t\tYou Go First In Combat" : "\t\tThe Creature Goes First In Combat";
        cout << player.name << " HP: " << player.HP << middlePadding + "\t" << nameMonster << " HP: " << hpMonster << endl
             << playerActionStr << "\t" << attackStrMonster << endl;
        if (critPlayer)
        {
            cout << "\n\t\t"
                 << "YOU HAVE CRITICLY HIT THE CREATURE\n"
                 << endl;
        }
        else if (critMonster)
        {
            cout << "\t\t"
                 << "YOU HAVE BEEN CRITICLY HIT BY THE CREATURE" << endl;
        }
        cout << "You deal " << dmgPlayer << " damgage" << middlePadding << "The creature deals " << dmgMonster << " damgage" << endl;
        break;
    }
    //simple
    case 2:
        //stylized verion
        break;
    default:
        cout << "Something is wrong with the save file textType.\n";
    }
    return;
}