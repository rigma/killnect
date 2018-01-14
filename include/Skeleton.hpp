/**
 * @file Skeleton.hpp
 * @brief Kinect skeleton management
 * @author Romain Failla
 * @version 1.2
 */

#ifndef SKELETON_HPP
#define SKELETON_HPP

#include <vrpn/vrpn_Tracker.h>
#include <string>
#include <vector>

/**
 * @class Skeleton
 * @brief User skeleton
 * 
 * Representation of the Player skeleton of a Kinect user provided by Faast
 */
class Skeleton {
public:
    /**
     * @struct Skeleton::Joint
     * @brief Representation of a skeleton joint
     */
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
    /**
     * @brief Constructor
     *
     * @param name: the name of the player to retrieve
     * @param address: the address of the FAAST server
     * @param port: the emitting port of the FAAST server
     * @param shutup: if true, then no error messages will be displayed
     */
    Skeleton(const std::string &name, const std::string &address, int port = 3883, bool shutup = false);
    
    /**
     * @brief Constructor
     *
     * @param name: the name of the player to retrieve
     * @param address: the address of the FAAST server
     * @param port: the emitting port of the FAAST server
     * @param shutup: if true, then no error messages will be displayed
     */
    Skeleton(const char *name, const char *address, int port = 3883, bool shutup = false);

    /**
     * @brief Destructor
     */
    ~Skeleton();

public:
    /**
     * @brief Retrieve a skeleton joint with its name
     * @param jointName: the name of the joint to retrieve
     * @return A reference to the selected joint
     */
    const Joint &operator()(const char *jointName) const;
    
    /**
     * @brief Retrieve a skeleton joint with its name
     * @param jointName: the name of the joint to retrieve
     * @return A reference to the selected joint
     */
    const Joint &operator()(const std::string &jointName) const;

public:
    /**
     * @brief Retrieve all the joints of the skeleton
     * @return A vector of all skeleton joints
     */
    const std::vector<Joint> &joints() const;

    /**
     * @brief Return the Ankle Left joint
     * @return A reference to the joint
     */
    const Joint &ankleLeft() const;
    
    /**
     * @brief Return the Ankle Right joint
     * @return A reference to the joint
     */
    const Joint &ankleRight() const;

    /**
     * @brief Return the Elbow Left joint
     * @return A reference to the joint
     */
    const Joint &elbowLeft() const;

    /**
     * @brief Return the Elbow Right joint
     * @return A reference to the joint
     */
    const Joint &elbowRight() const;

    /**
     * @brief Return the Foot Left joint
     * @return A reference to the joint
     */
    const Joint &footLeft() const;

    /**
     * @brief Return the Foot Right joint
     * @return A reference to the joint
     */
    const Joint &footRight() const;

    /**
     * @brief Return the Hand Left joint
     * @return A reference to the joint
     */
    const Joint &handLeft() const;

    /**
     * @brief Return the Hand Right joint
     * @return A reference to the joint
     */
    const Joint &handRight() const;

    /**
     * @brief Return the Hand Tip Left joint
     * @return A reference to the joint
     */
    const Joint &handTipLeft() const;

    /**
     * @brief Return the Hand Tip Right joint
     * @return A reference to the joint
     */
    const Joint &handTipRight() const;

    /**
     * @brief Return the Head joint
     * @return A reference to the joint
     */
    const Joint &head() const;

    /**
     * @brief Return the Hip Left joint
     * @return A reference to the joint
     */
    const Joint &hipLeft() const;

    /**
     * @brief Return the Hip Right joint
     * @return A reference to the joint
     */
    const Joint &hipRight() const;

    /**
     * @brief Return the Knee Left joint
     * @return A reference to the joint
     */
    const Joint &kneeLeft() const;

    /**
     * @brief Return the Knee Right joint
     * @return A reference to the joint
     */
    const Joint &kneeRight() const;

    /**
     * @brief Return the Neck joint
     * @return A reference to the joint
     */
    const Joint &neck() const;

    /**
     * @brief Return the Shoulder Left joint
     * @return A reference to the joint
     */
    const Joint &shoulderLeft() const;

    /**
     * @brief Return the Shoulder Right joint
     * @return A reference to the joint
     */
    const Joint &shoulderRight() const;

    /**
     * @brief Return the Spine Base joint
     * @return A reference to the joint
     */
    const Joint &spineBase() const;

    /**
     * @brief Return the Spine Middle joint
     * @return A reference to the joint
     */
    const Joint &spineMiddle() const;

    /**
     * @brief Return the Spine Shoulder joint
     * @return A reference to the joint
     */
    const Joint &spineShoulder() const;

    /**
     * @brief Return the Thumb Left joint
     * @return A reference to the joint
     */
    const Joint &thumbLeft() const;

    /**
     * @brief Return the Thumb Right joint
     * @return A reference to the joint
     */
    const Joint &thumbRight() const;

    /**
     * @brief Return the Wrist Left joint
     * @return A reference to the joint
     */
    const Joint &wristLeft() const;

    /**
     * @brief Return the Wrist Right joint
     * @return A reference to the joint
     */
    const Joint &wristRight() const;

    /**
     * @brief Tell if the skeleton was refreshed
     * @return true if the skeleton were refreshed, false otherwise
     */
    const bool refreshed() const;

public:
    /**
     * @brief Refresh the skeleton
     *
     * Retrieve the last known informations of the skeleton tracked from the FAAST server
     */
    void refresh();

private:
    /**
     * @brief Initialize all the joints of the tracked skeleton
     */
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
