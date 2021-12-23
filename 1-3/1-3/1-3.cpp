#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>


using namespace std;

/*
* @brief вычисление пути пройдёным машиной
* @param a совершенная работа
* @param f сила тяги
* @return путь пройденный автомобилем
*/
double getMass(const double v, const double m);

int main()
{
	setlocale(0, "rus"); //перевод на русские буквы
	cout << "Введите массу пули - M: ";
	double m = 0;
	cin >> m;
	cout << "Ведите скорость - V: ";
	double v = 0;
	cin >> v;

	//double power = m * (v * v) / 2;

	cout << "Дж: " << getMass(v, m) << endl;
	return 0;
}

double getMass(const double v, const double m)
{
	return  (m * (v * v) / 2);
}