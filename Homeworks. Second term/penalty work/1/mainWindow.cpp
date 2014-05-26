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

    scene = new QGraphicsScene();
    ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    gun = new Cannon(ui->graphicsView->width(), scene->width(), scene->height());
    scene->addItem(gun);

    ball= new Bullet(gun->getWidth(), 50.0, 45.0,
                         gun->getRadius() + gun->getHeigh(),
                         (double)scene->width(), (double)scene->height());
    scene->addItem(ball);

    target = new Target(40, scene->width(), scene->height());
    scene->addItem(target);

    textResult = new QGraphicsSimpleTextItem("Change direction of the cannon and shoot power using special buttons. You can also use arrow keys.");
    scene->addItem(textResult);

    ui->graphicsView->setScene(scene);
    ui->progressBarSpeed->setValue(ball->getSpeed());

    shortcutInitialize();

    connect(ui->up, &QPushButton::clicked, this, &MainWindow::onUpClicked);
    connect(ui->down, &QPushButton::clicked, this, &MainWindow::onDownClicked);
    connect(ui->shoot, &QPushButton::clicked, this, &MainWindow::onShootClicked);
    connect(ui->powerDown, &QPushButton::clicked, this, &MainWindow::onPowerDownClicked);
    connect(ui->powerUp, &QPushButton::clicked, this, &MainWindow::onPowerUpClicked);
    connect(&timer, &QTimer::timeout, this, &MainWindow::timeOut);
    showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete shortcutDown;
    delete shortcutUp;
    delete shortcutLeft;
    delete shortcutRight;
    delete shortcutPower;
}

void MainWindow::shortcutInitialize()
{
    shortcutLeft = new QShortcut(QKeySequence(QKeySequence::MoveToPreviousChar), this);
    shortcutLeft->connect(shortcutLeft,SIGNAL(activated()),this,SLOT(onPowerDownClicked()));

    shortcutRight = new QShortcut(QKeySequence(QKeySequence::MoveToNextChar), this);
    shortcutRight->connect(shortcutRight,SIGNAL(activated()),this,SLOT(onPowerUpClicked()));

    shortcutDown = new QShortcut(QKeySequence(QKeySequence::MoveToNextLine), this);
    shortcutDown->connect(shortcutDown,SIGNAL(activated()),this,SLOT(onDownClicked()));

    shortcutUp = new QShortcut(QKeySequence(QKeySequence::MoveToPreviousLine), this);
    shortcutUp->connect(shortcutUp, SIGNAL(activated()), this, SLOT(onUpClicked()));

    shortcutPower = new QShortcut(QKeySequence(QKeySequence::InsertParagraphSeparator), this);
    shortcutPower->connect(shortcutPower,SIGNAL(activated()),this,SLOT(onShootClicked()));
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
}

void MainWindow::timeOut()
{
    ball->setPosition(0.0);
    scene->invalidate(ball->boundingRect());
    if (target->getPosition().contains(ball->getPosition()) || !ui->graphicsView->frameRect().contains(ball->getPosition()))
    {
        timer.stop();
        ball->stopTimer();
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
