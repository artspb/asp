#ifndef SOLVE_H
#define SOLVE_H

#include <QList>

class Solve
{
public:
    Solve() {} // Пустой конструктор.
    ~Solve() {} // Пустой деструктор.
    static QList<double> cube(double, double, double); // Возвращает корни приведенного кубического уравнения в обмен на коэффициенты.
    static QList<double> cube(double, double, double, double); // Возвращает корни кубического уравнения в обмен на коэффициенты.
    static double * mult(double *, double *); // Вызывает массив коэффициентов z при заданных p и q.
    static double * mult(int); // Вызывает массив коэффициентов z при стандартных p и q.

private:
    static const double accuracy = 1e-8; // Точность.
    static int sign(double); // Возвращает знак переменной.
};

#endif // SOLVE_H
