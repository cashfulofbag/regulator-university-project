#pragma once
#include "Regulator.h"
class Regulator_bb :public Regulator
{
public:
    Regulator_bb(float _zadana, Pomieszczenie* _pom, Grzejnik* _grzej);
    virtual void steruj(float _czas);
};

