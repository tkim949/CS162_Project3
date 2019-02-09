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
//#include <string>
#include <iostream>


BlueMen::BlueMen() //= default;
        :Character("Blue men", 12, 3)
{
}
BlueMen::~BlueMen() = default ;

/**********************************
BlueMen::BlueMen(std::string n, int s, int a)
        :Character(n, s, a)
{
}
*****************************************/

int BlueMen::Attack() {

    return Character::Dice(2, 10);

}
int BlueMen::Defense() {

    if (strength > 8){

        std::cout<< "Blue men's strength more than 8, so he has three dices."<<std::endl;
        return Character::Dice(3, 6);
    }

    else if ((strength <= 8) && (strength > 4)) {

        std::cout << "Blue men's strength is 8 or less and more than 4, so he has two dices" << std::endl;

        return Character::Dice(2, 6);

    }
    else //(strength <=4){
    {
        std::cout<< "Blue men's strength is 4 or less, so he has only one dice. "<<std::endl;

        return Character::Dice(1, 6);
    }

}