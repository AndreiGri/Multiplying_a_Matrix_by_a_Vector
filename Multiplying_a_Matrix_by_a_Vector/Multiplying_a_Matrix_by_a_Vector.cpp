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

void filling_the_vector(float *matrix)                                             // Метод проверяет корректность ввода значений
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

void show_vector(float* matrix)                                                   // Метод выводит в консоль вектор
{
    for (int i = 0; i < 4; i++)
    {
        int level = 1;
        std::cout << std::string(level * 2, ' ') << '|' << '\t' << matrix[i] << '\t' << '|' << std::endl;
    }
}

void show_matrix(float(*matrix)[4])                                              // Метод выводит в консоль матрицу
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int level = 1;
            if (j == 0)
            {
                std::cout << std::string(level * 2, ' ') << '|' << '\t' << matrix[i][j] << ',' << '\t';
            }
            else
            {
                if (j == 3)
                {
                    std::cout << matrix[i][j] << '\t' << '|' << std::endl; 
                }
                else
                {
                    std::cout << matrix[i][j] << ',' << '\t';
                }
            }
        }
    }
}

void multiplaying_a_matrix_by_a_vector(float(*matrix1)[4], float* matrix2, float* matrix3) // Метод умножает матрицу на вектор
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matrix3[i] += matrix1[i][j] * matrix2[i];
        }
    }
}

int main()
{
    system("color 80");

    int level = 1;
    float a[4][4];                                                                // Объявляем массив квадратной матрицы
    float b[4];                                                                   // Обявляем массив вектора
    float c[4]{ 0, 0, 0, 0 };                                                     // Объявляем массив результата умножения матрицы на вектор

    std::cout << " Enter mtaritsa values:" << std::endl;                          // Запрашиваем данные для матрицы
    filling_the_matrix(a);                                                        // Записываем данные в матрицу
    std::cout << " Enter vector values:" << std::endl;                            // Запрашиваем данные для вектора
    filling_the_vector(b);                                                        // Записываем данные вектора
    multiplaying_a_matrix_by_a_vector(a, b, c);                                   // Умножаем матрицу на вектор
    std::cout << std::endl;
    std::cout << std::string(level * 2, ' ') << " Multiplying the matrix" << std::endl;
    std::cout << std::endl;
    show_matrix(a);                                                               // Выводим в консоль матрицу
    std::cout << std::endl;
    std::cout << std::string(level * 2, ' ') << " by vector" << std::endl;
    std::cout << std::endl;
    show_vector(b);                                                               // Выводим в консоль вектор - множитель
    std::cout << std::endl;
    std::cout << std::string(level * 2, ' ') << " Result:" << std::endl;
    std::cout << std::endl;
    show_vector(c);                                                               // Выводим в консоль вектор - результат
}