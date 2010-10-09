#include "mult.h"
#include <QDebug>

mult::mult()
{
    p = 0;
    q = 0;
    z = 0;
    n = 0;
}

mult::mult(double * p, double * q, int n)
{
    mult::p = p;
    mult::q = q;
    mult::n = n;
}

mult::~mult()
{
    delete p;
    delete q;
    delete z;
}


int mult::count()
{
    return n;
}

double * mult::get()
{
    if(p && q && n)
    {
        z = new double[n+1];

        //Алгоритм для рассчета коэффициентов при степенях z.
        //Возвращает значения для полинома степени n.
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
    else
        return 0;
}

double * mult::get(double * p, double * q, int n)
{
    mult::p = p;
    mult::q = q;
    mult::n = n;

    return get();
}

double * mult::get(int n)
{
    mult::n = n;
    p = new double[n+1];
    q = new double[n+1];

    for(int i = 1; i <= n; i++)
    {
        p[i] = 0.2;
        q[i] = 0.8;
    }

    return get();
}
