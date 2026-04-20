///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 11a - Game Character Class Part II - ECE 205 - Spring 2026
//
///
/// @file    PlayerCharacter_Janelle.hpp
/// @author  Janelle Carlos <carlosjm@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#ifndef ECE205_LAB11A_GAME_CHARACTER_CLASS_PARTII_CARLOSJANMLC_PLAYERCHARACTER_HPP
#define ECE205_LAB11A_GAME_CHARACTER_CLASS_PARTII_CARLOSJANMLC_PLAYERCHARACTER_HPP

#include "GameCharacter.hpp"
#include <string>

class PlayerCharacter : public GameCharacter { // class Child : public ParentClass format <-- inheritance
private: // internal data
    // ATTRIBUTES
    int strength;
    int health;
    int agility;
	int wisdom;
	int intelligence;
    int defense;

public: // accessible + use pass-by-value references
    enum class Race {
        /// add race values
        WIZARD = 0,
        WITCH = 1,
        MERMAID = 2,
        HUMAN = 3,
    };

    enum class Profession {
        Barbarian = 0,
        Cleric = 1,
        Ranger = 2,
        Sorcerer = 3,
    };

    Race race; // variable type (enum - Race) variable name (race)
    Profession profession;

    // constructor
    PlayerCharacter(std::string& newName, int& raceCode, int& professionNum); // & <-- pass-by-reference (changes the original, no make copy)

    // METHODS

    // declare the rest of the class' getter methods
    int getStrength() const;
    int getHealth() const;
    int getAgility() const;
    int getWisdom() const;
    int getIntelligence() const;
    int getDefense() const;
    Race getRace() const;
    Profession getProfession() const;

    ///declare the class' setter methods
    void setStrength(int& newStrength);
    void setHealth(int& newHealth);
    void setAgility(int& newAgility);
	void setWisdom(int& newWisdom);
	void setIntelligence(int& newIntelligence);
    void setDefense(int& newDefense);
    void setRace(int& newRaceCode);
    void setProfession(int& newProfession);

    // dice simulator method
    int rollDice(int upper, int lower);

    ///declare the rest of the class' setter methods
    void printStats(); //print character stats

    // Kyla: Added virtual method to be overridden by profession subclasses
    virtual void performAction();
};

#endif //ECE205_LAB11A_GAME_CHARACTER_CLASS_PARTII_CARLOSJANMLC_PLAYERCHARACTER_HPP
