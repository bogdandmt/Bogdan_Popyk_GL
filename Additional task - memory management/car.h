/**
 * @file	car.h
 * @brief	Include file for class "Car"
 */

#ifndef _CAR_H_
#define _CAR_H_

#define COLOR_MAX	16777215U
#define YEAR_MAX	2012U
#define KM_MAX		2097151U
#define CAR_SZ		sizeof(Car)

typedef unsigned int UI;

enum Brand
{
	ALFA_ROMEO,
	ASTON_MARTIN,
	AUDI,
	BENTLEY,
	BMW,
	CADILLAC,
	CHEVROLET,
	CHRYSLER,
	CITROEN,
	DODGE,
	FERRARI,
	FIAT,
	FORD,
	HONDA,
	HUMMER,
	HYUNDAI,
	JAGUAR,
	JEEP,
	KIA,
	KOENIGSEGG,
	LAMBORGHINI,
	LAND_ROVER,
	LEXUS,
	MASERATI,
	MAYBACH,
	MAZDA,
	MERCEDES_BENZ,
	MITSUBISHI,
	NISSAN,
	OPEL,
	PEUGEOT,
	PORSCHE,
	RENAULT,
	ROLLS_ROYCE,
	SKODA,
	SUBARU,
	SUZUKI,
	TOYOTA,
	VOLKSWAGEN,
	VOLVO,
};

char *brands[] =
#pragma region brands
{
	"ALFA_ROMEO",
	"ASTON_MARTIN",
	"AUDI",
	"BENTLEY",
	"BMW",
	"CADILLAC",
	"CHEVROLET",
	"CHRYSLER",
	"CITROEN",
	"DODGE",
	"FERRARI",
	"FIAT",
	"FORD",
	"HONDA",
	"HUMMER",
	"HYUNDAI",
	"JAGUAR",
	"JEEP",
	"KIA",
	"KOENIGSEGG",
	"LAMBORGHINI",
	"LAND_ROVER",
	"LEXUS",
	"MASERATI",
	"MAYBACH",
	"MAZDA",
	"MERCEDES_BENZ",
	"MITSUBISHI",
	"NISSAN",
	"OPEL",
	"PEUGEOT",
	"PORSCHE",
	"RENAULT",
	"ROLLS_ROYCE",
	"SKODA",
	"SUBARU",
	"SUZUKI",
	"TOYOTA",
	"VOLKSWAGEN",
	"VOLVO",
};
#pragma endregion brands

struct Car
{
	Brand brand;	
	UI color : 24;
	UI year : 11;	
	UI kmetrage : 21;	
	char *surname;

	Car() : brand(ALFA_ROMEO), color(0), year(0), kmetrage(0) 
	{
		surname = new char('\0');
	}

	Car(const Car &car)
	{
		if (this != &car)
		{
			brand = car.brand;
			color = car.color;
			year = car.year;
			kmetrage = car.kmetrage;
			surname = new char[strlen(car.surname) + 1];
			strcpy(surname, car.surname);
		}
	}

	Car(Brand _brand, UI _color, UI _year, UI _kmetrage, const char *_surname)
	{
		if (_color <= COLOR_MAX && _year <= YEAR_MAX && _kmetrage <= KM_MAX)
		{
			brand = _brand;
			color = _color;
			year = _year;
			kmetrage = _kmetrage;
			surname = new char[strlen(_surname) + 1];
			strcpy(surname, _surname);
		}
		else
		{
			brand = ALFA_ROMEO;
			color = 0;
			year = 0;
			kmetrage = 0;
			surname = new char('\0');
		}
	}

	~Car()
	{
		delete surname;
	}

	friend std::ostream& operator<<(std::ostream &out, const Car &car)
	{
		out << brands[car.brand] << ' ' << car.color << ' ' << car.year << ' ' << car.kmetrage << ' ' << car.surname;
		return out;
	}
};

#endif /* _CAR_H_ */