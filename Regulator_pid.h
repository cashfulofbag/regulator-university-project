#pragma once
#include <vector>
#include "Regulator.h"
class Regulator_pid :
    public Regulator
{
    float kp;
    float ki;
    float kd;
    float suma_uchybu;
    float uchyb_pop;

public:
    Regulator_pid(float _zadana, Pomieszczenie* _pom, Grzejnik* _grzej, float _kp, float _ki, float _kd);
    virtual void steruj(float _czas);

};

