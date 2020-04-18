#pragma once

#include <Eigen/Core>

#include "optics/unit.hpp"

namespace Optics::Geometry
{

template <class power_type = Unit::Irradiance>
struct Ray {
    Eigen::Vector3d source;  // unit: mm
    Eigen::Vector3d dir;     // unit: /
    power_type I;
};


}  // namespace Optics::Geometry
