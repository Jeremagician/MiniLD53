#include "MainMenuScene.hpp"

using namespace sf;

MainMenuScene::MainMenuScene(void)
{
	font = FontManager::getInstance().getFont("data/DroidSansMono.ttf", true);
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
