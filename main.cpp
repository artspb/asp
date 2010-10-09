#include <QtCore/QCoreApplication>
#include <QDebug>
#include "mult.h"

int main(/*int argc, char *argv[]*/)
{
    //QCoreApplication a(argc, argv);

    //Создаем и определяем переменные.
    int n = 3;
    double * factors;
    mult poly;

    //Поставь TODO плагин наконец! ВотЪ.

    factors = poly.get(n);
    if(factors)
        for(int i = 0; i <=n; i++)
            qDebug() << factors[i];

    //Удаляем более не нужные указатели.
    delete factors;

    return 0;
}
