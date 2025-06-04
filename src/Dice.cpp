#include <iostream>
#include "Dice.h"
#include "utils.h"

using namespace std;


Dice::Dice(int currentMoney) {
    playDice = true;
    playersMoney = currentMoney;
    betAmount;
    selection;
}


int Dice::run() {

    cout << "===== Welcome to the dice table. =====" << endl;

    do {
        display_money(playersMoney);
        displayRules();
        cout << "Would you like to start? Press 1 to start 0 to exit the dice table" << endl;
        cin >> selection;
        validateInput();
        if (selection == 1) {
            play_pass_line();
        } else if (selection == 0) {
            cout << "Exiting dice table" << endl;
            playDice = false;
        }
        

    } while (playDice);
    return playersMoney;
}


void Dice::displayRules() {
    cout << "=======================================================================" << endl;
    cout << "You roll the dice, if you roll 7 or 11 you win!!!" << endl;
    cout << "Be ware if you roll 2, 3, or 12 you craps and lose" << endl;
    cout << "You establish a 'point' if oyu roll 4,5,6,78,9 or 10" << endl;
    cout << "You continue to roll, you need to repeat a point to win!!!" << endl;
    cout << "You craps out if you roll 7. Good Luck!" << endl;
    // cout << "2. You can bet on 2 numbers next to each other for significant reward." << endl;
    // cout << "3. You can bet on horizontal line that have 3 numbers - [1,2,3] or [4,5,6] etc. For a good reward" << endl;
    // cout << "5. You can bet on group of 12 (1-12, 13-24, 25-36) for decent reward " << endl;
    cout << "0. Press '0' to exit roulette table" << endl;
}


void Dice::play_pass_line() {
    
}
