#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pasteButton_clicked() {
    QString str = ui->textEdit_1->toPlainText(); // копируем текст из первого окна
    ui->textEdit_2->setText(str); // вставляем текст первого окна во второе
}

void MainWindow::on_swapButton_clicked() {
    QString str_1 = ui->textEdit_1->toPlainText(); // копируем текст из первого окна
    QString str_2 = ui->textEdit_2->toPlainText(); // копируем текст из второго окна

    ui->textEdit_1->setText(str_2); // вставляем текст первого окна во второе
    ui->textEdit_2->setText(str_1); // вставляем текст второго окна в первое
}

void MainWindow::on_clearButton_clicked() { // очищаем поля ввода
    ui->textEdit_1->clear();
    ui->textEdit_2->clear();
}

void MainWindow::on_htmlButton_clicked() { // вставляем html код
    ui->textEdit_1->setHtml("<font color='red'>Hello</font>");
}

