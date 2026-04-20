///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 11a - Game Character Class Part II - ECE 205 - Spring 2025
//
///
/// @file    main.cpp
/// @author  Janelle Carlos <carlosjm@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <unistd.h>
#include <string>
#include "PlayerCharacter_Janelle.hpp"
#include "Barbarian.hpp"
#include "Cleric.hpp"
#include "Ranger.hpp"
#include "Sorcerer.hpp"

using namespace std;

//The following program demonstrates how you might call some of the functions in your new class
//and produce the sample output shown in the assignment write-up
//you are not required to use this file and can refactor any existing code that you
//already have to produce the same results

void typewriter(string text);

int main()
{
    //declare variables
    string characterName;
    int characterRace;
    int characterProfession;
    string userResponse;

    //define variables
    cout << "========================" << endl;
    cout << "   CHARACTER CREATION" << endl;
    cout << "========================" << endl;

    cout << endl;
    cout << "Enter a name for your character: ";
    cin >> characterName;

    // While loops when user enters wrong number, game will keep asking until they give
    // a number that is within the range
    while (true) {
        cout << "Enter a race for your character (0 = Wizard, 1 = Witch, 2 = Mermaid, 3 = Human): ";
        cin >> characterRace;
        if (characterRace < 0 || characterRace > 3) {
            cout << "Invalid choice." << endl;
            continue;
        }
        break;
    }

    cout << endl;

    while (true) {
        cout << "Enter a profession for your character (0 = Barbarian, 1 = Clerk, 2 = Ranger, 3 = Sorcerer): ";
        cin >> characterProfession;
        if (characterProfession < 0 || characterProfession > 3) {
            cout << "Invalid choice." << endl;
            continue;
        }
        break;
    }

    cout << endl;

    // Use pointer so the correct subclass performAction() gets called\
    // Create PlayerCharacter object
    PlayerCharacter* player1 = nullptr;

    switch (characterProfession) {
        case 0: player1 = new Barbarian(characterName, characterRace, characterProfession); break;
        case 1: player1 = new Cleric(characterName, characterRace, characterProfession); break;
        case 2: player1 = new Ranger(characterName, characterRace, characterProfession); break;
        case 3: player1 = new Sorcerer(characterName, characterRace, characterProfession); break;
        default: cout << "Invalid profession." << endl;
            return 1;
    }

    // Print character's stats and greet user
    player1->printStats();//object method
    cout << endl;
    player1->greet(); //inherited method

    // Perform Action User Interaction
    cout << endl;
    cout << "========================" << endl;
    cout << "       GAME STORY" << endl;
    cout << "========================" << endl;
    typewriter("Game Master: You are wondering around the woods. A wild bear has appeared!"
                " There is no escape, your character will engage in battle.");
    player1->performAction();

    cout << endl;
	typewriter("Game Master: Wow. Very talented, you have defeated this wild bear. Go on with your journey!");


    /*
    cout << "You: ";
    cin >> userResponse;
    string characterResponse = "I'm sorry, I don't understand.";
    player1.speak(characterResponse);//inherited method
    */
    return 0;
}

// Added this function, since it's a text-based game, 
// I wanted it to print out the words as if it was talking to the user
void typewriter(string text) {
    for (int i = 0; i < text.length(); i++) {
        cout << text[i] << flush;
        usleep(25000);
    }
    cout << endl;
}