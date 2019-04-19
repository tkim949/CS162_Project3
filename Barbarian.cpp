/****************************************************************************************************
 * * Program name: CS162 Project3
 * * Author: Taekyoung Kim
 * * Date: 02/05/2019
 * * Description: This is Barbarian.h file for CS162 Project3
 * * This project demonstrates a fantasy combat game.
 * * There are 5 characters that have different ability and power.
 * * The real game is done with a dice.
 ******************************************************************************************************/

#include "Barbarian.h"
#include <iostream>

Barbarian::Barbarian() //=default;
         :Character("Barbarian", 12, 0)
{

}
Barbarian::~Barbarian()= default;


int Barbarian::Attack() {

    int roll = Character::Dice(2, 6);
    std::cout << "Attacker: "<<getName()<<" Attacker's roll: "<<roll<<std::endl;

    return roll;

}
void Barbarian::Defense(int at) {

    int numOfDef = Character::Dice(2, 6);
    int damage;
    damage = at -(numOfDef + armor);

    std::cout<<"Defender: "<<name;
    std::cout<<"  Defender's roll: "<<numOfDef<<std::endl;
    std::cout<<"Defender's Armor: "<<armor<<"  Strength: "<<getStrength()<<std::endl;

    if(damage >= getStrength()) {

        std::cout << "Total inflicted Damage: " << getStrength() << std::endl;
        setStrength(0);

    }
    else if (damage > 0 && damage < getStrength()) {

        std::cout << "Total inflicted Damage: " << damage << std::endl;
        setStrength(strength - damage);
    }
    else if(damage <= 0)
    {
        std::cout << "Total inflicted Damage: " << 0 << std::endl;

    }

}