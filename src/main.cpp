#include <MovementRecognition.hpp>
#include <Skeleton.hpp>

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char **argv) {
    Skeleton *skeleton(new Skeleton("Tracker0", "localhost"));
    MovementRecognition *recognition(new MovementRecognition(skeleton));

    for (;;) {
        skeleton->refresh();
        recognition->launchRecognition();
    }

    delete recognition;
    delete skeleton;

    return 0;
}
