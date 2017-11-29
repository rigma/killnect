#ifndef MOVEMENT_RECOGNITION_HPP
#define MOVEMENT_RECOGNITION_HPP

#include <map>
#include <vector>

#include "Action.hpp"
#include "Box.hpp"
#include "Skeleton.hpp"

class MovementRecognition {
public:
    typedef void(*DetectionBoxCallback)(const std::string&, const std::vector<std::string>&);
    typedef void(*ActionCallback)(const std::string&);

public:
    MovementRecognition(Skeleton *skeleton);
    ~MovementRecognition();

public:
    void launchRecognition(bool refreshSkeleton = false) const;

public:
    void addDetectionBox(const std::string &name, const std::vector<std::string> &joints, const Box &box, DetectionBoxCallback cb);
    void addDetectionBox(const std::string &name, const std::string &joint, const Box &box, DetectionBoxCallback cb);
    void addDetectionBox(const char *name, const std::vector<const char*> &joints, const Box &box, DetectionBoxCallback cb);
    void addDetectionBox(const char *name, const char *joint, const Box &box, DetectionBoxCallback cb);

public:
    void addAction(const std::string &name, const std::vector<std::string> &joints, const Action &action, ActionCallback cb);
    void addAction(const char *name, const std::vector<const char*> &joints, const Action &action, ActionCallback cb);

private:
    struct DetectionBox {
        std::vector<std::string> joints;
        Box box;
        DetectionBoxCallback cb;
    };

    struct DetectionAction {
        std::vector<std::string> joints;
        Action action;
        ActionCallback cb;
    };

private:
    std::map<std::string, DetectionBox> _detectionBoxes;
    std::map<std::string, DetectionAction> _actions;
    Skeleton *_skeleton;
};

#endif
