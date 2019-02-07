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


BlueMen::BlueMen() = default;
BlueMen::~BlueMen() = default ;
BlueMen::BlueMen(int s, int a, int numDie)
        :Chara(s, a)
{
    this ->numDie =numDie;
}
int BlueMen::getNumDie(){
    return this->numDie;
}
void BlueMen::setNumDie(int die){

    numDie = die;

}

int BlueMen::Attack() {

    return Chara::Dice(2, 10);

}
int BlueMen::Defense() {

    return Chara::Dice(3, 6);

}