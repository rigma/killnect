#ifndef SKELETON_HPP
#define SKELETON_HPP

#include <vrpn/vrpn_Tracker.h>
#include <string>
#include <vector>

class Skeleton {
public:
    struct Joint {
    public:
        const vrpn_float64 velocity(bool squared = true) const;
        const vrpn_float64 acceleration(bool squared = true) const;

    public:
        vrpn_float64 pos[3];
        vrpn_float64 vel[3];
        vrpn_float64 acc[3];
        vrpn_float64 distance;
        timeval timestamp;
    };

public:
    Skeleton(const std::string &name, const std::string &address, int port = 3883, bool shutup = false);
    Skeleton(const char *name, const char *address, int port = 3883, bool shutup = false);
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
    const bool refreshed() const;

public:
    void refresh();

private:
    void initSkeleton();

private:
    std::vector<Joint> _currentJoints;
    std::vector<Joint> _previousJoints;
    vrpn_Tracker_Remote *_remote;
    bool _refreshed;

    friend void VRPN_CALLBACK handleTrackerPositionInput(void*, const vrpn_TRACKERCB);
    friend void VRPN_CALLBACK handleTrackerVelocityInput(void*, const vrpn_TRACKERVELCB);
    friend void VRPN_CALLBACK handleTrackerAccelerationInput(void*, const vrpn_TRACKERACCCB);
};

#include "Skeleton.inl.hpp"

#endif
