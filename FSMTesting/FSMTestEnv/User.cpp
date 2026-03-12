#include "User.h"
#include <iostream>

User::User()
{
}

User::~User()
{
}

int User::GetInput() const
{
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    
    if(TestInputValid(choice))
    {
        return choice;
    }
    return -1;    
}

bool User::TestInputValid(int valueGiven) const
{
    if (std::cin.fail() || valueGiven <= 0) 
    {
        std::cout << "Invalid amount. Please enter a positive number.\n";
        std::cin.clear(); // Clear error flag
        std::cin.ignore(1000, '\n'); // Discard bad input
        return false;
    } 
    return true;
}
