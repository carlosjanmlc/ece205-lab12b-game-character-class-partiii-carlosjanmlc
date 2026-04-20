///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 12b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Sorcerer.cpp
/// @author  Kyla Mae Lumabao <kmal@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Sorcerer.hpp"
#include <iostream>
#include <math.h>

// Constructor
Sorcerer::Sorcerer(std::string& newName, int& raceCode, int& professionNum)
    : PlayerCharacter(newName, raceCode, professionNum) {
    sorceryPoints = 2;
    magicBarrier = false;
    intelligenceBonus = static_cast<int>(floor(getIntelligence() - 10)/2);
}

// Getters
bool Sorcerer::getMagicShield() const { return magicBarrier; }
int Sorcerer::getSorceryPoints() const { return sorceryPoints; }

/// Sorcerers Methods
// Method: magicShield
void Sorcerer::magicShield() {
    std::cout << getName() << " uses their magic from within." << std::endl;

    if (sorceryPoints > 0) {
        sorceryPoints--;
        magicBarrier = true;
        int newDefense = getDefense() + 5;
        setDefense(newDefense);
        std::cout << std::endl;
        std::cout << getName() << " has formed their shield. Their defense has now increased by 5." << std::endl;
    }
    else {
        std::cout << getName() << " magic is not working. " << sorceryPoints << " sorcery points." << std::endl;
    }
}

// Method: firebolt
void Sorcerer::firebolt() {
    std::cout << getName() << " shoots their firebolt at the enemy!" << std::endl;

    std::cout << std::endl;
    std::cout << getName() << " will need to roll a 8 or more to hit!" << std::endl;
    int rollHit = rollDice(20, 1);
    int hit = rollHit + intelligenceBonus;
    std::cout << "Rolled: " << rollHit << " + INT(" << intelligenceBonus << ") = " << hit << std::endl;
    std::cout << std::endl;
    if (hit >= 8) {
        int rollDamage = rollDice(12, 1);
        int damage =  rollDamage + intelligenceBonus;
        std::cout << "PHWOOFPH!! " << getName() << " blazes the enemy with their firebolt." << std::endl;
        std::cout << "Damage dealt: " << rollDamage << " + INT(" << intelligenceBonus << ") = "
                << damage << std::endl;
    }
    else {
        std::cout << "pOOf.. " << getName() << " was not able to hit the enemy." << std::endl;
    }
}


/// Overrides for actions and stats
// Override: performAction()
void Sorcerer::performAction() {
    int choice;
    std::cout << "What action would you like " << getName() << " to take? " << std::endl;
    std::cout << "1. Magic Shield" << std::endl;
    std::cout << "2. Firebolt" << std::endl;
    std::cout << "► ";

    std::cin >> choice;
    switch (choice) {
        case 1:
            magicShield();
            break;
        case 2:
            firebolt();
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
    }
}


// Override: printStats()
void Sorcerer::printStats() {
    PlayerCharacter::printStats();
    std::cout << "Abilities: Magic Shield and Firebolt" << std::endl;
    std::cout << "----------------------------------" << std::endl;
}