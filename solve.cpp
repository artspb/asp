#include "solve.h"
#include <math.h> // Очень полезный пакет :)
#include <QDebug>

int Solve::sign(double value)
{
    return (value > 0) ? (1) : ((value < 0) ? (-1) : (0));
}

QList<double> Solve::cube(double a, double b, double c)
{
    QList<double> x;
    x.clear();

    // Считаем Q и R.
    double Q = (pow(a, 2) - 3.0 * b) / 9;
    double R = (2 * pow(a, 3) - 9 * a * b + 27 * c) / 54;

    if (pow(R, 2) < pow(Q, 3))
    {
        // Три действительых корня.
        double t = acos(R / sqrt(pow(Q, 3))) / 3.0;
        x.append(-2 * sqrt(Q) * cos(t) - a / 3.0);
        x.append(-2 * sqrt(Q) * cos(t + 2 * M_PI / 3.0) - a / 3.0);
        x.append(-2 * sqrt(Q) * cos(t - 2 * M_PI / 3.0) - a / 3.0);
    }
    else
    {
        // Считаем A.
        double A = -sign(R) * pow(fabs(R) + sqrt(pow(R, 2) - pow(Q, 3)), 1.0/3.0);
        // Округляем A, чтобы оно могло быть равным 0.
        if(floor((A + accuracy / 2) / accuracy) * accuracy == 0)
            A = 0;

        // Считаем B.
        double B;
        if (A != 0)
            B = Q / A;
        else
            B = A;

        if (fabs(A - B) > accuracy)
        {
            // Один корень действительный и два комплексных.
            x.append((A + B) - a / 3.0);
        }
        else
        {
            // Три действительных корня, два или три будут кратными.
            x.append((A + B) - a / 3.0);
            x.append(-A - a / 3.0);
            x.append(-A - a / 3.0);
        }
    }

    // Округляем полученные корни.
    for (int i = 0; i < x.size(); ++i)
        x.replace(i, floor((x.value(i) + accuracy / 2) / accuracy) * accuracy);

    return x;
}

QList<double> Solve::cube(double a, double b, double c, double d)
{
    QList<double> x;
    x.clear();

    if (a != 0)
        return cube(b / a, c / a, d / a);
    else
        return x;
}

QList<double> Solve::mult(QList<double> p, QList<double> q)
{
    QList<double> z;
    z.clear();

    if(!p.isEmpty() && !q.isEmpty())
    {
        // Вставляем пустые значение, которые не будут использованы, для простоты реализации алгоритма.
        p.insert(0, 0);
        q.insert(0, 0);
        unsigned int n = (p.size() > q.size()) ? (q.size() - 1) : (p.size() - 1);

        // Алгоритм для рассчета коэффициентов при степенях z.
        // Возвращает значения для полинома степени n.
        z.insert(0, q.value(1));
        z.insert(1, p.value(1));
        for(unsigned int i = 2; i <= n; i++)
        {
            z.insert(i, 0);
            for(unsigned int j = i; j > 0; j--)
            {
                z.replace(j, z.value(j) * q.value(i) + z.value(j-1) * p.value(i));
            }
            z.replace(0, z.value(0) * q.value(i));
        }
    }

    return z;
}

QList<double> Solve::mult(QList<double> p)
{
    QList<double> q;
    q.clear();

    for(int i = 0; i < p.size(); i++)
        q.append(1.0 - p.value(i));

    return mult(p, q);
}

QList<double> Solve::mult(int n)
{
    QList<double> p;
    p.clear();
    QList<double> q;
    q.clear();

    for(int i = 0; i < n; i++)
    {
        p.append(0.2);
        q.append(0.8);
    }

    return mult(p, q);
}
