#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class Monster
{
private:
    int screamPower;
    std::string name;
public:
    Monster(std::string name, int screamPower);
    virtual ~Monster();
    bool compare();
};

#endif