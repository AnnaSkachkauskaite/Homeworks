#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include "calculation.h"
#include <QMainWindow>
#include "calculation.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Calculator calculator;

private slots:
    void getResult();
};

#endif // MAINWINDOW_H
