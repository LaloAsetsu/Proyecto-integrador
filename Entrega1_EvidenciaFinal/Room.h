// Codigo que creara un cuarto que se obtendra del catalogo de monstruos
// Eduardo Antonio Mora Hernández - A10774400
// Ultima Modificación el 24 de octubre del 2024
#pragma once
#include "MonsterCatalog.h"
#include <iostream>
#include <fstream>

class Room {
private:
    Monster monster;  
    friend std::ostream& operator<<(std::ostream& os, const Room& room);
    
public:
    Room(); 
    Room(const Monster& monster);
    ~Room(); 
};

