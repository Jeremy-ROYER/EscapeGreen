#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "room_1.h"
#include "room_2.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_rules_clicked();

    void on_pushButton_start_clicked();

    void on_pushButton_exit_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
