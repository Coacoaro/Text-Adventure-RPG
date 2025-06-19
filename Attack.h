#pragma once

#include <string>

class Attack {
protected:
    int amount;
    // int num_of_diff_attacks;
    // Attack *diff_attacks;
    int staminaNeeded;
    int type;       // implement later
    bool advantage; // implement later
    std::string name;   // implement later

public:
    Attack(int);
    // Attack(int, Weapon)
    const int getAmount() const;
    const int staminaUsed() const;


};