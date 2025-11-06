#pragma once
#include "Macro.h"

namespace engine::Math
{

    using Real = float; // Change to double if you prefer higher precision

    // ---------- Constants ----------
    inline constexpr Real pi = CAST(Real, 3.14159265358979323846);
    inline constexpr Real tau = CAST(Real, 2.0 * 3.14159265358979323846);
    inline constexpr Real halfPi = CAST(Real, 1.57079632679489661923);
    inline constexpr Real degToRad = CAST(Real, pi / 180.0);
    inline constexpr Real radToDeg = CAST(Real, 180.0 / pi);
    inline constexpr Real epsilon = CAST(Real, 1e-6);
    inline constexpr Real infinity = std::numeric_limits<Real>::infinity();
    inline constexpr Real SQRT2_ = CAST(Real, 1.4142135623730951);
    inline constexpr Real INV_SQRT2_ = CAST(Real, 0.7071067811865476);
    inline constexpr Real golden = CAST(Real, 1.6180339887498948);




    // ---------- Scalar utilities ----------
#pragma region Scalar utilities

    /// <summary>Converts degrees to radians.</summary>
    inline constexpr Real DegToRad(const Real& _degrees) noexcept
    {
        return _degrees * degToRad;
    }

    /// <summary>Converts radians to degrees.</summary>
    inline constexpr Real RadToDeg(const Real& _radian) noexcept
    {
        return _radian * radToDeg;
    }

    /// <summary>Returns the absolute value of a scalar.</summary>
    inline constexpr Real Abs(const Real& _value) noexcept
    {
        return _value < 0 ? -_value : _value;
    }

    /// <summary>Returns the sign of a value (-1, 0, or 1).</summary>
    inline constexpr Real Sign(const Real& _value) noexcept
    {
        return CAST(Real, (_value > 0)) - CAST(Real, (_value < 0));
    }

    inline constexpr Real MinVal(const Real& _a, const Real& _b) noexcept
    {
        return _a < _b ? _a : _b;
    }

    inline constexpr Real MaxVal(const Real& _a, const Real& _b) noexcept
    {
        return _a > _b ? _a : _b;
    }

    /// <summary>Clamps a value between a minimum and maximum range.</summary>
    inline constexpr Real Clamp(const Real& _value, const Real& _min, const Real& _max) noexcept
    {
        return _value < _min ? _min : _value > _max ? _max : _value;
    }

    /// <summary>Clamps a value between 0 and 1.</summary>
    inline constexpr Real Saturate(const Real& _value) noexcept
    {
        return Clamp(_value, CAST(Real, 0), CAST(Real, 1));
    }

    /// <summary>Returns true if two values are approximately equal (within epsilon).</summary>
    inline constexpr bool ApproxEqual(const Real& _a, const Real& _b, const Real& _eps = epsilon) noexcept
    {
        return Abs(_a - _b) <= _eps;
    }

#pragma endregion


    // ---------- Interpolation ----------

#pragma region Interpolation

    /// <summary>Linearly interpolates between two values.</summary>
    inline constexpr Real Lerp(const Real& _a, const Real& _b, const Real& _time) noexcept
    {
        return _a + (_b - _a) * _time;
    }

    inline constexpr Real ConstantLerp(const Real& _start, const Real& _end, const Real& _time)
    {
        return (1 - _time) * _start + _time * _end;
    }

    /// <summary>Inverse linear interpolation (returns how far _v is between _a and _b).</summary>
    inline constexpr Real InverseLerp(const Real& _a, const Real& _b, const Real& _v) noexcept
    {
        return (_b - _a) == 0 ? 0 : (_v - _a) / (_b - _a);
    }

    /// <summary>Remaps a value from one range to another.</summary>
    inline constexpr Real Remap(const Real& _inMin, const Real& _inMax, const Real& _outMin, const Real& _outMax, const Real& _v) noexcept
    {
        return Lerp(_outMin, _outMax, Saturate(InverseLerp(_inMin, _inMax, _v)));
    }

    /// <summary>Returns a smooth interpolation between 0 and 1 based on x (Hermite curve).</summary>
    inline Real SmoothStep(const Real& _edge0, const Real& _edge1, Real _x) noexcept
    {
        _x = Saturate((_x - _edge0) / (_edge1 - _edge0));
        return _x * _x * (3 - 2 * _x);
    }

    /// <summary>Returns a smoother interpolation (cubic curve) between 0 and 1.</summary>
    inline Real SmootherStep(const Real& _edge0, const Real& _edge1, Real _x) noexcept
    {
        _x = Saturate((_x - _edge0) / (_edge1 - _edge0));
        return _x * _x * _x * (_x * (_x * 6 - 15) + 10);
    }

#pragma endregion


}
