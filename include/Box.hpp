/**
 * @file Box.hpp
 * @brief Define 3D box which is able to test if a point is in it
 * @author Romain Failla
 * @version 1.0
 */

#ifndef BOX_HPP
#define BOX_HPP

#include <limits>
#include <vector>

/**
 * @class Box
 * @brief Class representing a 3D box in space
 *
 * This class allows to modelize a box into a 3D space and to tell if a point is in it or not
 */
class Box {
public:
    /**
     * @brief Constructor
     *
     * Default constructor of the class
     *
     * @param x: the abscissa of the center
     * @param y: the ordinate of the center
     * @param z: the depth of the center
     * @param width: the width of the box
     * @param height: the height of the box
     * @param depth: the depth of the box
     */
    Box(
        const double &x = 0.,
        const double &y = 0.,
        const double &z = 0.,
        const double &width = std::numeric_limits<double>::infinity(),
        const double &height = std::numeric_limits<double>::infinity(),
        const double &depth = std::numeric_limits<double>::infinity()
    );

    /**
     * @brief Constructor
     * 
     * General constructor of the class
     *
     * @param center: the center of the 3D box
     * @param width: the width of the 3D box
     * @param height: the height of the 3D box
     * @param depth: the depth of the 3D box
     */
    Box(
        const std::vector<double> &center,
        const double &width = std::numeric_limits<double>::infinity(),
        const double &height = std::numeric_limits<double>::infinity(),
        const double &depth = std::numeric_limits<double>::infinity()
    );

    /**
     * @brief Destructor
     *
     * Destructor of the class
     */
    ~Box();

public:
    /**
     * @brief Affectation operator
     *
     * Copy the attributes of another box instance into this one
     *
     * @param parent: the Box instance copied
     */
    void operator=(const Box &parent);

public:
    /**
     * @brief Width of the box
     *
     * Returns the width of the box
     *
     * @return the with of the instance
     */
    const double &width() const;

    /**
     * @brief Height of the box
     *
     * Returns the height of the box
     *
     * @return the height of the instance
     */
    const double &height() const;

    /**
     * @brief Depth of the box
     *
     * Returns the depth of the box
     *
     * @return the depth of the instance
     */
    const double &depth() const;

public:
    /**
     * @brief Set the width
     *
     * Set the width of the box
     *
     * @param value: the new width of the box
     * @return the reference of the instance if success, nullptr instead
     */
    Box *width(const double &value);

    /**
    * @brief Set the height
    *
    * Set the height of the box
    *
    * @param value: the new height of the box
    * @return the reference of the instance if success, nullptr instead
    */
    Box *height(const double &value);

    /**
    * @brief Set the depth
    *
    * Set the depth of the box
    *
    * @param value: the new depth of the box
    * @return the reference of the instance if success, nullptr instead
    */
    Box *depth(const double &value);

public:
    /**
     * @brief Point in the box?
     *
     * Tell if a point is in the box
     *
     * @param pt: the vector-point to test
     * @return true if pt is in the box, false instead
     */
    bool in(const std::vector<double> &pt) const;
    
    /**
    * @brief Point in the box?
    *
    * Tell if a point is in the box
    *
    * @param pt: the vector-point to test
    * @return true if pt is in the box, false instead
    */
    bool in(const double *pt) const;

private:
    std::vector<double> _center;
    double _width;
    double _height;
    double _depth;
};

inline Box::~Box() {}

inline void Box::operator=(const Box &parent) {
    _center = parent._center;
    _width = parent._width;
    _height = parent._height;
    _depth = parent._depth;
}

inline const double &Box::width() const {
    return _width;
}

inline const double &Box::height() const {
    return _height;
}

inline const double &Box::depth() const {
    return _depth;
}

inline Box *Box::width(const double &value) {
    if (value >= 0.) {
        _width = value;

        return this;
    }

    return nullptr;
}

inline Box *Box::height(const double &value) {
    if (value >= 0.) {
        _height = value;

        return this;
    }

    return nullptr;
}

inline Box *Box::depth(const double &value) {
    if (value >= 0.) {
        _depth = value;

        return this;
    }

    return nullptr;
}

#endif
