#ifndef BOX_HPP
#define BOX_HPP

#include <limits>
#include <vector>

class Box {
public:
    Box();
    Box(
        const std::vector<double> &center,
        const double &width = std::numeric_limits<double>::infinity(),
        const double &height = std::numeric_limits<double>::infinity(),
        const double &depth = std::numeric_limits<double>::infinity()
    );
    ~Box();

public:
    void operator=(const Box &parent);

public:
    const double &width() const;
    const double &height() const;
    const double &depth() const;

public:
    Box *width(const double &value);
    Box *height(const double &value);
    Box *depth(const double &value);

public:
    bool in(const std::vector<double> &pt) const;
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
    if (value >= 0.)
        _width = value;

    return this;
}

inline Box *Box::height(const double &value) {
    if (value >= 0.)
        _height = value;

    return this;
}

inline Box *Box::depth(const double &value) {
    if (value >= 0.)
        _depth = value;

    return this;
}

#endif
