#pragma once

#include <boost/units/io.hpp>
#include <boost/units/systems/si.hpp>

inline namespace Unit
{

using _value_type = double;

template <class D, class value_type = _value_type>
using unit_type = boost::units::quantity<D, value_type>;

// Unit Types
using Length = unit_type<boost::units::si::length, _value_type>;
using Vel = unit_type<boost::units::si::velocity, _value_type>;
using Acc = unit_type<boost::units::si::acceleration, _value_type>;
using Angle = _value_type;
using AngularVel = unit_type<boost::units::si::angular_velocity, _value_type>;
using AngularAcc = unit_type<boost::units::si::angular_acceleration, _value_type>;
using Time = unit_type<boost::units::si::time, _value_type>;
using Force = unit_type<boost::units::si::force, _value_type>;
using Mass = unit_type<boost::units::si::mass, _value_type>;
using Area = unit_type<boost::units::si::area, _value_type>;
using Power = unit_type<boost::units::si::power, _value_type>;
using Energy = unit_type<boost::units::si::energy, _value_type>;
using Frequency = unit_type<boost::units::si::frequency, _value_type>;
using Irradiance = decltype(Power{} / Area{});
using Phase = Angle;

}  // namespace Unit
