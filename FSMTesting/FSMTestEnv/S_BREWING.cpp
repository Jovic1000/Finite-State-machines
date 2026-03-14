#include "S_BREWING.h"
#include <iostream>
#include <chrono>
#include <thread>

void S_BREWING::Update()
{
    
}

void S_BREWING::Render()
{
    using std::cout, std::endl;
    std::cout << "Brewing coffee.";
    std::flush(cout);
    Delay(50);
    std::cout << ".";
    std::flush(cout);
    Delay(50);
    std::cout << ".\n";
    std::flush(cout);
    Delay(50);

    std::cout << "Here is your coffee! Enjoy!\n" << std::endl;
}

void S_BREWING::Exit()
{
}

void S_BREWING::Enter()
{
}

void S_BREWING::Delay(int delayInMillisec)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(delayInMillisec));
}
