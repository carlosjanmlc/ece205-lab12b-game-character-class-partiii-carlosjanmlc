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
PlayerCharacter::PlayerCharacter(std::string& newName, int& raceCode) : GameCharacter(newName) {

	setRace(raceCode);
	health = 100;

	// using rollDice to randomize a value from 0-10
	strength = rollDice(10, 0);
	agility = rollDice(10, 0);
	defense = rollDice(10, 0);
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
int PlayerCharacter::getDefense() const {
  return defense;
}
PlayerCharacter::Race PlayerCharacter::getRace() const {
  return race;
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
  std::cout << "Race: " << raceString << std::endl;
  std::cout << "Health: " << health << std::endl;
  std::cout << "Strength: " << strength << std::endl;
  std::cout << "Agility: " << agility << std::endl;
  std::cout << "Defense: " << defense << std::endl;
  std::cout << "----------------------------------" << std::endl;

  /// create a new method that can be overriden by the children of PlayerCharacter class
  virtual void performAction() {
    std::cout << "I'm sorry, there's nothing I can do." << std::endl;
  }
}

