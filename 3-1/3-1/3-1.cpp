#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/*
* \brief вычисление значения функции
* \param x значение переменной x
* \return значение функции
*/
double getY(const double x);

/*
* \brief выполняет функцию
* \param x значение переменной x
* \return 0, в случае успеха
*/
double NoGetY(const double x);

/*
* \brief точка входа в программу
* \return 0, в случае успеха
*/
int main()
{
    setlocale(0, "rus");
    cout << fixed << setprecision(5);
    double x = -10;
    const auto edge = 2.3;
    const auto step = 0.1;

    for (x; x <= edge; x += step)
    {
        if (NoGetY(x))
        {
            cout << "Нет решений" << endl;
        }
        cout << "x = " << x << " " << "y = " << getY(x) << " " << "\n";
    }

    return 0;
}

double getY(const double x)
{
    return 3 * sin(sqrt(x)) + 0.39 * x - 3.8;
}
