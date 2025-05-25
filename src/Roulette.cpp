#include "Roulette.h"
#include <iostream>
#include "utils.h"
#include <random>
#include <ctime>
#include <vector>

using namespace std;


Roulette::Roulette(int currentMoney) {
    playRoulette = true;
    playersMoney = currentMoney;
    betType;
    betAmount;
}

// 1-36 red and black and green 0
// a. bet on a number (35:1)
// b. two numbers next ot ech other (17:1)
// c. three numbers (11:1)
// d. red black (1:1)
// e. odd even (1:1) 0 is not included
// d. (1-12, 13-24, 25-36) (2:1)


int Roulette::run() {

    cout << "===== Welcome to the roulette table. =====" << endl;

    do {

        displayRules();
        cout << "What kind of bet would you like to place? ";
        cin >> betType;
        validateInput();
        if (betType == 1) {numberBet();}
        else if (betType == 2) {}
        else if (betType == 3) {}


        

    } while (playRoulette);
    return playersMoney;
}

void Roulette::displayRules() {
    cout << "You have numbers from 1-36. Odd numbers are red, even numbers are black." << endl;
    cout << "There is also green 0 you can place your bet on." << endl;
    cout << "We offer you 5 groups of bets: " << endl;
    cout << "1. You can bet on a individual number with very high reward." << endl;
    cout << "2. You can bet on 2 numbers next to each other for significant reward." << endl;
    cout << "3. You can bet on horizontal line that have 3 numbers - [1,2,3] or [4,5,6] etc. For a good reward" << endl;
    cout << "4. You can bet on a red/black for basic reward" << endl;
    cout << "5. You can bet on group of 12 (1-12, 13-24, 25-36) for decent reward " << endl;
}


void Roulette::numberBet() {
    bool wrongBet = true;
    int betValue;
    do {
        cout << "Select number you would like to bet on ";
        cin >> selectedNumber;
        validateInput();
        if (selectedNumber < 1 && selectedNumber > 36) {cout << "Number out of roulette range" << endl;continue;}
        else {
            cout << "How much money would you like to bet?";
            cin >> betValue;
            validateInput();
            reduceMoney(playersMoney, betValue);
            wrongBet = false;
            int result = rouletteSpin();
            if (result == selectedNumber) {
                cout << "You won!" << endl;
                int reward = grantReward(36, betValue);
                cout << "You are getting: " << reward << endl;
                playersMoney = playersMoney + grantReward(36, betValue);
            } else {
                cout << "Unfortunatelly number is: " << result << endl;
            }
        }

    } while (wrongBet);
 
}


int Roulette::rouletteSpin() {
    int rouletteNumber;
    srand(time(0));
    rouletteNumber = rand() % 37;
    return rouletteNumber;
}




