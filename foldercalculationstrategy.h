#ifndef FOLDERCALCULATIONSTRATEGY_H
#define FOLDERCALCULATIONSTRATEGY_H
#include "calculationstrategy.h"
#include <QDebug>
#include <QDir>


class FolderCalculationStrategy : public CalculationStrategy {
private:
    // Calculates size of the folder in argument
    qint64 getSizeOf(QString path) {
        QFileInfo fileInfo = QFileInfo(path);
        if (fileInfo.isDir()) {
            QDir dir = fileInfo.dir();
            if (dir.cd(fileInfo.fileName())) {
                qint64 currentDirectorySize = 0;
                foreach (QFileInfo file, dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Size)) {
                    currentDirectorySize += file.size();
                }
                foreach (QFileInfo folder, dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Size)) {
                    currentDirectorySize += getSizeOf(folder.absoluteFilePath());
                }
                return currentDirectorySize;
            }
        }
        else {
            return fileInfo.size();
        }
    };

    qint64 getSizeOfFilesIn(QString path) {
        QFileInfo fileInfo = QFileInfo(path);
        if (fileInfo.isDir()) {
            QDir dir = fileInfo.dir();
            if (dir.cd(fileInfo.fileName())) {
                qint64 currentDirectorySize = 0;
                foreach (QFileInfo file, dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Size)) {
                    currentDirectorySize += file.size();
                }
                foreach (QFileInfo file, dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Size)) {
                    getSizeOf(file.absoluteFilePath());
                }
                return currentDirectorySize;
            }
        }
        else {
            return fileInfo.size();
        }
    }
public:
    FolderCalculationStrategy() {};
    QMap<QString, quint64> exec(QString path)  {
        QDir dir = QDir(path);
        QMap<QString, quint64> folder_size;

        folder_size.insert("(Current Directory)", getSizeOfFilesIn(path));
        foreach (QFileInfo folder, dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Size)) {
            folder_size.insert(folder.fileName(), getSizeOf(folder.absoluteFilePath()));
        }

        return folder_size;
    };
};


#endif // FOLDERCALCULATIONSTRATEGY_H
