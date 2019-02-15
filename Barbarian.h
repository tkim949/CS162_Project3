/****************************************************************************************************
 * * Program name: CS162 Project3
 * * Author: Taekyoung Kim
 * * Date: 02/05/2019
 * * Description: This is Barbarian.h file for CS162 Project3
 * * This project demonstrates a fantasy combat game.
 * * There are 5 characters that have different ability and power.
 * * The real game is done with a dice.
 ******************************************************************************************************/

#ifndef BARBARIAN_H
#define BARBARIAN_H
#include "Character.h"
#include <string>
#include <iostream>


class Barbarian:
        public Character
{

private:

public:

    Barbarian();
    ~Barbarian() override;
    int Attack() override;
    void Defense(int at) override;
};



#endif //BARBARIAN_H
