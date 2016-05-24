#include "corewindow.h"

CoreWindow::CoreWindow()
{

    setFixedSize(300, 150);

    move(QApplication::desktop()->screen()->rect().center() - this->rect().center());

    connect(m_pMainButton, SIGNAL(pressed()), this, SLOT(handleMainButton()));

    m_pMainButton->setFixedSize(250, 25);
    m_pMainButton->move(this->rect().center() - m_pMainButton->rect().center());
    m_pMainButton->show();
}

void CoreWindow::handleMainButton()
{
    QString dossier = QFileDialog::getExistingDirectory(this);
    FileManager fileManager(dossier);
    fileManager.doWork();


}

