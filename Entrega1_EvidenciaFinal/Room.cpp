// Codigo con los metodos de "Room.h"
// Eduardo Antonio Mora Hernández - A10774400
// Ultima Modificación el 24 de octubre del 2024
#include "Room.h"

Room::Room() : monster(Monster()) {}

Room::Room(const Monster& monster) : monster(monster) {}

Room::~Room() {}

//Sobrecarga de operadores de Room 
std::ostream& operator<<(std::ostream& os, const Room& room) {
    os << "Room with: " << room.monster;
    return os;
}
