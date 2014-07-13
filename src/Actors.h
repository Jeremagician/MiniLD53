#ifndef ACTORS_H_
#define ACTORS_H_

#include <SFML/Graphics.hpp>

enum class State {IDLE, WALKING, JUMPING, DYING, ATTACKING, USING};

class Actors : public sf::Sprite
{
public:
	void update(float delta);

protected:
	float stateTime;
	State state;
};


#endif /* ACTORS_H_ */
