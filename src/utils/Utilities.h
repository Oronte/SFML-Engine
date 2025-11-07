#pragma once
#include "SubclassOf.h"

namespace engine
{
    //unsigned int GetUniqueID();
    //int GetRandomNumberInRange(const int& _min, const int& _max);
    //float DegToRad(const float& _degrees);
    //float RadToDeg(const float& _radians);
    //float Lerp(const float& _start, const float& _end, const float& _time);
    //float Lerp_Constant(const float& _start, const float& _end, const float& _time);
    //float DotProduct(const sf::Vector2f& _direction, const sf::Vector2f& _normal);
    //float EaseOutQuart(const float& _time);
    //sf::Vector2f ComputeNormal(const sf::FloatRect& _rect);
    //float Length(const sf::Vector2f& _vector);
    //void Normalize(sf::Vector2f& _vector);
    //float Distance(const float& _first, const float& _second);
    //float Distance(const sf::Vector2f& _first, const sf::Vector2f& _second);
    //sf::Vector2f ComputeNormal(const sf::FloatRect& _rect);
    //sf::Vector2f SmoothDamp(const sf::Vector2f& _current, sf::Vector2f _target, sf::Vector2f& _currentVelocity,
    //    float _smoothTime, const float& _deltaTime, const float& _maxSpeed = INFINITY);
    //std::vector<std::string> SplitString(const std::string& _string, const char& _delimiter);

    //template <typename Type, typename ...Args>
    //Type* Spawn(Args&&... _args)
    //{
    //    return new Type(forward<Args>(_args)...);
    //}

    //template <typename Type>
    //Type* Spawn(const SubclassOf<Type>& _ref)
    //{
    //    return new Type(_ref.GetObject());
    //}

    //template <typename T>
    //T GetRandomNumberInRange(const T& _min, const T& _max)
    //{
    //    std::random_device _rSeed; // Get a random seed
    //    std::mt19937 _gen(_rSeed()); // Init generator with the seed
    //    std::uniform_real_distribution<T> _distr(_min, _max); // Define limits

    //    return _distr(_gen); // Generate number
    //}

    //template <typename Type, typename BaseType, IS_BASE_OF(BaseType, Type)>
    //Type* Cast(BaseType* _baseType)
    //{
    //    if (!_baseType) return nullptr;
    //    return dynamic_cast<Type*>(_baseType);
    //}

    //template<typename T, typename K>
    //bool InstanceOf(K _object)
    //{
    //    return std::is_same<T, decltype(_object)>::value;
    //}
}