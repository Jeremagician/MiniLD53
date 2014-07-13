#include "PastHero.h"

class PastHero : Hero
{
protected:
	PastHero::PastHero(int seedAmount) : Hero(10, 20, "Charles"), seedAmount(seedAmount)
	{
	}

	void PastHero::talk(Actors other){
		//bla bla
	}

	void PastHero::use(Actors other){
		//use some seed or weed ?
	}
public:
	int seedAmount;

};