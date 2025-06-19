#include <string>
#include "Attack.h"

Attack::Attack(int amount) {
    this->amount = amount;
}
// Attack(int amount, Weapon &weapon) {}

const int Attack::getAmount() const {return amount;}
const int Attack::staminaUsed() const {return staminaNeeded;}