#include <QApplication>
#include "corewindow.h"

#include <QFileDialog>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CoreWindow myWindow;
    myWindow.show();


    return app.exec();
}
