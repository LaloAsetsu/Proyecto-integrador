// Codigo que tendra la lista de "Monsters" la cual es la estructura del Dungeon
// Eduardo Antonio Mora Hernández - A10774400
// Ultima Modificación el 24 de octubre del 2024
#pragma once
#include "Room.h"
#include "Monster.h"
#include "LinkedList.h"

class Dungeon {
private:
    LinkedList<Monster> roomList;  

public:
    Dungeon();
    ~Dungeon();
    bool createRoom(const Monster& monster);  
    void printRooms() const; 
};

