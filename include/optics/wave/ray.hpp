#pragma once

#include <Eigen/Core>

#include "optics/geometry/ray.hpp"
#include "optics/unit.hpp"

namespace Optics::Wave
{

template <class power_type = Unit::Irradiance>
struct Ray : public Geometry::Ray<power_type> {
    Unit::Phase phase;
};


}  // namespace Optics::Wave
