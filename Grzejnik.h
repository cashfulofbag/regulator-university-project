#pragma once
class Grzejnik
{
	float moc_nominalna;
	float poziom_mocy;

public:
	Grzejnik(const float _moc_nominalna);
	float cieplo(float _sterowanie);
	float daj_poziom_mocy();
};

