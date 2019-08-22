#include "../include/Game.hpp"
#include "Player.hpp"

int main(int, char const**)
{
    Player::setDefaultsInputs();
    Game game;
    game.run(60);
    
    return 0;
}
