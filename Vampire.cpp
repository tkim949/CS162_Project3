/****************************************************************************************************
 * * Program name: CS162 Project3
 * * Author: Taekyoung Kim
 * * Date: 02/05/2019
 * * Description: This is Vampire.cpp file for CS162 Project3
 * * This project demonstrates a fantasy combat game.
 * * There are 5 characters that have different ability and power.
 * * The real game is done with a dice.
 ******************************************************************************************************/


#include "Vampire.h"
#include <iostream>
#include <random>
#include "Dice.h"

Vampire::Vampire()  //= default;
        :Character("Vampire", 18, 1)
{

}

Vampire::~Vampire()= default;

int Vampire::Attack() {

    int roll = Character::Dice(1, 12);
    std::cout << "Attacker: "<<getName()<<" Attacker's roll: "<<roll<<std::endl;

    return roll;
}


void Vampire::Defense(int at) {

    int charm;
    int numOfDef;
    numOfDef = Character::Dice(1, 6);
    int damage;
    damage = at-(numOfDef + armor);

    std::cout<<"Defender: "<<name;
    std::cout<<"  Defender's roll: "<<numOfDef<<std::endl;
    std::cout<<"Defender's Armor: "<<armor<<"  Strength: "<<getStrength()<<std::endl;

    std::random_device ran1;
    std::mt19937 mt1(ran1());
    std::uniform_int_distribution<int> dist(0, 1);
    charm = dist(mt1);

    if(charm == 0){

        std::cout << "Vampire activates her Charm, so the attack";
        std::cout<<" didn't reach her at all."<<std::endl;
        std::cout<< "Total inflicted Damage: "<< 0 <<std::endl;

    }
    else { //charm == 1

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


}


