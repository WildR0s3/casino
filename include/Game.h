#ifndef GAME_H
#define GAME_H
#include <string>
#include <map>
#include <functional>

using namespace std;



class Game {
    
    public:

        Game();

        void run();
        void selectGame();
        void endRun();

    private:

        bool play;
        int currentGame;
        int startingMoney;

        map<char, void (Game::*)()> main_map;
        map<int, string> selection;

        void initialize_selection_map();
        void initialize_mainloop_map();
        void runRoulette();


};


#endif