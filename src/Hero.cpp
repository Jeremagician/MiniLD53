#include "Hero.h"

class Hero : Actors
{
	public:
		Hero::Hero(int maxHealth, int power, std::string name) : health(maxHealth), power(power), name(name), maxHealth(maxHealth), VELOCITY(4), JUMP_VELOCITY(4)
		{
		}

		bool Hero::isDead(){
			return Hero::health <= 0;
		}

		bool Hero::takeDamage(int amount){
			Hero::health -= amount;
			if (Hero::health < 0)
				Hero::health = 0;

			return Hero::isDead;
		}

		void heal(int amount){
			Hero::health += amount;
			if (Hero::health > maxHealth)
				Hero::health = maxHealth;
		}

		void update(float delta){
			Actors::update(delta);
			//Actors::move();
		}

		bool isFacingLeft()
		{
			return Hero::facingLeft;
		}

	private:
		int health, maxHealth;
		int power;
		const int VELOCITY;
        const int JUMP_VELOCITY;
		std::string name;
		bool facingLeft = true;
};