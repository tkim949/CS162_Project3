/****************************************************************************************************
 * * Program name: CS162 Project3
 * * Author: Taekyoung Kim
 * * Date: 02/05/2019
 * * Description: This is Chara.h file for CS162 Project3
 * * This project demonstrates a fantasy combat game.
 * * There are 5 characters that have different ability and power.
 * * The real game is done with a dice.
 ******************************************************************************************************/

#ifndef CHARA_H
#define CHARA_H


class Chara {

protected:

    int strength;
    int armor;

public:
    Chara();
    virtual ~Chara();
    Chara(int s, int a);
    virtual int getStrength() const;
    virtual void setStrength(int s);
    virtual int getArmor() const;
    virtual void setArmor(int a);
    virtual int Attack()=0;
    virtual int Defense()=0;
    int Dice (int num, int side)const;

};


#endif //PROJECT3_CHARACT_H
