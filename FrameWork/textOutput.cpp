#pragma once
#include <iostream>
using namespace std;

void dialogueLong(string str, string startStr, int paddingLength, string padding);
void dialogue(string str, int msgType, string speaker);
void Menu(string menuName, string optionsStr[][2], int optionsNum, int menuType);

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
    int textType = 0; //import from save file
    switch (textType)
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
    int textType = 0; //import from save file
    switch (textType)
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
/* testingSystems
int main()
{
    dialogue("Hello world");
    dialogue("Rumble" , 1, "Enviroment");
    dialogue("It cannot be seen, cannot be felt, cannot be heard, and cannot be smelt. It lies behind stars and under hills, And empty holes it fills. It comes first and follows after, Ends life, and kills laughter. What is it?", 2, "NPC");
    
    int menuOptions = 5;
    string menuStr[][2] =
    {
        {"1", "Talk to book NPC"},
        {"2", "Go to perk store"},
        {"3", "Open char sheet"},
        {"4", "Settings Menu"},
        {"5", "Exit the game"}
    };
    menu("Living Libary Menu", menuStr, menuOptions);

    //size checker
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 10; j++)
            cout << j;

    return 0;
}
*/