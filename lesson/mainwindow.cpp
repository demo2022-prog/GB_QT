#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtMath"
#include "QLineEdit"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->calcButton, &QPushButton::clicked, this, &MainWindow::on_calc_clicked);

  connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::on_clear_clicked);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_calc_clicked() {
  double numA = ui->num1->text();
  double numB = ui->num2->text();
  double numC = ui->num3->text();

  double diskr = (numB * numB) - (4 * (numA * numC));
  if(dickr > 0) {
      double val1 = ((-numB) + qSqrt(diskr)) / (2 * numA);
      double val2 = ((-numB) - qSqrt(diskr)) / (2 * numA);
      ui->value1->setText(val1);
      ui->value2->setText(val2);
    } else if (diskr = 0) {
      double val = (-(numB / (2 * numA)));
      ui->value1->setText(val);
    } else {

    }

}

void MainWindow::on_clear_clicked()
{

}

