#ifndef TRIE_FRUITS_H
#define TRIE_FRUITS_H

#include <QWidget>
#include "trie_game.h"

namespace Ui {
class Trie_fruits;
}

class Trie_fruits : public QWidget, public Trie_game
{
    Q_OBJECT

public:
    explicit Trie_fruits(QWidget *parent = nullptr);
    ~Trie_fruits();
    /* Check if the button clicked is the right one */
    void verif_click(int);
    /* overload the function close to send signal to room1 */
    bool close(){emit closing(); return QWidget::close();}
    /* show or hide widgets related to the game */
    void game_show(bool);

private:
    Ui::Trie_fruits *ui;
    const vector<int> answer{3,2,1,3,3,1,4,3,1,2}; /* summer->1 ; autumn->2 ; winter->3 ; spring->4 */

signals :
    /* signal to say that the window is closing */
    void closing();

private slots:
    void on_summer_pushButton_clicked();
    void on_autumn_pushButton_clicked();
    void on_winter_pushButton_clicked();
    void on_spring_pushButton_clicked();
    void on_next_pushButton_clicked();
};

#endif // TRIE_FRUITS_H
