#ifndef SERIALPORTREADER_H
#define SERIALPORTREADER_H

#include <QObject>
#include <QByteArray>
#include <QSerialPort>
#include <QTimer>
#include <QTextStream>
#include <QString>
#include <QVector>

class SerialPortReader : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortReader(QSerialPort *serialPort,
                              QObject *parent = nullptr);

    int a;

private:
    QSerialPort *m_serialPort = nullptr;
    QByteArray m_readData;
    //QByteArray m_newData;
    //adding two QBtyeArray's causes crash for some reason
    QTextStream m_standardOutput;
    QString serialBuffer;
     QStringList buffer_split;
     QStringList m_readData_split;

    QVector<QString> strVector;
    QTimer serialPort_timer;


private slots:
    void handleReadyRead();
    void handleTimeout();
    void handleError(QSerialPort::SerialPortError error);

};


#endif // SERIALPORTREADER_H
