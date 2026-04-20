///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 12b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Cleric.cpp
/// @author  Kyla Mae Lumabao <kmal@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Cleric.hpp"
#include <iostream>
#include <math.h>


// Constructor
Cleric::Cleric(std::string& newName, int& raceCode, int& professionNum)
    : PlayerCharacter(newName, raceCode, professionNum) {
    orbAmount = 0;
    healingPower = 5;
    wisdomBonus = static_cast<int>(floor(getWisdom() - 10)/2);
}


// Getters
int Cleric::getOrbAmount() const { return orbAmount; }
int Cleric::getHealingPower() const { return healingPower; }


/// Clerics Methods
// Method: attack
void Cleric::attack() {
    std::cout << getName() << "readies their mace." << std::endl;

    int rollHit = rollDice(20, 1);
    int hit = rollHit + wisdomBonus;
    std::cout << "Rolled: " << rollHit << " + WIS(" << wisdomBonus << ") = " << hit << std::endl;
    if (hit >= 8) {
        if (orbAmount < 5) {
            orbAmount++;
        }
        int rollDamage = rollDice(10, 1);
        int damage =  rollDamage + orbAmount;
        std::cout << "WHAM!!" << getName() << " showed no mercy to the enemy." << std::endl;
        std::cout << "Damage dealt: " << rollDamage << " + WIS(" << wisdomBonus << ")"
                << " + Orb Power (" << orbAmount << ") = " << damage << std::endl;
    }
    else {
        orbAmount = 0;
        std::cout << getName() << " swung the mace too hard and missed." << std::endl;
        std::cout << "Orb amount: " << orbAmount << std::endl;
    }
}
// Method: heal
// Restores HP based on dice roll & healingPower
void Cleric::heal() {
    int roll = rollDice(10, 2);
    int healAmount = roll + healingPower;
    int newHP = getHealth() + healAmount;
    if (newHP > 100) {
        newHP = 100;
    }
    setHealth(newHP);

    std::cout << getName() << "channels divine energy!" << std::endl;
    std::cout << "Rolled: " << roll << " + Healing Power (" << healingPower << ")  " << " + WIS("
            << wisdomBonus << ") = " <<  healAmount << " HP restored." << std::endl;
    std::cout << "New health: " << getHealth() << std::endl;
}


/// Overrides for actions and stats
// Override: performAction()
void Cleric::performAction() {
    int choice;
    std::cout << "What action would you like " << getName() << " to take? " << std::endl;
    std::cout << "1. Attack" << std::endl;
    std::cout << "2. Heal" << std::endl;

    std::cin >> choice;
    switch (choice) {
        case 1:
            attack();
            break;
        case 2:
            heal();
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
    }
}


// Override: printStats()
void Cleric::printStats() {
    PlayerCharacter::printStats();
    std::cout << "Abilities: Healing and Radiating Orbs" << std::endl;
    std::cout << "----------------------------------" << std::endl;
}