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
