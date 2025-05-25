#ifndef ROULETTE_H
#define ROULETTE_H
#include <vector>
#include <iostream>




class Roulette {

    public:
        Roulette(int currentMoney);
        int run();


    private:
        bool playRoulette;
        int playersMoney;
        void displayRules();
        int betType;
        int betAmount;
        std::vector<int> rewardRatio;
        void numberBet();
        int selectedNumber;
        int rouletteSpin();


};


#endif