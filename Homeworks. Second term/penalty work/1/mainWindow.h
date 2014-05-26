#pragma once

#include <QMainWindow>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsSimpleTextItem>
#include "cannon.h"
#include "bullet.h"
#include "target.h"
#include <QShortcut>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void onUpClicked();
    void onDownClicked();
    void onShootClicked();
    void onPowerDownClicked();
    void onPowerUpClicked();

    void timeOut();

private:
    void shortcutInitialize();

    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Cannon *gun;
    Bullet *ball;
    QTimer timer;
    Target *target;
    QGraphicsSimpleTextItem *textResult;

    QShortcut *shortcutUp;
    QShortcut *shortcutDown;
    QShortcut *shortcutLeft;
    QShortcut *shortcutRight;
    QShortcut *shortcutPower;

};
