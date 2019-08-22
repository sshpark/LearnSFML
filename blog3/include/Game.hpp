#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Player.hpp"

class Game {
public:
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    Game();
    void run(int minimum_frame_per_seconds);
    
private:
    void processEvents();
    void update(sf::Time deltatime);
    void render();
    
    sf::RenderWindow _window;
    Player _player;
};

#endif