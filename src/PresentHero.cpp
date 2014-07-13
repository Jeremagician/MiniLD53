#include "PresentHero.h"

class PresentHero : Hero
{
protected:
	PresentHero::PresentHero(int munitionAmount, int moneyAmount) : Hero(10, 20, "Al Capone"), munitionAmount(munitionAmount), moneyAmount(moneyAmount)
	{
	}

	void PresentHero::talk(Actors other){
		//bla bla if other is PNJ
	}

	void PresentHero::use(Actors other){
		//use some seed or weed ?
	}
public:
	int munitionAmount;
	int moneyAmount;

};