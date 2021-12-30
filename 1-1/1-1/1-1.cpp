#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;
/**
* @brief Функция для вычисление значения A
* @param x параметр x
* @param y параметр y
* @param z параметр z
* @return значение A
*/
double getA(const double x, const double y, const double z);

/**
* @brief Функция для вычисление значения B
* @param x параметр x
* @param y параметр y
* @param z параметр z
* @return значение B
*/
double getB(const double x, const double y, const double z);

/**
* @brief Точка входа в программу
* @return 0 в случае успеха
*/
int main()
{
	const double x = 1.426;
	const double y = -1.22;
	const double z = 3.5;
	double a = getA(x, y, z);
	double b = getB(x, y, z);
	cout « "a = " « a « endl;
	cout « "b = " « b « endl;
	return 0;
}

double getA(const double x, const double y, const double z)
{
	return 2 * cos((x - M_PI / 6)) / 1.0 / 2 + pow(sin(y), 2);
}

double getB(const double x, const double y, const double z)
{
	return 1 + (z * z) / 3 + ((z * z) / 5);
}
