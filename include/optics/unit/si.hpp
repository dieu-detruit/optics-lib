#pragma once

#include <boost/units/io.hpp>
#include <boost/units/systems/si.hpp>

#include "optics/unit/quantity.hpp"

inline namespace Unit
{

namespace SI
{

// Unit Constants
inline const Length& meter = 1.0 * boost::units::si::meter;
inline const Length& millimeter = 1.0e-3 * boost::units::si::meter;
inline const Time& second = 1.0 * boost::units::si::second;
inline const Time& millisecond = 1.0e-3 * boost::units::si::second;
inline const Time& microsecond = 1.0e-6 * boost::units::si::second;
inline const Angular& radian = 1.0;
inline const Angular& milliradian = 1.0e-3 * radian;
inline const Power& watt = 1.0 * boost::units::si::watt;

}  // namespace SI

}  // namespace Unit
