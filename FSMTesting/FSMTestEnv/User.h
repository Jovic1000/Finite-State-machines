#pragma once

class User
{
public:
    User();
    ~User();
    
    int GetInput() const;
private:
    bool TestInputValid(int valueGiven) const;

};
