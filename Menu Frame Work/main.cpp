#include "header.h"

int main()
{
    //load character make global
    //load settings make global

    //run game
    int location = 1;
    bool mainGameLoop = true;
    while (mainGameLoop)
    {
        if (location == 0)
        {
            cout << "Thank You For Playing" << endl;
            cout << "This was made by David Jorgensen, Jason Jellie, and Scott Kurtz " << endl;
            return 0;
        }
        else if (location == 1)
        {
            libraryChoices();
        }
        else if (location == 2)
        {
            bookRealm();
        }
    }
}
