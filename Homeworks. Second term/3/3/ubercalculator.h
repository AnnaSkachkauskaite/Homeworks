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
    ///Adding symbols to lineEdit
    void addToLine(QString str);
    ///Computing value of the expression from lineEdit
    void getResult();
    ///Clear lineEdit
    void clearLine();

};

#endif // UBERCALCULATOR_H
