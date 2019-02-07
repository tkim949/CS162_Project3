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


HarryP::HarryP() = default;
HarryP::~ HarryP() = default;
HarryP::HarryP(int s, int a, int newLife)
         :Chara( s, a)
{
    this->newLife = newLife;
}

int HarryP::getNewLife(){
    return this->newLife;
}
void HarryP::setNewLife(int nLife){

    newLife = nLife;
}

int HarryP::Attack() {

   return Chara::Dice(2, 6);
}

int HarryP::Defense() {

    return Chara::Dice(2, 6);

}