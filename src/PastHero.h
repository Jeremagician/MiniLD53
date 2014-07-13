#include "Hero.h"

class PastHero : Hero
{
public:
	PastHero::PastHero(int seedAmount);
	void PastHero::talk(Actors other);
	void PastHero::use(Actors other);
protected:
	int seedAmount;
};