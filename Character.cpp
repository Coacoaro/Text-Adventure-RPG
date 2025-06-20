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
    : hp(HP_BASE), damage(0), energy(ENERGY_BASE), level(LEVEL_BASE),
      xp(XP_BASE), name(name), life(true), attackMove{Attack(5), Attack(7)},
      XP_MAX(30)
    {}

    Character::Character(const std::string& name, int level) 
    : Character(name)
    {
        setLevel(level);
        scaleHp(level);
        scaleDamage(level);
        scaleEnergy(level);
        scaleXp(level);
    }

    int Character::getHp() const {return hp;}
    int Character::getHpMax() const {return HP_MAX;}
    int Character::getDamage() const {return damage;}
    int Character::getEnergy() const {return energy;}
    int Character::getEnergyMax() const {return ENERGY_MAX;}
    int Character::getLevel() const {return level;}
    int Character::getXp() const {return xp;}
    int Character::getXpThreshold() const {return XP_MAX;}
    bool Character::isAlive() const {return life;}
    const std::string& Character::getName() const {return name;}
    const Attack& Character::getAttack(int i) const {return attackMove[i];}
    void Character::setHp(int hp) {
        if (hp > HP_MAX) {this->hp = HP_MAX;}
        else if (hp <= 0) {
            this->hp = 0;
            setLife(false);
        }
        else {this->hp = hp;}
    }
    void Character::setHpMax(int newMax) {
        if (newMax > 0) {this->HP_MAX = newMax;}
    }  
    void Character::setDamage(int damage) {
        this->damage = damage > 0 ? damage : 0;
    }
    void Character::setEnergy(int energy) {
        if (energy > ENERGY_MAX) {this->energy = ENERGY_MAX;}
        else if (energy < 0) {this->energy = 0;}
        else {this->energy = energy;}
    }
    void Character::setEnergyMax(int newMax) {
        if (newMax > 0) {this->ENERGY_MAX = newMax;}
    }
    void Character::setXp(int xp) {
        this->xp = xp > 0 ? xp : 0;
    }
    void Character::setXpThreshold(int newMax) {
        if (newMax > 0) {this->XP_MAX = newMax;}
    }
    void Character::setLevel(int level) {
        this->level = level > 1 ? level : 1;
    }
    void Character::setName(const std::string& name) {this->name = name;}
    void Character::setLife(const bool life) {this->life = life;}

    void Character::stats() const {
        std::cout << getName() << '\n';
        std::cout << "Hp: " << getHp() << '\n';
        std::cout << "Damage: " << getDamage() << '\n';
        std::cout << "Energy: " << getEnergy() << '\n';
        std::cout << "Level: " << getLevel() << '\n';
        std::cout << "Xp: " << getXp() << '\n';
    }
    void Character::attack(Character& target, const Attack& attackMove) {
        int damageDone = attackMove.getAmount();
        if (damageDone <= 0) {
            damageDone = 0;
        }
        else {
            setEnergy(getEnergy() - attackMove.energyUsed());
            target.setHp(target.getHp() - damageDone);
        }
        std::cout << target.getName() << " took " << damageDone << " damage!\n";
    }   
    void Character::scaleDamage() {
        int newDamage = ceil(getDamage() * DAMAGE_SCALE);
        setDamage(newDamage);
    }
    void Character::scaleDamage (int level) {
        int newDamage = ceil(DAMAGE_BASE * pow(DAMAGE_SCALE, level - 1));
        setDamage(newDamage);
    }
    void Character::recoverHp(int hpGain) {
        int oldHp = getHp();
        setHp(oldHp + hpGain);
        
        int newHp = getHp();
        int gain = newHp - oldHp;
        std::cout << getName() << " recovered " << gain << " hp.\n";
    }
    void Character::scaleHp() {
        int newMaxHp = ceil(getHpMax() * HP_SCALE);
        setHpMax(newMaxHp);
    }
    void Character::scaleHp(int level) {
        int newMaxHp = ceil(HP_BASE * pow(HP_SCALE, level - 1));
        setHpMax(newMaxHp);
    }
    void Character::recoverEnergy(int energyGain) {
        int oldEnergy = getEnergy();
        setEnergy(oldEnergy + energyGain);

        int newEnergy = getEnergy();
        int gain = newEnergy - oldEnergy;
        std::cout << getName() << " recovered " << gain << " energy.\n";
    }
    void Character::scaleEnergy() {
        int newMaxEnergy = ceil(getEnergyMax() * ENERGY_SCALE);
        setEnergyMax(newMaxEnergy);
    }
    void Character::scaleEnergy(int level) {
        int newMaxEnergy = ceil(ENERGY_BASE * pow(ENERGY_SCALE, level - 1));
        setEnergyMax(newMaxEnergy);
    }
    void Character::scaleXp(int level) {
        int newXpThreshold = ceil(XP_BASE * pow(XP_SCALE, level - 1));
    }
    void Character::gainXp(int xpGain) {
        if (xpGain <= 0) {
            return;
        }
        int totalXp = getXp() + xpGain;
        int xpRemaining = calculateLevels(totalXp);
        setXp(xpRemaining);

        std::cout << getName() << " gained " << xpGain << " xp.\n";
    }
    int Character::calculateLevels(int xp) {
        int levels = 0;
        int xpThreshold = getXpThreshold();
        while (xp >= xpThreshold) {
            xp -= xpThreshold;
            levels++;
            xpThreshold = ceil(xpThreshold * XP_SCALE);
        }
        if (levels > 0) {
            levelUp(levels);
        }
        setXpThreshold(xpThreshold);  // Set new threshold
        return xp;  // Left over xp 
    }
    
    void Character::levelUp(int levels)  {
        int newLevel = getLevel() + levels;
        setLevel(newLevel);
        scaleHp();
        scaleEnergy();
        scaleDamage();
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