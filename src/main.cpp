#include <MovementRecognition.hpp>
#include <Skeleton.hpp>

#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>

static bool click(false);

static void mouseClickDown(const std::string &name, const std::vector<std::string> &joints, const Skeleton *skeleton) {
    if ((*skeleton)(joints[0]).velocity() > 2. && !click) {
        INPUT input[1];

        input[0].type = INPUT_MOUSE;
        input[0].mi.dx = skeleton->handRight().pos[0] * GetSystemMetrics(SM_CXSCREEN);
        input[0].mi.dy = -skeleton->handRight().pos[1] * GetSystemMetrics(SM_CYSCREEN);
        input[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

        SendInput(1, input, sizeof(INPUT));
        click = true;
    }
}

static void mouseClickUp(const Skeleton *skeleton) {
    INPUT input[1];

    input[0].type = INPUT_MOUSE;
    input[0].mi.dx = skeleton->handRight().pos[0] * GetSystemMetrics(SM_CXSCREEN);
    input[0].mi.dy = -skeleton->handRight().pos[1] * GetSystemMetrics(SM_CYSCREEN);
    input[0].mi.dwFlags = MOUSEEVENTF_LEFTUP;

    SendInput(1, input, sizeof(INPUT));
    click = false;
}

int main(int argc, char **argv) {
    Skeleton *skeleton(new Skeleton("Tracker0", "localhost"));
    MovementRecognition *recognition(new MovementRecognition(skeleton));

    DWORD width(GetSystemMetrics(SM_CXSCREEN));
    DWORD height(GetSystemMetrics(SM_CYSCREEN));
    Box clickBox(-.5, .5, 0., 1., 1.);

    recognition->addDetectionBox("Click", "HandLeft", clickBox, &mouseClickDown);

    for (;;) {
        skeleton->refresh();

        // Setting the position of the cursor
        const Skeleton::Joint &mouse(skeleton->handRight());
        if (mouse.velocity() > 2.5)
            SetCursorPos(static_cast<int>(mouse.pos[0] * width), static_cast<int>(-mouse.pos[1] * height));

        recognition->launchRecognition();

        if (!recognition->detectionBox("Click").active && click)
            mouseClickUp(skeleton);
    }

    delete recognition;
    delete skeleton;

    return 0;
}
