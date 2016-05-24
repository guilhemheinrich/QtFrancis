#include "filemanager.h"

FileManager::FileManager()
{

}

FileManager::FileManager(QString in_sRootDirectory)
{
    m_qsPath = in_sRootDirectory;

}

bool FileManager::mooveFileToGeneratedFolder(QString in_qsFileToBeMoved)
{
    QString qdDestination = m_qsPath + "/" + m_qsGeneratedFolder;
    qDebug() << qdDestination;
    QFileInfo file(in_qsFileToBeMoved);
    QDir myDir = QDir::root();
    myDir.rename(in_qsFileToBeMoved, qdDestination + "/" + file.baseName() + "." + file.completeSuffix());
    return true;
}


void FileManager::doWork()
{
    QMessageBox msgBox;
    msgBox.setText("Succeed");

    QDir myDir = QDir::root();
    if(!myDir.exists(m_qsPath + "/" + m_qsGeneratedFolder))
    {
        myDir.mkdir(m_qsPath + "/" + m_qsGeneratedFolder);
        msgBox.exec();
    }

    QStringList allFiles;
    QDirIterator it(m_qsPath, QDir::Files, QDirIterator::Subdirectories);
    QFileInfo file;
    while (it.hasNext()) {
        file.setFile(it.next());
        qDebug()<<file.baseName().size();
        if (file.baseName().size() == 8){
             allFiles << file.absoluteFilePath();
        }
    }

    for (QString file : allFiles)
    {
        mooveFileToGeneratedFolder(file);
    }
    qDebug()<<allFiles;
}



