/****************************************************************************************************
 * * Program name: CS162 Project3
 * * Author: Taekyoung Kim
 * * Date: 02/05/2019
 * * Description: This is HarryP.cpp file for CS162 Project3
 * * This project demonstrates a fantasy combat game.
 * * There are 5 characters that have different ability and power.
 * * The real game is done with a dice.
 ******************************************************************************************************/

#include "HarryP.h"
#include <iostream>



HarryP::HarryP() //= default;
       :Character("Harry Potter", 10, 0)
{}
HarryP::~ HarryP() = default;

int HarryP::getNewLife() const{
    return this->newLife;
}
void HarryP::setNewLife(int nLife){

    newLife = nLife;
}

int HarryP::Attack() {

    int roll = Character::Dice(2, 6);
    std::cout << "Attacker: "<<getName()<<" Attacker's roll: "<<roll<<std::endl;

   return roll;
}

void HarryP::Defense(int at) {

    Character::Dice(2, 6);

    int numOfDef = Character::Dice(2, 6);
    int damage;
    damage = at -(numOfDef + armor);

    std::cout<<"Defender: "<<name;
    std::cout<<"  Defender's roll: "<<numOfDef<<std::endl;
    std::cout<<"Defender's Armor: "<<armor<<"  Strength: "<<getStrength()<<std::endl;


    if ((getStrength() <= damage) && getNewLife() > 0 ) {



        if(damage >= getStrength()) {

            std::cout << "Total inflicted Damage: " <<getStrength();
        }
        else if(damage > 0 && damage < getStrength()){
            std::cout<<"Total inflicted Damage: "<< damage;
        }

        setStrength(getNewLife());

        std::cout<<" He lost all his strength."<<std::endl;
        std::cout <<"But Harry Potter activates 'Hogwarts' and now his strength is 20." << std::endl;
        setNewLife(0);

    }

    else {

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
            std::cout << "Damage: " << 0 << std::endl;

        }
    }

}