#include <vrpn/vrpn_Types.h>
#include <Action.hpp>

bool Action::performed(const std::vector<Skeleton::Joint> &joints) const {
    vrpn_float64 distance(0.);

    for (std::uint8_t i(0); i < 3; ++i)
        distance += (joints[0].pos[i] - joints[1].pos[i]) * (joints[0].pos[i] - joints[1].pos[i]);

    if (distance > _distance)
        return false;

    if ((*joints.begin()).speed < _speed && (*joints.end()).speed < _speed)
        return false;

    if ((*joints.begin()).acceleration < _acceleration && (*joints.end()).acceleration < _acceleration)
        return false;

    return true;
}
