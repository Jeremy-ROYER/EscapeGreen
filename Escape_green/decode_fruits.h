#ifndef DECODE_FRUITS_H
#define DECODE_FRUITS_H

#include <QWidget>
#include "game.h"

namespace Ui {
class Decode_fruits;
}

class Decode_fruits : public QWidget, public Game
{
    Q_OBJECT

public:
    explicit Decode_fruits(QWidget *parent = nullptr);
    ~Decode_fruits();
    /* Check if it's the good answer in each  */
    void verif_click(int = 0);
    /* show or hide widgets related to the game */
    void game_show(bool);
    /* overload the function close to send signal to room1 */
    bool close(){emit closing(); return QWidget::close();}

signals:
    /* signal to say that the window is closing */
    void closing();

private slots:
    void on_valid_pushButton_clicked();

    void on_next_pushButton_clicked();

private:
    Ui::Decode_fruits *ui;
};

#endif // DECODE_FRUITS_H
