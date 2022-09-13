#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Pomieszczenie.h"
#include "Grzejnik.h"
#include "Regulator.h"
#include "Regulator_bb.h"
#include "Regulator_pid.h"
class Symulacja
{
	Pomieszczenie pom;
	Grzejnik grzejnik1;
	float czas_calkowity;
	std::vector <float> temp;
	std::vector <float> czas;
	std::vector <float> moc;
	Regulator* reg;
	float temp_zadana;
	int w_reg;

public:
	Symulacja(float _wys, float _szer, float _gleb, float _moc_nom);
	~Symulacja();
	Symulacja(const Symulacja& _sym_kopia) = delete;					//zasada 3
	Symulacja& operator=(const Symulacja& _sym_kopia) = delete;
	void wybierz_bb();
	void wybierz_pid();
	void iteracja(float _czas);
	void przebieg(float _czas, int _ilosc);
	void zapis();
};

