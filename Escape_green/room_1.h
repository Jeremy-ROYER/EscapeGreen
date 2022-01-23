#ifndef ROOM_1_H
#define ROOM_1_H

#include <QWidget>
#include "trie_dechets.h"
#include "decode.h"
#include "room.h"

namespace Ui {
class room_1;
}

class room_1 : public QWidget, public Room
{
    Q_OBJECT

public:
    explicit room_1(int level, QWidget *parent = nullptr);
    ~room_1();
    /* Check if the button clicked is the right one */
    void verif_click(int);
    /* show or hide widgets related to the game 2 */
    void game2_show(bool);
    /* overload the function close to send signal to room2 */
    bool close(){emit closing(); return QWidget::close();}

/* different slots depending on the user's actions on the window */
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
    Ui::room_1 *ui;

signals:
    /* signal to say that the window is closing */
    void closing();
};

#endif // ROOM_1_H
