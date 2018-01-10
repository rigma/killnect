#include <MovementRecognition.hpp>
#include <Skeleton.hpp>

#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>

static STARTUPINFO infos;
static PROCESS_INFORMATION process;
static bool paintLaunched(false);
static bool click(false);

static bool launchPaint() {
    ZeroMemory(&infos, sizeof(infos));
    ZeroMemory(&process, sizeof(process));
    infos.cb = sizeof(infos);

    if (!CreateProcessA(nullptr, "c:\\windows\\system32\\mspaint.exe", nullptr, nullptr, false, 0, nullptr, nullptr, &infos, &process))
        return false;

    return true;
}

static void killPaint() {
    TerminateProcess(process.hProcess, 0);
    CloseHandle(process.hProcess);
    CloseHandle(process.hThread);
}

static void mouseClickDown(const std::string &name, const std::string &joint, const Skeleton *skeleton) {
    if ((*skeleton)(joint).velocity() > 2. && !click) {
        INPUT input[1];

        input[0].type = INPUT_MOUSE;
        input[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
        input[0].mi.time = 0;

        SendInput(1, input, sizeof(INPUT));
        click = true;
    }
}

static void mouseClickUp(const Skeleton *skeleton) {
    INPUT input[1];

    input[0].type = INPUT_MOUSE;
    input[0].mi.dwFlags = MOUSEEVENTF_LEFTUP;
    input[0].mi.time = 0;

    SendInput(1, input, sizeof(INPUT));
    click = false;
}

static void openPaint(const std::string &name, const std::vector<std::string> &joints, const Skeleton *skeleton) {
    if (!paintLaunched && skeleton->refreshed())
        paintLaunched = launchPaint();
}

static void closePaint(const std::string &name, const std::vector<std::string> &joints, const Skeleton *skeleton) {
    if (paintLaunched && skeleton->refreshed() && (*skeleton)(joints[0]).velocity() > 5.) {
        killPaint();
        paintLaunched = false;
    }
}

int main(int argc, char **argv) {
    Skeleton *skeleton(new Skeleton("Tracker0", "localhost"));
    MovementRecognition *recognition(new MovementRecognition(skeleton));

    DWORD width(GetSystemMetrics(SM_CXSCREEN));
    DWORD height(GetSystemMetrics(SM_CYSCREEN));

    Box clickBox(-.75, .75, 0., 1., 1.);
    Box closeBox(0., -1, 0., std::numeric_limits<double>::infinity(), 1.);

    std::vector<const char*> hands(2);
    hands[0] = "HandLeft";
    hands[1] = "HandRight";
    Action clapAction(0.01, 5.);

    recognition->addDetectionBox("Close", "HandLeft", closeBox, &closePaint);
    recognition->addAction("Clap", hands, clapAction, &openPaint);

    for (;;) {
        skeleton->refresh();

        // Setting the position of the cursor
        const Skeleton::Joint &mouse(skeleton->handRight());
        if (mouse.velocity() > 2.5)
            SetCursorPos(static_cast<int>(mouse.pos[0] * width), static_cast<int>(-mouse.pos[1] * height));

        // Checking if the mouse is clicked
        if (skeleton->handLeft().pos[1] >= skeleton->shoulderLeft().pos[1] && !click)
            mouseClickDown("Click", "HandLeft", skeleton);
        else if (skeleton->handLeft().pos[1] < skeleton->shoulderLeft().pos[1] && click)
            mouseClickUp(skeleton);

        recognition->launchRecognition();
    }

    delete recognition;
    delete skeleton;

    return 0;
}
