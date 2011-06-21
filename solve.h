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
    static QList<double> mult(QList<double>, QList<double>); // Вызывает массив коэффициентов z при заданных p и q.
    static QList<double> mult(QList<double>); // Вызывает массив коэффициентов z при заданном p, q = 1 - p.
    static QList<double> mult(int); // Вызывает массив коэффициентов z при стандартных p и q.

private:
    static const double accuracy = 1e-8; // Точность.
    static int sign(double); // Возвращает знак переменной.
};

#endif // SOLVE_H
