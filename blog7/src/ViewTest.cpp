#include <SFML/Graphics.hpp>
#include "AssetManager.hpp"

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Views");
    AssetManager manager;


    auto wSize = window.getSize();
    sf::View view(sf::FloatRect(0, 0, wSize.x, wSize.y));
    view.setCenter(sf::Vector2f(0, 0));
    window.setView(view);

    sf::Vector2f spriteSize = sf::Vector2f(118, 114);
    sf::Sprite sprite(AssetManager::GetTexture(
        "/Users/huangjiaming/Documents/developer/LearnSFML/blog7/src/myTexture.png"));
    sprite.setOrigin(spriteSize * 0.5f);

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.draw(sprite);
        window.display();
    }
    return 0;
}