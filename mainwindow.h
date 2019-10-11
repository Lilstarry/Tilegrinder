#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "location.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QList<Location *> m_locations;
};

#endif // MAINWINDOW_H
