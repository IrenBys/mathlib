#ifndef MATHLIB_H
#define MATHLIB_H

#include <iostream>

namespace mathlib {

// Функция для сложения двух чисел
int addition(int a, int b, double* result)
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
int division(int a, int b, double* result)
{
    if (b == 0)
    {
        std::cerr << "Error! Division by zero!\n";
        return -1;
    }        
    *result = a / b;
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

// Функции для вычисления факториала числа n

double factorial_recursive(int n)
{
    // Базовый случай
    if (n == 0 || n == 1)
    {
        return 1.0;
    }
    
    // Рекурсивный
    return n * factorial_recursive(n - 1);
}

int factorial(int n, double* result)
{
    // Проверяем, что число не отрицательное
    if (n < 0)
    {
        std::cerr << "Error! Factorial of negative number.\n";
        return -1;
    }

    *result = factorial_recursive(n);
    return 0;
}

} // namespace mathlib

#endif // MATHLIB_H