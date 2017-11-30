#include <cmath>
#include <Skeleton.hpp>

static void VRPN_CALLBACK handleTrackerPositionInput(void *data, vrpn_TRACKERCB tracker) {
    Skeleton *skeleton(static_cast<Skeleton*>(data));
    skeleton->_refreshed = true;

    for (std::uint8_t i(0); i < 3; ++i) {
        skeleton->_previousJoints[tracker.sensor].pos[i] = skeleton->_currentJoints[tracker.sensor].pos[i];
        skeleton->_currentJoints[tracker.sensor].pos[i] = tracker.pos[i];
    }

    skeleton->_currentJoints[tracker.sensor].timestamp = tracker.msg_time;

    if (!std::isnan<double>(skeleton->_previousJoints[tracker.sensor].pos[0])) {
        vrpn_float64 dst(0.);
        for (std::uint8_t i(0); i < 3; ++i) {
            vrpn_float64 tmp(skeleton->_currentJoints[tracker.sensor].pos[i] - skeleton->_previousJoints[tracker.sensor].pos[i]);

            dst += (tmp * tmp);
        }

        skeleton->_currentJoints[tracker.sensor].distance = dst;
    } else {
        skeleton->_currentJoints[tracker.sensor].distance = 0.;
    }
}

static void VRPN_CALLBACK handleTrackerVelocityInput(void *data, vrpn_TRACKERVELCB tracker) {
    Skeleton *skeleton(static_cast<Skeleton*>(data));
    skeleton->_refreshed = true;

    for (std::uint8_t i(0); i < 3; ++i) {
        skeleton->_previousJoints[tracker.sensor].vel[i] = skeleton->_currentJoints[tracker.sensor].vel[i];
        skeleton->_currentJoints[tracker.sensor].vel[i] = tracker.vel[i];
    }
}

static void VRPN_CALLBACK handleTrackerAccelerationInput(void *data, vrpn_TRACKERACCCB tracker) {
    Skeleton *skeleton(static_cast<Skeleton*>(data));
    skeleton->_refreshed = true;

    for (std::uint8_t i(0); i < 3; ++i) {
        skeleton->_previousJoints[tracker.sensor].acc[i] = skeleton->_currentJoints[tracker.sensor].acc[i];
        skeleton->_currentJoints[tracker.sensor].acc[i] = tracker.acc[i];
    }
}

Skeleton::Skeleton(const std::string &name, const std::string &address, int port, bool shutup) : _currentJoints(25), _previousJoints(25), _refreshed(false) {
    _remote = new vrpn_Tracker_Remote((name + std::string("@") + address + std::string(":") + std::to_string(port)).c_str());
    _remote->register_change_handler(static_cast<void*>(this), &handleTrackerPositionInput);
    _remote->register_change_handler(static_cast<void*>(this), &handleTrackerVelocityInput);
    _remote->register_change_handler(static_cast<void*>(this), &handleTrackerAccelerationInput);

    if (_remote != nullptr) {
        _remote->shutup = shutup;
    }

    initSkeleton();
}

Skeleton::Skeleton(const char *name, const char *address, int port, bool shutup) : _currentJoints(25), _previousJoints(25), _refreshed(false) {
    _remote = new vrpn_Tracker_Remote((name + std::string("@") + address + std::string(":") + std::to_string(port)).c_str());
    _remote->register_change_handler(static_cast<void*>(this), &handleTrackerPositionInput);
    _remote->register_change_handler(static_cast<void*>(this), &handleTrackerVelocityInput);
    _remote->register_change_handler(static_cast<void*>(this), &handleTrackerAccelerationInput);

    if (_remote != nullptr) {
        _remote->shutup = shutup;
    }

    initSkeleton();
}

Skeleton::~Skeleton() {
    delete _remote;
}

const Skeleton::Joint &Skeleton::operator()(const std::string &name) const {
    if (name == "AnkleLeft")
        return _currentJoints[14];
    else if (name == "AnkleRight")
        return _currentJoints[18];
    else if (name == "ElbowLeft")
        return _currentJoints[5];
    else if (name == "ElbowRight")
        return _currentJoints[9];
    else if (name == "FootLeft")
        return _currentJoints[15];
    else if (name == "FootRight")
        return _currentJoints[19];
    else if (name == "HandLeft")
        return _currentJoints[7];
    else if (name == "HandRight")
        return _currentJoints[11];
    else if (name == "HandTipLeft")
        return _currentJoints[21];
    else if (name == "HandTipRight")
        return _currentJoints[23];
    else if (name == "Head")
        return _currentJoints[3];
    else if (name == "HipLeft")
        return _currentJoints[12];
    else if (name == "HipRight")
        return _currentJoints[16];
    else if (name == "KneeLeft")
        return _currentJoints[13];
    else if (name == "KneeRight")
        return _currentJoints[17];
    else if (name == "Neck")
        return _currentJoints[2];
    else if (name == "ShoulderLeft")
        return _currentJoints[4];
    else if (name == "ShoulderRight")
        return _currentJoints[8];
    else if (name == "SpineBase")
        return _currentJoints[0];
    else if (name == "SpineMiddle")
        return _currentJoints[1];
    else if (name == "SpineShoulder")
        return _currentJoints[20];
    else if (name == "ThumbLeft")
        return _currentJoints[22];
    else if (name == "ThumbRight")
        return _currentJoints[24];
    else if (name == "WristLeft")
        return _currentJoints[6];
    else if (name == "WristRight")
        return _currentJoints[10];

    return _currentJoints[0];
}

const Skeleton::Joint &Skeleton::operator()(const char *name) const {
    std::string input(name);

    if (input == "AnkleLeft")
        return _currentJoints[14];
    else if (input == "AnkleRight")
        return _currentJoints[18];
    else if (input == "ElbowLeft")
        return _currentJoints[5];
    else if (input == "ElbowRight")
        return _currentJoints[9];
    else if (input == "FootLeft")
        return _currentJoints[15];
    else if (input == "FootRight")
        return _currentJoints[19];
    else if (input == "HandLeft")
        return _currentJoints[7];
    else if (input == "HandRight")
        return _currentJoints[11];
    else if (input == "HandTipLeft")
        return _currentJoints[21];
    else if (input == "HandTipRight")
        return _currentJoints[23];
    else if (input == "Head")
        return _currentJoints[3];
    else if (input == "HipLeft")
        return _currentJoints[12];
    else if (input == "HipRight")
        return _currentJoints[16];
    else if (input == "KneeLeft")
        return _currentJoints[13];
    else if (input == "KneeRight")
        return _currentJoints[17];
    else if (input == "Neck")
        return _currentJoints[2];
    else if (input == "ShoulderLeft")
        return _currentJoints[4];
    else if (input == "ShoulderRight")
        return _currentJoints[8];
    else if (input == "SpineBase")
        return _currentJoints[0];
    else if (input == "SpineMiddle")
        return _currentJoints[1];
    else if (input == "SpineShoulder")
        return _currentJoints[20];
    else if (input == "ThumbLeft")
        return _currentJoints[22];
    else if (input == "ThumbRight")
        return _currentJoints[24];
    else if (input == "WristLeft")
        return _currentJoints[6];
    else if (input == "WristRight")
        return _currentJoints[10];

    return _currentJoints[0];
}

void Skeleton::refresh() {
    _refreshed = false;
    _remote->mainloop();
}

void Skeleton::initSkeleton() {
    for (std::uint8_t i(0); i < 25; ++i) {
        Joint joint;

        for (std::uint8_t j(0); j < 3; ++j) {
            joint.pos[i] = std::nan(nullptr);
            joint.vel[i] = std::nan(nullptr);
            joint.acc[i] = std::nan(nullptr);
        }

        joint.distance = 0.;

        _currentJoints[i] = joint;
        _previousJoints[i] = joint;
    }
}
