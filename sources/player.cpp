#include "player.hpp"

namespace ariel {
    Player::Player(string name) {
        this->name = name;
    }
    Player::Player(){
        this->name = "NULL";
    }

    int Player::stacksize()
        {
            return 0;
        }
    int Player::cardesTaken()
        {
            return 0;
        }
}