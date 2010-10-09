#ifndef MULT_H
#define MULT_H

class mult
{
public:
    mult(); //Пустой конструктор.
    mult(double *, double *, int); //Конструктор принимает значения коэффициентов p и q при соответствующих степенях, а также наивысшую степень z.
    ~mult();
    int count(); //Возвращает наивысшую степень z при расчетах (значение n).
    double * get(); //Возвращает массив из значений коэффициентов при z соответствующих степеней.
    double * get(double *, double *, int); //Вызывает get() с соответствуюими параметрами.
    double * get(int); //Вызывает get() при стандартных p и q.

private:
    double * p;
    double * q;
    double * z;
    int n;
};

#endif // MULT_H
