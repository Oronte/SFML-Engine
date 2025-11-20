#pragma once
#include "utils/Singleton.h"
#include "actors/ShapeObject.h"

namespace engine
{

	class TextureManager : public Singleton<TextureManager>
	{
		std::string defaultTexturePath = "Default";
		std::string defaultTextureExtension = "png";
		sf::Texture defaultTexture;

	public:
		TextureManager() {}

	public:
		void SetTextureRect(sf::Shape* _shape, const IVector2& _start, const IVector2& _size);
		void SetTextureRect(sf::Shape* _shape, const IRect& _rect);
	};

}

