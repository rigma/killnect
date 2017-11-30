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
     * @param velocity: the velocity of the joints during the action
     * @param acceleration: the acceleration of the joints during the action
     */
    Action(const double &distance = std::numeric_limits<double>::epsilon(), const double &velocity = 0., const double &acceleration = 0.);

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
    const double &velocity() const;

    /**
     * @brief Returns the acceleration of the joints
     * @return The acceleration of the joints during the action
     */
    const double &acceleration() const;

public:
    Action *distance(const double &value);
    Action *velocity(const double &speed);
    Action *acceleration(const double &acceleration);

public:
    bool performed(const std::vector<Skeleton::Joint> &joints) const;

private:
    double _distance;
    double _velocity;
    double _acceleration;
};

#include "Action.inl.hpp"

#endif
