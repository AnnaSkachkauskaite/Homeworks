#pragma once

#include <QMainWindow>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsSimpleTextItem>
#include "cannon.h"
#include "bullet.h"
#include "target.h"


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

    ///lots for working with buttons
    void onUpClicked();
    void onDownClicked();
    void onShootClicked();
    void onPowerDownClicked();
    void onPowerUpClicked();

    void onSmallClicked();
    void onMediumClicked();
    void onLargeClicked();
    void onQuitClicked();

    void timeOut();

private:

    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Cannon *gun;
    Bullet *ball;
    ///For large cannonball
    int maxRadius;
    QTimer timer;
    Target *target;
    ///Text
    QGraphicsSimpleTextItem *textResult;


};
