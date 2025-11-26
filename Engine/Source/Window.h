#pragma once
#include "CoreMinimal.h"
#include "Image.h"


namespace engine
{
	
	class ShapeObject;
	class CameraComponent;
	class Vertices;

	class Window
	{
		sf::RenderWindow window;

	public:
		INLINE bool IsOpen() const noexcept
		{
			return window.isOpen();
		}
		INLINE void SetFramerateLimit(const unsigned int& _limit)
		{
			window.setFramerateLimit(_limit);
		}
		INLINE void SetVerticalSyncEnabled(const bool& _enabled)
		{
			window.setVerticalSyncEnabled(_enabled);
		}
		INLINE void SetTitle(const std::string& _title)
		{
			window.setTitle(sf::String(_title.c_str()));
		}
		INLINE void SetSize(const UVector2& _size)
		{
			window.setSize(_size);
		}
		INLINE UVector2 GetSize() const noexcept
		{
			return UVector2(window.getSize());
		}
		INLINE void SetPosition(const IVector2& _position)
		{
			window.setPosition(_position);
		}
		INLINE IVector2 GetPosition() const
		{
			return IVector2(window.getPosition());
		}
		INLINE void SetIcon(const Image& _image)
		{
			window.setIcon(_image);
		}
		INLINE bool HasFocus() const
		{
			return window.hasFocus();
		}
		INLINE void RequestFocus()
		{
			window.requestFocus();
		}
		void SetView(const CameraComponent* _camera);

		Window() {}

		void Create(const std::string& _name, const UVector2& _windowSize, const bool& _isFullscreen);
		void Clear(const Color& _color);
		void Display();
		void Close();

		void Draw(const sf::Drawable& _drawable);
		void Draw(const ShapeObject& _drawable);
	};

}