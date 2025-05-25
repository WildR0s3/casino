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
    currentMoney = currentMoney - betMoney;
}


int grantReward(int ratio, int bet) {
    return ratio * bet;
}