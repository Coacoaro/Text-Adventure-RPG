#pragma once

#include <string>

class Attack {
    int amount;
    int type;       // implement later
    bool advantage; // implement later
    std::string name;   // implement later

public:
    Attack(int);
    // Attack(int, Weapon)
    int getAmount();

};