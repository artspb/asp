#include <QtCore/QCoreApplication>
#include <QDebug>
#include "solve.h"
#include "terminal.h"
#include <math.h> //Необходим для функции pow (возведение в степень).

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Terminal terminal;

    for(int i = 0; i < 25; ++i)
        terminal.append(0.976, 1.1);

    for(int i = 0; i < 15; ++i)
        terminal.append(0.828, 0.697);

    for(int i = 0; i < 10; ++i)
        terminal.append(0.486, 0.0508);

//    for(int i = 0; i < 100; ++i)
//    {
//        mu.append(1);
//        lambda.append(3.5);
//    }

//    Terminal terminal(mu, lambda);

//    QList<double> Z = terminal.getZ();

//    for(int i = 0; i <= 100; ++i)
//        qDebug() << i << Z.value(i);

    terminal.setS(5);
    qDebug() << terminal.getD();
    qDebug() << terminal.getTw();
    qDebug() << terminal.getTs(1);
    qDebug() << terminal.getTs(30);
    qDebug() << terminal.getTs(45);
    qDebug() << terminal.getIt();

    double temp;
    temp = (25 * terminal.getTs(1) + 15 * terminal.getTs(30) + 10 * terminal.getTs(45)) / 50;
    qDebug() << temp;

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
