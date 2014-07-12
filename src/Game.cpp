#include <cstdlib>
#include <iostream>
#include "InputHandler.hpp"
#include "Game.hpp"

#include "MainMenuScene.hpp"

using namespace std;
using namespace sf;

Game::Game(int argc, char** argv)
	: running(true)
{
	// We open at best resolution possible
	mainWindow.create(VideoMode::getDesktopMode(), "MiniLD 53");
	currentScene = make_shared<MainMenuScene>();
}

Game::~Game()
{
	mainWindow.close();
}

int Game::exec(void)
{
	loop();
	return EXIT_SUCCESS;
}

void Game::loop(void)
{
	Clock clock;
	float deltatime;

	while(running)
	{
		deltatime = clock.getElapsedTime().asSeconds();
		clock.restart();

		processInput();
		update(deltatime);
		render();
	}
}

void Game::stop(void)
{
	running = false;
}

void Game::processInput(void)
{
	Event e;
	InputHandler::Ptr ih;

	if(currentScene != nullptr)
	{
		// the current scene input handler is used to delegate
		// input events

		ih = currentScene->getInputHandler();
	}

	// Here we fetch all possible event
	// the switch will be pretty fast
	// since most compiler implements big switchs with jump tables

	while(mainWindow.pollEvent(e))
	{
		switch(e.type)
		{
			// Window
		case Event::Closed:
			stop();
			break;
		case Event::Resized:
			mainWindow.setView(View(FloatRect(0, 0, e.size.width, e.size.height)));
			break;
		case Event::LostFocus:
			// Not used
			break;
		case Event::GainedFocus:
			// Not used
			break;

			// Keyboard
		case Event::KeyPressed:
			if(ih != nullptr) ih->OnKeyDown(e.key);

			// Makes the dev easier
			if(e.key.code == Keyboard::Escape)
				stop();

			break;
		case Event::KeyReleased:
			if(ih != nullptr) ih->OnKeyUp(e.key);
			break;
		case Event::TextEntered:
			if(ih != nullptr) ih->OnChar(e.text);
			break;

			// Mouse
		case Event::MouseMoved:
			if(ih != nullptr) ih->OnMouseMove(e.mouseMove);
			break;
		case Event::MouseButtonPressed:
			if(ih != nullptr) ih->OnMouseDown(e.mouseButton);
			break;
		case Event::MouseButtonReleased:
			if(ih != nullptr) ih->OnMouseUp(e.mouseButton);
			break;
		case Event::MouseWheelMoved:
			if(ih != nullptr) ih->OnMouseWheel(e.mouseWheel);
			break;
		case Event::MouseEntered:
			// Not used
			break;
		case Event::MouseLeft:
			// Not used
			break;

			// Joystick
		case Event::JoystickButtonPressed:
			if(ih != nullptr) ih->OnJoystickButtonDown(e.joystickButton);
			break;
		case Event::JoystickButtonReleased:
			if(ih != nullptr) ih->OnJoystickButtonUp(e.joystickButton);
			break;
		case Event::JoystickMoved:
			if(ih != nullptr) ih->OnJoystickMove(e.joystickMove);
			break;
		case Event::JoystickConnected:
			// Not used
			break;
		case Event::JoystickDisconnected:
			// Not used
			break;
		default: break;
		}
	}
}

void Game::update(float deltatime)
{
	if(currentScene != nullptr)
	{
		currentScene->update(deltatime);
	}
}

void Game::render(void)
{
	mainWindow.clear();
	if(currentScene != nullptr)
	{
		mainWindow.draw(*currentScene);
	}
	mainWindow.display();
}
