#include <SFML/Graphics.hpp>
#include <cmath>

int main() {
    unsigned int w = 400;
    unsigned int h = 400;
    float r_shape = 16;
    float r = 300 / 2;
    sf::RenderWindow window(sf::VideoMode(w, h), "SFML works!");
    sf::CircleShape shape(r_shape, 7);
    shape.setFillColor(sf::Color::Green);
    shape.move(w / 2 - r_shape, h / 2 - r_shape);

    float a = 0;
    sf::Time dt = sf::milliseconds(80);

    sf::Event event;
    sf::Clock clock;
    clock.restart();

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (clock.getElapsedTime().asSeconds() > 0.1f) {
            {
                shape.move(r * cos(a), r * sin(a));

                window.clear();
                window.draw(shape);
                window.display();


                shape.move(-r * cos(a), -r * sin(a));

                a += M_PI / 16;
                clock.restart();
            }
        }

        sf::sleep(dt);


    }

    return 0;
}