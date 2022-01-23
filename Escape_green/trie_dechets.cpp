#include "trie_dechets.h"
#include "ui_trie_dechets.h"

Trie_dechets::Trie_dechets(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Trie_dechets)
{
    ui->setupUi(this);

    ui->result_message->hide();
    ui->next_pushButton->hide();
}

Trie_dechets::~Trie_dechets()
{
    delete ui;
}

/* show or hide widgets related to the game */
void Trie_dechets::game_show(bool flag)
{
    if(flag)
    {
        ui->yellowBin_pushButton->show();
        ui->greenBin_pushButton->show();
        ui->blueBin_pushButton->show();
        ui->brownBin_pushButton->show();
        ui->compost_pushButton->show();
        ui->current_obj->show();
    }
    else
    {
        ui->yellowBin_pushButton->hide();
        ui->greenBin_pushButton->hide();
        ui->blueBin_pushButton->hide();
        ui->brownBin_pushButton->hide();
        ui->compost_pushButton->hide();
        ui->current_obj->hide();
    }
}

/* Check if the button clicked is the right one */
void Trie_dechets::verif_click(int pushButton)
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

void Trie_dechets::on_next_pushButton_clicked()
{
    /* If it was the last one, we have to close this game */
    if(compt >= comptMax)
    {
        this->close();
    }

    ui->result_message->hide();
    ui->next_pushButton->hide();

    char path[32];
    sprintf(path, "../pictures/waste/%d.jpg", compt);
    QPixmap pm_curObj(path);
    ui->current_obj->setPixmap(pm_curObj);

    game_show(true);
}

void Trie_dechets::on_yellowBin_pushButton_clicked()
{
    verif_click(1);
}

void Trie_dechets::on_greenBin_pushButton_clicked()
{
    verif_click(2);
}


void Trie_dechets::on_blueBin_pushButton_clicked()
{
    verif_click(3);
}


void Trie_dechets::on_brownBin_pushButton_clicked()
{
    verif_click(4);
}


void Trie_dechets::on_compost_pushButton_clicked()
{
    verif_click(5);
}
