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
    /**
     * @brief Set the minimal distance when the action is performed
     * @return The instance modified
     */
    Action *distance(const double &value);

    /**
     * @brief Set the minimal velocity when the action is performed
     * @return The instance modified
     */
    Action *velocity(const double &speed);

    /**
    * @brief Set the minimal acceleration when the action is performed
    * @return The instance modified
    */
    Action *acceleration(const double &acceleration);

public:
    /**
     * @brief Tells if the action has been performed by the skeleton
     *
     * Checks if the joints of the provided list have the minimal distance, the minimal velocity and the minimal acceleration
     * to says that the action is performed.
     *
     * @param joints: the list of the joints which are supposed to perform the action. Must be of two elements
     * @return true if the action is performed, false otherwise
     */
    bool performed(const std::vector<Skeleton::Joint> &joints) const;

private:
    double _distance;
    double _velocity;
    double _acceleration;
};

#include "Action.inl.hpp"

#endif
