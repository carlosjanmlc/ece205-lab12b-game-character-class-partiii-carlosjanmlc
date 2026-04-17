///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 11a - Game Character Class Part II - ECE 205 - Spring 2025
//
///
/// @file    main.cpp
/// @author  Janelle Carlos <carlosjm@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "PlayerCharacter_Janelle.hpp"

using namespace std;

//The following program demonstrates how you might call some of the functions in your new class
//and produce the sample output shown in the assignment write-up
//you are not required to use this file and can refactor any existing code that you
//already have to produce the same results

int main()
{
    //declare variables
    string characterName;
    int characterRace;
    string userResponse;

    //define variables
    cout << "Enter a name for your character: " << endl;
    cin >> characterName;
    cout << "Enter a race for your character (0 = wizard, 1 = witch, 2 = mermaid, 3 = human): ";
    cin >> characterRace;

    //create PlayerCharacter object
    PlayerCharacter player1 = PlayerCharacter(characterName, characterRace);

    player1.printStats();//object method
    player1.greet();//inherited method
    cout << "You: ";
    cin >> userResponse;
    string characterResponse = "I'm sorry, I don't understand.";
    player1.speak(characterResponse);//inherited method

    return 0;
}
