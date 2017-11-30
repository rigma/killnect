#include <MovementRecognition.hpp>

MovementRecognition::MovementRecognition(Skeleton *skeleton) : _detectionBoxes(), _actions() {
    if (skeleton != nullptr)
        _skeleton = skeleton;
}

MovementRecognition::~MovementRecognition() {
    _detectionBoxes.clear();
    _actions.clear();
}

void MovementRecognition::launchRecognition(bool refreshSkeleton) const {
    if (refreshSkeleton)
        _skeleton->refresh();

    for (const auto &pair : _detectionBoxes) {
        std::vector<std::string> detectedJoints;

        for (const std::string &joint : pair.second.joints) {
            if (pair.second.box.in((*_skeleton)(joint).pos))
                detectedJoints.push_back(joint);
        }

        if (detectedJoints.size() > 0)
            pair.second.sig(pair.first, detectedJoints, _skeleton);
    }

    for (const auto &pair : _actions) {
        std::vector<Skeleton::Joint> joints;

        for (const std::string &joint : pair.second.joints)
            joints.push_back((*_skeleton)(joint));

        if (pair.second.action.performed(joints))
            pair.second.sig(pair.first);
    }
}

void MovementRecognition::addDetectionBox(const std::string &name, const std::vector<std::string> &joints, const Box &box, MovementRecognition::DetectionBoxCallback cb) {
    _detectionBoxes[name].joints = joints;
    _detectionBoxes[name].box = box;
    _detectionBoxes[name].sig.connect(cb);
}

void MovementRecognition::addDetectionBox(const std::string &name, const std::string &joint, const Box &box, MovementRecognition::DetectionBoxCallback cb) {
    MovementRecognition::DetectionBox detectionBox;
    _detectionBoxes[name].joints = std::vector<std::string>(1);
    _detectionBoxes[name].joints[0] = joint;
    _detectionBoxes[name].box = box;
    _detectionBoxes[name].sig.connect(cb);
}

void MovementRecognition::addDetectionBox(const char *name, const std::vector<const char*> &joints, const Box &box, MovementRecognition::DetectionBoxCallback cb) {
    _detectionBoxes[std::string(name)].joints = std::vector<std::string>(joints.size());
    _detectionBoxes[std::string(name)].box = box;
    _detectionBoxes[std::string(name)].sig.connect(cb);

    for (size_t i(0); i < joints.size(); ++i)
        _detectionBoxes[std::string(name)].joints[i] = std::string(joints[i]);
}

void MovementRecognition::addDetectionBox(const char *name, const char *joint, const Box &box, MovementRecognition::DetectionBoxCallback cb) {
    _detectionBoxes[std::string(name)].joints = std::vector<std::string>(1);
    _detectionBoxes[std::string(name)].joints[0] = joint;
    _detectionBoxes[std::string(name)].box = box;
    _detectionBoxes[std::string(name)].sig.connect(cb);
}

void MovementRecognition::addAction(const std::string &name, const std::vector<std::string> &joints, const Action &action, MovementRecognition::ActionCallback cb) {
    _actions[name].joints = joints;
    _actions[name].action = action;
    _actions[name].sig.connect(cb);
}

void MovementRecognition::addAction(const char *name, const std::vector<const char*> &joints, const Action &action, MovementRecognition::ActionCallback cb) {
    _actions[std::string(name)].joints = std::vector<std::string>(joints.size());
    _actions[std::string(name)].action = action;
    _actions[std::string(name)].sig.connect(cb);

    for (size_t i(0); i < joints.size(); ++i)
        _actions[std::string(name)].joints[i] = std::string(joints[i]);
}
