#include <MovementRecognition.hpp>
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
    MovementRecognition *recognition(new MovementRecognition(skeleton));
    sf::RenderWindow w(sf::VideoMode(400, 400), "SARFML");
    sf::CircleShape shape(200.f);

    shape.setFillColor(sf::Color::Green);   

    while (w.isOpen()) {
        skeleton->refresh();
        recognition->launchRecognition();

        sf::Event evt;
        while (w.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed)
                w.close();
        }

        w.clear();
        w.draw(shape);
        w.display();
    }

    delete recognition;
    delete skeleton;

    return 0;
}
