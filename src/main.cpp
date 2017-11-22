#include <MovementRecognition.hpp>
#include <Skeleton.hpp>

#include <iostream>
#include <string>
#include <vector>

static void handUp(const std::string &name, const std::vector<std::string> &joints) {
    std::cout << name << " up!" << std::endl;
}

static void handDown(const std::string &name, const std::vector<std::string> &joints) {
    std::cout << name << " down!" << std::endl;
}

int main(int argc, char **argv) {
    Skeleton *skeleton(new Skeleton("Tracker0", "localhost"));
    MovementRecognition *recognition(new MovementRecognition(skeleton));

    std::vector<double> upAnchor(3);
    upAnchor[0] = 0.;
    upAnchor[1] = .2;
    upAnchor[2] = 0.;

    std::vector<double> downAnchor(3);
    downAnchor[0] = 0.;
    downAnchor[1] = -.2;
    downAnchor[2] = 0.;

    Box upBox(upAnchor, 1, .2);
    Box downBox(downAnchor, 1, .2);

    recognition->addDetectionBox("LeftHand", "HandLeft", upBox, handUp);
    recognition->addDetectionBox("RightHand", "HandRight", upBox, handUp);

    for (;;) {
        skeleton->refresh();
        recognition->launchRecognition();
    }

    delete recognition;
    delete skeleton;

    return 0;
}
