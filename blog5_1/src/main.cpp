#include <SFML/Graphics.hpp>

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Texture Test");

    sf::Texture texture;
    if (!texture.loadFromFile("leaf.png")) {
        return -1;
    }
    sf::Vector2u textureSize = texture.getSize();
    float rectWidth = static_cast<float>(textureSize.x);
    float rectHeight = static_cast<float>(textureSize.y);

    sf::RectangleShape rectShape(sf::Vector2f(rectWidth, rectHeight));
    rectShape.setTexture(&texture);

    while (window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        window.draw(rectShape);
        window.display();
    }

    return 0;
}