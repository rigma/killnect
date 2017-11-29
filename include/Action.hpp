/**
* @file Action.hpp
* @brief Recognizable action
* @author Romain Failla
* @version 1.0
*/

#ifndef ACTION_HPP
#define ACTION_HPP

#include <limits>

#include "Skeleton.hpp"

/**
 * @class Action
 * @brief Represents the parameters of an action performed by a user
 */
class Action {
public:
    /**
     * @brief Constructor
     *
     * Default constructor
     *
     * @param distance: the distance between the joints during the action
     * @param speed: the speed of the joints during the action
     * @param acceleration: the acceleration of the joints during the action
     */
    Action(const double &distance = std::numeric_limits<double>::epsilon(), const double &speed = 0., const double &acceleration = 0.);

public:
    /**
     * @brief Returns the distance between the joints
     * @return The distance between the joints during the action
     */
    const double &distance() const;

    /**
     * @brief Returns the speed of the joints
     * @return The speed of the joints during the action
     */
    const double &speed() const;

    /**
     * @brief Returns the acceleration of the joints
     * @return The acceleration of the joints during the action
     */
    const double &acceleration() const;

public:
    Action *distance(const double &value);
    Action *speed(const double &speed);
    Action *acceleration(const double &acceleration);

public:
    bool performed(const std::vector<Skeleton::Joint> &joints) const;

private:
    double _distance;
    double _speed;
    double _acceleration;
};

inline Action::Action(const double &distance, const double &speed, const double &acceleration) : _distance(distance),
    _speed(speed),
    _acceleration(acceleration) {}

inline const double &Action::distance() const {
    return _distance;
}

inline const double &Action::speed() const {
    return _speed;
}

inline const double &Action::acceleration() const {
    return _acceleration;
}

inline Action *Action::distance(const double &value) {
    if (value >= 0.) {
        _distance = value;

        return this;
    }

    return nullptr;
}

inline Action *Action::speed(const double &value) {
    if (value >= 0.) {
        _speed = value;

        return this;
    }

    return nullptr;
}

inline Action *Action::acceleration(const double &value) {
    if (value >= 0.) {
        _acceleration = value;

        return this;
    }

    return nullptr;
}

#endif
