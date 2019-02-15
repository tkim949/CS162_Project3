/****************************************************************************************************
 * * Program name: CS162 Project3
 * * Author: Taekyoung Kim
 * * Date: 02/05/2019
 * * Description: This is BlueMen.cpp file for CS162 Project3
 * * This project demonstrates a fantasy combat game.
 * * There are 5 characters that have different ability and power.
 * * The real game is done with a dice.
 ******************************************************************************************************/

#include "BlueMen.h"
#include <iostream>


BlueMen::BlueMen() //= default;
        :Character("Blue men", 12, 3)
{
}
BlueMen::~BlueMen() = default ;


int BlueMen::Attack() {

    int roll = Character::Dice(2, 10);

    std::cout << "Attacker: "<<getName()<<" Attacker's roll: "<<roll<<std::endl;

    return roll;

}
void BlueMen::Defense(int at) {

    int numOfDef;
    int damage;

    if (strength > 8){

        std::cout<< "Defender Blue men has 3 dices."<<std::endl;
        numOfDef = Character::Dice(3, 6);
    }

    else if ((strength <= 8) && (strength > 4)) {

        std::cout << "Defender Blue men has 2 dices now." << std::endl;
        numOfDef = Character::Dice(2, 6);

    }
    else //(strength <=4){
    {
        std::cout<< "Defender Blue men 1 dice now."<<std::endl;
        numOfDef = Character::Dice(1, 6);

    }

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