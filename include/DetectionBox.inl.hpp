#ifndef DETECTION_BOX_INL_HPP
#define DETECTION_BOX_INL_HPP

inline DetectionBox::DetectionBox() : Detection(), _box() {}

inline DetectionBox::DetectionBox(const std::string &name, const std::vector<std::string> &joints, const Box &box) : Detection(name, joints), _box(box) {}

inline DetectionBox::DetectionBox(const DetectionBox &parent) : Detection(parent._name, parent._joints), _box(parent._box) {}

inline void DetectionBox::sendSignal(const std::vector<std::string> &joints, const Skeleton *skeleton) const {
    _sig(_name, joints, skeleton);
}

inline const Box &DetectionBox::box() const {
    return _box;
}

inline Box &DetectionBox::box() {
    return _box;
}

#endif
