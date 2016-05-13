#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QFileSystemModel>
#include <QTreeView>
#include <QInputDialog>
#include <QMessageBox>
#include <QDir>
#include <QDebug>
class FileManager
{
public:
    FileManager();
    FileManager(QString in_sRootDirectory);

    void test();
    void doWork();

    QFileSystemModel *m_pFileSystem = new QFileSystemModel;
    QTreeView *m_pTreeView = new QTreeView();
    QString path;
private:

};

#endif // FILEMANAGER_H
