#include <iostream>
#include <string>
#include <random>

using namespace std;

/**
 * \brief Проверка ввода размера массива.
 * \return Размер массива.
 */
size_t GetSize();

/**
 * \brief Вывод элементов массива, значения которых больше заданного числа А.
 * \param myArray массив.
 * \param size размер массива.
 */
void ArrayPrintIndex(const int* myArray, const size_t size);

/**
 * \brief Заполнение массива случайными числами.
 * \param size размер массива.
 * \param minValue минимальное значение элементов массива.
 * \param maxValue максимальное значение элементов массива.
 * \return заполненный массив.
 */
int* getRandomInputArray(size_t size, int minValue, int maxValue);

/**
 * \brief Вывод массива на консоль.
 * \param myArray массив.
 * \param size размер массива.
 */
void ArrayPrint(const int* myArray, const size_t size);

/**
 * \brief Функция для нахождения суммы элементов, имеющих нечетное значение.
 * \param myArray массив.
 * \param size размер массива.
 * \return Сумма элементов, имеющих нечетное значение.
 */
int Sum(const int* myArray, const size_t size);

/**
 * \brief Замена второго элемента массива на максимальный среди отрицательных.
 * \param myArray массив.
 * \param size размер массива.
 * \return maxValue максимальное значение, которое может принимать элемент массива.
 */
int* Replace(int* myArray, const size_t size, const int minValue);

/**
 * \brief Метод, возвращающий заполненный пользователем массив.
 * \param size размер массива.
 * \param minValue минимальное значение элементов массива.
 * \param maxValue максимальное значение элементов массива.
 * \return заполненный массив.
 */
int* ReturnUserArray(size_t size);

/**
 * \brief Варианы ввода массива
 * \MANUAL Ручной способ
 * \RANDOM заполнение массива случайными числами
 */
enum class ArrayInputChoise
{
    RANDOM,
    MANUAL
};

/**
 * \brief Точка входа в программу.
 * \return 0, в случае успеха.
 */
int main()
{
    size_t size = GetSize();

    if (size == 0)
        return 1;

    cout << "Как вы хотите заполнить массив?\n";
    cout << static_cast<int>(ArrayInputChoise::RANDOM) << " - random,\n";
    cout << static_cast<int>(ArrayInputChoise::MANUAL) << " - manual.\n";
    cout << "Ваш выбор: ";
    int choice;
    cin >> choice;

    const auto chosen = static_cast<ArrayInputChoise>(choice);
    int* myArray = nullptr;

    auto minValue = 0;
    auto maxValue = 0;
    cout << "Введите диапазон чисел массива (сначала минимум, потом максимум) " << endl;
    cin >> minValue >> maxValue;

    if (maxValue <= minValue)
    {
        cout << "Введен неправильный диапазон!" << endl;
    }

    switch (chosen)
    {
    case ArrayInputChoise::RANDOM:
    {
        myArray = ReturnUserArray(size, minValue, maxValue);
        break;
    }
    case ArrayInputChoise::MANUAL:
    {
        myArray = ReturnUserArray(size);
        break;
    }
    }

    ArrayPrint(myArray, size);

    cout << "Сумма нечетных элементов массива: "<<Sum(myArray, size)<<endl;

    Sum(myArray, size);

    cout << "Индексы элементов больших а" << endl;
    ArrayPrintIndex(myArray, size);
    cout << endl;

    Replace(myArray, size, minValue);
    ArrayPrint(myArray, size);

    myArray = Replace(myArray, size, maxValue);
    if (myArray != nullptr) {

        delete[] myArray;
        myArray = nullptr;

    }
    return 0;

}

size_t GetSize() {
    int size = 0;
    cout << "Введите размер массива" << endl;
    cin >> size;
    if (size <= 0)
    {
        cout << "Введён неверный размер";
        return 0;
    }
    else
        return size;
};

int Sum(const int* myArray, const size_t size) {
    int sum = 0;
    for (size_t index = 0; index < size; index++) {
        if (myArray[index] % 2 == 1)
            sum+= myArray[index]; {
        }
    }
    return sum;
}

void ArrayPrintIndex(const int* myArray, const size_t size) {
    int a;
    cout << "Введите a"<< endl;
    cin >> a;
    for (size_t index = 0; index < size; index++) {
        if ((myArray[index]) > a) {
            cout << index << " ";
        }
    }
}

int* Replace(int* myArray, const size_t size, const int minValue)
{
    int temprary = 0;
    if (myArray == nullptr)
        cout << "Массив пуст";

    auto maxNegativeArrayValue = minValue;
    size_t maxNegativeElementIndex = 0;

    for (size_t index = 0; index < size; index++) {
        if (myArray[index] <0 && myArray[index] > maxNegativeArrayValue) {
            maxNegativeArrayValue = myArray[index];
            maxNegativeElementIndex = index;
        }
    }

    if (maxNegativeArrayValue > 0) {
        cout << "Ошибка";
    }
    else {
        temprary = myArray[maxNegativeElementIndex];
        myArray[maxNegativeElementIndex] = myArray[(size - 1) / 2];
        myArray[(size - 1) / 2] = temprary;
    }

    return myArray;
}

void ArrayPrint(const int* myArray, const size_t size)
{
    if (myArray == nullptr)
    {
        cout << "Массива не существует";
    }
    else {
        cout << "\nМассив:\n";
        for (size_t index = 0; index < size; index++) {
            cout << myArray[index] << " ";
        }
        cout << "\n";

    }
}

int* getRandomInputArray(const size_t size, const int minValue, const int maxValue)
{
    random_device rd;

    mt19937 gen(rd());

    const std::uniform_int_distribution<> uniformIntDistribution(minValue, maxValue);

    auto* myArray = new int[size];

    for (size_t index = 0; index < size; index++)
    {
        myArray[index] = uniformIntDistribution(gen);
    }
    return myArray;
}

int* ReturnUserArray(const size_t size)
{
    auto* array = new int[size];
    cout << "Введите элементы массива" << "\n";
    for (size_t index = 0; index < size; index++)
    {
        cin >> array[index];
    }
    return array;
}