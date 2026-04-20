# ece205-lab12b-game-character-class-partiii-carlosjanmlc (Polymorphism)

After a PlayerCharacter subclass has been created and is set to inherit from the GameCharacter base class, the objective of this lab is to use polymorphism to define specialized actions that the characters can perform based on their different professions.

The goals of this lab:
1. Create and manage a repo
2. Share code with peers
3. Work within the limits and design specifications of someone else's code
4. Refactor someone else's code
5. Write more classes in C++ and gain experience managing files in a growing project

The team members will swap PlayerCharacter classes to be used to create another layer of subclasses with different professions.

The final repo will contain:
1. GameCharcter.hpp
2. GameCharacter.cpp
3. PlayerCharacter_Janelle.hpp (provided by another member)
4. PlayerCharacter_Janelle.cpp (provided by another member) 
5. main.cpp (add/update to teammates' repo)
6. Source and Header files for each derived class created in this lab (added to teammate's repo)

Tasks for this lab:
1. Create repo with files from Lab 11a
2. Update the PlayerCharacter class by creating a new method: performAction() that overrides any children of the PlayerCharacter class
3. Share repo with teammates and update the author info in the files + specify who owns each PlayerCharacter file
4. Clone a team member's repo
6. Implement your derived subclasses that inherit from teammate's Character class (add 2-4 new derived classes that inherit teammate's PlayerCharacter + override performAction + each class must have at least 2 unique attributes and 2 unique methods)
7. Add/Update teammate's README file
8. Give instructions to the user that explain the new class' capabilities + update main() to interact with user

example:
Enter a name for your character: Bob  
Enter a race for your character (0 = Dwarf, 1 = Elf, 2 = Human, 3 = Orc): 1 
Enter a profession for your character (0 = Cleric, 1 = Fighter, 2 = Rogue, 3 = Wizard): 0  

---------- Stats for Bob ---------- 
- Race: Elf 
- Health: 100 
- Strength: 9 
- Agility: 3 
- Defense: 1 
-----------------------------------  

Bob the Cleric: Hello, I’m Bob.   
Game Master: What would you like Bob to do? (0 = Cast Spell, 1 = Teleport): 0  
Game Master: You need to roll at least a 10 to successfully cast a spell.  

You rolled a 4. Your spell failed!!! Practice your craft more.

------------------------------------------
## Your final program contains the following parts:

GameCharacter.hpp – base class header provided from a previous lab
GameCharacter.cpp – base class source file provided from a previous lab
PlayerCharacter_Janelle.hpp – teammate-provided PlayerCharacter class header
PlayerCharacter_Janelle.cpp – teammate-provided PlayerCharacter class source
Barbarian.hpp / Barbarian.cpp – profession subclass created for this lab
Cleric.hpp / Cleric.cpp – profession subclass created for this lab
Ranger.hpp / Ranger.cpp – profession subclass created for this lab
Sorcerer.hpp / Sorcerer.cpp – profession subclass created for this lab
main.cpp – allows the user to create and interact with the chosen profession class


The program allows the user to create a character by entering a name, selecting a race, and then selecting a profession. 
After the character is created, the program prints the character stats, greets the user, and then repeatedly asks the 
user what action they would like to perform until they choose to stop.

The available races are:

0 = Wizard
1 = Witch
2 = Mermaid
3 = Human

The available professions are:

0 = Barbarian
1 = Cleric
2 = Ranger
3 = Sorcerer

Each subclass inherits from PlayerCharacter and overrides the performAction() method to provide unique profession behavior.
The performAction() virtual method was added to PlayerCharacter_Janelle.hpp and defined in PlayerCharacter_Janelle.cpp as 
the base definition. Each subclass overrides it with profession-specific actions. All class-specific attributes are 
hardcoded in each constructor so that characters always reset to their standard starting values at the beginning of a
fight.

--------------------------------------------------------
## Subclass Descriptions
### Barbarian: 
A fierce melee fighter who channels primal rage to devastate enemies. Due to their intense rage and fearsome rein, 
they will have four attributes - rageCharges, isRaging, ACCURACY_PENALTY, and strengthBonus. rageCharges tracks how many times 
the Barbarian can activate rage (starting at 3) and isRaging will determine if the character is currently in rage mode. 
ACCURACY_PENALTY is a constant value of 4 that is subtracted from hit rolls while raging. strengthBonus is derived 
from the Barbarian's strength stat and is used in both hit and damage rolls. The Barbarian has two methods: 
inRage() and recklessAttack(). inRage() will activate the Barbarians rage mode (costs 1 rage charge) to double their 
attack damage but applies the accuracy penalty to the hit roll. If they are already raging, they will be able to perform a 
rage-powered attack. recklessAttack() will roll two dice and takes the higher result (high accuracy in hit rolls), but incoming 
attacks also gain advantage for the round towards the Barbarian. The Barbarian overrides performAction() so the user can 
choose between inRage() and recklessAttack(), and overrides printStats() to display their abilities and rage charges. 


### Cleric:
A devoted healer who channels divine power to restore health and bless allies. To cleanse peoples sins and help
the world, the Cleric has three attributes - healingPower, orbAmount, and wisdomBonus. healingPower is a flat bonus to all healing rolls. 
orbAmount tracks how many radiant orbs have been charged through successful hits (up to 5), adding bonus damage. wisdomBonus is derived 
from the Cleric's wisdom stat and is used in both hit and damage rolls. The Cleric has two methods: attack() and heal(). attack() rolls
to hit an enemy with a mace - a successful hit charges an orb and deals bonus orb damage, while a miss resets all orbs. heal() restores HP 
based on a dice roll plus healingPower. The Cleric overrides performAction() so the user can choose between attack() and heal(), and 
overrides printStats() to display their abilities.


### Ranger:
A swift scout who excels at ranged attacks and tracking. As hunters of the wild, they gained these keen intuition skills from 
survival of a gruesome forest. The Ranger has four attributes - arrowCount, multiplier, hasHuntersMark, and dexterityBonus. arrowCount()
tracks the remaining arrows (starting at 10). multiplier is a damage bonus (additional 20%) applied when Hunter's Mark is active. 
hasHuntersMark tracks whether the Ranger has marked their target. dexterityBonus is derived from the Ranger's agility stat and is used 
in hit and damage rolls. The Ranger has two methods: shoot() and huntersMark(). shoot() fires an arrow at an enemy — if Hunter's Mark 
is active, damage is multiplied by the multiplier bonus. huntersMark() activates the mark to boost the Ranger's next attack. The Ranger 
overrides performAction() so the user can choose between shoot() and huntersMark(), and overrides printStats() to display their ability and 
number of arrows they have.


### Sorcerer:
A spellcaster who draws magic from within. As they have been studying magic, learning the world, the source of how it came to be,
they have gained three attributes - sorceryPoints, hasMagicBarrier, and intelligenceBonus. sorceryPoints tracks remaining spell resources 
(starting at 2). hasMagicBarrier tracks whether the Sorcerer has an active magic shield. intelligenceBonus is derived from the Sorcerer's 
intelligence stat and is used in hit and damage rolls. The Sorcerer has two methods: magicShield() and firebolt(). magicShield() costs 
1 sorcery point and raises the Sorcerer's defense by 5. firebolt() launches a fire-based ranged attack using intelligence for hit and 
damage rolls. The Sorcerer overrides performAction() so the user can choose between magicShield() and firebolt(), and overrides printStats() to
display their abilities.

-------------------------------------------------------------------------------
## Why is the program like this?
To make the program easier to use, input validation was added in main.cpp and in each subclass action menu. 
If the user enters a number outside the listed choices, or types an invalid response, the program displays an error 
message and asks again. This makes the interaction clearer and helps prevent the program from behaving unexpectedly.

The program also includes simple stat and inventory limits in several subclasses. For example, rage charges, orbs, arrows, and sorcery 
points, are kept within reasonable ranges so that resources do not go below zero or grow without limit. This makes the behavior of 
each class more consistent and easier to test.

Now that the PlayerCharacter class has been extended with profession-based subclasses, the program demonstrates how inheritance and 
polymorphism can be used together to create multiple character types with shared base traits but different specialized behaviors.