#include "Roulette.h"
#include <iostream>
#include "utils.h"
#include <random>
#include <ctime>
// #include <vector>
#include <algorithm>

#include <chrono>
#include <thread>


using namespace std;


Roulette::Roulette(int currentMoney) {
    playRoulette = true;
    playersMoney = currentMoney;
    betType;
    betAmount;
    black_numbers = {2,4,6,8,10,11,13,15,17,19,21,23,25,27,29,31,33,35};
    srand(time(0));
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
        cout << "What would you like to do? " << endl;
        cout << "0. Press '0' to exit roulette table" << endl;
        cout << "1. Bet on a indyvidual number" << endl;
        cout << "2. Bet on color black/red" << endl;
        cout << "5. Display rules" << endl;
        cout << "6. Show how much money you have" << endl;
        cin >> betType;
        validateInput();
        if (betType == 1) {numberBet();}
        else if (betType == 2) {redBlackBet();}
        else if (betType == 5) {displayRules();}
        else if (betType == 6) {display_money(playersMoney);}
        else if (betType == 0) {
            cout << "Exiting roulette table" << endl;
            playRoulette = false;
        } 

        if (playersMoney <= 0) {
            cout << "Sorry Casino is not for people broke as a joke. Get out!!!!";
            playRoulette = false;
        }  

    } while (playRoulette);
    return playersMoney;
}

void Roulette::displayRules() {
    cout << "=======================================================================" << endl;
    cout << "You have numbers from 1-36. Odd numbers are red, even numbers are black." << endl;
    cout << "There is also green 0 you can place your bet on." << endl;
    cout << "We offer you 2 possible bets: " << endl;
    cout << "1. You can bet on a individual number with very high reward." << endl;
    cout << "2. You can bet on a red/black for basic reward" << endl;
    // cout << "2. You can bet on 2 numbers next to each other for significant reward." << endl;
    // cout << "3. You can bet on horizontal line that have 3 numbers - [1,2,3] or [4,5,6] etc. For a good reward" << endl;
    // cout << "5. You can bet on group of 12 (1-12, 13-24, 25-36) for decent reward " << endl;
    cout << "=======================================================================" << endl;
}


void Roulette::numberBet() {
    bool wrongBet = true;
    int betValue;
    do {
        cout << endl;
        cout << "Select number you would like to bet on ";
        cin >> selectedNumber;
        validateInput();
        if (selectedNumber < 1 || selectedNumber > 36) {cout << "Number out of roulette range" << endl;continue;}
        else {
            cout << "How much money would you like to bet? ";
            cin >> betValue;
            validateInput();
            if (!check_money(playersMoney, betValue)) {continue;}
            reduceMoney(playersMoney, betValue);
            wrongBet = false;
            int result = rouletteSpin();
            if (result == selectedNumber) {
                cout << "You won!" << endl;
                int reward = grantReward(36, betValue);
                cout << "You are getting: " << reward << endl;
                playersMoney = playersMoney + reward;
            } else {
                cout << "Unfortunatelly you lost " << result << endl;
            }
        }

    } while (wrongBet);
}


void Roulette::redBlackBet() {
    bool wrongBet = true;
    int betValue;
    do {
        cout << endl;
        cout << "Select color you would like to bet on, press 1. for black or 2. for red ";
        cin >> selectedNumber;
        validateInput();
        if (selectedNumber != 1 && selectedNumber != 2) {cout << "Please to select color press 1-black or 2-red" << endl;continue;}
        else {
            cout << "How much money would you like to bet? ";
            cin >> betValue;
            validateInput();
            if (!check_money(playersMoney, betValue)) {continue;}
            reduceMoney(playersMoney, betValue);
            wrongBet = false;
            int result = rouletteSpin();
            bool black = check_black_number(result);
            string color;
            this_thread::sleep_for(chrono::seconds(1));
            if (black) {color="black";} else {color="red";}
            if (black && selectedNumber == 1 || !black && selectedNumber == 2) {
                cout << "You won! Number: " << result << " is " << color << endl;
                int reward = grantReward(2, betValue);
                cout << "You are getting: " << reward << endl;
                playersMoney = playersMoney + reward;
                this_thread::sleep_for(chrono::seconds(1));
            } else {
                cout << "Unfortunatelly you lost cause number " << result << " is " << color << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
        }

    } while (wrongBet);
}


bool Roulette::check_black_number(int number) {
    int occurences = count(black_numbers.begin(),  black_numbers.end(), number);
    if (occurences > 0 && number != 0) {return true;}
    else {return false;}
}



int Roulette::rouletteSpin() {
    this_thread::sleep_for(chrono::seconds(1));
    int rouletteNumber;
    rouletteNumber = rand() % 37;
    cout << "Number is: " << rouletteNumber << endl;
    return rouletteNumber;
}










