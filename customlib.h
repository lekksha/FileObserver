#ifndef CUSTOMLIB_H
#define CUSTOMLIB_H

#include <QDir>
#include <QFileInfo>
#include <QString>
#include <QDebug>
#include <cmath>


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
}


qint64 getSizeOfFilesIn(QString path) {
    QFileInfo fileInfo = QFileInfo(path);
    if (fileInfo.isDir()) {
        QDir dir = fileInfo.dir();
        if (dir.cd(fileInfo.fileName())) {
            qint64 currentDirectorySize = 0;
            foreach (QFileInfo file, dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Size)) {
                currentDirectorySize += file.size();
            }
            return currentDirectorySize;
        }
    }
    else {
        return fileInfo.size();
    }
}




// Calculates number of digints in an argument
int numOfDigits(quint64 num) {
    if (num == 0) {
        return 1;
    }
    return std::floor(std::log10(num) + 1);
}


int calculateMaxStringLengthInPair(QList<QPair<quint64, QString>> size_item, unsigned int index_in_pair, unsigned int header_length) {
    int maximum_length = header_length;
    if (index_in_pair > 2) {
        throw std::runtime_error("Not Supported");
    }
    else if (index_in_pair == 0) {
        for (int i = 0; i < size_item.size(); i++) {
            if (maximum_length < numOfDigits(size_item[i].first)) {
                maximum_length = numOfDigits(size_item[i].first);
                }
        }
    }
    else if (index_in_pair == 1) {
        for (int i = 0; i < size_item.size(); i++) {
                if (maximum_length < size_item[i].second.length()) {
                    maximum_length = size_item[i].second.length();
                }
        }
    }
    return maximum_length;
}


QString getPercent(quint64 dir_size, quint64 total_size) {
    // Calculating size of the whole folder
    double percent = static_cast<double>(dir_size) / static_cast<double>(total_size);
    QString res = "";
    if (percent < 0.01) {
        res = "<0.01";
    }
    else {
        res = QString::number(percent, 'f', 2);
    }
    return res;
}


void show(QList<QPair<quint64, QString>> size_item, QString second_item_name) {
    QString bytes = "Bytes";
    QString percent = "Percent";
    int maxStringLengthInColumn1 = calculateMaxStringLengthInPair(size_item, 0, bytes.length());
    int maxStringLengthInColumn2 = calculateMaxStringLengthInPair(size_item, 1, second_item_name.length());

    qDebug() << qPrintable(QString("%1 %2 %3")
                               .arg(bytes, maxStringLengthInColumn1)
                               .arg(second_item_name, maxStringLengthInColumn2)
                               .arg(percent, percent.length()+1));  // +1 comes for percent display in strings
    qDebug() << " ";

    // Calculating size of the whole folder
    quint64 totalSize = 0;
    for (int i = 0; i < size_item.size(); i++) {
        totalSize += size_item[i].first;
    };

    // Showing details to console
    for (int i = 0; i < size_item.size(); i++) {
        qDebug() << qPrintable(QString("%1 %2 %3%")
                                   .arg(size_item[i].first, maxStringLengthInColumn1)
                                   .arg(size_item[i].second, maxStringLengthInColumn2)
                                   .arg(getPercent(size_item[i].first, totalSize), percent.length()));
                                            // percent.length() - has the biggest length if 2 dighits after dot are required
    }
}




#endif // CUSTOMLIB_H
