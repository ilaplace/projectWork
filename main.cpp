#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QtDebug>
#include <QProcess>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QSerialPort>
#include <QStringList>
#include <QObject>

#include "serialportreader.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    const QString serialPortName = "/dev/ttyACM0";
    const int serialPortBaudRate = QSerialPort::Baud9600;

    QSerialPort serialPort;
    serialPort.setBaudRate(serialPortBaudRate);
    serialPort.setPortName(serialPortName);
    QTextStream standardOutput(stdout);

    if(!serialPort.open(QIODevice::ReadOnly)){
        standardOutput << QObject::tr("Failed to open port %1, error: %2")
                                 .arg(serialPortName)
                                 .arg(serialPort.errorString())
                              << endl;

    }else{standardOutput<< QObject::tr("Port is open sire");}

    SerialPortReader serialPortReader(&serialPort);


        //qDebug() << file.exists();
        //To see the current position
        // auto pozisyon= in.pos();

        //Get to the specified position

         //auto str = QProcess::readLine();

        //QString str = in.readLine();

    //w.QObject::dumpObjectTree();
    return a.exec();
}
