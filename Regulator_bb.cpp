#include "Regulator_bb.h"

Regulator_bb::Regulator_bb(float _zadana, Pomieszczenie* _pom, Grzejnik* _grzej)
{
	zadana_temperatura = _zadana;
	pom = _pom;
	grzej = _grzej;
}

void Regulator_bb::steruj(float _czas)
{
	if (pom == nullptr) throw "B³¹d przypisania pomieszczenia";				//wyj¹tki
	if (grzej == nullptr) throw "B³¹d przypisania grzejnika";

	if (zadana_temperatura > pom->getTemperatura())
	{
		float cieplo1 = grzej->cieplo(1);
		pom->dodajCieplo(cieplo1);
	}
	else
	{
		float cieplo1 = grzej->cieplo(0);
		pom->dodajCieplo(cieplo1);
	}
}