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
//#include <string>
#include <iostream>

Barbarian::Barbarian() //=default;
         :Character("Barbarian", 12, 0)
{

}
Barbarian::~Barbarian()= default;

/*************************************************
Barbarian::Barbarian(std::string n, int s, int a)
          :Character("Barbarian", 12, 0)
{
}
 ***********************************************/

int Barbarian::Attack() {

    return Character::Dice(2, 6);

}
int Barbarian::Defense() {

    return Character::Dice(2, 6);
}