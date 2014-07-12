#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include "Scene.hpp"

class Game
{
public:
	Game(int argc, char** argv);
	virtual ~Game();

	int exec(void);

protected:
	void loop(void);

	void processInput(void);
	void update(float deltatime);
	void render(void);

	sf::RenderWindow mainWindow;
	bool running;

	Scene::Ptr currentScene;
};


#endif /* GAME_H_ */
