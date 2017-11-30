inline Action::Action(const double &distance, const double &velocity, const double &acceleration) : _distance(distance),
_velocity(velocity),
_acceleration(acceleration) {}

inline const double &Action::distance() const {
    return _distance;
}

inline const double &Action::velocity() const {
    return _velocity;
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

inline Action *Action::velocity(const double &value) {
    if (value >= 0.) {
        _velocity = value;

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
