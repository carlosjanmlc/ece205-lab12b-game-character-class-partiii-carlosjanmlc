///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 12b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Ranger.hpp
/// @author  Kyla Mae Lumabao <kmal@hawaii.edu>
///
/// Ranger: A swift scout who excels at ranged attacks and tracking
/// Attributes: arrowCount, accuracy
/// Methods:    shoot(), track()
///////////////////////////////////////////////////////////////////////////////

#ifndef ECE205_LAB12B_GAME_CHARACTER_CLASS_PARTIII_CARLOSJANMLC_RANGER_HPP
#define ECE205_LAB12B_GAME_CHARACTER_CLASS_PARTIII_CARLOSJANMLC_RANGER_HPP

#include "PlayerCharacter_Janelle.hpp"
#include <string>

class Ranger : public PlayerCharacter {
private:
    int arrowCount; // Number of arrows remaining
    float multiplier;   // Bonus added to hit rolls & tracking checks (0-10)
    bool hasHuntersMark;
    int dexterityBonus;

public:
    // Constructor
    Ranger(std::string& newName, int& raceCode, int& professionNum);

    // Methods
    void shoot();   // Fire an arrow + accuracy bonus
    void huntersMark();   // Attempt to track an enemy

    // Getters
    int getArrowCount() const;
    float getMultiplier() const;

    // Overrides
    void performAction() override;
    void printStats();
};

#endif //ECE205_LAB12B_GAME_CHARACTER_CLASS_PARTIII_CARLOSJANMLC_RANGER_HPP