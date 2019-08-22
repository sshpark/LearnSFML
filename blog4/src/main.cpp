#include <SFML/Graphics.hpp>

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "String Test");
    sf::String buffer;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::EventType::Closed:
                    window.close();
                    break;
                case sf::Event::EventType::TextEntered:
                    buffer += event.text.unicode;
                    break;
                case sf::Event::EventType::KeyReleased:
                    if (event.key.code == sf::Keyboard::Key::Return) {
                        window.setTitle(buffer);
                        buffer.clear();
                    }
                    break;
                default:
                    break;
            }
        }
        window.clear();
        window.display();
    }
    
    return 0;
}