#ifndef DETECTION_ACTION_INL
#define DETECTION_ACTION_INL

inline DetectionAction::DetectionAction() : Detection(), _action() {}

inline DetectionAction::DetectionAction(const std::string &name, const std::vector<std::string> &joints, const Action &action) : Detection(name, joints), _action(action) {}

inline DetectionAction::DetectionAction(const DetectionAction &parent) : Detection(parent._name, parent._joints), _action(parent._action) {}

inline void DetectionAction::sendSignal(const std::vector<std::string> &joints, const Skeleton *skeleton) const {
    _sig(_name, joints, skeleton);
}

inline const Action &DetectionAction::action() const {
    return _action;
}

inline Action &DetectionAction::action() {
    return _action;
}

#endif
