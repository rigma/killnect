#ifndef SKELETON_HPP
#define SKELETON_HPP

#include <vrpn/vrpn_Tracker.h>
#include <string>
#include <vector>

class Skeleton {
public:
    Skeleton(const std::string &name, std::string &address, int port, bool shutup = false);
    Skeleton(const char *name, const char *address, int port, bool shutup = false);
    ~Skeleton();

public:
    const std::vector<vrpn_float64> &operator()(const char *jointName) const;
    const std::vector<vrpn_float64> &operator()(const std::string &jointName) const;

public:
    const std::vector<std::vector<vrpn_float64>> &joints() const;
    const std::vector<vrpn_float64> &ankleLeft() const;
    const std::vector<vrpn_float64> &ankleRight() const;
    const std::vector<vrpn_float64> &elbowLeft() const;
    const std::vector<vrpn_float64> &elbowRight() const;
    const std::vector<vrpn_float64> &footLeft() const;
    const std::vector<vrpn_float64> &footRight() const;
    const std::vector<vrpn_float64> &handLeft() const;
    const std::vector<vrpn_float64> &handRight() const;
    const std::vector<vrpn_float64> &handTipLeft() const;
    const std::vector<vrpn_float64> &handTipRight() const;
    const std::vector<vrpn_float64> &head() const;
    const std::vector<vrpn_float64> &hipLeft() const;
    const std::vector<vrpn_float64> &hipRight() const;
    const std::vector<vrpn_float64> &kneeLeft() const;
    const std::vector<vrpn_float64> &kneeRight() const;
    const std::vector<vrpn_float64> &neck() const;
    const std::vector<vrpn_float64> &shoulderLeft() const;
    const std::vector<vrpn_float64> &shoulderRight() const;
    const std::vector<vrpn_float64> &spineBase() const;
    const std::vector<vrpn_float64> &spineMiddle() const;
    const std::vector<vrpn_float64> &spineShoulder() const;
    const std::vector<vrpn_float64> &thumbLeft() const;
    const std::vector<vrpn_float64> &thumbRight() const;
    const std::vector<vrpn_float64> &wristLeft() const;
    const std::vector<vrpn_float64> &wristRight() const;

public:
    void refreshSkeleton() const;

private:
    void VRPN_CALLBACK handleTrackerInput(void *data, const vrpn_TRACKERCB tracker);
    void initSkeleton();

private:
    std::vector<std::vector<vrpn_float64>> _joints;
    vrpn_Tracker_Remote *_remote;
};

inline const std::vector<std::vector<vrpn_float64>> &Skeleton::joints() const {
    return _joints;
}

inline const std::vector<vrpn_float64> &Skeleton::ankleLeft() const {
    return _joints[14];
}

inline const std::vector<vrpn_float64> &Skeleton::ankleRight() const {
    return _joints[18];
}

inline const std::vector<vrpn_float64> &Skeleton::elbowLeft() const {
    return _joints[5];
}

inline const std::vector<vrpn_float64> &Skeleton::elbowRight() const {
    return _joints[9];
}

inline const std::vector<vrpn_float64> &Skeleton::footLeft() const {
    return _joints[15];
}

inline const std::vector<vrpn_float64> &Skeleton::footRight() const {
    return _joints[19];
}

inline const std::vector<vrpn_float64> &Skeleton::handLeft() const {
    return _joints[7];
}

inline const std::vector<vrpn_float64> &Skeleton::handRight() const {
    return _joints[11];
}

inline const std::vector<vrpn_float64> &Skeleton::handTipLeft() const {
    return _joints[21];
}

inline const std::vector<vrpn_float64> &Skeleton::handTipRight() const {
    return _joints[23];
}

inline const std::vector<vrpn_float64> &Skeleton::head() const {
    return _joints[3];
}

inline const std::vector<vrpn_float64> &Skeleton::hipLeft() const {
    return _joints[12];
}

inline const std::vector<vrpn_float64> &Skeleton::hipRight() const {
    return _joints[16];
}

inline const std::vector<vrpn_float64> &Skeleton::kneeLeft() const {
    return _joints[13];
}

inline const std::vector<vrpn_float64> &Skeleton::kneeRight() const {
    return _joints[17];
}

inline const std::vector<vrpn_float64> &Skeleton::neck() const {
    return _joints[2];
}

inline const std::vector<vrpn_float64> &Skeleton::shoulderLeft() const {
    return _joints[4];
}

inline const std::vector<vrpn_float64> &Skeleton::shoulderRight() const {
    return _joints[8];
}

inline const std::vector<vrpn_float64> &Skeleton::spineBase() const {
    return _joints[0];
}

inline const std::vector<vrpn_float64> &Skeleton::spineMiddle() const {
    return _joints[1];
}

inline const std::vector<vrpn_float64> &Skeleton::spineShoulder() const {
    return _joints[20];
}

inline const std::vector<vrpn_float64> &Skeleton::thumbLeft() const {
    return _joints[22];
}

inline const std::vector<vrpn_float64> &Skeleton::thumbRight() const {
    return _joints[24];
}

inline const std::vector<vrpn_float64> &Skeleton::wristLeft() const {
    return _joints[6];
}

inline const std::vector<vrpn_float64> &Skeleton::wristRight() const {
    return _joints[10];
}

#endif
