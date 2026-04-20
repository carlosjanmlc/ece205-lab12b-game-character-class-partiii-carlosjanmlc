///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 12b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Barbarian.cpp
/// @author  Kyla Mae Lumabao <kmal@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Barbarian.hpp"
#include <iostream>
#include <math.h>


// Use constructor to initialize PlayerCharacter base, then Barbarian attributes
Barbarian::Barbarian(std::string& newName, int& raceCode, int& professionNum)
    : PlayerCharacter(newName, raceCode, professionNum) {
    rageCharges = 3;
    isRaging = false;
	ACCURACY_PENALTY;
    strengthBonus = static_cast<int>(floor(getStrength() - 10)/2);
}

// Getters
int Barbarian::getRageCharges() const { return rageCharges; }
bool Barbarian::getIsRaging()   const { return isRaging; }


/// When Barbarian uses Methods
// Method: inRage
// Activates rage if charges remain. While raging, damage is doubles but accuracy is reduced
void Barbarian::inRage() {
    // If player tries to activate rage with no rage charges
    if (rageCharges <= 0) {
        std::cout << getName() << " has no rage charges left!" << std::endl;
        return;
    }

    rageCharges--;
    isRaging = true;
    std::cout << getName() << " enters a furious RAGE!!!" << std::endl;
    std::cout << "Damage will be doubled, but accuracy is reduced. " << std::endl;
    std::cout << "Rage charges remaining: " << rageCharges << std::endl;

    if (isRaging) {
        // Perform rage attack
        int rollHit = rollDice(20, 1);
		int hit = rollHit + strengthBonus - ACCURACY_PENALTY;
		int rollDamage = rollDice(12, 1);
        int damage = (rollDamage + strengthBonus) * 2; // double damage

        std::cout << getName() << " attacks in a furious rage! " << std::endl;
        std::cout << "Hit roll: " << rollHit << " + STR(" << strengthBonus << ") - PENALTY(" << ACCURACY_PENALTY << ") = " << hit << std::endl;

        if (rollHit >= 8) {
            std::cout << "WABAMM!!! "<< getName() << "whacked the enemy hard!" << std::endl;
            std::cout << "Damage dealt: " << rollDamage << "+ STR(" << strengthBonus << ") = " << damage << " (doubled from rage)" << std::endl;
        }
        else {
            std::cout << "Missed! The rage made the attack too reckless." << std::endl;
        }
        return;
    }
}


// Method: recklessAttack
// Rolls twice and takes the higher result (advantage) for a powerful strike, but
// all incoming attacks against barbarian will also have advantage for the same round
void Barbarian::recklessAttack() {
    int roll1 = rollDice(20, 1);
    int roll2 = rollDice(20, 1);
    int best = (roll1 > roll2) ? roll1 : roll2; // Shorter way for an if, then, and else

    int damageBonus = isRaging ? strengthBonus * 2 : strengthBonus;
    int damage = best + damageBonus;

    std::cout << getName() << " launches a reckless attack! " << std::endl;
    std::cout << "Hit roll: " << roll1 << " and " << roll2 << ". Highest: " << best << std::endl;
    if (best >= 4) {
        std::cout << "Damage dealt: " << best << " + STR bonus(" << damageBonus << ") = " << damage << std::endl;
    }

    std::cout << "WARNING: Enemies also have advantage on attacks against " << getName() << " this round!" << std::endl;
}


/// Overrides for actions and stats
// Override: performAction()
void Barbarian::performAction() {
    int choice;
    std::cout << "What action would you like " << getName() << " to take? " << std::endl;
    std::cout << "1. Rage" << std::endl;
    std::cout << "2. Reckless Attack" << std::endl;

    std::cin >> choice;
    switch (choice) {
        case 1:
            inRage();
            break;
        case 2:
            recklessAttack();
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
    }
}


// Override: printStats()
void Barbarian::printStats() {
    PlayerCharacter::printStats();
    std::cout << "Rage Charges: " << rageCharges << std::endl;
    std::cout << "Ability: Reckless Attack" << std::endl;
    std::cout << "----------------------------------" << std::endl;
}
