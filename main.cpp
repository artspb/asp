#include <QtCore/QCoreApplication>
#include <QDebug>
#include "solve.h"
#include <math.h> //Необходим для функции pow (возведение в степень).

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    QListIterator<double> i(Solve::cube(1, -27, 0));
//    while(i.hasNext())
//        qDebug() << i.next();

    //Создаем и определяем переменные.
    int const n = 3;

    qDebug() << "New";
    double * factors = Solve::mult(n);
    if(factors)
        for(unsigned int i = 0; i <= sizeof(factors) - 1; ++i)
            qDebug() << factors[i];


    //Проверяем, что расчеты совпадают с расчетами через бином Ньютона.
    qDebug() << "Old";
    double pn;
    double m = n;
    double p = 0.2;
    double q = 1 - p;
    pn = pow(q, m); //n = 0 - нулевая итеррация.
    qDebug() << pn;
    for(int n = 1; n <= m; n++)
    {
        pn = pn * ((m - (n - 1)) / n) * (p / q);
        qDebug() << pn;
    }

    //Удаляем более не нужные указатели.
    delete factors;

    return 0;//a.exec(); //Нужно разобраться, почему нет выхода в случае, когда a.exec().
}
