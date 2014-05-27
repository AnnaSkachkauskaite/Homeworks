#include "mainWindow.h"
#include "ui_mainWindow.h"
#include <QPen>
#include <QBrush>
#include <QGraphicsView>
#include <QTimer>
#include <QProgressBar>
#include <QKeySequence>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->down->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    ui->up->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    ui->shoot->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    ui->powerDown->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    ui->powerUp->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    ui->quit->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

    ui->shoot->setShortcut(QKeySequence::InsertParagraphSeparator);
    ui->powerDown->setShortcut(QKeySequence::MoveToPreviousChar);
    ui->powerUp->setShortcut(QKeySequence::MoveToNextChar);
    ui->down->setShortcut(QKeySequence::MoveToNextLine);
    ui->up->setShortcut(QKeySequence::MoveToPreviousLine);


    scene = new QGraphicsScene();
    ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    gun = new Cannon(ui->graphicsView->width() * 2, scene->width() * 3, scene->height() * 3);
    scene->addItem(gun);

    ball= new Bullet(gun->getWidth(), 50.0, 45.0,
                         gun->getRadius() + gun->getHeigh(),
                         (double)scene->width(), (double)scene->height());
    maxRadius = ball->getRadius();
    scene->addItem(ball);

    target = new Target(40, scene->width(), scene->height());
    scene->addItem(target);

    textResult = new QGraphicsSimpleTextItem("Change direction of the cannon and shoot power using special buttons. You can also use arrow keys.");
    scene->addItem(textResult);

    ui->graphicsView->setScene(scene);
    ui->progressBarSpeed->setValue(ball->getSpeed());

    showFullScreen();

    connect(ui->up, &QPushButton::clicked, this, &MainWindow::onUpClicked);
    connect(ui->down, &QPushButton::clicked, this, &MainWindow::onDownClicked);
    connect(ui->shoot, &QPushButton::clicked, this, &MainWindow::onShootClicked);
    connect(ui->powerDown, &QPushButton::clicked, this, &MainWindow::onPowerDownClicked);
    connect(ui->powerUp, &QPushButton::clicked, this, &MainWindow::onPowerUpClicked);
    connect(ui->small, &QPushButton::clicked, this, &MainWindow::onSmallClicked);
    connect(ui->medium, &QPushButton::clicked, this, &MainWindow::onMediumClicked);
    connect(ui->large, &QPushButton::clicked, this, &MainWindow::onLargeClicked);
    connect(ui->quit, &QPushButton::clicked, this, &MainWindow::onQuitClicked);
    connect(&timer, &QTimer::timeout, this, &MainWindow::timeOut);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}


void MainWindow::onUpClicked()
{
    gun->up();
    ball->setAngle(gun->getangle());
    scene->invalidate(gun->boundingRect());
}

void MainWindow::onDownClicked()
{
    gun->down();
    ball->setAngle(gun->getangle());
    scene->invalidate(gun->boundingRect());
}

void MainWindow::onShootClicked()
{
    timer.start(10);
    ui->shoot->setEnabled(false);
    ui->up->setEnabled(false);
    ui->down->setEnabled(false);
    ui->powerDown->setEnabled(false);
    ui->powerUp->setEnabled(false);
    ui->small->setEnabled(false);
    ui->medium->setEnabled(false);
    ui->large->setEnabled(false);
}

void MainWindow::timeOut()
{
    ball->setPosition(0.0);
    scene->invalidate(ball->boundingRect());
    if (target->getPosition().contains(ball->getPosition()) || !ui->graphicsView->frameRect().contains(ball->getPosition()))
    {
        timer.stop();
        ball->stopTimer();
        ui->shoot->setEnabled(true);
        ui->up->setEnabled(true);
        ui->down->setEnabled(true);
        ui->powerDown->setEnabled(true);
        ui->powerUp->setEnabled(true);
        ui->small->setEnabled(true);
        ui->medium->setEnabled(true);
        ui->large->setEnabled(true);
        if (target->getPosition().contains(ball->getPosition()))
        {
            textResult->setText("Great! Now try with smaller target");
            if (target->radiusTarget() <= 10)
            {
                int ok = QMessageBox::information(this, "Congratulations!", "You win!!!");
                if (ok == QMessageBox::Ok)
                    qApp->quit();
            }
            target->replaceTarget(target->radiusTarget() - 1);
        }
        else
        {
            textResult->setText("You lose. Now try aggain.");
            target->replaceTarget(target->radiusTarget());
        }
        return;
    }
}

void MainWindow::onPowerDownClicked()
{
    if (ball->getSpeed() < 1)
        return;
    ball->speedDown();
    ui->progressBarSpeed->setValue(ball->getSpeed());
}

void MainWindow::onPowerUpClicked()
{
    if (ball->getSpeed() > 99)
        return;
    ball->speedUp();
    ui->progressBarSpeed->setValue(ball->getSpeed());
}

void MainWindow::onSmallClicked()
{
    ball->setRadius(maxRadius / 3);
}

void MainWindow::onMediumClicked()
{
    ball->setRadius(maxRadius / 2);
}

void MainWindow::onLargeClicked()
{
    ball->setRadius(maxRadius);
}

void MainWindow::onQuitClicked()
{
    qApp->quit();
}
