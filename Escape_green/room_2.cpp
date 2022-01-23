#include "room_2.h"
#include "ui_room_2.h"

Room_2::Room_2(int level, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Room_2)
{
    _level = level;
    ui->setupUi(this);
    ui->pushButton_jeu2->hide();
    ui->pushButton_jeu3->hide();

    game2_show(false);
    ui->next_pushButton->hide();
    ui->resultmessage->hide();
    ui->info_label->hide();

    ui->nextRoom_pushButton->hide();
    ui->completed_picture->hide();
}

Room_2::~Room_2()
{
    delete ui;
}

void Room_2::on_pushButton_jeu1_clicked()
{
    Trie_fruits *game1 = new Trie_fruits();
    /* delete game1 when it has accepted the close event */
    game1->setAttribute(Qt::WA_DeleteOnClose, true);
    /* Performs the show() slot of this (show the window this) when game1 emits the closing() signal */
    connect(game1, SIGNAL(closing()), this, SLOT(show()));
    game1->show();
    this->hide();

    ui->pushButton_jeu1->setEnabled(false);
    ui->pushButton_jeu2->show();
}

/* show or hide widgets related to the game 2 */
void Room_2::game2_show(bool flag)
{
    if(flag)
    {
        ui->question_label->show();
        ui->ans1_pushButton->show();
        ui->ans2_pushButton->show();
        ui->ans3_pushButton->show();
    }
    else
    {
        ui->question_label->hide();
        ui->ans1_pushButton->hide();
        ui->ans2_pushButton->hide();
        ui->ans3_pushButton->hide();
    }

}

/* The game question is displayed when the button is clicked */
void Room_2::on_pushButton_jeu2_clicked()
{
    game2_show(true);
    ui->pushButton_jeu2->setEnabled(false);
}

void Room_2::verif_click(int pushButton)
{
    game2_show(false);

    if(pushButton == 3)
    {
        QPixmap pm_resMess("../pictures/picture_bravo.jpg");
        ui->resultmessage->setPixmap(pm_resMess);
        ui->next_pushButton->setText("Étape suivante !");
        ui->info_label->show();
    }
    else
    {
        QPixmap pm_resMess("../pictures/picture_tryAgain.png");
        ui->resultmessage->setPixmap(pm_resMess);
        ui->next_pushButton->setText("Réessaye !");
    }
    ui->resultmessage->show();
    ui->next_pushButton->show();
}

void Room_2::on_ans1_pushButton_clicked()
{
    verif_click(1);
}


void Room_2::on_ans2_pushButton_clicked()
{
    verif_click(2);
}


void Room_2::on_ans3_pushButton_clicked()
{
    verif_click(3);
}


void Room_2::on_next_pushButton_clicked()
{
    if(ui->next_pushButton->text() == "Étape suivante !")
    {
        ui->resultmessage->hide();
        ui->next_pushButton->hide();
        ui->info_label->hide();
        ui->pushButton_jeu3->show();
    }
    else
    {
        ui->resultmessage->hide();
        ui->next_pushButton->hide();
        ui->info_label->hide();

        game2_show(true);
    }
}

/* launches the third game in the room */
void Room_2::on_pushButton_jeu3_clicked()
{
    Decode_fruits *game3 = new Decode_fruits();
    /* delete game3 when it has accepted the close event */
    game3->setAttribute(Qt::WA_DeleteOnClose, true);
    /* Performs the show() slot of this (show the window this) when game3 emits the closing() signal */
    connect(game3, SIGNAL(closing()), this, SLOT(show()));
    game3->show();
    this->hide();

    ui->pushButton_jeu3->setEnabled(false);
    ui->completed_picture->show();
    ui->nextRoom_pushButton->show();
}


void Room_2::on_nextRoom_pushButton_clicked()
{
    this->close();
}

