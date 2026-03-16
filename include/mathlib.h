#ifndef MATHLIB_H
#define MATHLIB_H

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
int power(int a, int b)
{
    int c = 1;
    for (int i = 0; i < b; ++i)
    {
        c = c * a;
    }
    return c;
}

// Функция для вычисления факториала числа n
unsigned long long factorial(int n)
{
    if (n < 0)
        return -1; // ошибка для отрицательных чисел
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

} // namespace mathlib

#endif // MATHLIB_H