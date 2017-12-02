#ifndef DETECTION_HPP
#define DETECTION_HPP

#include <boost/signals2/signal.hpp>
#include <string>
#include <vector>

#include "Skeleton.hpp"

/**
* @class Detection
* @brief Represents a configuration for a detection configuration
*/
class Detection {
public:
    Detection();
    Detection(const std::string &name, const std::vector<std::string> &joints);
    virtual ~Detection();

public:
    virtual void sendSignal(const std::vector<std::string> &joints, const Skeleton *skeleton = nullptr) const = 0;

public:
    const boost::signals2::signal<void(const std::string&, const std::vector<std::string>&, const Skeleton*)> &signal() const;
    const std::vector<std::string> &joints() const;
    const std::string &name() const;
    const bool &active() const;

public:
    boost::signals2::signal<void(const std::string&, const std::vector<std::string>&, const Skeleton*)> &signal();
    std::vector<std::string> &joints();
    std::string &name();
    bool &active();

protected:
    boost::signals2::signal<void(const std::string&, const std::vector<std::string>&, const Skeleton*)> _sig;
    std::vector<std::string> _joints;
    std::string _name;
    bool _active;
};

#include "Detection.inl.hpp"

#endif
