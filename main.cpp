#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include "Character.h"

void GameOver() {
    std::cout << "You have been defeated!\n";
    std::cout << "***** GAME OVER! *****";
}
 
int PlayerOption(std::string *options, int size) {
    int option;
    do {
        std::cout << "Select an option:\n";
        for (int i = 0; i < size; i++) {
            std::cout << options[i] << '\n';
        }
        std::cout << "> ";
        std::cin >> option;
    } while (option > size || option < 1);

    return --option;
}

void BattleState(Character& player, Character& enemy) {
    int choice;
    std::string options[] = {"1. Light Attack", "2. Heavy Attack", "3. Rest", "4. Heal", "5. Status"};
    // find a way to display the stats to text the damage.
    int size = sizeof(options)/sizeof(options[0]);
    
    do {
        // Player turn
        choice = PlayerOption(options, size);
        switch (choice) {
            case 0:
                player.attack(enemy, player.getAttack(0));
                break;
            case 1:
                player.attack(enemy, player.getAttack(1));
                break;
            case 2:
                player.recoverStamina(3);
                break;
            case 3:
                player.recoverHp(6);
                break;
            case 4:
                player.stats();
                enemy.stats();
                continue;
        }
        player.recoverStamina(1);

        // Comp Turn
        choice = rand() % 4;
        switch (choice) {
            case 0:
                enemy.attack(player, enemy.getAttack(0));
                break;
            case 1:
                enemy.attack(player, enemy.getAttack(1));
                break;
            case 2:
                enemy.recoverStamina(3);
                break;
            case 3:
                enemy.recoverHp(6);
                break;
        }
        enemy.recoverStamina(1);

    } while (player.isAlive() && enemy.isAlive());

    if (player.isAlive()) {
        std::cout << "You have defeated " << enemy.getName() << "!\n";
        
        int xpGained = enemy.getXp();
        player.gainXp(xpGained);
        enemy.setXp(0);
        
    }
    else {
        GameOver();
    }
}


int main() {

    Player p1("Player 1");
    Enemy slime("Slime", 1);

    slime.setHp(6);
    BattleState(p1, slime);
    p1.stats();
    slime.stats();
    std::cout << "Slime life: " << slime.isAlive() << '\n';


    return 0;
}