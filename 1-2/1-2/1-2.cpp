#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;
/*
* @brief вычисление площади прямоугольника
* @param A длина 1-ой стороны прямоугольника
* @param B длина 2-ой стороны прямоугольника
* @return площадь прямоугольника
*/
double getA(const double a, const double b);

/*
* @brief вычисление периметра прямоугольника
* @param A длина 1-ой стороны прямоугольника
* @param B длина 2-ой стороны прямоугольника
* @return периметра прямоугольника
*/
double getB(const double a, const double b);

int main()
{
setlocale(0, "rus");
double n;
cout << "Введите коэффицент n: ";
cin >> n;
double a;
cout << "Введите длину стороны А: ";
cin >> a;
double b = n * a;
cout << "Площадь прямоугольника равна: " << getA(n, a) << endl;
cout << "Периметр прямоугольника равен: " << getB(n, a) << endl;

}

double getA(const double a, const double b)
{
return (a * b);
}

double getB(const double a, const double b)
{
return (2 * (a * b));
}
