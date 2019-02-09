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
//#include <string>
#include <random>

Vampire::Vampire()  //= default;
        :Character("Vampire", 18, 1)
{

}
Vampire::~Vampire()= default;
/**********************************************
Vampire::Vampire(std::string n, int s, int a)
        :Character("Vampire", 18, 1)
{

}
*********************************************/

int Vampire::Attack() {

    return Character::Dice(1, 12);
}

int Vampire::Defense() {

    int charm;
    std::random_device ran1;
    std::mt19937 mt1(ran1());
    std::uniform_int_distribution<int> dist(0, 1);
    charm = dist(mt1);

    if(charm == 0){
        return 999;
    }

    else {
        return Character::Dice(1, 6);
    }

}