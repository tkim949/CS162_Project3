/****************************************************************************************************
 * * Program name: CS162 Project3
 * * Author: Taekyoung Kim
 * * Date: 02/05/2019
 * * Description: This is Character.cpp file for CS162 Project3
 * * This project demonstrates a fantasy combat game.
 * * There are 5 characters that have different ability and power.
 * * The real game is done with a dice.
 ******************************************************************************************************/

#include "Character.h"
#include <iostream>
#include <random>


Character::Character()=default;
Character::~Character()=default;
Character::Character(std::string n, int s, int a) {
    this -> name = n;
    this -> strength = s;
    this -> armor = a;
}

std::string Character::getName() const {
    return this -> name;

}

int Character::getStrength() const{

    return this-> strength;
}
int Character::getArmor() const {
    return this ->armor;
}
//void Chara::setArmor(int a) {
//    armor = a;
//}
void Character::setStrength(int s){
    strength = s;
}
int Character::Dice (int num, int side)const {
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