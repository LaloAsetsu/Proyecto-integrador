// Codigo principal que creara una dungeon con 20 cuartos y estos cuartos imprimiran el nombre de los monstruos
// Eduardo Antonio Mora Hernández - A10774400
// Ultima Modificación el 24 de octubre del 2024#include <iostream>
#include "Dungeon.h"
#define NUMBER_ROOMS 20

using namespace std;

int main() { 
    MonsterCatalog catalog;
    Dungeon dungeon;

    if (!catalog.loadCatalog()) {
        cout << "The catalog couldn't be opened" << endl;
        return 0;
    }

    cout << "Generating dungeon..." << endl;
    for (int c = 0; c < NUMBER_ROOMS; c++) {
        Monster nMonster = catalog.getRandomMonster();

        if (nMonster.getName().empty()) {
            cout << "The monster couldn't be obtained" << endl;
            return 0;
        }

        if (!dungeon.createRoom(nMonster)) {
            cout << "The room couldn't be added to the dungeon" << endl;
            return 0;
        }
    }

    dungeon.printRooms();

    return 0;
}
