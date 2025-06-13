#include <string>
#include <cmath>
#include "Attack.h"

class Character {
private:
const int BASE_HEALTH = 20;
const int BASE_STAMINA = 10;
const int BASE_LEVEL = 1;
const int BASE_EXP = 0;

// ATTRIBUTES
    int health;
    int damage;
    int stamina;
    int level;
    int exp;
    std::string name;
    bool life;
    Attack attackMove[2];

public:
// CONSTRUCTORS
    Character(std::string);
    Character(std::string, int);

// METHODS
    // Getters
    int getHealth();
    int getDamage();
    int getStamina();
    int getLevel();
    int getExp();
    std::string getName();
    bool getLife();
    Attack getAttack(int);
    
    // Setters
    void setHealth(int);
    void setDamage(int);
    void setStamina(int);
    void setLevel(int);
    void setExp(int);
    void setName(std::string);
    void setLife(bool);

    void stats();

    // Actions
    void attack(Character&, Attack);
    // int Damage(Weapon &weapon, int damage) {
    //     return round((weapon.power + damage) * 0.8);
    // }
    void heal(int);
    void recover(int);
    void gainExp(int);
};

