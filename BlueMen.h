/****************************************************************************************************
 * * Program name: CS162 Project3
 * * Author: Taekyoung Kim
 * * Date: 02/05/2019
 * * Description: This is BlueMen.h file for CS162 Project3
 * * This project demonstrates a fantasy combat game.
 * * There are 5 characters that have different ability and power.
 * * The real game is done with a dice.
 ******************************************************************************************************/

#ifndef PROJECT3_BLUEMEN_H
#define PROJECT3_BLUEMEN_H


#include "Chara.h"

class BlueMen:
        public Chara
{

private:
    int numDie;


public:

    BlueMen();
    ~BlueMen() override;
    BlueMen(int s, int a, int die);
    int getNumDie();
    void setNumDie(int die);
    int Attack() override;
    int Defense() override;

};


#endif //PROJECT3_BLUEMEN_H
