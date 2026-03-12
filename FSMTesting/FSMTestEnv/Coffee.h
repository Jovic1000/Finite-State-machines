#ifndef COFFEE_H
#define COFFEE_H
#include "CoffeeTypes.h"

class Coffee
{
public:
    Coffee(CoffeeType);
    ~Coffee();
    
    void Drink();
    
private:
    CoffeeType m_type;
};

#endif // COFFEE_H
