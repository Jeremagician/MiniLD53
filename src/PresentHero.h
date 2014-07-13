#include "Hero.h"

class PresentHero : Hero
{
public:
	PresentHero::PresentHero(int munitionAmount);
	void PresentHero::talk(Actors other);
	void PresentHero::use(Actors other);
protected:
	int munitionAmount;
};