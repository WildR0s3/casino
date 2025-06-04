#ifndef ROULETTE_H
#define ROULETTE_H
#include <vector>
#include <iostream>
#include <algorithm>



class Roulette {

    public:
        Roulette(int currentMoney);
        int run();


    private:
        bool playRoulette;
        int playersMoney;
        std::vector<int> black_numbers;
        void displayRules();
        int betType;
        int betAmount;
        std::vector<int> rewardRatio;
        void numberBet();
        void redBlackBet();
        int selectedNumber;
        int rouletteSpin();
        bool check_black_number(int number);


};


#endif