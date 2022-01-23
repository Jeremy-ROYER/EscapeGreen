#include "decode_fruits.h"
#include "ui_decode_fruits.h"

Decode_fruits::Decode_fruits(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Decode_fruits)
{
    ui->setupUi(this);

    ui->next_pushButton->hide();
    ui->resultmessage->hide();
    ui->info_label->hide();
}

Decode_fruits::~Decode_fruits()
{
    delete ui;
}

/* Check if it's the good answer in each  */
void Decode_fruits::verif_click(int pushButton)
{
    /* Default value */
    if(pushButton == 0)
    {
        int compt = 0;

        if(ui->textEdit->toPlainText() == "saison")
        {
            compt++;
        }

        if(ui->textEdit_2->toPlainText() == "trois à cinq"
                || ui->textEdit_2->toPlainText() == "3 à 5")
        {
            compt++;
        }

        if(ui->textEdit_3->toPlainText() == "transport")
        {
            compt++;
        }

        game_show(false);

        if(compt == 3)
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
            ui->next_pushButton->setText("Réessaye !\nTu as "+ QString::number(compt) + " bonne(s) réponse(s).");
        }

        ui->resultmessage->show();
        ui->next_pushButton->show();
    }
}


/* show or hide widgets related to the game */
void Decode_fruits::game_show(bool flag)
{
    if(flag)
    {
        ui->text1_label->show();
        ui->text2_label->show();
        ui->text3_label->show();
        ui->charade1_label->show();
        ui->charade2_label->show();
        ui->charade3_label->show();
        ui->textEdit->show();
        ui->textEdit_2->show();
        ui->textEdit_3->show();
        ui->valid_pushButton->show();
    }
    else
    {
        ui->text1_label->hide();
        ui->text2_label->hide();
        ui->text3_label->hide();
        ui->charade1_label->hide();
        ui->charade2_label->hide();
        ui->charade3_label->hide();
        ui->textEdit->hide();
        ui->textEdit_2->hide();
        ui->textEdit_3->hide();
        ui->valid_pushButton->hide();
    }
}





void Decode_fruits::on_valid_pushButton_clicked()
{
    verif_click();
}


void Decode_fruits::on_next_pushButton_clicked()
{
    if(ui->next_pushButton->text() == "Étape suivante !")
    {
        ui->resultmessage->hide();
        ui->next_pushButton->hide();
        ui->info_label->hide();
        this->close();
    }
    else
    {
        ui->resultmessage->hide();
        ui->next_pushButton->hide();
        ui->info_label->hide();

        game_show(true);
    }
}

