#include "serialportreader.h"
#include <QCoreApplication>
#include <QDebug>
#include <QRegExp>

//To Do:
//Check If there is already a connection

SerialPortReader::SerialPortReader(QSerialPort *serialPort, QObject *parent) :
    QObject(parent),
    m_serialPort(serialPort),
    m_standardOutput(stdout)
{
    serialBuffer = "";


    connect(m_serialPort, &QSerialPort::readyRead,this, &SerialPortReader::handleReadyRead);
    connect(m_serialPort, &QSerialPort::errorOccurred,this, &SerialPortReader::handleError);
    connect(&serialPort_timer, &QTimer::timeout, this, &SerialPortReader::handleTimeout);
    a=1;
    serialPort_timer.start(5000);

    }

void SerialPortReader::handleReadyRead()

{



    m_readData.append(m_serialPort->readAll());
    //strVector.push_back(QString::fromStdString(m_readData.toStdString()));
 //m_readData_split  =  QString::fromStdString(m_readData.toStdString()).split("\\s+");
    //serialBuffer = serialBuffer + QString::fromStdString(m_readData.toStdString());
    //m_readData.clear();



    if(!serialPort_timer.isActive())
        serialPort_timer.start(5000);
}

void SerialPortReader::handleTimeout()
{


    if(m_readData.isEmpty()){
        m_standardOutput << QObject::tr("No data was currently available"
                                        "for reading from port %1")
                            .arg(m_serialPort->portName())<<endl;
    }else{
        m_standardOutput << QObject::tr("data recieved from %1")
                            .arg(m_serialPort->portName())<<endl;

        //m_standardOutput << m_readData <<endl;
        m_readData_split  =  QString::fromStdString(m_readData.toStdString()).split(QRegExp("\\s+"));
        m_standardOutput << m_readData_split[0];
    }
  //  QCoreApplication::quit();
}

void SerialPortReader::handleError(QSerialPort::SerialPortError error)
{
    if(error == QSerialPort::ReadError){
        m_standardOutput << QObject::tr("An I/O error occured"
                                        "while reading from %1, error: %2")
                            .arg(m_serialPort->portName())
                            .arg(m_serialPort->errorString())<<endl;
        QCoreApplication::exit(1);
    }
}
