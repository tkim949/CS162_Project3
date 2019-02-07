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

Barbarian::Barbarian() =default;
Barbarian::~Barbarian()= default;
Barbarian::Barbarian(int s, int a)
          :Chara(s, a)
{

}
int Barbarian::Attack() {

    return Chara::Dice(2, 6);

}
int Barbarian::Defense() {

    return Chara::Dice(2, 6);
}