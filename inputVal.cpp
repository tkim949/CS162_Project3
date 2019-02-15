/****************************************************************************************************
 * * Program name: CS162 Project2
 * * Author: Taekyoung Kim
 * * Date: 01/21/2019
 * * Description: This is inputVal.cpp file for CS162 Project2
 * * This function check users' input validation, so if the input is not integer, keeps asking users
 * * to input the correct input.
 ******************************************************************************************************/


#include "inputVal.h"
#include "Game.h"
#include <iostream>
#include <climits>
#include <cctype>
#include <algorithm>


/*********************************************************************
 * * This function get double parameter and return an integer value
 * * after checking if it is digit and positive number and double.
 * * and it checks that number is between 1 and 5.
 **********************************************************************/

int inputVal(double in) {

    // Check type validation first using std::cin.fail()
    if( std::cin.good() && in > 0 && in < 6 && (in - (int)in == 0)) {
        return (int)in;
    }

    else{

        do {

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


