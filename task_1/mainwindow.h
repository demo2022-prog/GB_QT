#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include<QListView>
#include <QStandardItemModel>
#include <QItemSelectionModel>

#include "specialcharacter.h"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_textEdit_textChanged();
    void on_ClearButton_clicked();

    void on_AddButton_clicked();
    void on_RemoveButton_clicked();

private:
    QString textFromEditor;
    QString textOld;
    SpecialCharacter *specialCharacter;
    bool isCheck{false};

    Ui::MainWindow *ui_;
    QStandardItemModel model_;
};



#endif // MAINWINDOW_H
