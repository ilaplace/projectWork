#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore/QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void timeoutHandler();
private:
    Ui::MainWindow *ui;
    QString fileString = "/home/s/QtProjects/readPlotApp/textFile.txt";
    QTimer m_timer;
};

#endif // MAINWINDOW_H
