#include "MainMenuScene.hpp"
#include <exception>

using namespace sf;

MainMenuScene::MainMenuScene(void)
{
	FontManager &mgr = FontManager::getInstance();
	try
	{
		font = mgr.getFont("data/DroidSansMono.ttf", true);
	}
	catch(std::exception &e)
	{
		font = mgr.empty();
	}
}

MainMenuScene::~MainMenuScene(void)
{

}

void MainMenuScene::update(float delta)
{

}

void MainMenuScene::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	Text text("Hello World !", *font, 64);
	RectangleShape bg;

	bg.setSize(Vector2f(target.getSize().x, target.getSize().y));
	bg.setPosition(0, 0);
	bg.setFillColor(Color(0, 50, 200));

	target.draw(bg);
	target.draw(text);
}
