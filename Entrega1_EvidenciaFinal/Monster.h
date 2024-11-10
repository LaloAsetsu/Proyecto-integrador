// Codigo que contiene los atributos y metodos de los monstruos que estaran en el calabozo
// Eduardo Antonio Mora Hernández - A10774400
// Ultima Modificación el 24 de octubre del 2024
#pragma once
#include <iostream>
#include <fstream>  

class Monster {
private:
    std::string name;
    float challenge_rate;
    std::string type;
    std::string size;
    unsigned int armor_class;
    unsigned int health_points;
    std::string align;
public:
    Monster();
    Monster(const std::string& name, float challenge_rate, const std::string& type, const std::string& size, unsigned int armor_class, unsigned int health_points, const std::string& align);
    ~Monster();
    void setName(const std::string& name);
    void setChallengeRate(float challenge_rate);
    void setType(const std::string& type);
    void setSize(const std::string& size);
    void setArmorClass(unsigned int armor_class);
    void setHealthPoints(unsigned int health_points);
    void setAlign(const std::string& align);
    std::string getName() const;
    float getChallengeRate() const;
    std::string getType() const;
    std::string getSize() const;
    unsigned int getArmorClass() const;
    unsigned int getHealthPoints() const;
    std::string getAlign() const;
    friend std::ostream& operator<<(std::ostream& os, const Monster& monster);
    bool operator<(const Monster& other) const;
    bool operator>(const Monster& other) const;
    bool operator==(const Monster& other) const;
    bool operator!=(const Monster& other) const;
};

