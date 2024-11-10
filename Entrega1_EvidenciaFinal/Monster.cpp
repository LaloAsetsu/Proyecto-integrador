// Codigo con los metodos de "Monster.h"
// Eduardo Antonio Mora Hernández - A10774400
// Ultima Modificación el 24 de octubre del 2024
#include "Monster.h"

Monster::Monster() : name(""), challenge_rate(0.0), type(""), size(""), armor_class(0), health_points(0), align("") {}

Monster::Monster(const std::string& name, float challenge_rate, const std::string& type, const std::string& size, unsigned int armor_class, unsigned int health_points, const std::string& align) 
    : name(name), challenge_rate(challenge_rate), type(type), size(size), armor_class(armor_class), health_points(health_points), align(align) {}

Monster::~Monster() {}

// Setters de los atributos del Monster
void Monster::setName(const std::string& name) {
    this->name = name;
}

void Monster::setChallengeRate(float challenge_rate) {
    if (challenge_rate >= 0.0) 
        this->challenge_rate = challenge_rate;
}

void Monster::setType(const std::string& type) {
    this->type = type;
}

void Monster::setSize(const std::string& size) {
    this->size = size;
}

void Monster::setArmorClass(unsigned int armor_class) {
    if (armor_class > 0) 
        this->armor_class = armor_class;
}

void Monster::setHealthPoints(unsigned int health_points) {
    if (health_points > 0)  
        this->health_points = health_points;
}

void Monster::setAlign(const std::string& align) {
    this->align = align;
}

// Getters de los atributos de Monster
std::string Monster::getName() const {
    return name;
}

float Monster::getChallengeRate() const {
    return challenge_rate;
}

std::string Monster::getType() const {
    return type;
}

std::string Monster::getSize() const {
    return size;
}

unsigned int Monster::getArmorClass() const {
    return armor_class;
}

unsigned int Monster::getHealthPoints() const {
    return health_points;
}

std::string Monster::getAlign() const {
    return align;
}

// Sobrecarga de operadores de Monster
bool Monster::operator<(const Monster& nMons) const {
    return this->challenge_rate < nMons.challenge_rate;
}

bool Monster::operator>(const Monster& nMons) const {
    return this->challenge_rate > nMons.challenge_rate;
}

bool Monster::operator==(const Monster& nMons) const {
    return this->name == nMons.name && this->challenge_rate == nMons.challenge_rate;
}

bool Monster::operator!=(const Monster& nMons) const {
    return !(*this == nMons);
}

std::ostream& operator<<(std::ostream& os, const Monster& monster) {
    os << "Room with: " << monster.name;
    return os;
}
