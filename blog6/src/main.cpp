#include <SFML/Graphics.hpp>
#include "AssetManager.hpp"
#include "Animator.hpp"

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Crystal");

    AssetManager manager;

    sf::Vector2i spriteSize(118, 114);
    sf::Sprite sprite;
    sprite.setPosition(320, 240);
    sprite.setOrigin(59, 57);

    Animator animator(sprite);


    auto& idleAnimation = animator.CreateAnimation("Idle", 
        "/Users/huangjiaming/Documents/developer/LearnSFML/blog6/src/crystal1.png",
        sf::seconds(1), true);

    idleAnimation.AddFrames(sf::Vector2i(0, 0), spriteSize, 8);
    

    sf::Clock clock;


    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed)
                window.close();
        }
        sf::Time dt = clock.restart();

        animator.Update(dt);

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}