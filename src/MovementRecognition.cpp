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

    for (auto &detectionBox : _detectionBoxes) {
        std::vector<std::string> detectedJoints;
        detectionBox.active() = false;

        for (const std::string &joint : detectionBox.joints()) {
            if (detectionBox.box().in((*_skeleton)(joint).pos))
                detectedJoints.push_back(joint);
        }

        if (detectedJoints.size() > 0) {
            detectionBox.active() = true;
            detectionBox.sendSignal(detectedJoints, _skeleton);
        }
    }

    for (auto &action : _actions) {
        std::vector<Skeleton::Joint> joints;

        for (const std::string &joint : action.joints())
            joints.push_back((*_skeleton)(joint));

        if (action.action().performed(joints))
            action.sendSignal(action.joints());
    }
}

void MovementRecognition::addDetectionBox(const std::string &name, const std::vector<std::string> &joints, const Box &box, Detection::Callback cb) {
    DetectionBox detectionBox(name, joints, box);
    detectionBox.connect(cb);

    _detectionBoxes.push_back(detectionBox);
}

void MovementRecognition::addDetectionBox(const std::string &name, const std::string &joint, const Box &box, Detection::Callback cb) {
    std::vector<std::string> joints(1);
    joints[0] = joint;

    DetectionBox detectionBox(name, joints, box);
    detectionBox.connect(cb);

    _detectionBoxes.push_back(detectionBox);
}

void MovementRecognition::addDetectionBox(const char *name, const std::vector<const char*> &joints, const Box &box, Detection::Callback cb) {
    std::vector<std::string> jts(joints.size());
    for (size_t i(0); i < joints.size(); ++i)
        jts[i] = joints[i];

    DetectionBox detectionBox(name, jts, box);
    detectionBox.connect(cb);

    _detectionBoxes.push_back(detectionBox);
}

void MovementRecognition::addDetectionBox(const char *name, const char *joint, const Box &box, Detection::Callback cb) {
    std::vector<std::string> joints(1);
    joints[0] = std::string(joint);

    DetectionBox detectionBox(name, joints, box);
    detectionBox.connect(cb);

    _detectionBoxes.push_back(detectionBox);
}

DetectionBox &MovementRecognition::detectionBox(const std::string &name) {
    for (auto &box : _detectionBoxes) {
        if (box.name() == name)
            return box;
    }

    return *_detectionBoxes.begin();
}

DetectionBox &MovementRecognition::detectionBox(const char *name) {
    for (auto &box : _detectionBoxes) {
        if (box.name() == name)
            return box;
    }

    return *_detectionBoxes.begin();
}

void MovementRecognition::addAction(const std::string &name, const std::vector<std::string> &joints, const Action &action, Detection::Callback cb) {
    DetectionAction detectionAction(name, joints, action);
    detectionAction.connect(cb);

    _actions.push_back(detectionAction);
}

void MovementRecognition::addAction(const char *name, const std::vector<const char*> &joints, const Action &action, Detection::Callback cb) {
    std::vector<std::string> jts(joints.size());
    for (size_t i(0); i < joints.size(); ++i)
        jts[i] = std::string(joints[i]);

    DetectionAction detectionAction(name, jts, action);
    detectionAction.connect(cb);

    _actions.push_back(detectionAction);
}

DetectionAction &MovementRecognition::action(const std::string &name) {
    for (auto &action : _actions) {
        if (action.name() == name)
            return action;
    }

    return *_actions.begin();
}

DetectionAction &MovementRecognition::action(const char *name) {
    for (auto &action : _actions) {
        if (action.name() == name)
            return action;
    }

    return *_actions.begin();
}
