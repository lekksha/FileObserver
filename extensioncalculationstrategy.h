#ifndef EXTENSIONCALCULATIONSTRATEGY_H
#define EXTENSIONCALCULATIONSTRATEGY_H

#include "calculationstrategy.h"

#include <QFileInfo>
#include <QDir>
#include <QMap>
#include <QDebug>
#include <QList>
#include "customlib.h"

QMap<QString, quint64> extensionCalculate(QString path, QMap<QString, quint64>& map) {
    QFileInfo fileInfo = QFileInfo(path);
    if (fileInfo.isDir()) {
        QDir dir = fileInfo.dir();
        if (dir.cd(fileInfo.fileName())) {
            foreach (QFileInfo file, dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Size)) {
                if (map.contains(file.completeSuffix())) {
                    map[file.completeSuffix()] += file.size();
                }
                else {
                    map[file.completeSuffix()] = file.size();
                }
            }
            foreach (QFileInfo folder, dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Size)) {
                extensionCalculate(folder.absoluteFilePath(), map);
            }
        }
    }
    return map;
}


class ExtensionCalculationStrategy : public CalculationStrategy {
public:
    void calculate(QString path) {
        QDir dir = QDir("C:/Users/lekks/TSU/semester 6/TRPO/5-12/lab3/testFiles");
        QMap<QString, quint64> extensions_size;
        extensions_size = extensionCalculate(path, extensions_size);

        QList<QPair<quint64, QString>> listOfExstensonSize;
        for(auto it = extensions_size.begin(); it != extensions_size.end(); ++it)
            listOfExstensonSize.append(qMakePair(it.value(), it.key()));

        std::sort(listOfExstensonSize.begin(), listOfExstensonSize.end());

        show(listOfExstensonSize, "Extensions");
        }
    };

#endif // EXTENSIONCALCULATIONSTRATEGY_H
