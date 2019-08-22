#include "Game.hpp"


Game::Game() : _window(sf::VideoMode(800, 600), "Game"){}

void Game::processEvents() {
    sf::Event event;
    
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                _window.close();
            } else if (event.key.code == sf::Keyboard::Up) {
                _player.isMoving = true;
            } else if (event.key.code == sf::Keyboard::Left) {
                _player.rotation = -1;
            } else if (event.key.code == sf::Keyboard::Right) {
                    _player.rotation = 1;
            }
        } else if (event.type == sf::Event::KeyReleased) {
            if(event.key.code == sf::Keyboard::Up)
                _player.isMoving = false;
            else if (event.key.code == sf::Keyboard::Left)
                _player.rotation = 0;
            else if (event.key.code == sf::Keyboard::Right)
                _player.rotation = 0;
        }
    }
}

void Game::update(sf::Time deltatime) {
    _player.update(deltatime);
}

void Game::render() {
    _window.clear();
    _window.draw(_player);
    _window.display();
}

void Game::run(int minimum_frame_per_seconds) {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate;
    sf::Time TimePerFrame = sf::seconds(1.f / minimum_frame_per_seconds);
    
    while (_window.isOpen()) {
        processEvents();
        timeSinceLastUpdate = clock.restart();
        
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            update(TimePerFrame);
        }
        update(timeSinceLastUpdate);
        render();
    }
}