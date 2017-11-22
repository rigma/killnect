#include <Skeleton.hpp>

Skeleton::Skeleton(const std::string &name, const std::string &address, int port, bool shutup) : _joints(25) {
    _remote = new vrpn_Tracker_Remote((name + std::string("@") + address + std::string(":") + std::to_string(port)).c_str());
    _remote->register_change_handler(0, this->handleTrackerInput);

    if (_remote != nullptr) {
        _remote->shutup = shutup;
    }

    initSkeleton();
}

Skeleton::Skeleton(const char *name, const char *address, int port, bool shutup) : _joints(25) {
    _remote = new vrpn_Tracker_Remote((name + std::string("@") + address + std::string(":") + std::to_string(port)).c_str());
    _remote->register_change_handler(0, this->handleTrackerInput);

    if (_remote != nullptr) {
        _remote->shutup = shutup;
    }

    initSkeleton();
}

Skeleton::~Skeleton() {
    delete _remote;
}

const std::vector<vrpn_float64> &Skeleton::operator()(const std::string &name) const {
    if (name == "AnkleLeft")
        return _joints[14];
    else if (name == "AnkleRight")
        return _joints[18];
    else if (name == "ElbowLeft")
        return _joints[5];
    else if (name == "ElbowRight")
        return _joints[9];
    else if (name == "FootLeft")
        return _joints[15];
    else if (name == "FootRight")
        return _joints[19];
    else if (name == "HandLeft")
        return _joints[7];
    else if (name == "HandRight")
        return _joints[11];
    else if (name == "HandTipLeft")
        return _joints[21];
    else if (name == "HandTipRight")
        return _joints[23];
    else if (name == "Head")
        return _joints[3];
    else if (name == "HipLeft")
        return _joints[12];
    else if (name == "HipRight")
        return _joints[16];
    else if (name == "KneeLeft")
        return _joints[13];
    else if (name == "KneeRight")
        return _joints[17];
    else if (name == "Neck")
        return _joints[2];
    else if (name == "ShoulderLeft")
        return _joints[4];
    else if (name == "ShoulderRight")
        return _joints[8];
    else if (name == "SpineBase")
        return _joints[0];
    else if (name == "SpineMiddle")
        return _joints[1];
    else if (name == "SpineShoulder")
        return _joints[20];
    else if (name == "ThumbLeft")
        return _joints[22];
    else if (name == "ThumbRight")
        return _joints[24];
    else if (name == "WristLeft")
        return _joints[6];
    else if (name == "WristRight")
        return _joints[10];

    return _joints[0];
}

const std::vector<vrpn_float64> &Skeleton::operator()(const char *name) const {
    std::string input(name);

    if (input == "AnkleLeft")
        return _joints[14];
    else if (input == "AnkleRight")
        return _joints[18];
    else if (input == "ElbowLeft")
        return _joints[5];
    else if (input == "ElbowRight")
        return _joints[9];
    else if (input == "FootLeft")
        return _joints[15];
    else if (input == "FootRight")
        return _joints[19];
    else if (input == "HandLeft")
        return _joints[7];
    else if (input == "HandRight")
        return _joints[11];
    else if (input == "HandTipLeft")
        return _joints[21];
    else if (input == "HandTipRight")
        return _joints[23];
    else if (input == "Head")
        return _joints[3];
    else if (input == "HipLeft")
        return _joints[12];
    else if (input == "HipRight")
        return _joints[16];
    else if (input == "KneeLeft")
        return _joints[13];
    else if (input == "KneeRight")
        return _joints[17];
    else if (input == "Neck")
        return _joints[2];
    else if (input == "ShoulderLeft")
        return _joints[4];
    else if (input == "ShoulderRight")
        return _joints[8];
    else if (input == "SpineBase")
        return _joints[0];
    else if (input == "SpineMiddle")
        return _joints[1];
    else if (input == "SpineShoulder")
        return _joints[20];
    else if (input == "ThumbLeft")
        return _joints[22];
    else if (input == "ThumbRight")
        return _joints[24];
    else if (input == "WristLeft")
        return _joints[6];
    else if (input == "WristRight")
        return _joints[10];

    return _joints[0];
}

void Skeleton::refreshSkeleton() const {
    _remote->mainloop();
}

void VRPN_CALLBACK Skeleton::handleTrackerInput(void *data, vrpn_TRACKERCB tracker) {
    for (std::uint8_t i(0); i < 3; ++i)
        _joints[tracker.sensor][i] = tracker.pos[i];
}

void Skeleton::initSkeleton() {
    for (std::uint8_t i(0); i < 25; ++i) {
        std::vector<vrpn_float64> pos(3);

        for (std::uint8_t j(0); j < 3; ++j)
            pos[j] = 0.;

        _joints[i] = pos;
    }
}
