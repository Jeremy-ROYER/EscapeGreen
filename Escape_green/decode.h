#ifndef DECODE_H
#define DECODE_H

#include <QWidget>
#include <stdlib.h>
#include <string>
#include "game.h"

using namespace std;

namespace Ui {
class Decode;
}

class Decode : public QWidget, public Game
{
    Q_OBJECT

public:
    explicit Decode(QWidget *parent = nullptr);
    ~Decode();
    /* Check if it's the good answer in each  */
    void verif_click(int = 0);
    /* show or hide widgets related to the game */
    void game_show(bool);
    /* overload the function close to send signal to room1 */
    bool close(){emit closing(); return QWidget::close();}

private:
    Ui::Decode *ui;

signals:
    /* signal to say that the window is closing */
    void closing();
private slots:
    void on_valid_pushButton_clicked();
    void on_next_pushButton_clicked();
};

#endif // DECODE_H
