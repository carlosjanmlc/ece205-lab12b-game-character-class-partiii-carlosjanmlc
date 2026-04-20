cmake_minimum_required(VERSION 3.28)
project(ece205-lab12b-game-character-class-partiii-carlosjanmlc)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_HEADERS
        GameCharacter.hpp
        PlayerCharacter_Janelle.hpp
        Barbarian.hpp
        Cleric.hpp
        Ranger.hpp
        Sorcerer.hpp
)
set(PROJECT_SOURCES
        main.cpp
        GameCharacter.cpp
        PlayerCharacter_Janelle.cpp
        Barbarian.cpp
        Cleric.cpp
        Ranger.cpp
        Sorcerer.cpp
)
add_executable(ece205-lab12b-game-character-class-partiii-carlosjanmlc main.cpp ${PROJECT_SOURCES} ${PROJECT_HEADERS})
