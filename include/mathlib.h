#ifndef MATHLIB_H
#define MATHLIB_H

#include <cstdio>
#include <cstdint>

// Библиотека для выполнения базовых математических операций над целыми числами
// Каждая функция принимает два целых числа в качестве аргументов и указатель на переменную для сохранения результата.
// Функция вычисления факториала принимает одно целое число и указатель на переменную для сохранения результата.
// Результат сохраняется в переменной, на которую указывает указатель, переданный в функцию.
// Функции возвращают целое число, указывающее на статус выполнения операции:
//  0 - успешное выполнение, 
// -1 - общая ошибка, 
//  1 - переполнение, 
//  2 - деление на ноль, 
//  3 - отрицательный факториал.

namespace mathlib {

    // Функция для сложения
    int addition(int a, int b, double* result_ptr)
    {
        int result;
        if (__builtin_add_overflow(a, b, &result))
        {
            return 1;
        }
        *result_ptr = (double)result;
        return 0;
    }

    // Функция для вычитания
    int substraction(int a, int b, double* result_ptr)
    {
        int result;
        if (__builtin_sub_overflow(a, b, &result))
        {
            return 1;
        }
        *result_ptr = (double)result;
        return 0;
    }

    // Функция для умножения
    int multiplication(int a, int b, double* result_ptr)
    {
        int result;
        if (__builtin_mul_overflow(a, b, &result))
        {
            return 1;
        }
        *result_ptr = (double)result;
        return 0;
    }

    // Функция для деления
    int division(int a, int b, double* result_ptr)
    {
        if (b == 0)
        {
            return 2;
        }
        *result_ptr = (double)a / b;
        return 0;
    }

    // Функция для возведения числа a в степень b
    int power(int a, int b, double* result_ptr)
    {
        double temp = 1.0;

        if (b >= 0)
        {
            for (int i = 0; i < b; ++i) temp *= a;
        }
        else
        {
            if (a == 0)
            {
                return -1;
            }
            for (int i = 0; i < -b; ++i) temp *= a;
            temp = 1.0 / temp;
        }

        // Проверка переполнения double
        if (temp != temp || temp == 1.0 / 0.0) // NaN или inf
        {
            return 1;
        }

        *result_ptr = temp;
        return 0;
    }

    // Рекурсивная функция факториала
    double factorial_recursive(int n)
    {
        if (n == 0 || n == 1) return 1.0;
        return n * factorial_recursive(n - 1);
    }

    // Функция факториала
    int factorial(int n, double* result_ptr)
    {
        if (n < 0)
        {
            return 3;
        }
        *result_ptr = factorial_recursive(n);
        return 0;
    }

} // namespace mathlib

#endif // MATHLIB_H