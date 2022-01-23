#ifndef ROOM_2_H
#define ROOM_2_H

#include <QWidget>
#include "trie_fruits.h"
#include "decode_fruits.h"
#include "room.h"

namespace Ui {
class Room_2;
}

class Room_2 : public QWidget, public Room
{
    Q_OBJECT

public:
    explicit Room_2(int level, QWidget *parent = nullptr);
    ~Room_2();
    /* Check if the button clicked is the right one */
    void verif_click(int);
    /* show or hide widgets related to the game 2 */
    void game2_show(bool);
    /* overload the function close to send signal to room2 */
    bool close(){emit closing(); return QWidget::close();}

private slots:
    void on_pushButton_jeu1_clicked();

    void on_pushButton_jeu2_clicked();

    void on_ans1_pushButton_clicked();

    void on_ans2_pushButton_clicked();

    void on_ans3_pushButton_clicked();

    void on_next_pushButton_clicked();

    void on_pushButton_jeu3_clicked();

    void on_nextRoom_pushButton_clicked();

private:
    Ui::Room_2 *ui;

signals:
    /* signal to say that the window is closing */
    void closing();
};

#endif // ROOM_2_H
