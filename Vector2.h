#pragma once
#include "utils/Math.h"

namespace engine
{

    template<typename T>
    struct Vector2
    {
        static_assert(std::is_arithmetic_v<T>, "Vector2<T> requires an arithmetic type T");

        using Real = Math::Real; // TODO Change to CalcType

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
            y = CAST(T, _vector.y);
        }


        NO_DISCARD Real LengthSquared() const noexcept 
        { 
            return CAST(Real, x) * CAST(Real, x) + CAST(Real, y) * CAST(Real, y);
        }
        NO_DISCARD Real Length() const noexcept 
        { 
            return Math::Sqrt(LengthSquared());
        }

        // normalized renvoie Vector2<calc_type> (utile quand T est entier)
        NO_DISCARD Vector2<Real> Normalized(Real _fallback = 0.0) const noexcept
        {
            Real _length = Length();
            if (_length <= Math::epsilon) return Vector2<Real>(_fallback, _fallback);
            return Vector2<Real>(CAST(Real, x) / _length, CAST(Real, y) / _length);
        }

        NO_DISCARD Real Dot(const Vector2& _other) const noexcept
        {
            return CAST(Real, x) * CAST(Real, _other.x) + CAST(Real, y) * CAST(Real, _other.y);
        }

        // cross produit 2D -> scalaire z
        NO_DISCARD Real Cross(const Vector2& _other) const noexcept
        {
            return CAST(Real, x) * CAST(Real, _other.y) - CAST(Real, y) * CAST(Real, _other.x);
        }

        NO_DISCARD Vector2 Perp() const noexcept 
        { 
            return Vector2(CAST(T, -y), CAST(T, x));
        }

        NO_DISCARD Real DistanceSquared(const Vector2& _other) const noexcept 
        { 
            return (*this - _other).LengthSquared();
        }
        NO_DISCARD Real Distance(const Vector2& _other) const noexcept 
        { 
            return std::sqrt(DistanceSquared(_other));
        }

        // clampMagnitude : retourne Vector2<common_type<T,double>> pour éviter perte si T entier
        template<typename U = double>
        NO_DISCARD auto ClampMagnitude(U maxLen) const noexcept
        {
            using R = std::common_type_t<T, U>;
            R ls = static_cast<R>(LengthSquared());
            R maxLs = maxLen * maxLen;
            if (ls <= maxLs) return Vector2<R>(static_cast<R>(x), static_cast<R>(y));
            R len = std::sqrt(ls);
            return Vector2<R>(static_cast<R>(x) * (maxLen / len), static_cast<R>(y) * (maxLen / len));
        }

        // moveTowards : retourne Vector2<common_type<T,double>>
        template<typename U = double>
        NO_DISCARD auto MoveTowards(const Vector2& target, U maxDelta) const noexcept
        {
            using R = std::common_type_t<T, U>;
            Vector2<R> cur{ static_cast<R>(x), static_cast<R>(y) };
            Vector2<R> tgt{ static_cast<R>(target.x), static_cast<R>(target.y) };
            Vector2<R> toTarget = tgt - cur;
            R dist = toTarget.Length();
            if (dist <= static_cast<R>(maxDelta) || dist <= Eps()) return tgt;
            return cur + toTarget * (static_cast<R>(maxDelta) / dist);
        }

        // reflect (renvoie Vector2<common_type<T,double>>)
        template<typename U = double>
        NO_DISCARD auto Reflect(const Vector2& n) const noexcept
        {
            using R = std::common_type_t<T, U>;
            Vector2<R> v{ static_cast<R>(x), static_cast<R>(y) };
            Vector2<R> nn{ static_cast<R>(n.x), static_cast<R>(n.y) };
            R d = v.Dot(nn);
            return v - nn * (static_cast<R>(2) * d);
        }

        // project (renvoie Vector2<common_type<T,double>>)
        template<typename U = double>
        NO_DISCARD auto Project(const Vector2& axis) const noexcept
        {
            using R = std::common_type_t<T, U>;
            Vector2<R> v{ static_cast<R>(x), static_cast<R>(y) };
            Vector2<R> a{ static_cast<R>(axis.x), static_cast<R>(axis.y) };
            R denom = a.Dot(a);
            if (denom <= Eps()) return Vector2<R>(static_cast<R>(0), static_cast<R>(0));
            return a * (v.Dot(a) / denom);
        }

        NO_DISCARD Real AtanToRadian() const noexcept { return std::atan2(static_cast<Real>(y), static_cast<Real>(x)); }

        NO_DISCARD Real AngleBetweenRadians(const Vector2& o) const noexcept
        {
            Real da = AtanToRadian();
            Real db = o.AtanToRadian();
            Real diff = db - da;
            while (diff <= -pi) diff += tau;
            while (diff > pi) diff -= tau;
            return diff;
        }

        NO_DISCARD Real SignedAngleDeg(const Vector2& to) const noexcept
        {
            return AngleBetweenRadians(to) * radToDeg;
        }

        // rotated : retourne Vector2<common_type<T,double>>
        template<typename U = double>
        NO_DISCARD auto Rotated(U angleRad) const noexcept
        {
            using R = std::common_type_t<T, U>;
            R c = std::cos(angleRad);
            R s = std::sin(angleRad);
            return Vector2<R>(static_cast<R>(x) * c - static_cast<R>(y) * s,
                static_cast<R>(x) * s + static_cast<R>(y) * c);
        }

        template<typename U = double>
        NO_DISCARD auto RotatedDeg(U angleDeg) const noexcept
        {
            return Rotated(angleDeg * degToRad);
        }

        template<typename U = double>
        NO_DISCARD auto RotateAround(const Vector2& pivot, U angleRad) const noexcept
        {
            using R = std::common_type_t<T, U>;
            Vector2<R> p{ static_cast<R>(pivot.x), static_cast<R>(pivot.y) };
            Vector2<R> self{ static_cast<R>(x), static_cast<R>(y) };
            return p + (self - p).rotated(angleRad);
        }

        // ---------- interpolation ----------
        template<typename U = double>
        NO_DISCARD auto Lerp(const Vector2& b, U t) const noexcept
        {
            using R = std::common_type_t<T, U>;
            return Vector2<R>(static_cast<R>(x) + (static_cast<R>(b.x) - static_cast<R>(x)) * static_cast<R>(t),
                static_cast<R>(y) + (static_cast<R>(b.y) - static_cast<R>(y)) * static_cast<R>(t));
        }

        // ---------- géométrie ----------
        // closestPointOnSegment renvoie Vector2<common_type<T,double>>
        template<typename U = double>
        NO_DISCARD auto ClosestPointOnSegment(const Vector2& a, const Vector2& b) const noexcept
        {
            using R = std::common_type_t<T, U>;
            Vector2<R> A{ static_cast<R>(a.x), static_cast<R>(a.y) };
            Vector2<R> B{ static_cast<R>(b.x), static_cast<R>(b.y) };
            Vector2<R> P{ static_cast<R>(x), static_cast<R>(y) };
            Vector2<R> AB = B - A;
            R ab2 = AB.LengthSquared();
            if (ab2 <= epsilon) return A;
            R t = (P - A).dot(AB) / ab2;
            if (t < 0) t = 0;
            else if (t > 1) t = 1;
            return A + AB * t;
        }

        template<typename U = double>
        NO_DISCARD auto DistanceToSegment(const Vector2& a, const Vector2& b) const noexcept
        {
            using R = std::common_type_t<T, U>;
            auto cp = ClosestPointOnSegment(a, b);
            Vector2<R> P{ static_cast<R>(x), static_cast<R>(y) };
            return (P - cp).length();
        }

        template<typename U = double>
        NO_DISCARD Real SignedDistanceToLine(const Vector2& a, const Vector2& b) const noexcept
        {
            using R = std::common_type_t<T, U>;
            Vector2<R> A{ static_cast<R>(a.x), static_cast<R>(a.y) };
            Vector2<R> B{ static_cast<R>(b.x), static_cast<R>(b.y) };
            Vector2<R> P{ static_cast<R>(x), static_cast<R>(y) };
            Vector2<R> AB = B - A;
            R denom = std::sqrt(AB.LengthSquared());
            if (denom <= epsilon) return static_cast<calc_type>(0);
            return static_cast<calc_type>(AB.Cross(P - A) / denom);
        }

        bool IsOnSegment(const Vector2& a, const Vector2& b, Real epsVal = eps()) const noexcept
        {
            return DistanceToSegment(a, b) <= epsVal;
        }

        // ---------- intersections ----------
        // p + r*t  and  q + s*u (returns t and u)
        template<typename U = double>
        static bool LineLineIntersection(const Vector2& p, const Vector2& r,
            const Vector2& q, const Vector2& s,
            Real& outT, Real& outU) noexcept
        {
            using R = std::common_type_t<T, U>;
            Vector2<R> P{ static_cast<R>(p.x), static_cast<R>(p.y) };
            Vector2<R> Rv{ static_cast<R>(r.x), static_cast<R>(r.y) };
            Vector2<R> Q{ static_cast<R>(q.x), static_cast<R>(q.y) };
            Vector2<R> Sv{ static_cast<R>(s.x), static_cast<R>(s.y) };

            R rxs = Rv.Cross(Sv);
            Vector2<R> qmp = Q - P;
            R qmpxr = qmp.Cross(Rv);
            if (std::abs(rxs) <= Eps()) return false;
            outT = static_cast<calc_type>(qmp.Cross(Sv) / rxs);
            outU = static_cast<calc_type>(qmpxr / rxs);
            return true;
        }

        template<typename U = double>
        static bool SegmentSegmentIntersection(const Vector2& p, const Vector2& r,
            const Vector2& q, const Vector2& s,
            Vector2<double>* outPoint = nullptr) noexcept
        {
            calc_type t, u;
            if (!LineLineIntersection(p, r, q, s, t, u)) return false;
            if (t < 0.0 || t > 1.0 || u < 0.0 || u > 1.0) return false;
            if (outPoint) {
                // p + r * t
                using R = double;
                outPoint->x = static_cast<R>(p.x) + static_cast<R>(r.x) * t;
                outPoint->y = static_cast<R>(p.y) + static_cast<R>(r.y) * t;
            }
            return true;
        }

        template<typename U = double>
        static bool SegmentSegmentIntersectionPoints(const Vector2& a1, const Vector2& a2,
            const Vector2& b1, const Vector2& b2,
            Vector2<double>* outPoint = nullptr) noexcept
        {
            Vector2 r = a2 - a1;
            Vector2 s = b2 - b1;
            return SegmentSegmentIntersection(a1, r, b1, s, outPoint);
        }


        std::string ToString() const
        {
            return std::format("X : {}, Y : {}", x, y);
        }

        #pragma region Operators

        friend std::ostream& operator << (std::ostream& _os, const Vector2& _vector)
        {
            _os << _vector.ToString();
            return _os;
        }

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
        constexpr Vector2 operator * (const Vector2& _other) const
        {
            return Vector2(CAST(T, x * _other.x), CAST(T, y * _other.y));
        }
        constexpr Vector2 operator / (const Vector2& _other) const
        {
            if (_other.x == 0 || _other.y == 0) throw Exception("Can't divide by zero !");
            return Vector2(CAST(T, x / _other.x), CAST(T, y / _other.y));
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
        Vector2& operator *= (const Vector2& _other) noexcept 
        { 
            x = CAST(T, x * _other.x);
            y = CAST(T, y * _other.y);
            return *this;
        }
        Vector2& operator /= (const Vector2& _other) 
        { 
            if (_other.x == 0 || _other.y == 0) throw Exception("Can't divide by zero !");
            x = CAST(T, x / _other.x);
            y = CAST(T, y / _other.y);
            return *this;
        }

        template<typename U, typename = std::enable_if_t<std::is_arithmetic_v<U>>>
        constexpr auto operator * (U _scalar) const noexcept
        {
            using R = std::common_type_t<T, U>;
            return Vector2<R>(CAST(R, x * _scalar), (CAST(R, y * _scalar)));
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

    using FVector2 = Vector2<float>;
    using UVector2 = Vector2<unsigned int>;
    using DVector2 = Vector2<double>;
    using LVector2 = Vector2<long>;

}

///////////////////////////////////////////////////////////
// 
//  Debug : 
//  
//  FVector2 _vector = FVector2(1, 2);
//  LOG(engine::VerbosityType::Warning, _vector);
// 
///////////////////////////////////////////////////////////