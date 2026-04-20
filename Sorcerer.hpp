///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 12b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Sorcerer.hpp
/// @author  Kyla Mae Lumabao <kmal@hawaii.edu>
///
/// Sorcerer: A spellcaster who draws magic from within
/// Attributes: spellSlots, sorceryPoints
/// Methods:    magicShield(), chainLightning()
///////////////////////////////////////////////////////////////////////////////

#ifndef ECE205_LAB12B_GAME_CHARACTER_CLASS_PARTIII_CARLOSJANMLC_SORCERER_HPP
#define ECE205_LAB12B_GAME_CHARACTER_CLASS_PARTIII_CARLOSJANMLC_SORCERER_HPP

#include "PlayerCharacter_Janelle.hpp"
#include <string>

class Sorcerer : public PlayerCharacter {
private:
    int sorceryPoints;     // Number of spell slots remaining (each spell costs 1)
    bool magicBarrier;  // Secondary resource - for magicShield
    int intelligenceBonus;

public:
    // Constructor
    Sorcerer(std::string& newName, int& raceCode, int& professionNum);

    // Methods
    void magicShield();     // Uses 1 sorcery point. Creates a barrier that absorbs
                            // the next incoming hit by boosting defense
    void firebolt();        // Hits target with fire damage

    // Getters
    bool getMagicShield() const;
    int getSorceryPoints() const;

    // Overrides
    void performAction() override;
    void printStats();
};


#endif //ECE205_LAB12B_GAME_CHARACTER_CLASS_PARTIII_CARLOSJANMLC_SORCERER_HPP