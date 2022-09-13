#include "Grzejnik.h"

Grzejnik::Grzejnik(const float _moc_nominalna)
{
	moc_nominalna = _moc_nominalna;
	poziom_mocy = 0;
}

float Grzejnik::cieplo(float _sterowanie)
{
	poziom_mocy = _sterowanie;
	if (poziom_mocy > 1)
	{
		poziom_mocy = 1;
	}
	if (poziom_mocy < 0)
	{
		poziom_mocy = 0;
	}
	return (moc_nominalna * poziom_mocy);
}

float Grzejnik::daj_poziom_mocy()
{
	return poziom_mocy;
}