#include "Regulator_pid.h"

Regulator_pid::Regulator_pid(float _zadana, Pomieszczenie* _pom, Grzejnik* _grzej, float _kp, float _ki, float _kd)
	:kp(_kp)
	,ki(_ki)
	,kd(_kd)
{
	zadana_temperatura = _zadana;
	pom = _pom;
	grzej = _grzej;
	suma_uchybu = 0;
	uchyb_pop = 0;
}

void Regulator_pid::steruj(float _czas)
{
	if (pom == nullptr) throw "B��d przypisania pomieszczenia";				//wyj�tki
	if (grzej == nullptr) throw "B��d przypisania grzejnika";
	if (_czas == 0) throw "B��d pr�ba dzielnia przez 0";
	
	float uchyb = zadana_temperatura - pom->getTemperatura();
	float up = kp * uchyb;				//proporcjonalna
	float ut = uchyb * _czas;			//ca�kuj�ca
	suma_uchybu = suma_uchybu + ut;
	float ui = ki * suma_uchybu;
	float du = (uchyb - uchyb_pop) / _czas;		//r�niczkuj�ca
	float ud = kd * du;

	float u = ud + ui + up;

	float cieplo1 = grzej->cieplo(u);
	pom->dodajCieplo(cieplo1);
}