#pragma once
#include "Grzejnik.h"
#include "Pomieszczenie.h"

class Regulator
{
protected:
	Pomieszczenie *pom = nullptr;
	Grzejnik* grzej = nullptr;
	float zadana_temperatura;
public:
	virtual void steruj(float _czas) = 0;

};

