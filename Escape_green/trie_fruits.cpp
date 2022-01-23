#include "trie_fruits.h"
#include "ui_trie_fruits.h"

Trie_fruits::Trie_fruits(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Trie_fruits)
{
    ui->setupUi(this);

    ui->result_message->hide();
    ui->next_pushButton->hide();
}

Trie_fruits::~Trie_fruits()
{
    delete ui;
}

/* show or hide widgets related to the game */
void Trie_fruits::game_show(bool flag)
{
    if(flag)
    {
        ui->summer_pushButton->show();
        ui->winter_pushButton->show();
        ui->spring_pushButton->show();
        ui->autumn_pushButton->show();
        ui->current_fruits->show();
    }
    else
    {
        ui->summer_pushButton->hide();
        ui->winter_pushButton->hide();
        ui->spring_pushButton->hide();
        ui->autumn_pushButton->hide();
        ui->current_fruits->hide();
    }
}

/* Check if the button clicked is the right one */
void Trie_fruits::verif_click(int pushButton)
{
    game_show(false);

    /* Good answer */
    if(answer[compt] == pushButton)
    {
        QPixmap pm_resMess("../pictures/picture_bravo.jpg");
        ui->result_message->setPixmap(pm_resMess);

        /* Last picture and good answer */
        if(compt >= comptMax-1)
        {
            ui->next_pushButton->setText("Étape suivante !");
        }
        else
        {
            ui->next_pushButton->setText("Image suivante");
        }

        compt++;
    }
    else
    {
        QPixmap pm_resMess("../pictures/picture_tryAgain.png");
        ui->result_message->setPixmap(pm_resMess);
        ui->next_pushButton->setText("Réessaye");
    }

    ui->result_message->show();
    ui->next_pushButton->show();
}


void Trie_fruits::on_next_pushButton_clicked()
{
    /* If it was the last one, we have to close this game */
    if(compt >= comptMax)
    {
        this->close();
    }

    ui->result_message->hide();
    ui->next_pushButton->hide();

    char path[32];
    sprintf(path, "../pictures/fruits/%d.jpg", compt);
    QPixmap pm_curObj(path);
    ui->current_fruits->setPixmap(pm_curObj);

    game_show(true);
}


void Trie_fruits::on_summer_pushButton_clicked()
{
    verif_click(1);
}


void Trie_fruits::on_autumn_pushButton_clicked()
{
    verif_click(2);
}


void Trie_fruits::on_winter_pushButton_clicked()
{
    verif_click(3);
}


void Trie_fruits::on_spring_pushButton_clicked()
{
    verif_click(4);
}
