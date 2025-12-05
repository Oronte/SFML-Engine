#include "Window.h"
#include "Graphics/Shapes/ShapeObject.h"
#include "Components/CameraComponent.h"
#include "Graphics/Ressources/Vertices.h"

void engine::Window::SetView(const CameraComponent* _camera)
{
	window.setView(*_camera->GetView());
}

void engine::Window::Create(const std::string& _name, const UVector2& _windowSize, const bool& _isFullscreen)
{
	const UVector2& _size = _isFullscreen ? UVector2(1920, 1080) : _windowSize;
	window.create(sf::VideoMode(_size),
		CAST(sf::String, _name.c_str()),
		_isFullscreen ? sf::State::Fullscreen : sf::State::Windowed);
}

void engine::Window::Clear(const Color& _color)
{
	window.clear(_color);
}

void engine::Window::Display()
{
	window.display();
}

void engine::Window::Close()
{
	window.close();
}

std::optional<sf::Event> engine::Window::PollEvent()
{
	return window.pollEvent();
}

void engine::Window::Draw(const sf::Drawable& _drawable)
{
	window.draw(_drawable);
}

void engine::Window::Draw(const ShapeObject& _drawable)
{
	window.draw(*(_drawable.GetShape()->Get()));
}