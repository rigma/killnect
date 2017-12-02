#ifndef DETECTION_BOX_HPP
#define DETECTION_BOX_HPP

#include <string>
#include <vector>

#include "Box.hpp"
#include "Detection.hpp"

/**
* @class DetectionBox
* @brief Represents the configuration of a detection box
*/
class DetectionBox : public Detection {
public:
    DetectionBox();
    DetectionBox(const std::string &name, const std::vector<std::string> &joints, const Box &box);
    DetectionBox(const DetectionBox &parent);

public:
    void sendSignal(const std::vector<std::string> &joints, const Skeleton *skeleton = nullptr) const;

public:
    const Box &box() const;

public:
    Box &box();

private:
    Box _box;
};

#include "DetectionBox.inl.hpp"

#endif
