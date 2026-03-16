#ifndef MATHLIB_H
#define MATHLIB_H

#include <iostream>

namespace mathlib {

    bool check_overflow(long long value)
    {
        if (value > INT_MAX || value < INT_MIN)
        {
            std::cerr << "Error! Overflow\n";
            return true;
        }
        return false;
    }

    // Функция для сложения двух чисел
    int addition(int a, int b, double* result)
    {
        long long temp = (long long)a + b;

        if (check_overflow(temp))
        {
            return -1;
        }

        *result = (double)temp;
        return 0;
    }

    // Функция для вычитания двух чисел
    int substraction(int a, int b, double* result)
    {
        long long temp = (long long)a - b;

        if (check_overflow(temp))
        {
            return -1;
        }

        *result = (double)temp;
        return 0;
    }


    // Функция для умножения двух чисел
    int multiplication(int a, int b, double* result)
    {
        long long temp = (long long)a * b;

        if (check_overflow(temp))
        {
            return -1;
        }

        *result = (double)temp;
        return 0;
    }

    // Функция для деления двух чисел
    int division(int a, int b, double* result)
    {
        if (b == 0)
        {
            std::cerr << "Error! Division by zero!\n";
            return -1;
        }        
        *result = (double)a / b;
        return 0;
    }

    // Функция для возведения числа a в степень b
    int power(int a, int b, double* result)
    {
        double temp = 1.0;

        if (b >= 0)
        {
            for (int i = 0; i < b; ++i)
            {
                temp *= a;
            }           
        }
        else     
        {
            for (int i = 0; i < -b; ++i)
            {
                temp *= a;
            }

            // Инвертируем результат для отрицательной степени
            temp = 1.0 / temp;
        }
        *result = temp;
        return 0;
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