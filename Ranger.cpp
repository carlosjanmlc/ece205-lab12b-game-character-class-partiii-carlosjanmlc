///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 12b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Ranger.cpp
/// @author  Kyla Mae Lumabao <kmal@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Ranger.hpp"
#include <iostream>
#include <math.h>


// Constructor
Ranger::Ranger(std::string& newName, int& raceCode, int& professionNum)
    : PlayerCharacter(newName, raceCode, professionNum) {
    arrowCount = 10;    // Number of arrows ranger starts with
    multiplier = 1.2;   // Domage multiplier bonus
    hasHuntersMark = false;
    dexterityBonus = static_cast<int>(floor(getAgility() - 10)/2);
}

// Getters
int Ranger::getArrowCount() const { return arrowCount; }
float Ranger::getMultiplier() const { return multiplier; }

/// Rangers Methods
// Method: shoot
void Ranger::shoot() {
    if (arrowCount <= 0) {
        std::cout << getName() << " has no arrows left!" << std::endl;
        return;
    }

    // When character has arrows
    int rollHit = rollDice(20, 1);
	int hit = rollHit + dexterityBonus;

    // Checks if character already activated hunter's mark
    int damageRoll = rollDice(12, 1);
    int damage = 0;
    if (hasHuntersMark == true) {
        damage = static_cast<int>(floor(damageRoll + dexterityBonus) * multiplier);
    }
    else {
        damage = damageRoll + dexterityBonus;
    }

    // Shooting action
    arrowCount--;
    std::cout << getName() << " fires an arrow!" << std::endl;
    std::cout << std::endl;
    std::cout << getName() << " will need to roll a 8 or more to hit!" << std::endl;
    std::cout << std::endl;
    std::cout << "Hit roll: " << rollHit << " + AGI(" << dexterityBonus << ") = " << hit << std::endl;
    std::cout << std::endl;
	if (rollHit >= 8) {
        std::cout << " THWACK!! " << getName() << " has shot the enemy." << std::endl;
	    std::cout << "Damage dealt: " << damageRoll << " + AGI(" << dexterityBonus << ") = " << damage << std::endl;
	}
    else {
        std::cout << "Thud... " << getName() << " missed the shot!" << std::endl;
    }
    return;

    std::cout << "Arrows remaining: " << arrowCount << std::endl;
}


// Method: huntersMark
void Ranger::huntersMark() {
    hasHuntersMark = true;
}


/// Overrides for actions and stats
// Override: performAction()
void Ranger::performAction() {
    int choice;
    std::cout << "What action would you like " << getName() << " to take? " << std::endl;
    std::cout << "1. Shoot" << std::endl;
    std::cout << "2. Hunter's Mark" << std::endl;

    std::cin >> choice;
    switch (choice) {
        case 1:
            shoot();
            break;
        case 2:
            huntersMark();
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
    }
}


// Override: printStats()
void Ranger::printStats() {
    PlayerCharacter::printStats();
    std::cout << "Arrows: " << arrowCount << std::endl;
    std::cout << "Ability: Hunter's Mark" << std::endl;
    std::cout << "----------------------------------" << std::endl;
}