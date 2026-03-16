#ifndef MATHLIB_H
#define MATHLIB_H

#include <iostream>

namespace mathlib {

// Функция для сложения двух чисел
int addition(int a, int b)
{
    return a + b;
}

// Функция для вычитания двух чисел
int substraction(int a, int b)
{
    return a - b;
}


// Функция для умножения двух чисел
int multiplication(int a, int b)
{
    return a * b;
}

// Функция для деления двух чисел
int division(int a, int b, int* c)
{
    if (b == 0)
        return -1;
    *c = a / b;
    return 0;
}

// Функция для возведения числа a в степень b
double power(int a, int b)
{
    double c = 1.0;

    if (b >= 0)
    {
        for (int i = 0; i < b; ++i)
        {
            c *= a;
        }
           
    }
    else     
    {
        for (int i = 0; i < -b; ++i)
        {
            c *= a;
        }

        // Инвертируем результат для отрицательной степени
        c = 1.0 / c;
    }
    return c;
}

// Функция для вычисления факториала числа n
unsigned long long factorial(int n)
{
    // Проверяем, что число не отрицательное
    if (n < 0)
    {
        std::cerr << "Error! Factorial of negative number.\n";
        return -1; 
    }
    
    // Базовый случай: 0! = 1! = 1
    if (n == 0 || n == 1)
    {
        return 1;
    }
    
    // Рекурсивный вызов для n * (n - 1)!
    return n * factorial(n - 1);
}

} // namespace mathlib

#endif // MATHLIB_H