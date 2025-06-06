#include "Game.h"
#include "utils.h"
#include "Roulette.h"
#include "Dice.h"
#include <iostream>
#include <map>
#include <functional>

using namespace std;



Game::Game() {
    initialize_selection_map();
    play = true;
    currentGame = 0;
    startingMoney = 1000;
}


void Game::run() {
    
    char choice;

    cout << "===== Welcome to the Casino! =====" << endl;
    cout << "We give you " << startingMoney << " USD for the start" << endl;

    do {
        
        cout << "Would you like to enter? (Y/N) ";
        cin >> choice;
        validateInput();
        choice = tolower(choice);
        if (choice == 'y')  {selectGame();}
        else if (choice == 'n') {endRun();}
        
    } while (play);

}


void Game::selectGame() {
    cout << endl;
    cout << "What would you like to play me Dear? " << endl;
    cout << "We have: \n";
    cout << "1. Dice - pass line" << endl;
    cout << "2. Roullete" << endl;
    cout << "3. Slot machine" << endl;
    cin >> currentGame;
    validateInput();
    if (currentGame == 1) {runDice();}
    if (currentGame == 2) {runRoulette();}
    if (currentGame ==3) {cout << "Work in progress";}
    if (startingMoney <= 0) {
            // cout << "Sorry Casino is not for people broke as a joke. Get out!!!!";
            play = false;
        }

}


void Game::runRoulette() {
    startingMoney = Roulette(startingMoney).run();
}

void Game::runDice() {
    startingMoney = Dice(startingMoney).run();
}


void Game::endRun() {

    play = false;
    cout << "Come by next time!!!" << endl;

}


void Game::initialize_selection_map() {
    selection = {
        {1, "BlackJack"},
        {2, "Roullete"},
        {3, "Slot machine"}
    };
}





