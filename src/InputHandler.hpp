#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_

#include <SFML/Window.hpp>
#include <memory>

class InputHandler
{
public:
	typedef std::shared_ptr<InputHandler> Ptr;

	// Keyboard
	void OnKeyDown(sf::Event::KeyEvent &e) {}
	void OnKeyUp(sf::Event::KeyEvent &e) {}
	void OnChar(sf::Event::TextEvent &e) {}

	// Mouse
	void OnMouseMove(sf::Event::MouseMoveEvent &e) {}
	void OnMouseDown(sf::Event::MouseButtonEvent &e) {}
	void OnMouseUp(sf::Event::MouseButtonEvent &e) {}
	void OnMouseWheel(sf::Event::MouseWheelEvent &e) {}

	// Joystick
	void OnJoystickButtonDown(sf::Event::JoystickButtonEvent &e) {}
	void OnJoystickButtonUp(sf::Event::JoystickButtonEvent &e) {}
	void OnJoystickMove(sf::Event::JoystickMoveEvent &e) {}
};

#endif /* INPUTHANDLER_H_ */
