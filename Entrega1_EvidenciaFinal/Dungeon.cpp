// Metodos del "Dungeon.h"
// Eduardo Antonio Mora Hernández - A10774400
// Ultima Modificación el 24 de octubre del 2024
#include "Dungeon.h"

Dungeon::Dungeon() {}

Dungeon::~Dungeon() {}

// Funcion para agregar un cuarto con un Monstruo a la lista de cuartos de la dungeon, recibe un Monster y regresa un bool si se inserta el Monster
bool Dungeon::createRoom(const Monster& monster) {
    if(!roomList.insertStart(monster)) return false;
    return true;
}

// Funcion para imprimir la lista de cuartos del dungeon
void Dungeon::printRooms() const {
    roomList.printList();
}
