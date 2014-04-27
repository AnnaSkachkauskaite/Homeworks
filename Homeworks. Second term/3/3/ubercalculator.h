#ifndef UBERCALCULATOR_H
#define UBERCALCULATOR_H

#include <QMainWindow>
#include <QSignalMapper>
#include <QObject>

namespace Ui {
class UberCalculator;
}

class UberCalculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit UberCalculator(QWidget *parent = 0);
    ~UberCalculator();

private:
    Ui::UberCalculator *ui;
    QSignalMapper *signalMapper;

private slots:
    void addToLine(QString str);
    void getResult();

};

#endif // UBERCALCULATOR_H
