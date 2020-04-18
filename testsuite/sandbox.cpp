#include "optics/geometry/ray.hpp"
#include "optics/unit.hpp"

#include <cmath>

int main()
{
    Unit::Phase phi = 0.0_rad;
    Unit::Length x = 0.1_um;

    double a = Unit::sin(phi);

    return 0;
}
