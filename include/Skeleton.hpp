#ifndef SKELETON_HPP
#define SKELETON_HPP

#include <vrpn/vrpn_Tracker.h>
#include <string>
#include <vector>

class Skeleton {
public:
    struct Joint {
        vrpn_float64 pos[3];
        vrpn_float64 distance;
        vrpn_float64 speed;
        vrpn_float64 acceleration;
        timeval timestamp;
    };

public:
    Skeleton(const std::string &name, const std::string &address, int port, bool shutup = false);
    Skeleton(const char *name, const char *address, int port, bool shutup = false);
    ~Skeleton();

public:
    const Joint &operator()(const char *jointName) const;
    const Joint &operator()(const std::string &jointName) const;

public:
    const std::vector<Joint> &joints() const;
    const Joint &ankleLeft() const;
    const Joint &ankleRight() const;
    const Joint &elbowLeft() const;
    const Joint &elbowRight() const;
    const Joint &footLeft() const;
    const Joint &footRight() const;
    const Joint &handLeft() const;
    const Joint &handRight() const;
    const Joint &handTipLeft() const;
    const Joint &handTipRight() const;
    const Joint &head() const;
    const Joint &hipLeft() const;
    const Joint &hipRight() const;
    const Joint &kneeLeft() const;
    const Joint &kneeRight() const;
    const Joint &neck() const;
    const Joint &shoulderLeft() const;
    const Joint &shoulderRight() const;
    const Joint &spineBase() const;
    const Joint &spineMiddle() const;
    const Joint &spineShoulder() const;
    const Joint &thumbLeft() const;
    const Joint &thumbRight() const;
    const Joint &wristLeft() const;
    const Joint &wristRight() const;

public:
    void refreshSkeleton() const;

private:
    void initSkeleton();

private:
    std::vector<Joint> _currentJoints;
    std::vector<Joint> _previousJoints;
    vrpn_Tracker_Remote *_remote;

    friend void VRPN_CALLBACK handleTrackerInput(void*, const vrpn_TRACKERCB);
};

inline const std::vector<Skeleton::Joint> &Skeleton::joints() const {
    return _currentJoints;
}

inline const Skeleton::Joint &Skeleton::ankleLeft() const {
    return _currentJoints[14];
}

inline const Skeleton::Joint &Skeleton::ankleRight() const {
    return _currentJoints[18];
}

inline const Skeleton::Joint &Skeleton::elbowLeft() const {
    return _currentJoints[5];
}

inline const Skeleton::Joint &Skeleton::elbowRight() const {
    return _currentJoints[9];
}

inline const Skeleton::Joint &Skeleton::footLeft() const {
    return _currentJoints[15];
}

inline const Skeleton::Joint &Skeleton::footRight() const {
    return _currentJoints[19];
}

inline const Skeleton::Joint &Skeleton::handLeft() const {
    return _currentJoints[7];
}

inline const Skeleton::Joint &Skeleton::handRight() const {
    return _currentJoints[11];
}

inline const Skeleton::Joint &Skeleton::handTipLeft() const {
    return _currentJoints[21];
}

inline const Skeleton::Joint &Skeleton::handTipRight() const {
    return _currentJoints[23];
}

inline const Skeleton::Joint &Skeleton::head() const {
    return _currentJoints[3];
}

inline const Skeleton::Joint &Skeleton::hipLeft() const {
    return _currentJoints[12];
}

inline const Skeleton::Joint &Skeleton::hipRight() const {
    return _currentJoints[16];
}

inline const Skeleton::Joint &Skeleton::kneeLeft() const {
    return _currentJoints[13];
}

inline const Skeleton::Joint &Skeleton::kneeRight() const {
    return _currentJoints[17];
}

inline const Skeleton::Joint &Skeleton::neck() const {
    return _currentJoints[2];
}

inline const Skeleton::Joint &Skeleton::shoulderLeft() const {
    return _currentJoints[4];
}

inline const Skeleton::Joint &Skeleton::shoulderRight() const {
    return _currentJoints[8];
}

inline const Skeleton::Joint &Skeleton::spineBase() const {
    return _currentJoints[0];
}

inline const Skeleton::Joint &Skeleton::spineMiddle() const {
    return _currentJoints[1];
}

inline const Skeleton::Joint &Skeleton::spineShoulder() const {
    return _currentJoints[20];
}

inline const Skeleton::Joint &Skeleton::thumbLeft() const {
    return _currentJoints[22];
}

inline const Skeleton::Joint &Skeleton::thumbRight() const {
    return _currentJoints[24];
}

inline const Skeleton::Joint &Skeleton::wristLeft() const {
    return _currentJoints[6];
}

inline const Skeleton::Joint &Skeleton::wristRight() const {
    return _currentJoints[10];
}

#endif
