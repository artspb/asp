#include <QtCore/QCoreApplication>
#include <QDebug>
#include "solve.h"
#include "terminal.h"
#include <math.h> //Необходим для функции pow (возведение в степень).

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<double> mu;
    QList<int> m;
    QList<double> lambda;

    mu.clear();
    m.clear();
    lambda.clear();

//    for(int i = 0; i < 25; ++i)
//        m.append(25);
//    for(int i = 0; i < 15; ++i)
//        m.append(15);
//    for(int i = 0; i < 10; ++i)
//        m.append(10);

//    for(int i = 0; i < 25; ++i)
//    {
//        mu.append(0.976);
//        lambda.append(1.1);
//    }

//    for(int i = 0; i < 15; ++i)
//    {
//        mu.append(0.828);
//        lambda.append(0.697);
//    }

//    for(int i = 0; i < 10; ++i)
//    {
//        mu.append(0.486);
//        lambda.append(0.0508);
//    }

    for(int i = 0; i < 100; ++i)
        m.append(100);

    for(int i = 0; i < 100; ++i)
    {
        mu.append(1);
        lambda.append(3.5);
    }

    Terminal terminal(mu, m, lambda);

//    QList<double> Z = terminal.getZ();

//    for(int i = 0; i <= 50; ++i)
//        qDebug() << i << Z.value(i);

    qDebug() << terminal.getD(5);
    qDebug() << terminal.getTs(1);

//    QListIterator<double> i(Solve::cube(1, -27, 0));
//    while(i.hasNext())
//        qDebug() << i.next();

//    //Создаем и определяем переменные.
//    int const n = 3;

//    qDebug() << "New";
//    QList<double> factors = Solve::mult(n);
//    if(!factors.isEmpty())
//        for(int i = 0; i < factors.size(); ++i)
//            qDebug() << factors.value(i);

//    //Проверяем, что расчеты совпадают с расчетами через бином Ньютона.
//    qDebug() << "Old";
//    double pn;
//    double m = n;
//    double p = 0.2;
//    double q = 1 - p;
//    pn = pow(q, m); //n = 0 - нулевая итеррация.
//    qDebug() << pn;
//    for(int n = 1; n <= m; n++)
//    {
//        pn = pn * ((m - (n - 1)) / n) * (p / q);
//        qDebug() << pn;
//    }

    return 0;//a.exec(); //Нужно разобраться, почему нет выхода в случае, когда a.exec().
}
