#include <QApplication>
#include <QDir>
#include <QDebug>
#include <iostream>
#include "foldercalculationstrategy.h"
#include "extensioncalculationstrategy.h"
#include <memory>


void execute(QString path, unsigned int flag) {
    std::unique_ptr<CalculationStrategy> strat = nullptr;
    if (QFileInfo(path).isDir()) {
        if (flag == 0) {
            strat = std::make_unique<FolderCalculationStrategy>();
        }
        else if (flag == 1) {
            strat = std::make_unique<ExtensionCalculationStrategy>();
        }
        else {
            throw std::runtime_error("Not supported");
        }
        strat->calculate(path);
    }
    else {
        throw std::runtime_error("Entered path is not a folder");
    }
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QString path = "C:/Users/lekks/TSU/semester 6/TRPO/5-12/lab3/testFiles/empty folder";
    unsigned int flag = CalculationStrategy::EXTENSION;
    execute(path, flag);


    return a.exec();
}
