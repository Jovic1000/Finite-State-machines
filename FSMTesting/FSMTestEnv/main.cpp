#include <iostream>
#include "ConsoleDefines.h"
#include "CoffeeMachine.h"
#include "User.h"

void 🏃();

int main()
{
    🏃();
    system(pause);
    return 0;
}


void 🏃() 
{
    int choice;
    bool machineActive = true;
    CoffeeMachine coffeeMaker3001;
    User user;
    while (machineActive) 
    {
        coffeeMaker3001.DisplayUserMessage();
        int choice = user.GetInput();
        if(choice == 6)
        {
            machineActive = false;
        }
        else if(choice > 0)
        {
            coffeeMaker3001.UserInteract(choice, user);
        }
    }
}

