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
    friend class CoreManager;
public:
    FileManager();
    FileManager(QString in_sRootDirectory);

    bool mooveFileToGeneratedFolder(QString in_qsFileToBeMoved);
    void doWork();


private:
    QTreeView *m_pTreeView = new QTreeView();
    QString m_qsPath;
    QString m_qsGeneratedFolder = "Reworked";

};

#endif // FILEMANAGER_H
