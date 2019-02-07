/****************************************************************************************************
 * * Program name: CS162 Project3
 * * Author: Taekyoung Kim
 * * Date: 02/05/2019
 * * Description: This is Chara.cpp file for CS162 Project3
 * * This project demonstrates a fantasy combat game.
 * * There are 5 characters that have different ability and power.
 * * The real game is done with a dice.
 ******************************************************************************************************/

#include "Chara.h"
#include <iostream>
#include <random>


Chara::Chara()=default;
Chara::~Chara()=default;
Chara::Chara(int s, int a) {
    this -> strength = s;
    this -> armor = a;
}

int Chara::getStrength() const{

    return this-> strength;
}
int Chara::getArmor() const {
    return this ->armor;
}
void Chara::setArmor(int a) {
    armor = a;
}
void Chara::setStrength(int s){
    strength = s;
}
int Chara::Dice (int num, int side)const {
    int output;

    if(num <=0 ){
        return 0;
    }
    else {
        std::random_device ran;
        std::mt19937 mt(ran());
        std::uniform_int_distribution<int> dist(1, side);
        output = dist(mt);
        //std::cout<< "The dice number is: "<<output<<std::endl;
        return(Dice(num-1, side) + output);
    }


}