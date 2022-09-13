#include <iostream>
#include "Symulacja.h"

int main()
{
	std::locale pol("pl_PL");
	std::locale::global(pol);
	float _wys, _szer, _gleb, _moc_nom;

	std::cout << "Podaj wysokoœæ pomieszczenia" << std::endl;
	while (1)
	{
		std::cin >> _wys;
		if (std::cin.fail() == true)
		{
			std::cout << "wykryto blad" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else break;
	}

	std::cout << "Podaj szerokoœæ pomieszcznia" << std::endl;
	while (1)
	{
		std::cin >> _szer;
		if (std::cin.fail() == true)
		{
			std::cout << "wykryto blad" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else break;
	}

	std::cout << "Podaj g³êbokoœæ pomieszcznia" << std::endl;
	while (1)
	{
		std::cin >> _gleb;
		if (std::cin.fail() == true)
		{
			std::cout << "wykryto blad" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else break;
	}

	if (_szer == 0) _szer = 0.1;
	if (_wys == 0) _wys = 0.1;
	if (_gleb == 0) _gleb = 0.1;

	std::cout << "Podaj moc nominaln¹ grzejnika" << std::endl;
	while (1)
	{
		std::cin >> _moc_nom;
		if (std::cin.fail() == true)
		{
			std::cout << "wykryto blad" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else break;
	}
	if(_moc_nom < 0)
	{
		_moc_nom = 0;
	}

	Symulacja sym(_wys, _szer, _gleb, _moc_nom);
}