#include <MovementRecognition.hpp>

MovementRecognition::MovementRecognition(Skeleton *skeleton) : _detectionBoxes() {
    if (skeleton != nullptr)
        _skeleton = skeleton;
}

MovementRecognition::~MovementRecognition() {
    _detectionBoxes.clear();
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
}

void MovementRecognition::addDetectionBox(const std::string &name, const std::vector<std::string> &joints, const Box &box, MovementRecognition::Callback cb) {
    MovementRecognition::DetectionBox detectionBox;
    detectionBox.joints = joints;
    detectionBox.box = box;
    detectionBox.cb = cb;

    _detectionBoxes[name] = detectionBox;
}

void MovementRecognition::addDetectionBox(const std::string &name, const std::string &joint, const Box &box, MovementRecognition::Callback cb) {
    MovementRecognition::DetectionBox detectionBox;
    detectionBox.joints = std::vector<std::string>(1);
    detectionBox.joints[0] = joint;
    detectionBox.box = box;
    detectionBox.cb = cb;

    _detectionBoxes[name] = detectionBox;
}

void MovementRecognition::addDetectionBox(const char *name, const std::vector<const char*> &joints, const Box &box, MovementRecognition::Callback cb) {
    MovementRecognition::DetectionBox detectionBox;
    detectionBox.joints = std::vector<std::string>(joints.size());
    detectionBox.box = box;
    detectionBox.cb = cb;

    for (size_t i(0); i < joints.size(); ++i)
        detectionBox.joints[i] = std::string(joints[i]);

    _detectionBoxes[std::string(name)] = detectionBox;
}

void MovementRecognition::addDetectionBox(const char *name, const char *joint, const Box &box, MovementRecognition::Callback cb) {
    MovementRecognition::DetectionBox detectionBox;
    detectionBox.joints = std::vector<std::string>(1);
    detectionBox.joints[0] = joint;
    detectionBox.box = box;
    detectionBox.cb = cb;

    _detectionBoxes[name] = detectionBox;
}
