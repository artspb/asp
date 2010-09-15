#include "mult.h"

mult::mult(double * newP, double * newQ, int newN)
{
    p = newP;
    q = newQ;
    n = newN;
}

int mult::count()
{
    return n;
}

double * mult::get()
{
    double * z = new double;

    //Алгоритм для рассчета коэффициентов при степенях z.
    //Возвращает значения только для полинома степени n.
    z[0] = q[1];
    z[1] = p[1];
    for(int i = 2; i <= n; i++)
    {
        z[i] = 0;
        for(int j = i; j > 0; j--)
        {
            z[j] = z[j] * q[i] + z[j-1] * p[i];
        }
        z[0] = z[0] * q[i];
    }

    return z;
}
