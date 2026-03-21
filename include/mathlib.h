#ifndef MATHLIB_H
#define MATHLIB_H

#include <cstdio>
#include <cstdint>

// Библиотека для выполнения базовых математических операций над целыми числами
// Каждая функция принимает два целых числа в качестве аргументов и указатель на переменную для сохранения результата.
// Функция вычисления факториала принимает одно целое число и указатель на переменную для сохранения результата.
// Результат сохраняется в переменной, на которую указывает указатель, переданный в функцию.
// Функции возвращают целое число, указывающее на статус выполнения операции:
// OK                 (0)  - успешное выполнение, 
// ERROR              (-1) - общая ошибка, 
// OVERFLOW           (1)  - переполнение, 
// DIV_BY_ZERO        (2)  - деление на ноль, 
// NEGATIVE_FACTORIAL (3)  - отрицательный факториал.

namespace mathlib {

    // Enum для результатов выполнения операций
    enum Status {
        OK = 0,            // успешное выполнение
        ERROR = -1,        // общая ошибка
        OVERFLOW,          // переполнение
        DIV_BY_ZERO,       // деление на ноль
        NEGATIVE_FACTORIAL // отрицательный факториал
    };

    // Функция для сложения
    Status addition(int a, int b, double* result_ptr)
    {
        int result;
        if (__builtin_add_overflow(a, b, &result))
        {
            fprintf(stderr, "Error! Overflow\n");
            return OVERFLOW;
        }
        *result_ptr = (double)result;
        return OK;
    }

    // Функция для вычитания
    Status substraction(int a, int b, double* result_ptr)
    {
        int result;
        if (__builtin_sub_overflow(a, b, &result))
        {
            fprintf(stderr, "Error! Overflow\n");
            return OVERFLOW;
        }
        *result_ptr = (double)result;
        return OK;
    }

    // Функция для умножения
    Status multiplication(int a, int b, double* result_ptr)
    {
        int result;
        if (__builtin_mul_overflow(a, b, &result))
        {
            fprintf(stderr, "Error! Overflow\n");
            return OVERFLOW;
        }
        *result_ptr = (double)result;
        return OK;
    }

    // Функция для деления
    Status division(int a, int b, double* result_ptr)
    {
        if (b == 0)
        {
            fprintf(stderr, "Error! Division by zero!\n");
            return DIV_BY_ZERO;
        }
        *result_ptr = (double)a / b;
        return OK;
    }

    // Функция для возведения числа a в степень b
    Status power(int a, int b, double* result_ptr)
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
                fprintf(stderr, "Error! Zero to negative power\n");
                return ERROR;
            }
            for (int i = 0; i < -b; ++i) temp *= a;
            temp = 1.0 / temp;
        }

        // Проверка переполнения double
        if (temp != temp || temp == 1.0 / 0.0) // NaN или inf
        {
            fprintf(stderr, "Error! Overflow in power\n");
            return OVERFLOW;
        }

        *result_ptr = temp;
        return OK;
    }

    // Рекурсивная функция факториала
    double factorial_recursive(int n)
    {
        if (n == 0 || n == 1) return 1.0;
        return n * factorial_recursive(n - 1);
    }

    // Функция факториала
    Status factorial(int n, double* result_ptr)
    {
        if (n < 0)
        {
            fprintf(stderr, "Error! Factorial of negative number.\n");
            return NEGATIVE_FACTORIAL;
        }
        *result_ptr = factorial_recursive(n);
        return OK;
    }

} // namespace mathlib

#endif // MATHLIB_H