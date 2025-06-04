#include <iostream>
#include <limits>
#include "utils.h"

using namespace std;


void validateInput() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


void reduceMoney(int &currentMoney, int betMoney) {
    if (betMoney > currentMoney) {
        cout << "You don't have that much money to bet";
        return;
    } else {
        currentMoney = currentMoney - betMoney;
    }
}



bool check_money(int currentMoney, int betMoney) {
    if (currentMoney > betMoney) {
        return true;
    } else {
        cout << "You don't have that much money to bet" << endl;
        return false;
    }
}



int grantReward(int ratio, int bet) {
    return ratio * bet;
}


void display_money(int playersMoney) {
    cout << "You currently have " << playersMoney << endl;
}