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


//constructor
HarryP::HarryP()
       :Character("Harry Potter", 10, 0)
{

}

//destructor
HarryP::~ HarryP() = default;

//Accessor for newLife
int HarryP::getNewLife() const{
    return this->newLife;
}

//Modifier for newLife
void HarryP::setNewLife(int nLife){

    newLife = nLife;
}
/*********************************************************************************
 * * This Attack() function call Dice function with its data and get the result.
 * * Then, it returns its result.
 ********************************************************************************/
int HarryP::Attack() {

    int roll = Character::Dice(2, 6);
    std::cout << "Attacker: "<<getName()<<" Attacker's roll: "<<roll<<std::endl;

   return roll;
}

/*****************************************************************************************
 * * This Defense() function takes integer number as its argument and that integer
 * * is the attacker's roll number. The, this function calls dice function and
 * * calculates damage and shows defender's roll number and armor and the damage.
 * * Also, Harry potter has speciality of Hogwarts, which is give him a new life/strength
 * * of 20 just one time. So, this function check if he use this Hogwarts.
 * * @param at
 *****************************************************************************************/

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