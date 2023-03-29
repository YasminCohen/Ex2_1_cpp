#pragma once
#include "player.hpp"
using namespace std;

namespace ariel{

    class Game{
        private:
            Player p1;
            Player p2;

        public:
            Game(Player player1, Player player2);
            void playAll();
            void printWiner();
            void printLog();
            void printStats();
            void printLastTurn();
            void playTurn();
    };

}