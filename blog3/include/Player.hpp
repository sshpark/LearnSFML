#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "ActionTarget.hpp"
#include "ActionMap.hpp"

class Player : public sf::Drawable, public ActionTarget<int> {
public:
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;
    Player();
    
    template<typename ... Args>
    void setPosition(Args&& ... args) {
        _shape.setPosition(std::forward<Args>(args)...);
    }
    
    void processEvents();
    void update(sf::Time deltaTime);
    static void setDefaultsInputs();

    enum PlayerInputs {Up,Left,Right};

    bool isMoving;
    int rotation;
    static ActionMap<int> _playerInputs;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::RectangleShape _shape;
    sf::Vector2f _velocity;
};

#endif