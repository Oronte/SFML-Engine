#include "Image.h"

engine::Image::Image()
{
	image = sf::Image();
}

engine::Image::Image(const UVector2& _size, const Color& _color)
{
	image = sf::Image(_size, _color);
}

engine::Image::Image(const UVector2& _size, const std::uint8_t* _pixels)
{
	image = sf::Image(_size, _pixels);
}

engine::Image::Image(const std::string& _path)
{
	image = sf::Image(std::filesystem::path(_path));
}

engine::Image::Image(const void* _data, const std::size_t& _size)
{
	image = sf::Image(_data, _size);
}

engine::Image::Image(const sf::Image& _image)
{
	image = _image;
}

void engine::Image::Resize(const UVector2& _size, const Color& _color)
{
	image.resize(_size, _color);
}

void engine::Image::ResizeFromPixels(const UVector2& _size, const std::uint8_t* _pixels)
{
	image.resize(_size, _pixels);
}

bool engine::Image::LoadFromFile(const std::string& _filename)
{
	return image.loadFromFile(std::filesystem::path(_filename));
}

bool engine::Image::LoadFromMemory(const void* _data, const std::size_t& _size)
{
	return image.loadFromMemory(_data, _size);
}

bool engine::Image::SaveToFile(const std::string& _filename) const
{
	return image.saveToFile(std::filesystem::path(_filename));
}

std::optional<std::vector<std::uint8_t>> engine::Image::SaveToMemory(const std::string_view& _format) const
{
	return image.saveToMemory(_format);
}

void engine::Image::CreateMaskFromColor(const Color& _color, const std::uint8_t& _alpha)
{
	image.createMaskFromColor(_color, _alpha);
}

bool engine::Image::Copy(const Image& _source, const UVector2& _dest, const IRect& _sourceRect, const bool& _applyAlpha)
{
	return image.copy(_source, _dest, _sourceRect, _applyAlpha);
}

void engine::Image::FlipHorizontally()
{
	image.flipHorizontally();
}

void engine::Image::FlipVertically()
{
	image.flipVertically();
}
