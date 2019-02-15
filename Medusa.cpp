/****************************************************************************************************
 * * Program name: CS162 Project3
 * * Author: Taekyoung Kim
 * * Date: 02/05/2019
 * * Description: This is Medusa.cpp file for CS162 Project3
 * * This project demonstrates a fantasy combat game.
 * * There are 5 characters that have different ability and power.
 * * The real game is done with a dice.
 ******************************************************************************************************/

#include "Medusa.h"
#include <iostream>


Medusa::Medusa() //= default;
       :Character("Medusa", 8, 3)
{
}
Medusa::~ Medusa() = default;


int Medusa::Attack() {


    int roll12 = Character::Dice(2, 6);

    std::cout << "Attacker: "<<getName()<<" Attacker's roll: "<<roll12<<std::endl;

    if(roll12 == 12){

        std::cout <<"Medusa use her Glare, so defender will become a stone"<<std::endl;
        return 999;

    }

    else {

        return roll12;
    }

}
void Medusa::Defense(int at) {

    int numOfDef = Character::Dice(1, 6);
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