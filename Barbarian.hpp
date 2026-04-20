///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 12b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Barbarian.hpp
/// @author  Kyla Mae Lumabao <kmal@hawaii.edu>
///
/// Barbarian:  A fierce melee fighter who channels primal rage in combat
/// Attributes: rageCharges, isRaging
/// Methods:    inRage(), recklessAttack()
///////////////////////////////////////////////////////////////////////////////


#ifndef ECE205_LAB12B_GAME_CHARACTER_CLASS_PARTIII_CARLOSJANMLC_BARBARIAN_HPP
#define ECE205_LAB12B_GAME_CHARACTER_CLASS_PARTIII_CARLOSJANMLC_BARBARIAN_HPP

#include "PlayerCharacter_Janelle.hpp"
#include <string>

class Barbarian : public PlayerCharacter {
private:
    int rageCharges;            // Number of times the character can activate rage
    bool isRaging;              // True if barbarian is currently in rage mode
    const int ACCURACY_PENALTY = 4; // Penalty when in rage
    int strengthBonus;

public:
    // Constructor
    Barbarian(std::string& newName, int& raceCode, int& professionNum);

    // Methods
    void inRage();          // Activates rage (costs 1 charge), while raging damage is doubled but accuracy is reduced
    void recklessAttack();  // Roll twice (advantage) for a powerful strike, but incoming attacks also gain advantage

    // Getters
    int getRageCharges() const;
    bool getIsRaging() const;

    //Overrides
    void performAction() override;
    void printStats();                  // To extend for their profession info for their stats
};

#endif //ECE205_LAB12B_GAME_CHARACTER_CLASS_PARTIII_CARLOSJANMLC_BARBARIAN_HPP