#include <iostream>
#include <string>
#include <cmath>
#include "Character.h"
#include "Attack.h"


// CONSTRUCTORS
    Character::Character(std::string name) 
    : health(BASE_HEALTH), damage(0), stamina(BASE_STAMINA), level(BASE_LEVEL),
      exp(BASE_EXP), name(name), life(true), attackMove{Attack(5), Attack(7)} {}

    Character::Character(std::string name, int level) 
    : health(BASE_HEALTH), damage(0), stamina(BASE_STAMINA), level(BASE_LEVEL),
      exp(BASE_EXP), name(name), life(true), attackMove{Attack(5), Attack(7)} {
        setLevel(level);
      }

// METHODS
    // Getters
    int Character::getHealth() {return health;}
    int Character::getDamage() {return damage;}
    int Character::getStamina() {return stamina;}
    int Character::getLevel() {return level;}
    int Character::getExp() {return exp;}
    std::string Character::getName() {return name;}
    bool Character::getLife() {return life;}
    Attack Character::getAttack(int i) {return attackMove[i];}
    
    // Setters
    void Character::setHealth(int health) {
        if (health > BASE_HEALTH) {this->health = BASE_HEALTH;}
        else if (health > 0) {this->health = health;}
        else {
            this->health = 0;
            setLife(false);
        }
    }
    void Character::setDamage(int damage) {
        this->damage = damage > 0 ? damage : 0;
    }
    void Character::setStamina(int stamina) {
        if (stamina > BASE_STAMINA) {this->stamina = BASE_STAMINA;}
        else if (stamina > 0) {this->stamina = stamina;}
        else {this->stamina = 0;}
    }
    void Character::setLevel(int level) {
        this->level = level > 1 ? level : 1;
    }
    void Character::setExp(int exp) {
        this->level = exp > 0 ? exp : 0;
    }
    void Character::setName(std::string name) {this->name = name;}
    void Character::setLife(bool life) {this->life = life;}

    void Character::stats() {
        std::cout << getName() << '\n';
        std::cout << "Health: " << getHealth() << '\n';
        std::cout << "Damage: " << getDamage() << '\n';
        std::cout << "Stamina: " << getStamina() << '\n';
        std::cout << "Level: " << getLevel() << '\n';
        std::cout << "Exp: " << getExp() << '\n';
    }

    // Actions
    void Character::attack(Character& target, Attack attackMove) {
        int damageDone = attackMove.getAmount();
        target.setHealth(target.getHealth() - damageDone);
        std::cout << target.getName() << " took " << damageDone << " damage!\n";
    }
    // int Damage(Weapon &weapon, int damage) {
    //     return round((weapon.power + damage) * 0.8);
    // }
    void Character::heal(int amount) {
        setHealth(getHealth() + amount);
    }
    void Character::recover(int amount) {
        setStamina(getStamina() + amount);
    }
    void Character::gainExp(int expGain) {
        int total = getExp() + expGain;
        setExp(total);
    }

