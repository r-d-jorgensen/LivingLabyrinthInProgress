#pragma once
#include <iostream>
#include "stats.cpp"
using namespace std;

void dialogueLong(string str, string startStr, int paddingLength, string padding);
void dialogue(string str, int msgType, string speaker);
int menu(string menuName, string optionsStr[][2], int optionsNum, int menuType);
void statsDisplay();
string playerCombatString(int actionPlayer);
void combatText(int actionPlayer, int dmgPlayer, bool critPlayer, string nameMonster,
                int hpMonster, int dmgMonster, int actionMonster, bool critMonster);
extern character player;

void dialogueLong(string str, string startStr = "", int paddingLength = 0, string padding = "")
{
    //parser
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

    //print parsed str
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
    //stylized format still in development
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