#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextEdit>
#include <QLayout>
#include<QIcon>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui_(new Ui::MainWindow) {
  ui_->setupUi(this);

  ui_->listView->setModel(&model_);
  ui_->listView->setSelectionMode(QAbstractItemView::SingleSelection);

  model_.appendRow(new QStandardItem("C++"));
  model_.appendRow(new QStandardItem("Java"));
  model_.appendRow(new QStandardItem("Py"));

  connect(ui_->AddButton, &QPushButton::clicked, this, &MainWindow::on_AddButton_clicked);
  connect(ui_->RemoveButton, &QPushButton::clicked, this, &MainWindow::on_RemoveButton_clicked);

  setWindowTitle("Lang list");
}

MainWindow::~MainWindow() {
  delete ui_;
}

void MainWindow::on_textEdit_textChanged(){

    textFromEditor = ui_->textEdit->toPlainText();
    textOld = textFromEditor;

    specialCharacter->specialCharacter(textFromEditor);

    if(textOld != textFromEditor){
        ui_->textEdit->setText(textFromEditor);

        QTextCursor cursor = ui_->textEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui_->textEdit->setTextCursor(cursor);
    }
}

void MainWindow::on_ClearButton_clicked() {
    ui_->textEdit->clear();

}


void MainWindow::on_AddButton_clicked() {
    if (!ui_->langNameEdit->text().isEmpty()) {
            model_.appendRow(new QStandardItem(ui_->langNameEdit->text()));
            ui_->langNameEdit->clear();
        }
}


void MainWindow::on_RemoveButton_clicked() {
    auto selection_model = ui_->listView->selectionModel();
        if (selection_model->hasSelection()) {
            auto cur_ind = selection_model->currentIndex();
            if (cur_ind.isValid()) {
                model_.removeRow(cur_ind.row());
            }
        }

}

