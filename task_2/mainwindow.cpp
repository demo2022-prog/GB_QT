#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtMath"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_calcButton_clicked() {
    quint32 lineA = ui->line_1->text().toInt();
    quint32 lineB = ui->line_2->text().toInt();
    quint32 angl = ui->angle->text().toDouble();

    if (ui->degreeButton->isChecked()) {
        double lineC = qSqrt(qPow(lineA, 2) + qPow(lineB, 2) - ((2 * lineA * lineB) * qCos(qDegreesToRadians(angl))));

        ui->value->setNum(lineC);
    }
    if(ui->radianButton->isChecked()){
        double lineC = qSqrt(qPow(lineA, 2) + qPow(lineB, 2) - ((2 * lineA * lineB) * qCos(angl)));

        ui->value->setNum(lineC);
    }
}


void MainWindow::on_clearButton_clicked() { // очищаем поля ввода/вывода
    ui->line_1->clear();
    ui->line_2->clear();
    ui->angle->clear();
    ui->value->clear();
}

