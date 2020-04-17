#pragma once

#include <Eigen/Core>

#include "optics/geometry/ray.hpp"
#include "optics/unit.hpp"

namespace Optics::Wave
{

template <class power_type = Irradiance>
struct Ray : public Geometry::Ray<power_type> {
    Phase phase;
};


}  // namespace Optics::Wave
