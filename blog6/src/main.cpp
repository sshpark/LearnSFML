#include <SFML/Graphics.hpp>

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Crystal");


    sf::Texture texture;

    if (!(texture.loadFromFile("/Users/huangjiaming/Documents/developer/LearnSFML/blog6/src/crystal1.png"))) {
        return -1;
    }

    sf::Vector2i spriteSize(118, 114);
    sf::Sprite sprite(texture);
    sprite.setPosition(320, 240);
    sprite.setOrigin(59, 57);

    sf::Clock clock;
    sf::Time elp;

    float animatorDuration = 2.0/8;

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed)
                window.close();
        }

        sf::Time dt = clock.restart();

        elp += dt;
        float timeAsSeconds = elp.asSeconds();

        int animFrame = static_cast<int>((timeAsSeconds / animatorDuration) * 8) % 8;
        sprite.setTextureRect(sf::IntRect(animFrame*spriteSize.x, 0, spriteSize.x, spriteSize.y));

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}