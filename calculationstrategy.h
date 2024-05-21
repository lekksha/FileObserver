#ifndef CALCULATIONSTRATEGY_H
#define CALCULATIONSTRATEGY_H

#include <QString>



class CalculationStrategy
{
public:
    enum STRATEGY
    {
        FOLDER,
        EXTENSION,
    };
    CalculationStrategy() {};
    virtual void calculate(QString path) = 0;
};

#endif // CALCULATIONSTRATEGY_H
