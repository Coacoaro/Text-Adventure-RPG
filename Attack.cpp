#include <string>
#include "Attack.h"

Attack::Attack(int amount) {
    this->amount = amount;
}
// Attack(int amount, Weapon &weapon) {}

int Attack::getAmount() {return amount;}