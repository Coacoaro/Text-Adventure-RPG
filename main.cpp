#include <iostream>
#include <string>
#include <cmath>
#include "Character.h"
#include "Attack.h"

// class Weapon {
//     public:
//         std::string name;
//         bool ammo = false;
//         int power;

//         Weapon(std::string name, int power) {
//             this->name = name;
//             this->power = power;
//         }
//         Weapon(std::string name, int power, bool ammo) {
//             this->name = name;
//             this->power = power;
//             this->ammo = ammo;
//         }
// };


int main() {
    
    Character p1("Player 1");
    Character slime("Slime");

    p1.setDamage(ceil(p1.getLevel() * 1.3));
    p1.attack(slime, p1.getAttack(0));
    p1.stats();
    slime.stats();

    return 0;
}