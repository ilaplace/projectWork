#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QtDebug>
#include <QProcess>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //qDebug() << file.exists();


        //To see the current position
        // auto pozisyon= in.pos();

        //Get to the specified position

         //auto str = QProcess::readLine();

        //QString str = in.readLine();






    return a.exec();
}
