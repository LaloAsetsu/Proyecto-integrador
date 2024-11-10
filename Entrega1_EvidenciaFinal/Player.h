// Codigo con los metodos de "Player.h, sin metodos implementados en esta entrega"
// Eduardo Antonio Mora Hernández - A10774400
// Ultima Modificación el 24 de octubre del 2024
#pragma once
#include "LinkedList.h"
#include "Monster.h"
#include <iostream>

class Player{
private:
    std::string name;
    std::string race;
    unsigned int health_points;
    unsigned int magic_points;
    LinkedList<Monster> monstersDefeated;
public:
    Player() : name(" "), race(" "), health_points(0), magic_points(0), monstersDefeated(){};
    ~Player(){}
};
