#include "Player.hpp"
#include "Action.hpp"
#include "ActionTarget.hpp"
#include <cmath>

ActionMap<int> Player::_playerInputs;

Player::Player() : ActionTarget(_playerInputs)
                ,_shape(sf::Vector2f(100,100))
                ,isMoving(false)
                ,rotation(0)

{
    _shape.setFillColor(sf::Color::Blue);
    _shape.setOrigin(50,50);
    _shape.setPosition(400, 300);

    bind(PlayerInputs::Up, [this](const sf::Event&){
        isMoving = true;
    });

    bind(PlayerInputs::Left, [this](const sf::Event&){
        rotation -= 1;
    });

    bind(PlayerInputs::Right, [this](const sf::Event&) {
        rotation += 1;
    });
}

void Player::setDefaultsInputs() {
    _playerInputs.map(PlayerInputs::Up, Action(sf::Keyboard::Up));
    _playerInputs.map(PlayerInputs::Right, Action(sf::Keyboard::Right));
    _playerInputs.map(PlayerInputs::Left, Action(sf::Keyboard::Left));
}

void Player::update(sf::Time deltaTime) {
    float seconds = deltaTime.asSeconds();
    
    if (rotation != 0) {
        float angle = (rotation > 0 ? 1 : -1)*180*seconds;
        _shape.rotate(angle);
    }

    if (isMoving) {
        float angle = _shape.getRotation() / 180 * M_PI - M_PI/2;
        _velocity += sf::Vector2f(std::cos(angle), std::sin(angle))*60.f*seconds;
    }
    _shape.move(seconds * _velocity);
}

void Player::processEvents() {
    isMoving = false;
    rotation = 0;
    ActionTarget::processEvents();
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states)
const {
    target.draw(_shape, states);
}