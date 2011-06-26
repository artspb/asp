#include "terminal.h"
#include "solve.h"
#include <QDebug>
#include <math.h>

Terminal::Terminal()
{
    clear();
}

void Terminal::clear()
{
    tw = 0;
    s = 0;
    d = 0;
    lambdaM = 0;
    mu.clear();
    lambda.clear();
}

void Terminal::append(double mu, double lambda)
{
    Terminal::mu.append(mu);
    Terminal::lambda.append(lambda);
    solve();
}

bool Terminal::append(QList<double> mu, QList<double> lambda)
{
    if (mu.size() != lambda.size())
        return false;
    else
    {
        Terminal::mu.append(mu);
        Terminal::lambda.append(lambda);
        solve();
        return true;
    }
}

void Terminal::solve()
{
    if (s > 0)
    {
        lambdaM = 0;
        for (int i = 0; i < getMs(); ++i)
            lambdaM = lambdaM + getLambda(i);

        double td = 1; // Содержит предыдущее значение d.
        d = 0;
        tw = 0;
        it = 0;

        // Считаем, пока не достигнем желаемой точности.
        while(fabs(td - d) > accuracy)
        {
            ++it;
            td = d;
            d = 0;
            QList<double> Z = getZ();

            for (int i = s + 1; i <= getMs(); ++i)
                d = d + (i - s) * Z.value(i);

            // Если будет еще одна итерация.
            if (fabs(td - d) > accuracy)
                tw = d * getMs() / getLambdaM();
        }
    }
}

QList<double> Terminal::getZ()
{
    // Не держим список Z в переменной, т.к. он меняется при изменении P.
    return Solve::mult(getP());
}

double Terminal::getP(int i)
{
    return getLambdaS(i) * (getT(i) + getTw());
}

QList<double> Terminal::getP()
{
    // Не держим P в переменной, т.к. P(i) меняется при изменении tw.
    QList<double> P;
    P.clear();
    for(int i = 0; i < getMs(); ++i)
        P.append(getP(i));
    return P;
}

double Terminal::getLambdaS(int i)
{
    return getLambda(i) / getM(i);
}

double Terminal::getT(int i)
{
    return 1 / getMu(i);
}

double Terminal::getTw()
{
    return tw;
}

double Terminal::getLambda(int i)
{
    return lambda.value(i);
}

double Terminal::getM(int i)
{
    return mu.count(mu.value(i));
}

double Terminal::getMu(int i)
{
    return mu.value(i);
}

void Terminal::setS(int s)
{
    Terminal::s = s;
    solve();
}

double Terminal::getD()
{
    return d;
}

double Terminal::getLambdaM()
{
    return lambdaM;
}

double Terminal::getTs(int i)
{
    return getT(i) + getTw();
}

int Terminal::getIt()
{
    return it;
}

int Terminal::getMs()
{
    return mu.size();
}
