#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "Character.h"
#include "Attack.h"

// ATTRIBUTES
    // Character::MAX_HP = Character::getLevel() * ;    

// CONSTRUCTORS
    Character::Character(const std::string& name) 
    : hp(BASE_HP), damage(0), stamina(BASE_STAMINA), level(BASE_LEVEL),
      xp(BASE_XP), name(name), life(true), attackMove{Attack(5), Attack(7)},
      MAX_XP(30)
    {}

    Character::Character(const std::string& name, int level) 
    : hp(BASE_HP), damage(0), stamina(BASE_STAMINA), level(BASE_LEVEL),
      xp(BASE_XP), name(name), life(true), attackMove{Attack(5), Attack(7)} 
    {
        setLevel(level);
    }

    int Character::getHp() const {return hp;}
    int Character::getDamage() const {return damage;}
    int Character::getStamina() const {return stamina;}
    int Character::getLevel() const {return level;}
    int Character::getXp() const {return xp;}
    int Character::getMaxXp() const {return MAX_XP;}
    bool Character::isAlive() const {return life;}
    const std::string& Character::getName() const {return name;}
    const Attack& Character::getAttack(int i) const {return attackMove[i];}
    void Character::setHp(int hp) {
        if (hp > BASE_HP) {this->hp = BASE_HP;}
        else if (hp > 0) {this->hp = hp;}
        else {
            this->hp = 0;
            setLife(false);
        }
    }
    // void Character::setMaxHp() {}  
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
    void Character::setXp(int xp) {
        this->xp = xp > 0 ? xp : 0;
    }
    void Character::setMaxXp(int newMax) {
        if (newMax > 0) {this->MAX_XP = newMax;}
    }
    void Character::setName(const std::string& name) {this->name = name;}
    void Character::setLife(bool life) {this->life = life;}

    void Character::stats() const {
        std::cout << getName() << '\n';
        std::cout << "Hp: " << getHp() << '\n';
        std::cout << "Damage: " << getDamage() << '\n';
        std::cout << "Stamina: " << getStamina() << '\n';
        std::cout << "Level: " << getLevel() << '\n';
        std::cout << "Xp: " << getXp() << '\n';
    }
    void Character::attack(Character& target, const Attack& attackMove) {
        int damageDone = attackMove.getAmount();
        if (damageDone <= 0) {
            damageDone = 0;
        }
        else {
            setStamina(getStamina() - attackMove.staminaUsed());
            target.setHp(target.getHp() - damageDone);
        }
        std::cout << target.getName() << " took " << damageDone << " damage!\n";
    }   
    void Character::recoverHp(const int amount) {
        const int currentHp = getHp();
        int hpGained = amount;
        int newHp = currentHp + amount;
        if (newHp > MAX_HP) {
            newHp = MAX_HP;
            hpGained = MAX_HP - currentHp;
        }
        else if (newHp < currentHp) {
            newHp = currentHp;
            hpGained = 0;
        }
        setHp(newHp);
        std::cout << getName() << " recovered " << hpGained << " hp.\n";
    }
    void Character::recoverStamina(const int amount) {
        const int currentSta = getHp();
        int staGained = amount;
        int newSta = currentSta + staGained;
        if (newSta > MAX_STAMINA) {
            newSta = MAX_STAMINA;
            staGained = MAX_STAMINA - currentSta;
        }
        else if (currentSta > newSta) {
            newSta = currentSta;
            staGained = 0;
        }
        setHp(newSta);
        std::cout << getName() << " recovered " << staGained << " stamina.\n";
    }
    // void Character::setMaxStamina() {}
    void Character::gainXp(const int amount) {
        if (amount <= 0) {return;}

        int xpGained = amount;
        int totalXp = getXp() + xpGained;
        std::cout << getName() << " gained " << xpGained << " xp.\n";
        
        int xpRemaining = calculateLevels(totalXp);
        setXp(xpRemaining);
    }
    int Character::calculateLevels(int xp) {
        int levels = 0;
        int xpThreshold = getMaxXp();
        while (xp >= xpThreshold) {
            xp -= xpThreshold;
            levels++;
            xpThreshold = ceil(xpThreshold * XP_SCALE);
        }
        if (levels > 0) {
            levelUp(levels);
        }
        setMaxXp(xpThreshold);    // set new threshold
        return xp;  // Left over xp 
    }
    void Character::levelUp(const int levels) {
        int newLevel = getLevel() + levels;
        setLevel(newLevel);
        std::cout << getName() << " is now level " << newLevel << "!\n";
    }

    
    Player::Player(const std::string& name)
    : Character(name)
    {}

    Enemy::Enemy(const std::string& name, const int level) 
    : Character(name, level)
    {
        setXp(5*level);
    }