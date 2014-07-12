#ifndef MAINMENUSCENE_H_
#define MAINMENUSCENE_H_

#include "Scene.hpp"
#include <SFML/Graphics.hpp>

class MainMenuScene : public Scene
{
public:
	MainMenuScene();
	virtual ~MainMenuScene();

	virtual void update(float delta);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
	sf::Font temp_font; // This is temporary, FontManager will be made
};

#endif /* MAINMENUSCENE_H_ */
