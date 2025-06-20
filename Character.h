#include <string>
#include <cmath>
#include "Attack.h"

class Character {
private:
    void levelUp(int);
    int calculateLevels(int);
    // link to visualize stat scales https://www.desmos.com/calculator/qprvgcyjvb
    void scaleHp();
    void scaleHp(int);
    void scaleEnergy();
    void scaleEnergy(int);
    void scaleDamage();
    void scaleDamage(int);
    void scaleXp(int);

protected:
const int HP_BASE = 20;
const int HP_SCALE = 1.05;
const int ENERGY_BASE = 10;
const int ENERGY_SCALE = 1.03;
const int DAMAGE_BASE = 2;
const int DAMAGE_SCALE = 1.07;
const int LEVEL_BASE = 1;
const int XP_BASE = 30; // Base xp threshold
const int XP_SCALE = 1.06;
int HP_MAX;  // Max hp for a given level
int ENERGY_MAX; // Max energy for given level
const int MAX_LEVEL = 100;    // Max possible level
int XP_MAX;     // Xp threshold before level up

// ATTRIBUTES
    int hp;
    int damage;
    int energy;
    int level;
    int xp;
    std::string name;
    bool life;
    Attack attackMove[2];

public:
// CONSTRUCTORS
    Character(const std::string&);
    Character(const std::string&, int);

// METHODS
    // Getters
    int getHp() const;
    int getHpMax() const;
    int getDamage() const;
    int getEnergy() const;
    int getEnergyMax() const;
    int getLevel() const;
    int getXp() const;
    int getXpThreshold() const;
    bool isAlive() const;
    const std::string& getName() const;
    const Attack& getAttack(int) const;
    
    // Setters
    void setHp(int);
    void setHpMax(int);
    void setDamage(int);
    void setEnergy(int);
    void setEnergyMax(int);
    void setLevel(int);
    void setXp(int);
    void setXpThreshold(int);
    void setName(const std::string&);
    void setLife(bool);

    void stats() const;

    // Actions
    void attack(Character&, const Attack&);
    // int Damage(Weapon &weapon, int damage) {
    //     return round((weapon.power + damage) * 0.8);
    // }
    void recoverHp(int);
    void recoverEnergy (int);
    void gainXp(int);

};

class Player : public Character {
public:
    Player(const std::string&); 
};

class Enemy : public Character {
public:
    Enemy(const std::string&, const int); 
};

