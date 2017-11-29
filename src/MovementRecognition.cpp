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

    for (const std::pair<std::string, MovementRecognition::DetectionBox> &pair : _detectionBoxes) {
        std::vector<std::string> detectedJoints;

        for (const std::string &joint : pair.second.joints) {
            if (pair.second.box.in((*_skeleton)(joint).pos))
                detectedJoints.push_back(joint);
        }

        if (detectedJoints.size() > 0)
            pair.second.cb(pair.first, detectedJoints);
    }

    for (const std::pair<std::string, MovementRecognition::DetectionAction> &pair : _actions) {
        std::vector<Skeleton::Joint> joints;

        for (const std::string &joint : pair.second.joints)
            joints.push_back((*_skeleton)(joint));

        if (pair.second.action.performed(joints))
            pair.second.cb(pair.first);
    }
}

void MovementRecognition::addDetectionBox(const std::string &name, const std::vector<std::string> &joints, const Box &box, MovementRecognition::DetectionBoxCallback cb) {
    MovementRecognition::DetectionBox detectionBox;
    detectionBox.joints = joints;
    detectionBox.box = box;
    detectionBox.cb = cb;

    _detectionBoxes[name] = detectionBox;
}

void MovementRecognition::addDetectionBox(const std::string &name, const std::string &joint, const Box &box, MovementRecognition::DetectionBoxCallback cb) {
    MovementRecognition::DetectionBox detectionBox;
    detectionBox.joints = std::vector<std::string>(1);
    detectionBox.joints[0] = joint;
    detectionBox.box = box;
    detectionBox.cb = cb;

    _detectionBoxes[name] = detectionBox;
}

void MovementRecognition::addDetectionBox(const char *name, const std::vector<const char*> &joints, const Box &box, MovementRecognition::DetectionBoxCallback cb) {
    MovementRecognition::DetectionBox detectionBox;
    detectionBox.joints = std::vector<std::string>(joints.size());
    detectionBox.box = box;
    detectionBox.cb = cb;

    for (size_t i(0); i < joints.size(); ++i)
        detectionBox.joints[i] = std::string(joints[i]);

    _detectionBoxes[std::string(name)] = detectionBox;
}

void MovementRecognition::addDetectionBox(const char *name, const char *joint, const Box &box, MovementRecognition::DetectionBoxCallback cb) {
    MovementRecognition::DetectionBox detectionBox;
    detectionBox.joints = std::vector<std::string>(1);
    detectionBox.joints[0] = joint;
    detectionBox.box = box;
    detectionBox.cb = cb;

    _detectionBoxes[name] = detectionBox;
}

void MovementRecognition::addAction(const std::string &name, const std::vector<std::string> &joints, const Action &action, MovementRecognition::ActionCallback cb) {
    MovementRecognition::DetectionAction detectionAction;
    detectionAction.joints = joints;
    detectionAction.action = action;
    detectionAction.cb = cb;

    _actions[name] = detectionAction;
}

void MovementRecognition::addAction(const char *name, const std::vector<const char*> &joints, const Action &action, MovementRecognition::ActionCallback cb) {
    MovementRecognition::DetectionAction detectionAction;
    detectionAction.joints = std::vector<std::string>(joints.size());
    detectionAction.action = action;
    detectionAction.cb = cb;

    for (size_t i(0); i < joints.size(); ++i)
        detectionAction.joints[i] = std::string(joints[i]);

    _actions[std::string(name)] = detectionAction;
}
