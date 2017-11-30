inline const vrpn_float64 Skeleton::Joint::velocity(bool squared) const {
    vrpn_float64 v(0.);

    for (std::uint8_t i(0); i < 3; ++i)
        v += vel[i] * vel[i];

    if (!squared)
        v = std::sqrt(v);

    return v;
}

inline const vrpn_float64 Skeleton::Joint::acceleration(bool squared) const {
    vrpn_float64 a(0.);

    for (std::uint8_t i(0); i < 3; ++i)
        a += acc[i] * acc[i];

    if (!squared)
        a = std::sqrt(a);

    return a;
}

inline const std::vector<Skeleton::Joint> &Skeleton::joints() const {
    return _currentJoints;
}

inline const Skeleton::Joint &Skeleton::ankleLeft() const {
    return _currentJoints[14];
}

inline const Skeleton::Joint &Skeleton::ankleRight() const {
    return _currentJoints[18];
}

inline const Skeleton::Joint &Skeleton::elbowLeft() const {
    return _currentJoints[5];
}

inline const Skeleton::Joint &Skeleton::elbowRight() const {
    return _currentJoints[9];
}

inline const Skeleton::Joint &Skeleton::footLeft() const {
    return _currentJoints[15];
}

inline const Skeleton::Joint &Skeleton::footRight() const {
    return _currentJoints[19];
}

inline const Skeleton::Joint &Skeleton::handLeft() const {
    return _currentJoints[7];
}

inline const Skeleton::Joint &Skeleton::handRight() const {
    return _currentJoints[11];
}

inline const Skeleton::Joint &Skeleton::handTipLeft() const {
    return _currentJoints[21];
}

inline const Skeleton::Joint &Skeleton::handTipRight() const {
    return _currentJoints[23];
}

inline const Skeleton::Joint &Skeleton::head() const {
    return _currentJoints[3];
}

inline const Skeleton::Joint &Skeleton::hipLeft() const {
    return _currentJoints[12];
}

inline const Skeleton::Joint &Skeleton::hipRight() const {
    return _currentJoints[16];
}

inline const Skeleton::Joint &Skeleton::kneeLeft() const {
    return _currentJoints[13];
}

inline const Skeleton::Joint &Skeleton::kneeRight() const {
    return _currentJoints[17];
}

inline const Skeleton::Joint &Skeleton::neck() const {
    return _currentJoints[2];
}

inline const Skeleton::Joint &Skeleton::shoulderLeft() const {
    return _currentJoints[4];
}

inline const Skeleton::Joint &Skeleton::shoulderRight() const {
    return _currentJoints[8];
}

inline const Skeleton::Joint &Skeleton::spineBase() const {
    return _currentJoints[0];
}

inline const Skeleton::Joint &Skeleton::spineMiddle() const {
    return _currentJoints[1];
}

inline const Skeleton::Joint &Skeleton::spineShoulder() const {
    return _currentJoints[20];
}

inline const Skeleton::Joint &Skeleton::thumbLeft() const {
    return _currentJoints[22];
}

inline const Skeleton::Joint &Skeleton::thumbRight() const {
    return _currentJoints[24];
}

inline const Skeleton::Joint &Skeleton::wristLeft() const {
    return _currentJoints[6];
}

inline const Skeleton::Joint &Skeleton::wristRight() const {
    return _currentJoints[10];
}

inline const bool Skeleton::refreshed() const {
    return _refreshed;
}
