#include <string>
#include <cmath>
#include "Attack.h"

class Character {
private:
    void levelUp(const int);
    int calculateLevels(int);

protected:
const int BASE_HP = 20;
const int BASE_STAMINA = 10;
const int BASE_LEVEL = 1;
const int BASE_XP = 0;
const int BASE_DAMAGE = 1;
const double XP_SCALE = 1.2;
static int MAX_HP;  // Max hp for a given level
static int MAX_STAMINA; // Max stamina for given level
// const int MAX_LEVEL;    // Max possible level
int MAX_XP;     // Xp threshold before level up

// ATTRIBUTES
    int hp;
    int damage;
    int stamina;
    int level;
    int xp;
    int xpNeeded;
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
    int getDamage() const;
    int getStamina() const;
    int getLevel() const;
    int getXp() const;
    int getMaxXp() const;
    bool isAlive() const;
    const std::string& getName() const;
    const Attack& getAttack(int) const;
    
    // Setters
    void setHp(int);
    void setMaxHp(int);
    void setDamage(int);
    void setStamina(int);
    void setLevel(int);
    void setXp(int);
    void setMaxXp(int);
    void setName(const std::string&);
    void setLife(bool);

    void stats() const;

    // Actions
    void attack(Character&, const Attack&);
    // int Damage(Weapon &weapon, int damage) {
    //     return round((weapon.power + damage) * 0.8);
    // }
    void recoverHp(const int);
    void recoverStamina (const int);
    void gainXp(const int);

};

class Player : public Character {
public:
    Player(const std::string&); 
};

class Enemy : public Character {
public:
    Enemy(const std::string&, const int); 
};

