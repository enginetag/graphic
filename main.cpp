#include <SFML/Graphics.hpp>
#include <cmath>

int main() {
    unsigned int w = 400;
    unsigned int h = 400;
    float r_shape = 16;
    float r = 300/2;
    sf::RenderWindow window(sf::VideoMode(w, h), "SFML works!");
    sf::CircleShape shape(r_shape, 7);
    shape.setFillColor(sf::Color::Green);
    shape.move(w / 2 - r_shape, h / 2 - r_shape);

    float a = 0;

    sf::Event event;
    sf::Clock clock;
    clock.restart();

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        {
            shape.move(r * cos(a), r * sin(a));

            window.clear();
            window.draw(shape);
            window.display();


            shape.move(-r * cos(a), -r * sin(a));

            a+=M_PI/16;
        }


        if (clock.getElapsedTime().asSeconds() > 1.0f) {
//            if (rectSourceSprite.left == 600)
//                rectSourceSprite.left = 0;
//            else
//                rectSourceSprite.left += 300;
//
//            sprite.setTextureRect(rectSourceSprite);
//            clock.restart();
        }



    }

    return 0;
}