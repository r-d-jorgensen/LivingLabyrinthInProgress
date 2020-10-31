#pragma once
#include <iostream>
using namespace std;

void dialogueLong(string str, string startStr = "", int paddingLength = 0, string padding = "");
void dialogue(string str, int msgType = 0, string speaker = "Self");

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
    for (i = 0; i < sizeof(parsedStr) / sizeof(parsedStr[0]); i++)
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
    int textType = 2; //import from save file
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
/*
int main()
{
    dialogue("Hello world");
    dialogue("Rumble" , 1, "Enviroment");
    dialogue("It cannot be seen, cannot be felt, cannot be heard, and cannot be smelt. It lies behind stars and under hills, And empty holes it fills. It comes first and follows after, Ends life, and kills laughter. What is it?", 2, "NPC");
    
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 10; j++)
            cout << j;

    return 0;
}
*/