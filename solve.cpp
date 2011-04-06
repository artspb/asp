#include "solve.h"
#include <math.h> // Очень полезный пакет :)

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

double * Solve::mult(double * p, double * q)
{
    if(p && q)
    {
        unsigned int n = (sizeof(p) > sizeof(q)) ? (sizeof(q) - 1) : (sizeof(p) - 1);
        double * z = new double[n+1];

        //Алгоритм для рассчета коэффициентов при степенях z.
        //Возвращает значения для полинома степени n.
        z[0] = q[1];
        z[1] = p[1];
        for(unsigned int i = 2; i <= n; i++)
        {
            z[i] = 0;
            for(unsigned int j = i; j > 0; j--)
            {
                z[j] = z[j] * q[i] + z[j-1] * p[i];
            }
            z[0] = z[0] * q[i];
        }

        return z;
    }
    else
        return 0;
}

double * Solve::mult(int n)
{
    double * p = new double[n+1];
    double * q = new double[n+1];

    for(int i = 1; i <= n; i++)
    {
        p[i] = 0.2;
        q[i] = 0.8;
    }

    return mult(p, q);
}
