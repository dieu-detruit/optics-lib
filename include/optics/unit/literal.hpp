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

#define DECLARE_LITERAL_IMPL(unit_type, constant, literal)                       \
    inline unit_type operator""_##literal(long double value)                     \
    {                                                                            \
        return static_cast<value_type<unit_type>::type>(value) * (SI::constant); \
    }

#define DECLARE_LITERAL_IMPL_SQ(unit_type, constant, literal)   \
    inline unit_type operator""_##literal##2(long double value) \
    {                                                           \
        return static_cast<value_type<unit_type>::type>(value)  \
               * (SI::constant * SI::constant);                 \
    }

#define DECLARE_LITERAL(unit_type, constant, literal)            \
    DECLARE_LITERAL_IMPL(unit_type, micro##constant, u##literal) \
    DECLARE_LITERAL_IMPL(unit_type, milli##constant, m##literal) \
    DECLARE_LITERAL_IMPL(unit_type, constant, literal)           \
    DECLARE_LITERAL_IMPL(unit_type, killo##constant, k##literal) \
    DECLARE_LITERAL_IMPL(unit_type, mega##constant, M##literal)

#define DECLARE_LITERAL_SQ(unit_type, constant, literal)            \
    DECLARE_LITERAL_IMPL_SQ(unit_type, micro##constant, u##literal) \
    DECLARE_LITERAL_IMPL_SQ(unit_type, milli##constant, m##literal) \
    DECLARE_LITERAL_IMPL_SQ(unit_type, constant, literal)           \
    DECLARE_LITERAL_IMPL_SQ(unit_type, killo##constant, k##literal) \
    DECLARE_LITERAL_IMPL_SQ(unit_type, mega##constant, M##literal)


DECLARE_LITERAL(Length, meter, m)
DECLARE_LITERAL_SQ(Area, meter, m)
DECLARE_LITERAL(Time, second, s)
DECLARE_LITERAL(Angle, radian, rad)
DECLARE_LITERAL(Power, watt, W)
DECLARE_LITERAL(Energy, joule, J)
DECLARE_LITERAL(Frequency, hertz, Hz)


}  // namespace SILiteral

}  // namespace Unit
