/****************************************************************************************************
 * * Program name: CS162 Project2
 * * Author: Taekyoung Kim
 * * Date: 01/21/2019
 * * Description: This is inputVal.cpp file for CS162 Project2
 * * This function check users' input validation, so if the input is not integer, keeps asking users
 * * to input the correct input.
 ******************************************************************************************************/


#include "inputVal.h"
#include <iostream>
#include <climits>
#include <cctype>
#include <algorithm>
#include "Chara.h"
#include "HarryP.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "Medusa.h"
#include "Vampire.h"

/*********************************************************************
 * * This function get double parameter and return an integer value
 * * after checking if it is digit and positive number and double.
 **********************************************************************/

int inputVal(double in) {

    // Check type validation first using std::cin.fail()
    if( std::cin.good() && in > 0 && in <11 && (in - (int)in == 0)) {
        return (int)in;
    }

    else{

        do {
            //std::cout << "Input" << input << std::endl;
            std::cout << "Wrong input! You need to input proper value!" << std::endl;

            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');

            std::cout << "Please try again. Input here: " << std::endl;
            std::cin >> in;
            //decimalCheck(input);

        } while(!(std::cin.good() && in > 0 && (in - (int)in == 0) ));

    }

    return (int)in;
}

/********************************************************************************
 * * This function get an integer parameter and check if the strength is positive.
 ******************************************************************************/

int isStrength(int a){

    Vampire vamp;
    Barbarian barb;
    BlueMen blue;
    Medusa med;
    HarryP harry;


    Vampire vampB;
    Barbarian barbB;
    BlueMen blueB;
    Medusa medB;
    HarryP  harryB;

    int power;

    std::cout<<"strength of vampire: "<<vamp.getStrength()<<" "<<"vampireB: "<<vampB.getStrength()<<std::endl;

    switch(a) {

        case 1:
            power = vamp.getStrength();
            break;

        case 2:
            power = vampB.getStrength();
            break;

        case 3:
            power = barb.getStrength();
            break;

        case 4:
            power = barbB.getStrength();
            break;
        case 5:
            power = blue.getStrength();
            break;
        case 6:
            power = blueB.getStrength();
            break;
        case 7:
            power = med.getStrength();
            break;
        case 8:
            power = medB.getStrength();
            break;
        case 9:
            power = harry.getStrength();
            break;
        case 10:
            power = harryB.getStrength();
            break;
        default:
            break;
    }

    double getInput;

    if(power > 0) {

        return a;
    }
    else{
        do{
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout<<"The warrior you chose is already dead. Please pick another one: ";
            std::cin >> getInput;
            a = inputVal(getInput);
        }while(a <= 0);
    }

    return a;
}

/***********************************************************************************************
 * * This function to check if the input is within the GPA range, which is between 0.0 and 4.0
 * * @param s, @return
 ************************************************************************************************/

double rangeForStudent(double s) {


    if(std::cin.good() && (s>=0 && s<=4.0)) {
        return s;
    }
    else{
        do{
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout<<"Wrong input. You should input between 0.0 and 4.0: ";
            std::cin >> s;
            s = inputVal(s);
        }while(!(std::cin.good()) && (!(s>=0 && s<=4.0)));
    }

    return s;

}
/********************************************************************************************************
 * * This function to check if the input is within the Rating range, which is between 0.0 and 5.0
 * * @param in, @return
 ********************************************************************************************************/

double rangeForInstructor(double in) {

    if(std::cin.good() &&(in>=0 && in<=5.0)) {
        return in;
    }
    else{
        do{
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout<<"Wrong input. You should input between 0.0 and 5.0: ";
            std::cin >> in;
            in = inputVal(in);
        }while(!(std::cin.good()) && (!(in>=0 && in<=4.0)));
    }

    return in;

}

/***********************************************************************************************************
 * * This function checks if the input is only alphabet letters.
 * @param str, @return
 **********************************************************************************************************/

std::string getLetters(std::string str) {


   bool onlyLetter;
   //onlyLetter = std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun((int(*)(int))std::isalpha)))!=str.end();
   onlyLetter = std::find_if(str.begin(), str.end(), [] (char c) {return !std::isalpha(c);}) !=str.end();

   if(!(onlyLetter)) {
       return str;
   }

   else{
       do{
           std::cin.clear();
           std::cin.ignore(INT_MAX, '\n');
           std::cout<<"Wrong input. You should input letters: ";
           std::getline(std::cin, str);
           onlyLetter = std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun((int(*)(int))std::isalpha)))!=str.end();

       }while(onlyLetter);
   }


    return str;

}