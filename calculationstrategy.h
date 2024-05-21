#ifndef CALCULATIONSTRATEGY_H
#define CALCULATIONSTRATEGY_H

#include <QString>



class CalculationStrategy
{
public:
    CalculationStrategy() {};
    virtual void calculate(QString path) = 0;
};

#endif // CALCULATIONSTRATEGY_H
