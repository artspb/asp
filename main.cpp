#include <QtCore/QCoreApplication>
#include <QDebug>
#include "mult.h"

int main(/*int argc, char *argv[]*/)
{
    //QCoreApplication a(argc, argv);

    double * p = new double;
    double * q = new double;
    int n;

    n = 2;

    for(int i = 1; i <= n; i++)
    {
        p[i] = 0,2;
        q[i] = 0,2;
    }

    mult poly = mult(p, q, n);

    qDebug() << poly.get()[0];

    return 0;
}
