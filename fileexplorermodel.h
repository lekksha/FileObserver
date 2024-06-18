#ifndef FILEEXPLORERMODEL_H
#define FILEEXPLORERMODEL_H

#include <QFileSystemModel>

class FileExplorerModel : public QFileSystemModel
{
public:
    explicit FileExplorerModel(QObject *parent = nullptr);
};

#endif // FILEEXPLORERMODEL_H
