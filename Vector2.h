#pragma once
#include "utils/Macro.h"

namespace engine
{

    using FVector2 = Vector2<float>;
    using UVector2 = Vector2<unsigned int>;
    using DVector2 = Vector2<double>;
    using LVector2 = Vector2<long>;


    template<typename T>
    struct Vector2
    {
        static_assert(std::is_arithmetic_v<T>, "Vector2<T> requires an arithmetic type T");

        using CalcType = double;

        T x;
        T y;

        constexpr Vector2() noexcept
        {
            x = y = CAST(T, 0.0f);
        }
        constexpr Vector2(T _x, T _y) noexcept
        {
            x = _x;
            y = _y;
        }
        explicit constexpr Vector2(T _value) noexcept
        {
            x = y = _value;
        }

        template<typename U, typename = std::enable_if_t<std::is_arithmetic_v<U>>>
        explicit Vector2(const sf::Vector2<U>& _vector) noexcept
        {
            x = CAST(T, _vector.x);
            x = CAST(T, _vector.y);
        }





        #pragma region Operators

        // Implicit conversion to sf::Vector2<T>
        operator sf::Vector2<T>() const noexcept
        {
            return { x, y };
        }

        constexpr Vector2 operator + (const Vector2& _other) const noexcept 
        { 
            return Vector2(CAST(T, x + _other.x), CAST(T, y + _other.y));
        }
        constexpr Vector2 operator - (const Vector2& _other) const noexcept 
        { 
            return Vector2(CAST(T, x - _other.x), CAST(T, y - _other.y));
        }
        constexpr Vector2 operator - () const noexcept 
        { 
            return Vector2(CAST(T, -x), CAST(T, -y));
        }

        Vector2& operator += (const Vector2& _other) noexcept 
        { 
            x = CAST(T, x + _other.x); 
            y = CAST(T, y + _other.y);
            return *this;
        }
        Vector2& operator -= (const Vector2& _other) noexcept 
        { 
            x = CAST(T, x - _other.x);
            y = CAST(T, y - _other.y);
            return *this;
        }

        // Multiplication/division by a scalar (generic)
        template<typename U, typename = std::enable_if_t<std::is_arithmetic_v<U>>>
        constexpr auto operator * (U _scalar) const noexcept
        {
            using R = std::common_type_t<T, U>;
            return Vector2<R>(CAST(R, x * _scalar), (CAST(R, y * _scalar));
        }
        template<typename U, typename = std::enable_if_t<std::is_arithmetic_v<U>>>
        constexpr auto operator/(U _scalar) const noexcept
        {
            using R = std::common_type_t<T, U>;
            return Vector2<R>(CAST(R, x / _scalar), CAST(R, y / _scalar));
        }
        template<typename U, typename = std::enable_if_t<std::is_arithmetic_v<U>>>
        Vector2& operator*=(U _scalar) noexcept
        {
            using R = std::common_type_t<T, U>;
            x = CAST(T, CAST(R, x) * CAST(R, _scalar));
            y = CAST(T, CAST(R, y) * CAST(R, _scalar));
            return *this;
        }
        template<typename U, typename = std::enable_if_t<std::is_arithmetic_v<U>>>
        Vector2& operator/=(U _scalar) noexcept
        {
            using R = std::common_type_t<T, U>;
            x = CAST(T, CAST(R, x) / CAST(R, _scalar));
            y = CAST(T, CAST(R, y) / CAST(R, _scalar));
            return *this;
        }

        #pragma endregion
    };



}

