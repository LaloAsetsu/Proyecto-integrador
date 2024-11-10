// Metodos de "MonsterCatalog.h"
// Eduardo Antonio Mora Hernández - A10774400
// Ultima Modificación el 24 de octubre del 2024
#include "MonsterCatalog.h"

// Funcion que cuneta la cantidad de monstruos en el csv, toma la lista de monstruos y regresa un int sin signo
unsigned int MonsterCatalog::countMonsters(NodoArbol<Monster>* monsterNode) {
    if (!monsterNode)
        return 0;
    return 1 + countMonsters(monsterNode->left) + countMonsters(monsterNode->right);
}

// Funcion auxiliar para buscar un monstruo basandose en su posicion, recibe en un inicio el root y una posicion y regresa el nodo con la posicion encontrada, si no existe regresa nullptr
Monster* MonsterCatalog::getMonsterRecursive(NodoArbol<Monster>* monsterNode, unsigned int* pos) {
    if (!monsterNode)
        return nullptr;

    Monster* left = getMonsterRecursive(monsterNode->left, pos);
    if (left != nullptr) 
        return left;

    if (*pos == 0)
        return &monsterNode->info;

    (*pos)--;

    return getMonsterRecursive(monsterNode->right, pos);
}

// El constructor carga la semilla del rand
MonsterCatalog::MonsterCatalog() {
    srand(time(NULL));
}

MonsterCatalog::~MonsterCatalog() {}

// Funcion para crear un catalogo con el archivo, no recibe nada y retorna un bool si lee o no el archivo
bool MonsterCatalog::loadCatalog() {
    std::ifstream file(FILENAME);
    if (!file.is_open()) {
        std::cerr << "The file couldn't be opened: " << FILENAME << std::endl;
        return false;
    }

    std::string line;
    if (!std::getline(file, line)) {
        std::cerr << "The archive doesn't have a header\n";
        file.close();
        return false;
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, type, size, align;
        float challenge_rate;
        unsigned int armor_class, health_points;
        std::getline(ss, name, ',');
        ss >> challenge_rate;
        ss.ignore(1, ',');
        std::getline(ss, type, ',');
        std::getline(ss, size, ',');
        ss >> armor_class;
        ss.ignore(1, ',');
        ss >> health_points;
        ss.ignore(1, ',');
        std::getline(ss, align, ',');
        Monster monster;
        monster.setName(name);
        monster.setChallengeRate(challenge_rate);
        monster.setType(type);
        monster.setSize(size);
        monster.setArmorClass(armor_class);
        monster.setHealthPoints(health_points);
        monster.setAlign(align);
        monsterCatalog.inserta(monster);
    }

    file.close();
    return true;
}

// Funcion para obtener un mosntruo aleatorio, no recibe nada y regresa un objeto tipo Monster
Monster MonsterCatalog::getRandomMonster() {
    unsigned int numMonsters = countMonsters(monsterCatalog.getRoot());
    if (numMonsters == 0)
        return Monster();

    unsigned int randomPos = rand() % numMonsters;

    Monster* ranMonster = getMonsterRecursive(monsterCatalog.getRoot(), &randomPos);
    if (ranMonster)
        return *ranMonster;

    return Monster();
}
