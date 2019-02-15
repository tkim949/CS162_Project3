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
#include "HarryP.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "Medusa.h"
#include "Vampire.h"



Game::Game() = default;
Game::~Game() = default;
//{/delete player1;
//delete player2;}

/****************************************************************************************************
 * * This play() function hosts the combat game between two players so it shows menu that has all
 * * characters' speciality and prompts users to choose two players to fight with each other.
 * * After every rounds end, it shows each character's roll numbers, defender's strength, and armor,
 * * damage and who wins and who die. Also, it asks users to play again.
 *****************************************************************************************************/

void Game::play(){

    double fighter1;
    int numForP1;
    double fighter2;
    int numForP2;
    int playAgain;


    do {
        std::cout <<"\nWelcome to the fantasy World!" << std::endl;
        std::cout <<"Now, you will have your warriors for the battle."<< std::endl;
        std::cout <<"Warriors who get a higher number in dices win the game."<< std::endl;
        std::cout <<"Some of characters has armor that can be added to the sum" << std::endl;
        std::cout <<"Warriors are 5 characters and two each characters, and they have different ability and skills."<<std::endl;
        std::cout <<"So, they can fight with a same character. Let me introduce them."<< std::endl;
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

        std::cout <<"\nNow please choose two warriors who are going to fight."<< std::endl;
        std::cout <<"The first player will attack first."<< std::endl;
        std::cout <<"First warrior: ";
        std::cin >> fighter1;
        numForP1 = inputVal(fighter1);

        std::cout <<"Second warrior: ";
        std::cin >> fighter2;
        numForP2 = inputVal(fighter2);

        switch(numForP1) {

            case 1:
                player1 = new Vampire();
                std::cout<<"Your choice for player1: 'Vampire' "<<std::endl;
                break;
            case 2:
                player1 = new Barbarian();
                std::cout<<"Your choice for player1: 'Barbarian' "<<std::endl;
                break;
            case 3:
                player1 = new BlueMen();
                std::cout<<"Your choice for player1:'Blue men' "<<std::endl;
                break;
            case 4:
                player1 = new Medusa();
                std::cout<<"Your choice for player1: 'Medusa' "<<std::endl;
                break;
            case 5:
                player1 = new HarryP();
                std::cout<<"Your choice for player1: 'Harry Potter' "<<std::endl;
                break;
            default:
                break;
        }

        switch(numForP2) {

            case 1:
                player2= new Vampire();
                std::cout<<"Your choice for player2: 'Vampire' "<<std::endl;
                break;
            case 2:
                player2= new Barbarian();
                std::cout<<"Your choice for player2: 'Barbarian' "<<std::endl;
                break;
            case 3:
                player2= new BlueMen();
                std::cout<<"Your choice for player2: 'Blue men' "<<std::endl;
                break;
            case 4:
                player2= new Medusa();
                std::cout<<"Your choice for player2: 'Medusa' "<<std::endl;
                break;
            case 5:
                player2= new HarryP();
                std::cout<<"Your choice for player2: 'Harry Potter' "<<std::endl;
                break;
            default:
                break;
        }


        int round = 1;
        int impact;
        do {

            std::cout << "--------------" << std::endl;
            std::cout << "  Round: " << round << std::endl;
            std::cout << "--------------" << std::endl;


            for (int i = 0; i < 2; i++) {

                std::cout << "Fight number " << i + 1 << std::endl;

                if (i == 0) {

                    impact = player1->Attack();

                    player2->Defense(impact);


                    if (player2->getStrength() > 0) {

                        std::cout<<"New strength: "<<player2->getStrength()<<std::endl;
                    }

                    else//(player2->getStrength() <= 0){
                    {
                        std::cout<<"New strength: "<< 0 <<std::endl;
                        std::cout<<std::endl;
                        std::cout<<"Player 2: "<<player2->getName()<<" died. Game Over!"<<std::endl;
                        break;
                    }
                    std::cout<<std::endl;
                }

                else // i=1
                {

                    impact = player2->Attack();

                    player1->Defense(impact);

                    if (player1->getStrength() > 0) {

                        std::cout<<"New strength: "<<player1->getStrength()<<std::endl;
                    }

                    else//(player1->getStrength() <= 0){
                    {
                        std::cout<<"New strength: "<< 0 <<std::endl;
                        std::cout<<std::endl;
                        std::cout<<"Player 1 "<<player1->getName()<<" died. Game Over!"<<std::endl;
                        break;
                    }
                    std::cout<<std::endl;

                }
            }
            round ++;
            std::cout<<std::endl;

        }while(player1->getStrength() > 0 && player2->getStrength() > 0 );

        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout<<"\nIf you want to play again, input 1. Otherwise, click any keys! ";
        std::cin>>playAgain;
        std::cout<<"----------------------------------------------------"<<std::endl;

        //deallocate the memory at the end of every round.
        delete player1;
        delete player2;
    }while(playAgain == 1);

        std::cout<<"So you want to exit. Good buy!"<<std::endl;

}
