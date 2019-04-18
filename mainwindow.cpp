#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&m_timer, &QTimer::timeout,
  this, &MainWindow::timeoutHandler);

    m_timer.setInterval(2000);
    m_timer.start();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeoutHandler()
{
    qDebug() << "I'm in timoutHandler";

    QFile file(fileString);
    file.open(QIODevice::ReadOnly);
    qDebug() << file.exists();
    QTextStream in(&file);

    while (!in.atEnd()) {
        QString str = in.readLine();
        qDebug() <<str;

    }
}
