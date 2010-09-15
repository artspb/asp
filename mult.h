#ifndef MULT_H
#define MULT_H

class mult
{
public:
    //Конструктор принимает значения коэффициентов p и q при соответствующих степенях, а также наивысшую степень z.
    mult(double *, double *, int);
    int count(); //Возвращает наивысшую степень z при расчетах.
    double * get(); //Возвращает массив из значений коэффициентов при z соответствующих степеней.

private:
    double * p;
    double * q;
    int n;
};

#endif // MULT_H
