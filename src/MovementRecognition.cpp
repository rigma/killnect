#include <MovementRecognition.hpp>

MovementRecognition::MovementRecognition(Skeleton *skeleton) : _detectionBoxes(), _actions() {
    if (skeleton != nullptr)
        _skeleton = skeleton;
}

MovementRecognition::~MovementRecognition() {
    _detectionBoxes.clear();
    _actions.clear();
}

void MovementRecognition::launchRecognition(bool refreshSkeleton) {
    if (refreshSkeleton)
        _skeleton->refresh();

    for (std::pair<const std::string, MovementRecognition::DetectionBox> &pair : _detectionBoxes) {
        std::vector<std::string> detectedJoints;
        pair.second.active = false;

        for (const std::string &joint : pair.second.joints) {
            if (pair.second.box.in((*_skeleton)(joint).pos))
                detectedJoints.push_back(joint);
        }

        if (detectedJoints.size() > 0) {
            pair.second.sig(pair.first, detectedJoints, _skeleton);
            pair.second.active = true;
        }
    }

    for (std::pair<const std::string, DetectionAction> &pair : _actions) {
        std::vector<Skeleton::Joint> joints;

        for (const std::string &joint : pair.second.joints)
            joints.push_back((*_skeleton)(joint));

        if (pair.second.action.performed(joints))
            pair.second.sig(pair.first, pair.second.joints, nullptr);
    }
}

void MovementRecognition::addDetectionBox(const std::string &name, const std::vector<std::string> &joints, const Box &box, DetectionCallback cb) {
    _detectionBoxes[name].joints = joints;
    _detectionBoxes[name].box = box;
    _detectionBoxes[name].active = false;

    _detectionBoxes[name].sig.connect(cb);
}

void MovementRecognition::addDetectionBox(const std::string &name, const std::string &joint, const Box &box, DetectionCallback cb) {
    _detectionBoxes[name].joints = std::vector<std::string>(1);
    _detectionBoxes[name].joints[0] = joint;
    _detectionBoxes[name].box = box;
    _detectionBoxes[name].active = false;

    _detectionBoxes[name].sig.connect(cb);
}

void MovementRecognition::addDetectionBox(const char *name, const std::vector<const char*> &joints, const Box &box, DetectionCallback cb) {
    _detectionBoxes[name].joints = std::vector<std::string>(joints.size());
    for (size_t i(0); i < joints.size(); ++i)
        _detectionBoxes[name].joints[i] = joints[i];

    _detectionBoxes[name].box = box;
    _detectionBoxes[name].active = false;

    _detectionBoxes[name].sig.connect(cb);
}

void MovementRecognition::addDetectionBox(const char *name, const char *joint, const Box &box, DetectionCallback cb) {
    _detectionBoxes[name].joints = std::vector<std::string>(1);
    _detectionBoxes[name].joints[0] = joint;
    _detectionBoxes[name].box = box;
    _detectionBoxes[name].active = false;

    _detectionBoxes[name].sig.connect(cb);
}

const MovementRecognition::DetectionBox &MovementRecognition::detectionBox(const std::string &name) const {
    return _detectionBoxes.at(name);
}

const MovementRecognition::DetectionBox &MovementRecognition::detectionBox(const char *name) const {
    return _detectionBoxes.at(name);
}

void MovementRecognition::addAction(const std::string &name, const std::vector<std::string> &joints, const Action &action, DetectionCallback cb) {
    _actions[name].joints = joints;
    _actions[name].action = action;

    _actions[name].sig.connect(cb);
}

void MovementRecognition::addAction(const char *name, const std::vector<const char*> &joints, const Action &action, DetectionCallback cb) {
    _actions[name].joints = std::vector<std::string>(joints.size());
    for (size_t i(0); i < joints.size(); ++i)
        _actions[name].joints[i] = joints[i];

    _actions[name].action = action;

    _actions[name].sig.connect(cb);
}

const MovementRecognition::DetectionAction &MovementRecognition::action(const std::string &name) const {
    return _actions.at(name);
}

const MovementRecognition::DetectionAction &MovementRecognition::action(const char *name) const {
    return _actions.at(name);
}
