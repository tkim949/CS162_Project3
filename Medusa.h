/****************************************************************************************************
 * * Program name: CS162 Project3
 * * Author: Taekyoung Kim
 * * Date: 02/05/2019
 * * Description: This is Medusa.h file for CS162 Project3
 * * This project demonstrates a fantasy combat game.
 * * There are 5 characters that have different ability and power.
 * * The real game is done with a dice.
 ******************************************************************************************************/

#ifndef PROJECT3_MEDUSA_H
#define PROJECT3_MEDUSA_H
#include "Character.h"
//#include "Chara.h"
//#include <string>
#include <iostream>


class Medusa:
        public Character
{

private:


public:

    Medusa();
    ~ Medusa() override;
    //Medusa(std::string n, int s, int a);
    int Attack() override;
    int Defense() override;

};


#endif //PROJECT3_MEDUSA_H
