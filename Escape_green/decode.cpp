#include "decode.h"
#include "ui_decode.h"

Decode::Decode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Decode)
{
    ui->setupUi(this);

    ui->next_pushButton->hide();
    ui->resultmessage->hide();
    ui->info_label->hide();
}

Decode::~Decode()
{
    delete ui;
}

/* show or hide widgets related to the game */
void Decode::game_show(bool flag)
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


/* Check if it's the good answer in each  */
void Decode::verif_click(int pushButton)
{
    /* Default value */
    if(pushButton == 0)
    {
        int compt = 0;

        if(ui->textEdit->toPlainText() == "ordinateur")
        {
            compt++;
        }

        if(ui->textEdit_2->toPlainText() == "1500")
        {
            compt++;
        }

        if(ui->textEdit_3->toPlainText() == "déchets")
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

void Decode::on_valid_pushButton_clicked()
{
    verif_click();
}


void Decode::on_next_pushButton_clicked()
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

