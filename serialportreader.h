#ifndef SERIALPORTREADER_H
#define SERIALPORTREADER_H

#include <QObject>

class serialportreader : public QObject
{
    Q_OBJECT
public:
    explicit serialportreader(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SERIALPORTREADER_H