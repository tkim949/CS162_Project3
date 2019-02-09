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
//#include <string>
#include <iostream>


Medusa::Medusa() //= default;
       :Character("Medusa", 8, 3)
{
}
Medusa::~ Medusa() = default;

/********************************
Medusa::Medusa(std::string n, int s, int a)
       :Character(n, s, a)
{
}
****************************/

int Medusa::Attack() {


    int roll12 = Character::Dice(2, 6);

    if(roll12 == 12){
        return 1000;
    }
    else {
        return Character::Dice(2, 6);
    }


}
int Medusa::Defense() {

    return Character::Dice(1, 6);

}