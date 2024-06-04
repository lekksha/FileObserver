#include <QApplication>
#include <QDir>
#include <QDebug>
#include <iostream>
#include "foldercalculationstrategy.h"
#include "extensioncalculationstrategy.h"
#include <memory>


void execute(QString path, unsigned int flag) {
    if (QFileInfo(path).isDir()) {
        std::shared_ptr<CalculationStrategy> strat = nullptr;
        if (flag == 0) {
            strat = std::make_shared<FolderCalculationStrategy>();
        }
        else if (flag == 1) {
            strat = std::make_shared<ExtensionCalculationStrategy>();
        }
        else {
            throw std::runtime_error("Not supported");
        }
        strat->exec(path);
    }
    else {
        throw std::runtime_error("Entered path is not a folder");
    }
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QString path = "C:/Users/lekks/TSU/semester 6/TRPO/5-12/lab3/testFiles/";
    unsigned int flag = CalculationStrategy::EXTENSION;
    execute(path, flag);


    return a.exec();
}
