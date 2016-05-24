#ifndef COREWINDOW_H
#define COREWINDOW_H

#include <QApplication>
#include <QPushButton>
#include <QDesktopWidget>
#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextEdit>


#include "filemanager.h"

class CoreWindow : public QWidget
{
    Q_OBJECT
public:
    CoreWindow();

private:
    QPushButton *m_pMainButton = new QPushButton("Select root directory", this);
//    QTextEdit *m_pMainTextArea = new QTextEdit("Select a root directory", this);
    FileManager *m_pFileManager = new FileManager;

private slots:
    void handleMainButton();
};

#endif // COREWINDOW_H
