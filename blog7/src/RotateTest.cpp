#include <SFML/Graphics.hpp>
#include "AssetManager.hpp"

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Views");
    AssetManager manager;


    auto wSize = window.getSize();
    sf::View view(sf::FloatRect(0, 0, wSize.x, wSize.y));
    view.setCenter(sf::Vector2f(0, 0));
    view.setRotation(45);
    window.setView(view);

    sf::Vector2f spriteSize = sf::Vector2f(118, 114);
    auto& texture = AssetManager::GetTexture(
        "/Users/huangjiaming/Documents/developer/LearnSFML/blog7/src/myTexture.png");

    sf::Sprite sprite1(texture);
    sprite1.setOrigin(spriteSize * 0.5f);
    sprite1.setPosition(sf::Vector2f(-100, -100));

    sf::Sprite sprite2(texture);
    sprite2.setOrigin(spriteSize * 0.5f);
    sprite2.setPosition(sf::Vector2f(100, -100));


    sf::Sprite sprite3(texture);
    sprite3.setOrigin(spriteSize * 0.5f);
    sprite3.setPosition(sf::Vector2f(100, 100));


    sf::Sprite sprite4(texture);
    sprite4.setOrigin(spriteSize * 0.5f);
    sprite4.setPosition(sf::Vector2f(-100, 100));




    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        window.draw(sprite1);
        window.draw(sprite2);
        window.draw(sprite3);
        window.draw(sprite4);
        window.display();
    }
    return 0;
}