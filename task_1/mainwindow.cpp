#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtMath"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_calcButton_clicked() {
    qint32 numA = ui->number_1->text().toDouble();
    qint32 numB = ui->number_2->text().toDouble();
    qint32 numC = ui->number_3->text().toDouble();

    if(numA == 0) { // проверка на А=0
        qint32 val = numC / (-numB);

        ui->value_1->setNum(val);
    } else {
        double diskr = (numB * numB) - (4 * (numA * numC)); // находим дискриминат
        if(diskr > 0) { // при D > 0
        qint32 val1 = ((-numB) + qSqrt(diskr)) / (2 * numA);
        qint32 val2 = ((-numB) - qSqrt(diskr)) / (2 * numA);

        ui->value_1->setNum(val1);
        ui->value_2->setNum(val2);
      } else if (diskr == 0) { // при D = 0
        qint32 val = (-(numB / (2 * numA)));

        ui->value_1->setNum(val);
      } else if(diskr < 0) { // при D < 0
            ui->value_1->setText("No roots");
            ui->value_2->setText("No roots");
      }
    }

}


void MainWindow::on_clearButton_clicked() { // очищаем поля ввода/вывода
    ui->number_1->clear();
    ui->number_2->clear();
    ui->number_3->clear();
    ui->value_1->clear();
    ui->value_2->clear();
}

