#pragma once
#include "utils/Singleton.h"
#include "actors/ShapeObject.h"

#define M_TEXTURE engine::TextureManager::GetInstance()

namespace engine
{

	class TextureManager : public Singleton<TextureManager>
	{
		std::string localPath = "../Content/Textures/StarterContent/";
		std::string defaultTexturePath = "Default";
		std::string defaultTextureExtension = "png";
		Texture defaultTexture;

	public:
		TextureManager();

	private:
		void LoadDefaultTexture();
		void SetTextureToDefault(Texture& _texture);
		void LoadTexture(Texture& _texture, const std::string& _path, const IRect& _rect = IRect());
		void SetTexture(Shape* _shape, const Texture* _texture);
		std::string GetExtensionNameByType(const TextureExtensionType& _textureType);

	public:
		void Load(ShapeObject* _shapeObject, const std::string& _path, const TextureExtensionType& _textureType = TextureExtensionType::PNG,
			const IRect& _rect = IRect(), const bool _isRepeated = false, const bool _smooth = true);
		void SetTextureRect(Shape* _shape, const IVector2& _start, const IVector2& _size);
		void SetTextureRect(Shape* _shape, const IRect& _rect);
	};

}

