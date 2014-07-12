#ifndef MAINMENUSCENE_H_
#define MAINMENUSCENE_H_

#include "Scene.hpp"
#include <SFML/Graphics.hpp>
#include "FontManager.hpp"

class MainMenuScene : public Scene
{
public:
	MainMenuScene();
	virtual ~MainMenuScene();

	virtual void update(float delta) override;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
	FontPtr font;
};

#endif /* MAINMENUSCENE_H_ */
