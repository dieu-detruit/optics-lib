#pragma once

#include <boost/units/io.hpp>
#include <boost/units/systems/si.hpp>

#include "optics/unit/quantity.hpp"

inline namespace Unit
{

namespace SI
{

#define DECLARE_CONST_IMPL(dim, name, constant) inline const dim& name = constant;

#define DECLARE_CONST(dim, name, constant)                  \
    DECLARE_CONST_IMPL(dim, micro##name, 1.0e-6 * constant) \
    DECLARE_CONST_IMPL(dim, milli##name, 1.0e-3 * constant) \
    DECLARE_CONST_IMPL(dim, name, 1.0 * constant)           \
    DECLARE_CONST_IMPL(dim, killo##name, 1.0e+3 * constant) \
    DECLARE_CONST_IMPL(dim, mega##name, 1.0e+6 * constant)


// Unit Constants
DECLARE_CONST(Length, meter, boost::units::si::meter)
DECLARE_CONST(Time, second, boost::units::si::second)
DECLARE_CONST(Angle, radian, 1.0)
DECLARE_CONST(Power, watt, boost::units::si::watt)
DECLARE_CONST(Energy, joule, boost::units::si::joule)
DECLARE_CONST(Frequency, hertz, boost::units::si::hertz)

}  // namespace SI

}  // namespace Unit
