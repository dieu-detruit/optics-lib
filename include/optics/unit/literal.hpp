#pragma once

#include <boost/units/io.hpp>
#include <boost/units/systems/si.hpp>

#include "optics/unit/literal.hpp"
#include "optics/unit/quantity.hpp"
#include "optics/unit/si.hpp"

inline namespace Unit
{

inline namespace SILiteral
{

template <class T>
struct value_type {
    using type = T;
};

template <class D, class T>
struct value_type<boost::units::quantity<D, T>> {
    using type = T;
};

#define DECLARE_LITERAL(unit_type, constant, literal)                        \
    inline unit_type operator""_##literal(long double value)                 \
    {                                                                        \
        return static_cast<value_type<unit_type>::type>(value) * (constant); \
    }

DECLARE_LITERAL(Length, SI::meter, m)
DECLARE_LITERAL(Length, SI::millimeter, mm)
DECLARE_LITERAL(Time, SI::second, s)
DECLARE_LITERAL(Time, SI::millisecond, ms)
DECLARE_LITERAL(Time, SI::microsecond, us)
DECLARE_LITERAL(Angular, SI::radian, rad)
DECLARE_LITERAL(Angular, SI::milliradian, mrad)
DECLARE_LITERAL(Area, SI::millimeter* SI::millimeter, mm2)
DECLARE_LITERAL(Area, SI::meter* SI::meter, m2)


}  // namespace SILiteral

}  // namespace Unit
