#include <cassert>
#include <cmath>

#include <Box.hpp>

Box::Box(const std::vector<double> &center, const double &width, const double &height, const double &depth) : _width(width), _height(height), _depth(depth) {
    assert(center.size() == 3);

    _center = center;
}

bool Box::in(const std::vector<double> &pt) const {
    assert(pt.size() == 3);

    if (_width < std::numeric_limits<double>::infinity()) {
        double half(_width / 2.);

        if (_center[0] - half > pt[0] || pt[0] > _center[0] + half)
            return false;
    }

    if (_height < std::numeric_limits<double>::infinity()) {
        double half(_height / 2.);

        if (_center[1] - half > pt[1] || pt[1] > _center[1] + half)
            return false;
    }

    if (_depth < std::numeric_limits<double>::infinity()) {
        double half(_depth / 2.);

        if (_center[2] - half > pt[2] || pt[2] > _center[2] + half)
            return false;
    }

    return true;
}

bool Box::in(const double *pt) const {
    if (_width < std::numeric_limits<double>::infinity()) {
        double half(_width / 2.);

        if (_center[0] - half > pt[0] || pt[0] > _center[0] + half)
            return false;
    }

    if (_height < std::numeric_limits<double>::infinity()) {
        double half(_height / 2.);

        if (_center[1] - half > pt[1] || pt[1] > _center[1] + half)
            return false;
    }

    if (_depth < std::numeric_limits<double>::infinity()) {
        double half(_depth / 2.);

        if (_center[2] - half > pt[2] || pt[2] > _center[2] + half)
            return false;
    }

    return true;
}
