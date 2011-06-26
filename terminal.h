#ifndef TERMINAL_H
#define TERMINAL_H

#include <QList>

class Terminal
{
public:
    Terminal(); // Lego.
    void clear(); // Обнуляем списки и переменные.
    void append(double mu, double lambda); // Добавляет судно на маршрут.
    bool append(QList<double> mu, QList<double> lambda); // Добавляет список судов на маршрут.
    double getD(); // Среднее число судов в терминале.
    double getTs(int i); // Среднее время пребывания в терминале i-го судна.
    double getT(int i); // Время обработки i-го судна.
    double getTw(); // Среднее время ожидания судов в терминале.
    int getIt(); // Возвращает количество итераций последнего вызова solve.
    int getMs(); // Возвращает длину списка mu как количество судов на маршруте.
    void setS(int s); // Устанавливает количество причалов терминала, после чего пересчитывает показетели качества.

private:
    void solve(); // Рассчитываем значения d и tw.
    double getP(int i); //
    QList<double> getZ(); //
    QList<double> getP(); //
    double getLambdaS(int i); //
    double getLambda(int i); //
    double getM(int i); //
    double getMu(int i); //
    double getLambdaM(); //

    static const double accuracy = 1e-8; // Точность.
    QList<double> mu; //
    QList<double> lambda; //
    int s; // Количество причалов.
    double tw; // Среднее время ожидания судна в терминале.
    double d; // Среднее число судов на обработке.
    double it; // Число итераций, за которое была достигнута необходимая точность.
    double lambdaM; // Сумма всех значений списка lambda.
};

#endif // TERMINAL_H
