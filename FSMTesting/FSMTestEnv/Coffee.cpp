#include "Coffee.h"
#include <iostream>

Coffee::Coffee(CoffeeType type): m_type(type) {}

Coffee::~Coffee() {}

void Coffee::Drink()
{
    using namespace std;    
    switch (m_type)
    {
        case NONE:
            cout << "You are holding an empty coffee cup...";
            break;
        case Americano:
            cout << "Black as a moonless night...";
            break;
        case Americano_Milk:
            cout << "Coffee, as it was always meant to be!";
            break;
        case Cappuccino:        
            cout << "A bit of froth to add to the experience!";
            break;
        case Latte:
            cout << "That's a latte calories for a drink!";
            break;
        case Mocha:
            cout << "Alright, this is too much indulgence. Might as well have hot chocolate!";
            break;
        case Espresso:
            cout << "More firey and bitter than the pits of hell itself... That. Is coffee.";
            break;
    }
    cout << endl;
}