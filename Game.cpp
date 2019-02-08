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
/************************
    Chara *vamp = new Vampire(18,1);
    Chara *vamp2 = new Vampire(18, 1);
    Chara *barb = new Barbarian(12, 0);
    Chara *barb2 = new Barbarian(12, 0);
    Chara *blue = new BlueMen(12, 3, 3);
    Chara *blue2 = new BlueMen(12, 3, 3);
    Chara *med = new Medusa(8,3);
    Chara *med2 = new Medusa(8,3);
    Chara *harry = new HarryP(10, 0, 20);
    Chara *harry2 = new HarryP(10, 0, 20);
    *******************************/

    arrayOfV = new Vampire[2];
    arrayOfB = new Barbarian[2];
    arrayOfBM = new BlueMen[2];
    arrayOfM = new Medusa[2];
    arrayOfH = new HarryP[2];



    Vampire vamp;
    //vamp = new Vampire(18,1);
    //Chara *vamp2 = new Vampire(18, 1);
    Barbarian barb;
    //barb = new Barbarian(12, 0);
    //Chara *barb2 = new Barbarian(12, 0);
    BlueMen blue;
   // blue = new BlueMen(12, 3, 3);
    //Chara *blue2 = new BlueMen(12, 3, 3);
    Medusa med;
    //med = new Medusa(8,3);
    //Chara *med2 = new Medusa(8,3);
    HarryP harry;
    //harry= new HarryP(10, 0, 20);
    //Chara *harry2 = new HarryP(10, 0, 20);

    for(int i=0; i< 2; i++ ){

        arrayOfV[i] = Vampire(18,1);
        arrayOfB[i] = Barbarian(12, 0);
        arrayOfBM[i] = BlueMen(12, 3,3);
        arrayOfM[i] = Medusa(8,3);
        arrayOfH[i] = HarryP(10, 0, 20);
    }

    /***************************
     Vampire vamp(18, 1);
     Barbarian barb(12, 0);
     BlueMen blue(12, 3, 3);
     Medusa med(8,3);
     HarryP harry(10, 0, 20);


     Vampire vampB(18, 1);
     Barbarian barbB(12, 0);
     BlueMen blueB(12, 3, 3);
     Medusa medB(8,3);
     HarryP  harryB(10, 0, 20);
     ******************************/

    //std::cout<<"strength of vampire: "<<vamp.getStrength()<<" "<<"vampireB: "<<vampB.getStrength()<<std::endl;


    double fighter1;
    int warrior1;
    double fighter2;
    int warrior2;
    int playAgain;
    int round = 1;

    int numOfAtt = 0;
    int numOfDef = 0;
    int arm = 0;
    int power = 0;
    int damage =0;
    int newPower =0;

    std::string nameOfW1;
    std::string nameOfW2;

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
        warrior1 = inputVal(fighter1);
        //warrior1 = isStrength(warrior1);

        std::cout <<"Second warrior: ";
        std::cin >> fighter2;
        warrior2 = inputVal(fighter2);

        int attacker;
        int defender;
        int output;

        std::cout<<"Now dice will decide who attack first!"<<std::endl;
        std::random_device ran;
        std::mt19937 mt(ran());
        std::uniform_int_distribution<int> dist(1, 2);
        output = dist(mt);

        if (output == 1) {
            attacker = warrior1;
            defender = warrior2;

            //std::cout<<"Now Attacker: "<<nameOfW1<<" Defender: "<<nameOfW2<<std::endl;
        } else {
            attacker = warrior2;
            defender = warrior1;

           // std::cout<<"Now Attacker: "<<nameOfW2<<" Defender: "<<nameOfW1<<std::endl;
        }

        std::string nameOfAtt;
        std::string nameOfDef;

        std::cout<<"--------------"<<std::endl;
        std::cout<<"  Round: "<<round<<std::endl;
        std::cout<<"--------------"<<std::endl;

        for (int i = 0; i < 2; i++) {

            /*******************************************

            if(attacker == defender) {

                switch (attacker) {

                    case 1:
                        numOfAtt = vamp->Attack();
                        nameOfAtt = "Vampire";
                        numOfDef = vamp2->Defense();
                        arm = vamp2->getArmor();
                        nameOfDef = "VampireB";
                        power = vamp2->getStrength();
                        break;

                    case 2:
                        numOfAtt = barb->Attack();
                        nameOfAtt = "Barbarian";
                        numOfDef = barb2->Defense();
                        arm = barb2->getArmor();
                        nameOfDef = "BarbarianB";
                        power = barb2->getStrength();
                        break;

                    case 3:
                        numOfAtt = blue->Attack();
                        nameOfAtt = "BlueMen";
                        numOfDef = blue2->Defense();
                        arm = blue2->getArmor();
                        nameOfDef = "BlueMen";
                        power = blue2->getStrength();
                        break;

                    case 4:
                        numOfAtt = med->Attack();
                        nameOfAtt = "Medusa";
                        numOfDef = med2->Defense();
                        arm = med2->getArmor();
                        nameOfDef = "Medusa";
                        power = med2->getStrength();
                        break;

                    case 5:
                        numOfAtt = harry->Attack();
                        nameOfAtt = "Harry Potter";
                        numOfDef = harry2->Defense();
                        arm = harry2->getArmor();
                        nameOfDef = "Harry Potter";
                        power = harry2->getStrength();
                        break;


                }


            }
            else {
             ********************************************************/

                switch (attacker) {

                    case 1:
                        numOfAtt = vamp.Attack();
                        nameOfAtt = "Vampire";
                        break;
                    case 2:
                        numOfAtt = barb.Attack();
                        nameOfAtt = "Barbarian";
                        break;
                    case 3:
                        numOfAtt = blue.Attack();
                        nameOfAtt = "BlueMen";
                        break;
                    case 4:
                        numOfAtt = med.Attack();
                        nameOfAtt = "Medusa";
                        break;
                    case 5:
                        numOfAtt = harry.Attack();
                        nameOfAtt = "Harry Potter";
                        break;
                    default:
                        break;
                }

                switch (defender) {

                    case 1:
                        numOfDef = vamp.Defense();
                        arm = vamp.getArmor();
                        nameOfDef = "Vampire";
                        power = vamp.getStrength();
                        break;

                    case 2:
                        numOfDef = barb.Defense();
                        arm = barb.getArmor();
                        nameOfDef = "Barbarian";
                        power = barb.getStrength();
                        break;

                    case 3:
                        numOfDef = blue.Defense();
                        arm = blue.getArmor();
                        nameOfDef = "BlueMen";
                        power = blue.getStrength();
                        break;

                    case 4:
                        numOfDef = med.Defense();
                        arm = med.getArmor();
                        nameOfDef = "Medusa";
                        power = med.getStrength();
                        break;

                    case 5:
                        numOfDef = harry.Defense();
                        arm = harry.getArmor();
                        nameOfDef = "Harry Potter";
                        power = harry.getStrength();
                        break;

                    default:
                        break;
                }


            damage = numOfAtt - (numOfDef + arm);
            if(damage <= 0) {
                damage = 0;
            }
            newPower = power - damage;


                std::cout << "Fight number " << i + 1 << std::endl;
                std::cout << "Attacker: " << nameOfAtt << ", Defender: " << nameOfDef << std::endl;
                std::cout << "The defender's armor: " << arm << ", strength: " << power << std::endl;



                if (((defender == 1)||(defender ==2)) && (numOfDef == 1000)) {
                    std::cout << "The attacker's die roll: " << numOfAtt << " VS Defender's: Charm" << std::endl;

                    std::cout << "Vampire activates her Charm, so the attack didn't reach her at all." << std::endl;

                }
                else if ((attacker == 4) && (numOfAtt == 1000)) {
                    std::cout << "The attacker's die roll: " << numOfAtt << " VS Defender's, Glare: "<<12<< std::endl;
                    std::cout << "Medusa use her Glare, so defender become stone and his/her strength is 0."
                              << std::endl;

                    switch (defender) {

                        case 1:
                            vamp.setStrength(0);
                            break;
                        case 2:
                            barb.setStrength(0);
                            break;
                        case 3:
                            blue.setStrength(0);
                            break;
                        case 4:
                            med.setStrength(0);
                            break;
                        case 5:
                            harry.setStrength(0);
                            break;
                        default:
                            break;

                    }
                }

                // This should think about it.!
                //else if (((defender == 9) ||(defender ==10)) && (newPower <= 0) ) {
                else if((defender == 9) && (newPower <= 0) && (harry.getNewLife() > 0) ) {

                   // if((defender == 9) && (harry.getNewLife() > 0)) {
                        std::cout << "The attacker's die roll: " << numOfAtt << " VS Defender's: " << numOfDef
                                  << std::endl;
                        std::cout
                                << "Harry potter lost all his power, but he use 'Hogwarts,' and returns and now his strength is 20."
                                << std::endl;

                        harry.setNewLife(0);
                 /*****************************************************************
                    }
                    else if((defender == 10)&& (harryB.getNewLife() > 0)) {

                        std::cout << "The attacker's die roll: " << numOfAtt << " VS Defender's: " << numOfDef
                                  << std::endl;
                        std::cout
                                << "Harry potterB lost all his power, but he use 'Hogwarts,' and returns and now his strength is 20."
                                << std::endl;
                        harry2.setNewLife(0);
                    }
                *************************************************************************/
                }

                else {
                    std::cout << "The attacker's die roll: " << numOfAtt << " VS Defender's: " << numOfDef << std::endl;
                    std::cout << "Total damage inflicted is: " << damage << std::endl;

                    switch (defender) {

                        case 1:
                            vamp.setStrength(newPower);
                            break;
                        case 2:
                            barb.setStrength(newPower);
                            break;
                        case 3:
                            blue.setStrength(newPower);
                            break;
                        case 4:
                            med.setStrength(newPower);
                            break;
                        case 5:
                            harry.setStrength(newPower);
                            break;
                        default:
                            break;

                    }

                }
            if (defender == 3) {
            //if ((defender == 3) ||(defender == 4)) {


                if ((newPower <= 8) && (newPower > 4)) {

                    std::cout<<"Blue men or Blue men B's strength is 8 or less, so he will lose one of his dice "<<std::endl;
                    std::cout<<"So, now this has two defense rolls."<<std::endl;

                    //if(defender == 3) {
                        blue.setNumDie(2);
                        /************************
                    }
                    else { //defender == 4
                        blueB.setNumDie(2);
                    }
                    *****************************/

                } else if ((newPower <= 4)) {

                    std::cout
                            << "Blue men's strength is 4 or less, so he will lose one of his dice. "<<std::endl;
                    std::cout<<"So, now this has one defense roll."<<std::endl;


                    //if(defender == 3) {
                        blue.setNumDie(1);
                   // }
                   /*********************************
                    else { //defender == 4
                        blueB.setNumDie(1);
                    }
                   **********************************************/
                }

            }

            std::cout<<"Defender's strength after the match: "<<newPower<<std::endl;
            std::cout<<" "<<std::endl;

            int temp = defender;
            defender = attacker;
            attacker = temp;

            if(newPower <= 0) {

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

    }while(playAgain == 1 && newPower > 0);

    if(newPower <= 0 ) {
        std::cout<<"One of warriors are dead, so Game Over."<<std::endl;
    }
    else {
        std::cout<<"So you want to exit. Good buy!"<<std::endl;
    }

}
