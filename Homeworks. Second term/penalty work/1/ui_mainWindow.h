/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *up;
    QPushButton *down;
    QPushButton *shoot;
    QPushButton *powerUp;
    QPushButton *powerDown;
    QLabel *label_3;
    QPushButton *small;
    QPushButton *medium;
    QPushButton *large;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QProgressBar *progressBarSpeed;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        up = new QPushButton(centralWidget);
        up->setObjectName(QStringLiteral("up"));

        verticalLayout->addWidget(up);

        down = new QPushButton(centralWidget);
        down->setObjectName(QStringLiteral("down"));

        verticalLayout->addWidget(down);

        shoot = new QPushButton(centralWidget);
        shoot->setObjectName(QStringLiteral("shoot"));

        verticalLayout->addWidget(shoot);

        powerUp = new QPushButton(centralWidget);
        powerUp->setObjectName(QStringLiteral("powerUp"));

        verticalLayout->addWidget(powerUp);

        powerDown = new QPushButton(centralWidget);
        powerDown->setObjectName(QStringLiteral("powerDown"));

        verticalLayout->addWidget(powerDown);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        small = new QPushButton(centralWidget);
        small->setObjectName(QStringLiteral("small"));

        verticalLayout->addWidget(small);

        medium = new QPushButton(centralWidget);
        medium->setObjectName(QStringLiteral("medium"));

        verticalLayout->addWidget(medium);

        large = new QPushButton(centralWidget);
        large->setObjectName(QStringLiteral("large"));

        verticalLayout->addWidget(large);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        progressBarSpeed = new QProgressBar(centralWidget);
        progressBarSpeed->setObjectName(QStringLiteral("progressBarSpeed"));
        progressBarSpeed->setValue(24);

        verticalLayout_2->addWidget(progressBarSpeed);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Turn cannon:", 0));
        up->setText(QApplication::translate("MainWindow", "up", 0));
        down->setText(QApplication::translate("MainWindow", "down", 0));
        shoot->setText(QApplication::translate("MainWindow", "shoot", 0));
        powerUp->setText(QApplication::translate("MainWindow", "power up", 0));
        powerDown->setText(QApplication::translate("MainWindow", "power down", 0));
        label_3->setText(QApplication::translate("MainWindow", "Choose cannonball size", 0));
        small->setText(QApplication::translate("MainWindow", "Small", 0));
        medium->setText(QApplication::translate("MainWindow", "Medium", 0));
        large->setText(QApplication::translate("MainWindow", "Large", 0));
        label_2->setText(QApplication::translate("MainWindow", "Power:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
