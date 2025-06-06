#include <iostream>
#include "Dice.h"
#include "utils.h"

#include <chrono>
#include <thread>


using namespace std;


Dice::Dice(int currentMoney) {
    playDice = true;
    playersMoney = currentMoney;
    betValue;
    point;
    selection;
    srand(time(0));
}


int Dice::run() {

    cout << "===== Welcome to the dice table. =====" << endl;

    do {
        cout << "Would would you like to do?" << endl;
        cout << "0. Exit dice table" << endl;
        cout << "1. Play dice!!! Yes!!!!!" << endl;
        cout << "2. Display rules" << endl;
        cout << "3. Show how much money you have ";
        cin >> selection;
        validateInput();
        if (selection == 2) {displayRules();}
        else if (selection == 3) {display_money(playersMoney);}
        else if (selection == 1) {
            play_pass_line();
        } else if (selection == 0) {
            cout << "Exiting dice table" << endl;
            playDice = false;
        }
        if (playersMoney <= 0) {
            cout << "Sorry Casino is not for people broke as a joke. Get out!!!!";
            playDice = false;
        }

    } while (playDice);
    return playersMoney;
}


void Dice::displayRules() {
    cout << "=======================================================================" << endl;
    cout << "You roll the dice, if you roll 7 or 11 you win!!!" << endl;
    cout << "Be ware if you roll 2, 3, or 12 you craps and lose" << endl;
    cout << "You establish a 'point' if you roll 4,5,6,7,8,9 or 10" << endl;
    cout << "You continue to roll, you need to repeat a point to win!!!" << endl;
    cout << "You craps out if you roll 7. Good Luck!" << endl;
    cout << "You get what you bet 1:1 if you win" << endl;
    cout << "=======================================================================" << endl;
}


void Dice::play_pass_line() {
    bool play_pass_line = true;
    int point;
    do {
        cout << endl;
        cout << "How much money would you like to bet? ";
        cin >> betValue;
        validateInput();
        if (!check_money(playersMoney, betValue)) {continue;}
        reduceMoney(playersMoney, betValue);
        if (!come_out_roll()) {play_pass_line = false;continue;}
        point_roll();
        play_pass_line = false;

    } while (play_pass_line);
}


bool Dice::come_out_roll() {
    cout << "Your are rolling!!!" << endl;
    
    int sum = doubleDiceRoll();
    this_thread::sleep_for(chrono::seconds(1));
    if (sum == 7 || sum == 11) {

        cout << "You win!!!" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        int reward = grantReward(2, betValue);
        cout << "You are getting: " << reward << endl;
        playersMoney = playersMoney + reward;
        return false;

    } else if (sum == 2 || sum == 3 || sum == 12) {

        cout << "You craps out!!! In laymans term it means you lose ;)" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        return false;

    } else {
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Point established: " << sum << endl;
        point = sum;
        return true;
    }
}


void Dice::point_roll() {
    bool play_point = true;
    do {
        cout << "Your are rolling for a point!!!" << endl;
        int sum =  doubleDiceRoll();
        if (sum == point) {
            this_thread::sleep_for(chrono::seconds(1));
            cout << "You win!!! You are amazing dice roller!" << endl;
            int reward = grantReward(2, betValue);
            cout << "You are getting: " << reward << endl;
            cout << endl;
            playersMoney = playersMoney + reward;
            play_point = false;
        } else if (sum == 7) {
            this_thread::sleep_for(chrono::seconds(1));
            cout << "Sorry Vinethou you lost!!!" << endl;
            cout << endl;
            play_point = false;
        } else {
            this_thread::sleep_for(chrono::seconds(1));
            cout << "Another chance to win some money!! You are rolling again!" << endl;
        }
    } while (play_point);

}


int Dice::diceRoll() {
    int dice_roll;
    dice_roll = (rand() % 6) + 1;
    return dice_roll;
}


int Dice::doubleDiceRoll() {
    this_thread::sleep_for(chrono::seconds(1));
    int first_dice = diceRoll();
    int second_dice = diceRoll();
    int sum = first_dice + second_dice;
    cout << "Dice 1: " << first_dice << " / Dice 2: " << second_dice << " # sum: " << sum << endl;
    return sum;
}
