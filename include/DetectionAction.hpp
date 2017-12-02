#ifndef DETECTION_ACTION_HPP
#define DETECTION_ACTION_HPP

#include <string>
#include <vector>

#include "Action.hpp"
#include "Detection.hpp"

/**
* @class DetectionAction
* @brief Represents the configuration of a recognizable action
*/
class DetectionAction : public Detection {
public:
    DetectionAction();
    DetectionAction(const std::string &name, const std::vector<std::string> &joints, const Action &action);
    DetectionAction(const DetectionAction &parent);

public:
    void sendSignal(const std::vector<std::string> &joints, const Skeleton *skeleton = nullptr) const;

public:
    const Action &action() const;

public:
    Action &action();

private:
    Action _action;
};

#include "DetectionAction.inl.hpp"

#endif 

