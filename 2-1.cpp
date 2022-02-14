#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

/**
 * \brief Константы объёма и площади поверхности шара.
 */
enum class ball
{
    /**
     * \brief Объём шара.
     */
    size,

    /**
     * \brief Площадь поверхности шара.
     */
    square
};

/**
*\ brief Математическая функция, рассчитывающая объём шара
*\ R - радиус шара
*\ return - объём шара
**/
double GetSize(const double R);

/**
*\ brief Математическая функция, рассчитывающая площадь поверхности шара
*\ R - радиус шара
*\ return - площадь поверхности шара
**/
double GetSquare(const double R);

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успеха.
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Выберите что нужно решить. "
        << "\nОбъём - " << static_cast<int>(ball::size)
        << "\nПлощадь поверхности - " << static_cast<int>(ball::square);
    cout << endl; 
    int choise;
    cin >> choise;
    double R = 0.0;
    cout << "Введите R ";
    cin >> R;

    const auto Figure = static_cast<ball>(choise);
    switch (Figure)
    {
    case ball::size:
        cout << "V = " << GetSize(R);
        break;
    case ball::square:
        cout << "S = " << GetSquare(R);
        break;
        return 0;
    }
}

double GetSize(const double R) 
{
    return (pow(R, 3)* ((4 * M_PI) / 3));
}

double GetSquare(const double R) 
{
    return (pow(R, 2)* M_PI * 4) ;
}
