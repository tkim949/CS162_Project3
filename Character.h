/****************************************************************************************************
 * * Program name: CS162 Project3
 * * Author: Taekyoung Kim
 * * Date: 02/05/2019
 * * Description: This is Character.h file for CS162 Project3
 * * This project demonstrates a fantasy combat game.
 * * There are 5 characters that have different ability and power.
 * * The real game is done with a dice.
 ******************************************************************************************************/

#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>


class Character {

protected:

    std::string name;
    int strength;
    int armor;

public:
    Character();
    virtual ~Character();
    Character(std::string n, int s, int a);
    virtual std::string getName() const;
    virtual int getStrength() const;
    virtual void setStrength(int s);
    virtual int getArmor() const;
    virtual void Defense(int at) = 0;
    virtual int Attack()=0;
    int Dice (int num, int side)const;

};


#endif //CHARACTER_H
