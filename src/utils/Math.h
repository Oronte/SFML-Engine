#pragma once
#include "Macro.h"

namespace engine::Math
{

    using Real = float; // Change to double if you prefer higher precision

    inline constexpr Real pi = CAST(Real, 3.14159265358979323846);
    inline constexpr Real tau = CAST(Real, 2.0 * 3.14159265358979323846);
    inline constexpr Real halfPi = CAST(Real, 1.57079632679489661923);
    inline constexpr Real degToRad = CAST(Real, pi / 180.0);
    inline constexpr Real radToDeg = CAST(Real, 180.0 / pi);
    inline constexpr Real epsilon = CAST(Real, 1e-6);
    inline constexpr Real infinity = std::numeric_limits<Real>::infinity();
    inline constexpr Real golden = CAST(Real, 1.6180339887498948);


    #pragma region Common Functions

    inline constexpr Real Sqrt(Real _x) noexcept
    {
        return std::sqrt(_x);
    }
    inline constexpr Real InvSqrt(Real _x) noexcept
    {
        return 1 / Sqrt(_x);
    }
    inline constexpr Real Pow(Real _base, int _exp) noexcept
    {
        return std::pow(_base, _exp);
    }
    inline constexpr Real Exp(Real _x) noexcept
    {
        return std::exp(_x);
    }
    inline constexpr Real Log(Real _x) noexcept
    {
        return std::log(_x);
    }
    inline Real Log10(const Real& _x) noexcept 
    { 
        return std::log10(_x);
    }

    inline constexpr Real Sin(Real _x) noexcept
    {
        return std::sin(_x);
    }
    inline constexpr Real Cos(Real _x) noexcept
    {
        return std::cos(_x);
    }
    inline constexpr Real Tan(Real _x) noexcept
    {
        return std::tan(_x);
    }
    
    inline Real Asin(const Real& _x) noexcept 
    { 
        return std::asin(_x); 
    }
    inline Real Acos(const Real& _x) noexcept 
    { 
        return std::acos(_x); 
    }
    inline Real Atan(const Real& _x) noexcept 
    { 
        return std::atan(_x); 
    }
    inline Real Atan2(const Real& _y, const Real& _x) noexcept 
    { 
        return std::atan2(_y, _x); 
    }

    inline Real Sinh(const Real& _x) noexcept 
    { 
        return std::sinh(_x); 
    }
    inline Real Cosh(const Real& _x) noexcept 
    { 
        return std::cosh(_x); 
    }
    inline Real Tanh(const Real& _x) noexcept 
    { 
        return std::tanh(_x); 
    }

    inline Real Floor(const Real& _x) noexcept 
    { 
        return std::floor(_x); 
    }
    inline Real Ceil(const Real& _x) noexcept 
    { 
        return std::ceil(_x); 
    }
    inline Real Round(const Real& _x) noexcept 
    { 
        return std::round(_x); 
    }
    inline Real Trunc(const Real& _x) noexcept 
    { 
        return std::trunc(_x); 
    }

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
