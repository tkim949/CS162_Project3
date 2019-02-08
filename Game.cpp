/****************************************************************************************************
 * * Program name: CS162 Project3
 * * Author: Taekyoung Kim
 * * Date: 02/05/2019
 * * Description: This is Game.cpp file for CS162 Project3
 * * This project demonstrates a fantasy combat game.
 * * There are 5 characters that have different ability and power.
 * * The real game is done with a dice.
 ******************************************************************************************************/

#include "Game.h"
#include "inputVal.h"
#include <iostream>
#include <random>
#include "Chara.h"
#include "HarryP.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "Medusa.h"
#include "Vampire.h"



Game::Game() = default;
Game::~Game() = default;


void Game::play(){

    Chara* player1;
    Chara* player2;

    double fighter1;
    int numForP1;
    double fighter2;
    int numForP2;
    int playAgain;
    int round = 1;

    do {
        std::cout << "Welcome to the fantasy World!" << std::endl;
        std::cout <<"Now, you will have your warriors for the battle."<<std::endl;
        std::cout <<"Warriors who get a higher number in dices win the game."<< std::endl;
        std::cout <<"Some of characters has armor that can be added to the sum" << std::endl;
        std::cout <<"Warriors are 5 characters and two each characters, and they have different ability and skills."<<std::endl;
        std::cout <<"So, they can fight with a same character. Let me introduce them."<<std::endl;
        std::cout <<"\nNumber 1: Vampire. Her strength is 18, highest one and her armor is 1.";
        std::cout <<"Although her attack and defence ability are lower than others, she has special skill, Charm.";
        std::cout <<"\nNumber 2: Barbarian. His strength is 12. His ability for attack and defense is average, 0 armor.";
        std::cout <<"\nNumber 3: Blue Men. his attach and defense ability are the highest, and he has 3 armor. ";
        std::cout <<"But, he lose a weakness. His defense will decrease as same as he lose the strength by 1/3.";
        std::cout <<"\nNumber 4: Medusa, her attack and defense ability is a little lower than others, but she has Glare.";
        std::cout <<"If she roll number 12 on her dice, she will win the game. She also has 3 armor.";
        std::cout <<"\nNumber 5: Happy porter, he has average attack and defense abilities and 0 armor";
        std::cout <<"However, he has special skill, Hogwarts that allows him a second life with 20 strengths,";
        std::cout <<"But, this is only one time chance."<< std::endl;
        std::cout <<"\nIf you want to exit, please click any key other than above." << std::endl;


        std::cout <<"\nNow please choose two warriors that are going to fight."<< std::endl;
        std::cout <<"First warrior: ";
        std::cin >> fighter1;
        numForP1 = inputVal(fighter1);

        std::cout <<"Second warrior: ";
        std::cin >> fighter2;
        numForP2 = inputVal(fighter2);

        int attacker = numForP1;
        int defender = numForP2;
        //int output;

        std::cout<<"--------------"<<std::endl;
        std::cout<<"  Round: "<<round<<std::endl;
        std::cout<<"--------------"<<std::endl;

        int numOfAtt = 0;
        int numOfDef = 0;
        int arm = 0;
        int power = 0;
        int damage = 0;

        for (int i = 0; i < 2; i++) {

            std::cout << "Fight number " << i + 1 << std::endl;

            switch(attacker) {

                case 1:
                    player1 = new Vampire("Vampire", 18, 1);
                    break;
                case 2:
                    player1 = new Barbarian("Barbarian", 12, 0);
                    break;
                case 3:
                    player1 = new BlueMen("Blue men", 12, 3, 3);
                    break;
                case 4:
                    player1 = new Medusa("Medusa", 8, 3);
                    break;
                case 5:
                    player1 = new HarryP("Harry Potter", 10, 0, 20);
                    break;
                default:
                    break;
            }

            switch(defender) {

                case 1:
                    player2= new Vampire("Vampire", 18, 1);
                    break;
                case 2:
                    player2= new Barbarian("Barbarian", 12, 0);
                    break;
                case 3:
                    player2= new BlueMen("Blue men", 12, 3, 3);
                    break;
                case 4:
                    player2= new Medusa("Medusa", 8, 3);
                    break;
                case 5:
                    player2= new HarryP("Harry Potter", 10, 0, 20);
                    break;
                default:
                    break;
            }

            numOfAtt = player1->Attack();
            numOfDef = player2->Defense();
            arm = player2 ->getArmor();
            power = player2 ->getStrength();

            std::cout << "Attacker: " << player1->getName()<< ", Defender: " << player2->getName() << std::endl;
            std::cout << "The defender's armor: " << arm << ", strength: " << power << std::endl;

            damage = numOfAtt -(numOfDef + arm);

            if(damage <= 0) {
                damage = 0;
            }

            if (defender == 1){

                std::cout <<"The attacker's die roll: "<<numOfAtt<< " VS Defender's: "<<numOfDef<< std::endl;
                if(numOfDef == 1000) {

                    std::cout <<"Vampire activates her Charm, so the attack didn't reach her at all." << std::endl;
                }
                else{
                    std::cout << "Total damage inflicted is: " << damage << std::endl;
                    player2->setStrength(power- damage);
                }
            }

            else if (attacker == 4) {

                std::cout <<"The attacker's die roll: "<<numOfAtt<< " VS Defender's: "<<numOfDef<< std::endl;

                if(numOfAtt == 1000 ) {
                    std::cout <<"Medusa use her Glare, so defender become stone and his/her strength is 0."<< std::endl;
                    player2->setStrength(0);
                }
                else{
                    std::cout << "Total damage inflicted is: " << damage << std::endl;
                    player2->setStrength(power- damage);
                }

            }

            else if(defender == 5) {

                HarryP harry;

                if(player2->getStrength() < 0) {
                    player2->setStrength(harry.getNewLife());

                    std::cout << "The attacker's die roll: " << numOfAtt << " VS Defender's: " << numOfDef
                              << std::endl;
                    std::cout << "Harry potter lost all his power, but he use 'Hogwarts' and now his strength is 20."
                              << std::endl;
                    harry.setNewLife(0);
                }

                else{

                    std::cout <<"The attacker's die roll: "<<numOfAtt<< " VS Defender's: "<<numOfDef<< std::endl;
                    std::cout << "Total damage inflicted is: " << damage << std::endl;
                    player2->setStrength(power- damage);
                }
            }

            else {
                std::cout << "The attacker's die roll: " << numOfAtt << " VS Defender's: " << numOfDef << std::endl;
                std::cout << "Total damage inflicted is: " << damage << std::endl;
                player2->setStrength(power- damage);
            }

            std::cout<<"Defender's strength after the match: "<<player2->getStrength()<<std::endl;
            std::cout<<" "<<std::endl;


            if (defender == 3) {
                BlueMen blue;

                if ((player2->getStrength() <= 8) && (player2->getStrength() > 4)) {

                    std::cout<<"Blue men or Blue men B's strength is 8 or less, so he will lose one of his dice "<<std::endl;
                    std::cout<<"So, now this has two defense rolls."<<std::endl;


                    blue.setNumDie(2);
                } else if (player2->getStrength() <= 4) {

                    std::cout
                            << "Blue men's strength is 4 or less, so he will lose one of his dice. "<<std::endl;
                    std::cout<<"So, now this has one defense roll."<<std::endl;

                    blue.setNumDie(1);

                }

            }

            int temp = defender;
            defender = attacker;
            attacker = temp;

            if(player2->getStrength() <= 0) {

                std::cout<<"Now defender lost all his strength. "<<std::endl;
                break;
            }

        }

        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout<<"\nIf you want to play again, input 1. Otherwise, click any keys! ";
        std::cin>>playAgain;
        std::cout<<"----------------------------------------------------"<<std::endl;

        round ++;

    }while(playAgain == 1 && (player2->getStrength()  > 0 ));

    if(player2->getStrength() <= 0 ) {
        std::cout<<"One of warriors are dead, so Game Over."<<std::endl;
    }
    else {
        std::cout<<"So you want to exit. Good buy!"<<std::endl;
    }

    delete [] player1;
    delete [] player2;

}
