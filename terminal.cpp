#include "terminal.h"
#include "solve.h"
#include <QDebug>
#include <math.h>

Terminal::Terminal()
{
    init();
}

Terminal::Terminal(QList<double> mu, QList<int> m, QList<double> lambda)
{
    init();
    Terminal::mu = mu;
    Terminal::m = m;
    Terminal::lambda = lambda;
    ms = m.count();
}

void Terminal::init()
{
    tw = 0;
    ms = 0;
    P.clear();
    mu.clear();
    m.clear();
    lambda.clear();
}

QList<double> Terminal::getZ()
{
    // TODO: Вынести в константу, рассчет только после инициализации или сета.
    return Solve::mult(getP());
}

double Terminal::getP(int i)
{
    return getLambdaS(i) * (getT(i) + getTw());
}

QList<double> Terminal::getP()
{
    // TODO: Вынести в константу, рассчет только после инициализации или сета.
    P.clear();
    for(int i = 0; i < ms; ++i)
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
    return m.value(i);
}

double Terminal::getMu(int i)
{
    return mu.value(i);
}

int Terminal::getS()
{
    return s;
}

double Terminal::getD(int s)
{
    double td = 1;
    d = 0;
    while(fabs(td - d) > accuracy)
    {
        td = d;
        d = 0;
        Z = getZ();
        for (int i = s + 1; i <= ms; ++i)
        {
            d = d + (i - s) * Z.value(i);
        }
        tw = d * ms / getLambdaM();
    }
    return d;
}

double Terminal::getLambdaM()
{
    double lambdaM = 0;
    for (int i = 0; i < ms; ++i)
    {
        lambdaM = lambdaM + getLambda(i);
    }
    return lambdaM;
}

double Terminal::getTs(int i)
{
    qDebug() << getTw();
    return getT(i) + getTw();
}
