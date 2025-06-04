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
        int betAmount;
        int selection;
        void displayRules();
        int diceRoll();
        void play_pass_line();

};


#endif