#include "Symulacja.h"

Symulacja::Symulacja(float _wys, float _szer, float _gleb, float _moc_nom)
	:czas_calkowity(0)
	,reg(nullptr)
	,pom(_wys, _szer, _gleb)
	,grzejnik1(_moc_nom)
{
	int wybor, _iteracje;
	float _czas;

	std::cout << "Podaj temperaturê zadan¹" << std::endl;
	while (1)
	{
		std::cin >> temp_zadana;
		if (std::cin.fail() == true)
		{
			std::cout << "wykryto blad" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else break;
	}

	std::cout << "Podaj iloœc iteracji" << std::endl;
	while (1)
	{
		std::cin >> _iteracje;
		if (std::cin.fail() == true)
		{
			std::cout << "wykryto blad" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else break;
	}

	std::cout << "Podaj czas iteracji" << std::endl;
	while (1)
	{
		std::cin >> _czas;
		if (std::cin.fail() == true)
		{
			std::cout << "wykryto blad" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else break;
	}


	std::cout << "Jakiego regulatora chcesz u¿yæ" << std::endl;
	std::cout << "1. Regulator BB" << std::endl;
	std::cout << "2. Regulator PID" << std::endl;
	while (1)
	{
		std::cin >> wybor;
		if (std::cin.fail() == true)
		{
			std::cout << "wykryto blad" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else break;
	}
	switch (wybor)
	{
	case 1:
		wybierz_bb();
		if (reg == nullptr)
		{
			std::cout << "B³¹d wybrania regulatora" << std::endl;
			break;
		}
		try
		{
			przebieg(_czas, _iteracje);
		}
		catch (const char* _opis)
		{
			std::cout << _opis << std::endl;
		}
		break;
		break;
	case 2:
		wybierz_pid();
		if (reg == nullptr)
		{
			std::cout << "B³¹d wybrania regulatora" << std::endl;
			break;
		}
		try
		{
			przebieg(_czas, _iteracje);
		}
		catch (const char* _opis)
		{
			std::cout << _opis << std::endl;
		}
			break;
	default:
		std::cout << "Nie wybrano regulatora" << std::endl;
		break;
	}


}

Symulacja::~Symulacja()
{
	delete reg;
}

void Symulacja::iteracja(float _czas)
{
	czas_calkowity += _czas;
	reg->steruj(_czas);
	czas.push_back(czas_calkowity);
	temp.push_back(this->pom.getTemperatura());
	moc.push_back(this->grzejnik1.daj_poziom_mocy());
	this->pom.aktualizuj(_czas);
}

void Symulacja::przebieg(float _czas, int _ilosc)
{	
	
	for (int i = 0; i < _ilosc; i++)
	{
		this->iteracja(_czas);
		std::cout << "Aktualna temperatura: " << this->pom.getTemperatura() << std::endl;

	}
	zapis();
}

void Symulacja::zapis()
{
	std::ofstream plik;
	try
	{
		plik.open("symulacja.csv", std::ifstream::out);
		if (!(plik.good())) throw "Nie uda³o siê otworzyæ pliku";
		for (int i = 0; i < czas.size(); i++)
		{
			plik << i << ";" << czas[i] << ";" << temp[i] << ";" << moc[i] << ";" << std::endl;
		}
		plik.close();
	}
	catch (const char* _opis)
	{
		plik.close();
		std::cout << _opis << std::endl;
	}
}

void Symulacja::wybierz_bb()
{
	reg = new Regulator_bb(this->temp_zadana, &pom, &grzejnik1);
}

void Symulacja::wybierz_pid()
{
	reg = new Regulator_pid(this->temp_zadana, &pom, &grzejnik1, 4, 0.02, 0.1);
}