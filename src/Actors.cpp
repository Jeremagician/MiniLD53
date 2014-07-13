
#include "Actors.h"

class Actors:public sf::Sprite
{		
public:
	void Actors::update(float delta){
		Actors::stateTime += delta;
	}
	State Actors::getState(){
		return Actors::state;
	}

	void Actors::setScale(State state){
		Actors::state = state;
	}
protected:
	float stateTime;
	State state = State::IDLE;
};