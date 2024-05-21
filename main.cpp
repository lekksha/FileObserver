#include <QApplication>
#include <QDir>
#include <QDebug>
#include <iostream>
#include "customlib.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString path = "C:/Users/lekks/TSU/semester 6/TRPO/5-12/lab3/testFiles";
    qDebug() << "SIZE: " << getSizeOf(path);
    qDebug() << "SIZE: " << getSizeOfFilesIn(path);
//    QDir myDir;
//    myDir.setPath("C:/Users/lekks/TSU/semester 6/TRPO/5-12/lab3/testFiles");
//    QFileInfo fileInfo = QFileInfo(myDir.path());
//    /* Рассмотрим способы обхода содержимого папок на диске.
//Предлагается вариант решения, который может быть применен для более сложных задач.
//Итак, если требуется выполнить анализ содержимого папки, то необходимо организовать обход
//содержимого.
//Например:*/
//    if (fileInfo.isDir()) {
//        /*
//Если fileInfo папка, то заходим в нее, чтобы просмотреть находящиеся в ней файлы.
//Если нужно просмотреть все файлы, включая все вложенные папки, то нужно организовать
//рекурсивный обход.
//*/
//        QDir dir = fileInfo.dir();
//        if (dir.cd(fileInfo.fileName())) {
//            /*
//Если зашли в папку, то пройдемся по контейнеру QFileInfoList, полученного методом
//entryInfoList,
//*/
//            foreach (QFileInfo inf, dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Type)) {
//                qDebug() << inf.fileName() << "---" << inf.size();
//            }
//            dir.cdUp();//выходим из папки
//        }
//    }

//-------------------------------------
//    QDir dir = QDir("C:/Users/lekks/TSU/semester 6/TRPO/5-12/lab3/testFiles"); //объявляем объект работы с папками
//    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
//    ///устанавливаем фильтр выводимых файлов
//    dir.setSorting(QDir::Size | QDir::Reversed); //устанавливаем сортировку "от меньшего к большему"
//        QFileInfoList list = dir.entryInfoList(); //получаем список файлов директории
//            qDebug() << " Bytes Filename"; //выводим заголовок
//    /* в цикле выводим сведения о файлах */
//    for (int i = 0; i < list.size(); ++i) {
//        QFileInfo fileInfo = list.at(i);
//        qDebug() << qPrintable(QString("%1 %2").arg(fileInfo.size(), 10).arg(fileInfo.fileName())); //выводим в формате "размер имя", переносим строку
//    }

    return a.exec();
}
