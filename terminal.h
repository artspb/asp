#ifndef TERMINAL_H
#define TERMINAL_H

#include <QList>

class Terminal
{
public:
    Terminal(); // Lego.
    Terminal(QList<double>, QList<int>, QList<double>); //
    QList<double> getZ(); //
    double getD(int); //
    double getTs(int); //
    double getT(int); //

private:
    void init(); //
    double getP(int); //
    QList<double> getP(); //
    double getLambdaS(int); //
    double getTw(); //
    double getLambda(int); //
    double getM(int); //
    double getMu(int); //
    int getS(); //
    double getLambdaM(); //

    static const double accuracy = 1e-8; // Точность.
    int ms; // Число судов на маршруте.
    QList<int> m; // Число судов в каждой группе.
    int s; // Количество причалов.
    QList<double> t; // Массив времен обработки судов.
    double tw; // Среднее время ожидания судна в терминале.
    QList<double> ts; // Массив суммарных времен пребывания судна в терминале (t + tw).
    double d; // Среднее число судов на обработке.
    double ds; // Среднее число судов в терминале.
    double it; // Число итераций, за которое была достигнута необходимая точность.
    double phi; //
    double nu; //
    QList<double> mu; //
    QList<double> lambda; //
    double psi; //
    double l; //
    double ls; //
    QList<double> P; //
    QList<double> Z;
};

#endif // TERMINAL_H
