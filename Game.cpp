/****************************************************************************************************
 * * Program name: CS162 Project3
 * * Author: Taekyoung Kim
 * * Date: 02/05/2019
 * * Description: This is Game.cpp file for CS162 Project3
 * * This project demonstrates a fantasy combat game.
 * * There are 5 characters that have different ability and power.
 * * The real game is done with a dice.
 ******************************************************************************************************/
#include <iostream>
#include <random>
#include <climits>
#include "Game.h"
#include "inputVal.h"
#include "Character.h"
//#include "Chara.h"
#include "HarryP.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "Medusa.h"
#include "Vampire.h"



Game::Game() = default;
Game::~Game() = default;
//{delete [] player1;
    //delete [] player2;}

void Game::play(){

    double fighter1;
    int numForP1;
    double fighter2;
    int numForP2;
    int playAgain;


    do {
        std::cout <<"\nWelcome to the fantasy World!" << std::endl;
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
        std::cout<<"The first player will attack first."<<std::endl;
        std::cout <<"First warrior: ";
        std::cin >> fighter1;
        numForP1 = inputVal(fighter1);

        std::cout <<"Second warrior: ";
        std::cin >> fighter2;
        numForP2 = inputVal(fighter2);

        switch(numForP1) {

            case 1:
                player1 = new Vampire();
                std::cout<<"You chose 'Vampire' as your first player."<<std::endl;
                break;
            case 2:
                player1 = new Barbarian();
                std::cout<<"You chose 'Barbarian' as your first player."<<std::endl;
                break;
            case 3:
                player1 = new BlueMen();
                std::cout<<"You chose 'Blue men' as your first player."<<std::endl;
                break;
            case 4:
                player1 = new Medusa();
                std::cout<<"You chose 'Medusa' as your first player."<<std::endl;
                break;
            case 5:
                player1 = new HarryP();
                std::cout<<"You chose 'Harry Potter' as your first player."<<std::endl;
                break;
            default:
                break;
        }

        switch(numForP2) {

            case 1:
                player2= new Vampire();
                std::cout<<"You chose 'Vampire' as your second player."<<std::endl;
                break;
            case 2:
                player2= new Barbarian();
                std::cout<<"You chose 'Barbarian' as your second player."<<std::endl;
                break;
            case 3:
                player2= new BlueMen();
                std::cout<<"You chose 'Blue men' as your second player."<<std::endl;
                break;
            case 4:
                player2= new Medusa();
                std::cout<<"You chose 'Medusa' as your second player."<<std::endl;
                break;
            case 5:
                player2= new HarryP();
                std::cout<<"You chose 'Harry Potter' as your second player."<<std::endl;
                break;
            default:
                break;
        }

        HarryP harry;
        harry.setNewLife(20);

        int numOfAtt = 0;
        int numOfDef = 0;
        int arm = 0;
        int power = 0;
        int damage = 0;
        int round = 1;
        do {

            std::cout << "--------------" << std::endl;
            std::cout << "  Round: " << round << std::endl;
            std::cout << "--------------" << std::endl;


            for (int i = 0; i < 2; i++) {

                std::cout << "Fight number " << i + 1 << std::endl;

                if (i == 0) {
                    numOfAtt = player1->Attack();
                    numOfDef = player2->Defense();
                    arm = player2->getArmor();
                    power = player2->getStrength();

                    std::cout << "Attacker: " << player1->getName() << ", Defender: " << player2->getName();
                    std::cout << "\nThe defender's armor: " << arm << ", strength: " << power << std::endl;
                    std::cout << "The attacker's die roll: " << numOfAtt << " VS Defender's: " << numOfDef;


                    damage = numOfAtt - (numOfDef + arm);
                    if (damage <= 0) {
                        damage = 0;
                    }
                    player2->setStrength(power - damage);

                    if (player2->getName() == "Vampire") {

                        if (player2->Defense() == 999) {
                            std::cout << "\nVampire activates her Charm, so the attack";
                            std::cout<<" didn't reach her at all."<<std::endl;

                        } else {
                            std::cout << "\nTotal damage inflicted is: " << damage << std::endl;

                        }
                    }
                    else if (player1->getName() == "Medusa") {

                        if (numOfAtt == 1000) {
                            std::cout << "\nMedusa use her Glare, so defender become";
                            std::cout<<" stone and his/her strength is 0."<<std::endl;
                            player2->setStrength(0);

                        } else {
                            std::cout << "\nTotal damage inflicted is: " << damage << std::endl;

                        }

                        if ((player2->getName() == "Harry Potter") && player2->getStrength() <= 0) {

                            if (harry.getNewLife() > 0) {
                                std::cout << "Harry Potter activates 'Hogwarts' so he regains his power, 20"<<std::endl;
                                player2->setStrength(harry.getNewLife());
                                harry.setNewLife(0);
                            }
                        }

                    }
                    else if (player2->getName() == "Harry Potter" && player2->getStrength() <= 0) {

                        if (harry.getNewLife() > 0) {
                            player2->setStrength(harry.getNewLife());

                            std::cout << "\nHarry potter activates 'Hogwarts' and his strength is 20."<<std::endl;

                            harry.setNewLife(0);

                        } else {

                            std::cout << "\nTotal damage inflicted is: " << damage << std::endl;
                        }
                    }

                    else {
                        std::cout << "\nTotal damage inflicted is: " << damage << std::endl;
                    }

                    std::cout << "\nDefender's strength after the match: " << player2->getStrength() << std::endl;
                    std::cout << std::endl;

                    if (player2->getStrength() <= 0) {

                        std::cout << "Now defender lost all his strength. " << std::endl;
                        break;
                    }

                }
                else // i=1
                {
                    numOfAtt = player2->Attack();
                    numOfDef = player1->Defense();
                    arm = player1->getArmor();
                    power = player1->getStrength();

                    std::cout << "Attacker: " << player2->getName() << ", Defender: " << player1->getName();
                    std::cout << "\nThe defender's armor: " << arm << ", strength: " << power << std::endl;
                    std::cout << "\nThe attacker's die roll: " << numOfAtt << " VS Defender's: " << numOfDef;
                    damage = numOfAtt - (numOfDef + arm);
                    if (damage <= 0) {
                        damage = 0;
                    }
                    player1->setStrength(power - damage);

                    if (player1->getName() == "Vampire") {

                        if (player2->Defense() == 999) {
                            std::cout << "\nVampire activates her Charm, so the attack";
                            std::cout<<" didn't reach her at all."<<std::endl;
                        } else {
                            std::cout << "\nTotal damage inflicted is: " << damage << std::endl;

                        }
                    }
                    else if (player2->getName() == "Medusa") {


                        if (numOfAtt == 1000) {
                            std::cout << "\nMedusa use her Glare, so defender become stone";
                            std::cout<<" and his/her strength is 0."<<std::endl;

                            player2->setStrength(0);

                        } else {
                            std::cout << "\nTotal damage inflicted is: " << damage << std::endl;

                        }

                        if ((player1->getName() == "Harry Potter") && player1->getStrength() <= 0) {

                            if (harry.getNewLife() > 0) {
                                std::cout << "\nHarry Potter activates 'Hogwarts' so he regains his power, 20"<<std::endl;

                                player1->setStrength(harry.getNewLife());
                                harry.setNewLife(0);
                            }
                        }

                    }
                    else if (player1->getName() == "Harry Potter" && player1->getStrength() <= 0) {


                        if (harry.getNewLife() > 0) {
                            player1->setStrength(harry.getNewLife());

                            std::cout <<"\nHarry potter lost all his power, but he use";
                            std::cout<<"'Hogwarts' and now his strength is 20."<<std::endl;

                            harry.setNewLife(0);
                        } else {

                            std::cout << "\nTotal damage inflicted is: " << damage << std::endl;
                        }
                    }

                    else {

                        std::cout << "\nTotal damage inflicted is: " << damage << std::endl;
                    }

                    std::cout << "Defender's strength after the match: " << player1->getStrength() << std::endl;
                    std::cout << " " << std::endl;

                    if (player1->getStrength() <= 0) {

                        std::cout << "Now defender lost all his strength. " << std::endl;
                        break;
                    }

                }
            }
            round ++;
            std::cout<<std::endl;

        }while(player1->getStrength() > 0 && player2->getStrength() > 0 );

        std::cout<<"One of warriors are dead, so Game Over."<<std::endl;

        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout<<"\nIf you want to play again, input 1. Otherwise, click any keys! ";
        std::cin>>playAgain;
        std::cout<<"----------------------------------------------------"<<std::endl;


    }while(playAgain == 1);

        std::cout<<"So you want to exit. Good buy!"<<std::endl;

    //delete [] player1;
   // delete [] player2;

    if(!(player1= nullptr)) {
        delete [] player1;
    }

    if(!(player2= nullptr)) {
        delete [] player2;
    }


}
