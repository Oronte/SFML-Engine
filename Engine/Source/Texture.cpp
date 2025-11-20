#include "Texture.h"

engine::Texture::Texture(const std::string& _path, const bool& _rgb)
{
	texture = sf::Texture(std::filesystem::path(_path), _rgb);
}

engine::Texture::Texture(const std::string& _path, const bool& _rgb, const IRect& _area)
{
	texture = sf::Texture(std::filesystem::path(_path), _rgb, _area);
}

engine::Texture::Texture(const void* data, std::size_t _size, const bool& _rgb)
{
	texture = sf::Texture(data, _size, _rgb);
}

engine::Texture::Texture(const void* data, std::size_t _size, const bool& _rgb, const IRect& _area)
{
	texture = sf::Texture(data, _size, _rgb, _area);
}

engine::Texture::Texture(const Image& _image, const bool& _rgb)
{
	texture = sf::Texture(_image, _rgb);
}

engine::Texture::Texture(const Image& _image, const bool& _rgb, const IRect& _area)
{
	texture = sf::Texture(_image, _rgb, _area);
}

engine::Texture::Texture(const UVector2& _size, const bool& _rgb)
{
	texture = sf::Texture(_size, _rgb);
}

engine::Texture::Texture(const sf::Texture& _texture)
{
	texture = _texture;
}

bool engine::Texture::Resize(const UVector2& _size, const bool& _rgb)
{
	return texture.resize(_size, _rgb);
}

bool engine::Texture::LoadFromFile(const std::string& _filename, const bool& _rgb, const IRect& _area)
{
	return texture.loadFromFile(std::filesystem::path(_filename), _rgb, _area);
}

bool engine::Texture::LoadFromMemory(const void* _data, const std::size_t& _size, const bool& _rgb, const IRect& _area)
{
	return texture.loadFromMemory(_data, _size, _rgb, _area);
}

bool engine::Texture::LoadFromImage(const Image& _image, const bool& _rgb, const IRect& _area)
{
	return texture.loadFromImage(_image, _rgb, _area);
}

void engine::Texture::Bind(const Texture* _texture, const bool& _isNoralize)
{
	// TODO fix
	//texture.bind(_texture, _isNoralize ? sf::CoordinateType::Normalized : sf::CoordinateType::Pixels);
}

engine::Image engine::Texture::CopyToImage() const
{
	return Image(texture.copyToImage());
}

bool engine::Texture::GenerateMipmap()
{
	return texture.generateMipmap();
}
