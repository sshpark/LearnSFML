#include <SFML/Graphics.hpp>
#include <vector>

const int size = 16;
const int windowWidth = 60;
const int windowHeight = 40;

int dir;

struct SnakeSegment {
    int x, y;

    SnakeSegment(int xx, int yy): x(xx), y(yy) {}

    bool operator == (const SnakeSegment& other) {
        return this->x == other.x && this->y == other.y;
    }
};

sf::Vector2i fruit;

std::vector<SnakeSegment> snake;

void init() {
    snake.clear();
    snake.push_back(SnakeSegment(1, 1));
    snake.push_back(SnakeSegment(2, 1));
    snake.push_back(SnakeSegment(3, 1));

    fruit.x = rand() % (windowWidth-1);
    fruit.y = rand() % (windowHeight-1);

    dir = 2;

}

void renderBorder(sf::RenderWindow& window) {
    sf::RectangleShape bd(sf::Vector2f(size, size));
    bd.setFillColor(sf::Color(122, 122, 122));

    // 绘制上下边界
    for (int i = 0; i < windowWidth; i++) {
        bd.setPosition(i*size, 0);
        window.draw(bd);

        bd.setPosition(i*size, (windowHeight-1)*size);
        window.draw(bd);
    }

    // 绘制左右边界
    for (int i = 1; i < windowHeight-1; i++) {
        bd.setPosition(0, i*size);
        window.draw(bd);

        bd.setPosition((windowWidth-1)*size, i*size);
        window.draw(bd);
    }    
}

void renderSnake(sf::RenderWindow& window) {
    sf::RectangleShape rec(sf::Vector2f(size-1, size-1));
    int n = snake.size();

    for (int i = 0; i < n-1; i++) {
        rec.setPosition(snake[i].x*size, snake[i].y*size);
        rec.setFillColor(sf::Color::Green);
        window.draw(rec);
    }
    rec.setPosition(snake[n-1].x*size, snake[n-1].y*size);
    rec.setFillColor(sf::Color::Yellow);
    window.draw(rec);
}

void render(sf::RenderWindow& window) {
    sf::RectangleShape rec(sf::Vector2f(size-1, size-1));
    rec.setFillColor(sf::Color::Red);
    rec.setPosition(fruit.x*size, fruit.y*size);
    window.draw(rec);

    renderBorder(window);
    renderSnake(window);
}

void update() {
    int n = snake.size();

    for (int i = 0; i < n-1; i++)
        snake[i] = snake[i+1];

    if (dir == 0) snake[n-1].x--; if (dir == 1) snake[n-1].y++;
    if (dir == 2) snake[n-1].x++; if (dir == 3) snake[n-1].y--;

    if (std::find(snake.begin(), snake.end()-1, snake[n-1]) != snake.end()-1)
        init();

    if (snake[n-1].x == fruit.x && snake[n-1].y == fruit.y) {
        fruit.x = rand() % (windowWidth-2)+1;
        fruit.y = rand() % (windowHeight-2)+1;
        snake.push_back(snake[n-1]);
    }

    if (snake[n-1].x >= windowWidth-1) snake[n-1].x = 1;
    if (snake[n-1].x < 1) snake[n-1].x = windowWidth-2;

    if (snake[n-1].y >= windowHeight-1) snake[n-1].y = 1;
    if (snake[n-1].y < 1) snake[n-1].y = windowHeight-2;

}


int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(windowWidth*size, windowHeight*size), "Snake Game");

    sf::Clock clock;
    float dtTime = 0;
    float delay = 0.2;
    srand(1000009);
    
    init();

    while(window.isOpen()) {
        sf::Event event;
        dtTime += clock.restart().asSeconds();

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && dir != 2) {
                dir = 0;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && dir != 3) {
                dir = 1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && dir != 0) {
                dir = 2;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && dir != 1) {
                dir = 3;
            }
        }

        if (dtTime > delay) {
            dtTime = 0;
            update();
        }

        window.clear(sf::Color::Black);
        render(window);
        window.display();
    }
    return 0;
}