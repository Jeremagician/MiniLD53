#ifndef HERO_H_
#define HERO_H_

#include "Actors.h"

class Hero : public Actors
{
public:
	Hero(int health, int power, std::string name);
	virtual void use(Actors object) =0;
	void takeDamage(int amount);
	void heal(int amount);
	virtual void talk(Actors object) =0;
	void update(float delta);

protected:
	int health;
	int power;
	const int VELOCITY;
	const int JUMP_VELOCITY;
	std::string name;
};


#endif /* HERO_H_ */
