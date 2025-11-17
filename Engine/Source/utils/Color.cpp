#include "Color.h"
#include "Logger.h"

using namespace engine;

engine::ColorData::ColorData()
{
    r = g = b = 0;
}

engine::ColorData::ColorData(const short& _r, const short& _g, const short& _b)
{
    if (_r > 255 || _g > 255 || _b > 255)
    {
        LOG(VerbosityType::Warning, std::format("Color values must be between 0 and 255 : r = {} g = {} b = {}", _r, _g, _b));
    }

    r = _r;
    g = _g;
    b = _b;
}

std::string engine::ColorData::ToString(const bool& _textOnly) const
{
    return _textOnly ? TEXT_RGB(r, g, b) : BG_RGB(r, g, b);
}

engine::Gradient::Gradient(const ColorData& _a, const ColorData& _b)
{
    gradA = _a;
    gradB = _b;
}

std::string Gradient::GradientString(const std::string& _text, const bool& _textOnly) const
{
    const int _size = static_cast<int>(_text.size());
    std::string _newWord = "";

    for (int _index = 0; _index < _size; _index++)
    {
        const ColorData& _color = ClampGradient(_index, _size);
        _newWord += _color.ToString(_textOnly) + _text[_index];
    }
    return _newWord + COLOR_RESET;
}

ColorData Gradient::ClampGradient(const int& _index, const int& _maxDisplayChar) const
{
    float _normalizer;
    float _valueRed = 0;
    float _valueGreen = 0;
    float _valueBlue = 0;

    const float& _rangeRed = CAST(float, gradB.r - gradA.r);
    _normalizer = _index * (_rangeRed / _maxDisplayChar);
    _valueRed += (gradA.r + _normalizer);

    const float& _rangeGreen = CAST(float, gradB.g - gradA.g);
    _normalizer = _index * (_rangeGreen / _maxDisplayChar);
    _valueGreen += (gradA.g + _normalizer);

    const float& _rangeBlue = CAST(float, gradB.b - gradA.b);
    _normalizer = _index * (_rangeBlue / _maxDisplayChar);
    _valueBlue += (gradA.b + _normalizer);

    return ColorData(
        CAST(short, _valueRed),
        CAST(short, _valueGreen),
        CAST(short, _valueBlue));
}
