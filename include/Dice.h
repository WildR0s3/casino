#ifndef DICE_H
#define DICE_H

#include <vector>
#include <iostream>
#include <algorithm>



class Dice {

    public:
        Dice(int currentMoney);
        int run();


    private:
        bool playDice;
        int playersMoney;
        int betValue;
        int selection;
        int point;
        void displayRules();
        int diceRoll();
        int doubleDiceRoll();
        void play_pass_line();
        bool come_out_roll();
        void point_roll();

};


#endif