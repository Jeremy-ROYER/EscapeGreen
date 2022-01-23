#include "mainwindow.h"
#include "ui_mainwindow.h"

int level = 0;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->end_picture->hide();
    ui->pushButton_exit->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_rules_clicked()
{
    char message[5096] = "Ce jeu est un escape game virtuel sur le thème de l'environnement.\nLe but est de sortir à temps pour sauver la planète.\nPour cela vous devrez résoudre différentes énigmes.\n\nCliquez sur \"Commencer\" et laissez vous guider.";
    QMessageBox::information(this,"Règles du jeu",message);
}


void MainWindow::on_pushButton_start_clicked()
{
    QMessageBox choose_level;
    QPushButton *easy = new QPushButton("Facile");
    QPushButton *medium = new QPushButton("Intermédiaire");
    QPushButton *hard = new QPushButton("Difficile");

    choose_level.addButton(easy, QMessageBox::AcceptRole);
    choose_level.addButton(medium, QMessageBox::AcceptRole);
    choose_level.addButton(hard, QMessageBox::AcceptRole);
    choose_level.setIcon(QMessageBox::Question);

    choose_level.setText("Veuillez choisir le niveau de jeu souhaité.");

    choose_level.exec();

    if(choose_level.clickedButton() == easy)
    {
        level = 1;
    }
    else if(choose_level.clickedButton() == medium)
    {
        level = 2;
    }
    else if(choose_level.clickedButton() == hard)
    {
        level = 3;
    }

    this->setAttribute(Qt::WA_DeleteOnClose, true);

    room_1 *room1 = new room_1(level);
    Room_2 *room2 = new Room_2(level);
    /* delete room1 when it has accepted the close event */
    room1->setAttribute(Qt::WA_DeleteOnClose, true);
    /* Performs the show() slot of room2 (show the window room2) when room1 emits the closing() signal */
    connect(room1, SIGNAL(closing()), room2, SLOT(show()));

    this->hide();
    ui->pushButton_rules->hide();
    ui->pushButton_start->hide();
    ui->welcome_picture->hide();
    room1->show();
    room2->hide();

    /* delete room2 when it has accepted the close event */
    room2->setAttribute(Qt::WA_DeleteOnClose, true);
    /* Performs the show() slot of this (show the window this) when room2 emits the closing() signal */
    connect(room2, SIGNAL(closing()), this, SLOT(show()));

    ui->end_picture->show();
    ui->pushButton_exit->show();

}


void MainWindow::on_pushButton_exit_clicked()
{
    this->destroy();
}

