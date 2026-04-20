///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 11a - Game Character Class Part II - ECE 205 - Spring 2026
//
///
/// @file    PlayerCharacter_Janelle.cpp
/// @author  Janelle Carlos <carlosjm@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "PlayerCharacter_Janelle.hpp"
#include <iostream>
#include <random>

// constructor
PlayerCharacter::PlayerCharacter(std::string& newName, int& raceCode, int& professionNum) : GameCharacter(newName) {


	setRace(raceCode);
  setProfession(professionNum);
	health = 100;

	// using rollDice to randomize a value from 0-10
	strength = 10;
	agility = 10;
  wisdom = 10;
  intelligence = 10;
	defense = 10;
}

// METHODS

// define the class' getter methods
int PlayerCharacter::getStrength() const {
  return strength;
}
int PlayerCharacter::getHealth() const {
  return health;
}
int PlayerCharacter::getAgility() const {
  return agility;
}
int PlayerCharacter::getWisdom() const {
  return wisdom;
}
int PlayerCharacter::getIntelligence() const {
  return intelligence;
}
int PlayerCharacter::getDefense() const {
  return defense;
}
PlayerCharacter::Race PlayerCharacter::getRace() const {
  return race;
}
PlayerCharacter::Profession PlayerCharacter::getProfession() const {
  return profession;
}

// define the class' setter methods
void PlayerCharacter::setStrength(int& newStrength) {
  strength = newStrength;
}
void PlayerCharacter::setHealth(int& newHealth) {
  health = newHealth;
}
void PlayerCharacter::setAgility(int& newAgility) {
  agility = newAgility;
}
void PlayerCharacter::setWisdom(int& newWisdom) {
  wisdom = newWisdom;
}
void PlayerCharacter::setIntelligence(int& newIntelligence) {
  intelligence = newIntelligence;
}
void PlayerCharacter::setDefense(int& newDefense) {
  defense = newDefense;
}

void PlayerCharacter::setRace(int& newRaceCode) {
  ///create a setRace method
  //This method accepts an int and sets the objects race to the corresponding enum value
  //example...
  switch (newRaceCode) {
    case 0:
      race = Race::WIZARD;
      break;
    case 1:
      race = Race::WITCH;
      break;
    case 2:
      race = Race::MERMAID;
      break;
    case 3:
      race = Race::HUMAN;
      break;
    default:
      std::cout << "Invalid choice." << std::endl;
  }
}

// Kyla: Using set profession method from PlayerCharacter
// to set user's number to their character's profession
void PlayerCharacter::setProfession(int& newProfession) {
  switch (newProfession) {
    case 0:
      profession = Profession::Barbarian;
      break;
    case 1:
      profession = Profession::Cleric;
      break;
    case 2:
      profession = Profession::Ranger;
      break;
    case 3:
      profession = Profession::Sorcerer;
      break;
    default:
      std::cout << "Invalid choice." << std::endl;
  }
}

// dice roll between upper and lower
int PlayerCharacter::rollDice(int upper, int lower) {
  // replace with random number generator
  static std::random_device rd;
  static std::mt19937 rng(rd());
  std::uniform_int_distribution<int> dist(lower, upper); /// int variables range from 0-10
  return dist(rng);
}

void PlayerCharacter::printStats() {
  /// print stats according to the output shown in the assignment
  std::cout << "--------- Stats for " << getName() << " ---------" << std::endl;

  std::string raceString;
  std::string professionString;

  switch (race) { /// for an enum class: use the enum names, not numbers
    case Race::WIZARD:
      raceString = "Wizard";
      break;
    case Race::WITCH:
      raceString = "Witch";
      break;
    case Race::MERMAID:
      raceString = "Mermaid";
      break;
    case Race::HUMAN:
      raceString = "Human";
      break;
  }

  // Kyla: Added profession using their names
  switch (profession) {
    case Profession::Barbarian:
      professionString = "Barbarian";
      break;
    case Profession::Cleric:
      professionString = "Cleric";
      break;
    case Profession::Ranger:
      professionString = "Ranger";
      break;
    case Profession::Sorcerer:
      professionString = "Sorcerer";
      break;
  }

  std::cout << "Race: " << raceString << std::endl;
  std::cout << "Profession: " << professionString << std::endl;
  std::cout << "Health: " << health << std::endl;
  std::cout << "Strength: " << strength << std::endl;
  std::cout << "Agility: " << agility << std::endl;
  std::cout << "Wisdom: " << wisdom << std::endl;
  std::cout << "Intelligence: " << intelligence << std::endl;
  std::cout << "Defense: " << defense << std::endl;
  std::cout << "----------------------------------" << std::endl;
}

// Kyla: Moved function outside - Default performAction
/// create a new method that can be overriden by the children of PlayerCharacter class
void PlayerCharacter::performAction() {
  std::cout << "I'm sorry, there's nothing I can do." << std::endl;
}

