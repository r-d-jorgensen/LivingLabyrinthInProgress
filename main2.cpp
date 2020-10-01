#include "header2.h"

int main()
{
    int location = 1;
    bool mainGameLoop = true;
    while (mainGameLoop)
    {
        if (location == 0)
        {
            cout << "Thank You For Playing" << endl;
            return 0;
        }
        else if (location == 1)
        {
            libraryChoices();
        }
    }
    cout << "Thank You For Playing" << endl;
    return 0;
}
