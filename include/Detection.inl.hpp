#ifndef DETECTION_INL_HPP
#define DETECTION_INL_HPP

inline Detection::Detection() : _sig(), _name(), _joints(), _active(false) {}

inline Detection::Detection(const std::string &name, const std::vector<std::string> &joints) : _sig(), _joints(joints), _name(name), _active(false) {}

inline Detection::~Detection() {
    _joints.clear();
    _sig.disconnect_all_slots();
}

inline void Detection::connect(Detection::Callback cb) {
    _sig.connect(cb);
}

inline const boost::signals2::signal<void(const std::string&, const std::vector<std::string>&, const Skeleton*)> &Detection::signal() const {
    return _sig;
}

inline const std::vector<std::string> &Detection::joints() const {
    return _joints;
}

inline const std::string &Detection::name() const {
    return _name;
}

inline const bool &Detection::active() const {
    return _active;
}

inline boost::signals2::signal<void(const std::string&, const std::vector<std::string>&, const Skeleton*)> &Detection::signal() {
    return _sig;
}

inline std::vector<std::string> &Detection::joints() {
    return _joints;
}

inline std::string &Detection::name() {
    return _name;
}

inline bool &Detection::active() {
    return _active;
}

#endif
