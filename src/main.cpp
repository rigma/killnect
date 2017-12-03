#include <Skeleton.hpp>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char **argv) {
    Skeleton *skeleton(new Skeleton("Tracker0", "localhost"));
    sf::RenderWindow w(sf::VideoMode(400, 400), "SARFML");
    sf::CircleShape shape(200.f);
    sf::Color color(sf::Color::Green);

    while (w.isOpen()) {
        skeleton->refresh();

        if (skeleton->refreshed()) {
            if (skeleton->elbowLeft().pos[1] > skeleton->shoulderLeft().pos[1] && skeleton->handLeft().pos[1] > skeleton->shoulderLeft().pos[1]) {
                std::cout << "Left arm raised!" << std::endl;
                color = sf::Color::Red;
            } else if (skeleton->elbowRight().pos[1] > skeleton->shoulderRight().pos[1] && skeleton->handRight().pos[1] > skeleton->shoulderRight().pos[1]) {
                std::cout << "Right arm raised!" << std::endl;
                color = sf::Color::Red;
            } else {
                color = sf::Color::Blue;
            }
        }

        shape.setFillColor(color);

        sf::Event evt;
        while (w.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed)
                w.close();
            else if (evt.type == sf::Event::KeyPressed && evt.key.code == sf::Keyboard::Escape)
                w.close();
        }

        w.clear();
        w.draw(shape);
        w.display();
    }

    delete skeleton;

    return 0;
}
