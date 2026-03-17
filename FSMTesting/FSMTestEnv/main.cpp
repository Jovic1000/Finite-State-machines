#include <iostream>
#include "ConsoleDefines.h"
#include "CoffeeMachine.h"
#include "User.h"

void Run();

int main()
{
    Run();
    system(pause);
    return 0;
}


void Run() 
{
    int choice;
    bool machineActive = true;
    CoffeeMachine coffeeMaker3001;
    User user;

    coffeeMaker3001.Init();

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

