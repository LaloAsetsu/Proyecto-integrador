// Codigo que cargará el archivo de "monster.cvs" para poder generar un monstruo del catalogo
// Eduardo Antonio Mora Hernández - A10774400
// Ultima Modificación el 24 de octubre del 2024
#pragma once
#include "ArbolBinario.h"
#include "Monster.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>

#define FILENAME "monsters.csv"

class MonsterCatalog {
private:
    ArbolBinario<Monster> monsterCatalog;
    unsigned int countMonsters(NodoArbol<Monster>* monsterNode);
    Monster* getMonsterRecursive(NodoArbol<Monster>* monsterNode, unsigned int* pos);

public:
    MonsterCatalog();
    ~MonsterCatalog();
    bool loadCatalog();
    Monster getRandomMonster();
};

