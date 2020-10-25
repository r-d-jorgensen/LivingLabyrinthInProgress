#include <iostream>
using namespace std;

void strParser(string str, string *parsedStr)
{
    string delimiter = " ";
    size_t pos = 0;
    int i = 0;
    int arraySize = str.length() / 4;
    while ((pos = str.find(delimiter)) != string::npos)
    {
        parsedStr[i] = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        i++;
    }
    parsedStr[i] = str;
    return;
}

void dialogue(string str, int msgType = 0, string speaker = "Self")
{
    int textType = 1; //import from save file
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
            //bare long string
            string parsedStr[100];
            strParser(str, parsedStr);
            int lineLength = 0;
            for (int i = 0; i < str.length() / 4; i++)
            {
                if (parsedStr[i] == " ")
                {
                    break;
                }
                lineLength += parsedStr[i].length() + 1;
                cout << parsedStr[i] + " ";
                if (lineLength + parsedStr[i + 1].length() > 80)
                {
                    cout << endl;
                    lineLength = 0;
                }
            }
        }
        cout << endl;
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
            //simple long string
            string parsedStr[100];
            strParser(str, parsedStr);
            int lineLength = speaker.length() + 2;
            cout << speaker << ": ";
            for (int i = 0; i < str.length() / 4; i++)
            {
                if (parsedStr[i] == " ")
                {
                    break;
                }
                lineLength += parsedStr[i].length() + 1;
                cout << parsedStr[i] + " ";
                if (lineLength + parsedStr[i + 1].length() > 80)
                {
                    cout << "\n\t";
                    lineLength = 9;
                }
            }
        }
        cout << endl;
        break;
    //stylized format
    case 2:
    {
        string edge = "*****";
        string internalSpace = "\t\t\t";
        string leftPadding = edge + internalSpace;
        string rightPadding = internalSpace + edge + "\n";
        cout << edge + "\t";
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
        cout << "\t" + edge
             << edge + internalSpace + internalSpace + internalSpace + edge << endl;
        break;
    }
    default:
        cout << "Something is wrong with the save file textType.\n";
    }
}