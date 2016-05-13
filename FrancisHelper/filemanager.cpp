#include "filemanager.h"

FileManager::FileManager()
{
    m_pFileSystem->setRootPath(QDir::currentPath());
    m_pTreeView->setAnimated(false);
    m_pTreeView->setSortingEnabled(true);
    m_pTreeView->setModel(m_pFileSystem);
    m_pTreeView->setRootIndex(m_pFileSystem->index(QDir::currentPath()));
}

FileManager::FileManager(QString in_sRootDirectory)
{
    path = in_sRootDirectory;
    m_pFileSystem->setRootPath(in_sRootDirectory);
    m_pTreeView->setAnimated(false);
    m_pTreeView->setSortingEnabled(true);
    m_pTreeView->setModel(m_pFileSystem);
    m_pTreeView->setRootIndex(m_pFileSystem->index(in_sRootDirectory));
}

void FileManager::test()
{
    //    m_pFileSystem->mkdir(parent(), QString("lol"));
}

void FileManager::doWork()
{
    QMessageBox msgBox;
    msgBox.setText("Succeed");

    QDir myDir = QDir::root();
    if(!myDir.exists(path + "/LOL"))
    {
        myDir.mkdir(path + "/LOL");
        msgBox.exec();
    }

    QDir recoredDir(path);
    QStringList allFiles = recoredDir.entryList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst);//(QDir::Filter::Files,QDir::SortFlag::NoSort)
    qDebug()<<allFiles;

}



