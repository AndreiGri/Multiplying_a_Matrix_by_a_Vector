#include <iostream>

void filling_the_matrix(float (*matrix)[4])                                         // Метод проверяет корректность ввода значений
{                                                                                   // матрицы и записывает их в матрицу
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            float n;
            std::cout << ' ';
            std::cin >> n;
            if (std::cin.fail() || std::cin.peek() != '\n')                         // если предыдущее извлечение оказалось неудачным,
            {
                std::cerr << " Incorrectly entered data!\n Try again!" << std::endl;
                std::cin.clear();                                                   // то возвращаем cin в 'обычный' режим работы
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // и удаляем значения предыдущего ввода из входного буфера
                j--;
            }
            else
            {
                matrix[i][j] = n;                                                   // иначе записываем данные в ячейку
            }
        }
    }
}

void filling_the_matrix1(float *matrix)                                            // Метод проверяет корректность ввода значений
{                                                                                  // вектора и записывает их в массив
    for (int j = 0; j < 4; j++)
    {
        float n;
        std::cout << ' ';
        std::cin >> n;
        if (std::cin.fail() || std::cin.peek() != '\n')                            // если предыдущее извлечение оказалось неудачным,
        {
            std::cerr << " Incorrectly entered data!\n Try again!" << std::endl;
            std::cin.clear();                                                      // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // и удаляем значения предыдущего ввода из входного буфера
            j--;
        }
        else
        {
            matrix[j] = n;                                                        // иначе записываем данные в ячейку
        }
    }
}

int main()
{
    float a[4][4];                                                               // Объявляем массив квадратной матрицы
    float b[4];                                                                  // Обявляем массив вектора
    float c[4];                                                                  // Объявляем массив результата умножения матрицы на вектор

    std::cout << " Enter mtaritsa values:" << std::endl;                         // Запрашиваем данные для матрицы
    filling_the_matrix(a);                                                       // Записываем данные в матрицу
    std::cout << " Enter vector values:" << std::endl;                           // Запрашиваем данные для вектора
    filling_the_matrix1(b);                                                      // Записываем данные вектора
}