///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 12b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Cleric.hpp
/// @author  Kyla Mae Lumabao <kmal@hawaii.edu>
///
/// Cleric: A devoted healer who channels divine power to aid allies
/// Attributes: faithLevel, healingPower
/// Methods:    heal(), bless()
///////////////////////////////////////////////////////////////////////////////

#ifndef ECE205_LAB12B_GAME_CHARACTER_CLASS_PARTIII_CARLOSJANMLC_CLERIC_HPP
#define ECE205_LAB12B_GAME_CHARACTER_CLASS_PARTIII_CARLOSJANMLC_CLERIC_HPP

#include "PlayerCharacter_Janelle.hpp"

class Cleric : public PlayerCharacter {
private:
    int orbAmount;
    int healingPower;
    int wisdomBonus;

public:
    // Constructor
    Cleric(std::string& newName, int& raceCode, int& professionNum);

    // Methods
    void attack();   // Attack with mace
    void heal();    // Restores health based on healingPower

    // Getters
    int getOrbAmount() const;
    int getHealingPower() const;

    // Overrides
    void performAction() override;
    void printStats();
};

#endif //ECE205_LAB12B_GAME_CHARACTER_CLASS_PARTIII_CARLOSJANMLC_CLERIC_HPP