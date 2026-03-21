#ifndef MATHLIB_H
#define MATHLIB_H

#include <cstdio>
#include <cstdint>

namespace mathlib {

    int addition(int a, int b, double* result_ptr)
    {
        int result;

        // Проверка переполнения
        if (__builtin_add_overflow(a, b, &result))
        {
            fprintf(stderr, "Error! Overflow\n");
            return -1;
        }

        *result_ptr = (double)result;    // сохраняем результат в указатель
        return 0;
    }

    // Функция для вычитания двух чисел
    int substraction(int a, int b, double* result_ptr)
    {
        int result;

        // Проверка переполнения
        if (__builtin_sub_overflow(a, b, &result))
        {
            fprintf(stderr, "Error! Overflow\n");
            return -1;
        }

        *result_ptr = (double)result;  // сохраняем результат в указатель
        return 0;
    }


    // Функция для умножения двух чисел
    int multiplication(int a, int b, double* result_ptr)
    {
        int result;

        // Проверка переполнения
        if (__builtin_mul_overflow(a, b, &result))
        {
            fprintf(stderr, "Error! Overflow\n");
            return -1;
        }

        *result_ptr = (double)result;  // сохраняем результат в указатель
        return 0;
    }

    // Функция для деления двух чисел
    int division(int a, int b, double* result)
    {
        if (b == 0)
        {
            fprintf(stderr, "Error! Division by zero!\n");
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
            fprintf(stderr, "Error! Factorial of negative number.\n");
            return -1;
        }

        *result = factorial_recursive(n);
        return 0;
    }

} // namespace mathlib

#endif // MATHLIB_H