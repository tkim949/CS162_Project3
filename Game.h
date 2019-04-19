/****************************************************************************************************
 * * Program name: CS162 Project3
 * * Author: Taekyoung Kim
 * * Date: 02/05/2019
 * * Description: This is Game.h file for CS162 Project3
 * * This project demonstrates a fantasy combat game.
 * * There are 5 characters that have different ability and power.
 * * The real game is done with a dice.
 ******************************************************************************************************/

#ifndef PROJECT3_GAME_H
#define PROJECT3_GAME_H
//#include "Chara.h"
#include "Character.h"
#include "HarryP.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "Medusa.h"
#include "Vampire.h"


class Game {


private:
    Character* player1;
    Character* player2;
    Character* temp;

protected:

public:
    Game();
   ~Game();

   void play();

};


#endif //PROJECT3_GAME_H
