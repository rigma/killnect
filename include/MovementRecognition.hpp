#ifndef MOVEMENT_RECOGNITION_HPP
#define MOVEMENT_RECOGNITION_HPP

#include <map>
#include <vector>

#include "Box.hpp"
#include "Skeleton.hpp"

class MovementRecognition {
public:
    typedef void(*Callback)(const std::string&, const std::vector<std::string>&);

private:
    struct DetectionBox {
        std::vector<std::string> joints;
        Box box;
        Callback cb;
    };

public:
    MovementRecognition(Skeleton *skeleton);
    ~MovementRecognition();

public:
    void launchRecognition(bool refreshSkeleton = false) const;

public:
    void addDetectionBox(const std::string &name, const std::vector<std::string> &joints, const Box &box, Callback cb);
    void addDetectionBox(const std::string &name, const std::string &joint, const Box &box, Callback cb);
    void addDetectionBox(const char *name, const std::vector<const char*> &joints, const Box &box, Callback cb);
    void addDetectionBox(const char *name, const char *joint, const Box &box, Callback cb);

private:
    Skeleton *_skeleton;
    std::map<std::string, DetectionBox> _detectionBoxes;
};

#endif
