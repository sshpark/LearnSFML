#include <SFML/Graphics.hpp>

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Repeated Texture");

    sf::Texture texture;

    if (!(texture.loadFromFile("/Users/huangjiaming/Documents/developer/LearnSFML/blog5/src/rep.png"))) {
        return -1;
    }
    texture.setRepeated(true);

    sf::RectangleShape rectShape(sf::Vector2f(128 * 3, 221 * 2));
    rectShape.setTextureRect(sf::IntRect(0, 0, 128 * 3, 221 * 2));
    rectShape.setTexture(&texture);


    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(rectShape);
        window.display();
    }
    return 0;
}