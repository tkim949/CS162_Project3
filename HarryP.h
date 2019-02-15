/****************************************************************************************************
 * * Program name: CS162 Project3
 * * Author: Taekyoung Kim
 * * Date: 02/05/2019
 * * Description: This is HarryP.h file for CS162 Project3
 * * This project demonstrates a fantasy combat game.
 * * There are 5 characters that have different ability and power.
 * * The real game is done with a dice.
 ******************************************************************************************************/

#ifndef HARRYP_H
#define HARRYP_H
#include "Character.h"
#include <iostream>



class HarryP:
        public Character

{
private:
      int newLife =20;

public:

    HarryP();
    ~ HarryP() override;
    int getNewLife() const;
    void setNewLife(int nLife);
    int Attack() override;
    void Defense(int at) override;
};


#endif //HARRYP_H
