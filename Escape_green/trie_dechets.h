#ifndef TRIE_DECHETS_H
#define TRIE_DECHETS_H

#include <QWidget>
#include <string>
#include "trie_game.h"

using namespace std;

namespace Ui {
class Trie_dechets;
}

class Trie_dechets : public QWidget, public Trie_game
{
    Q_OBJECT

public:
    /* Constructor / Destructor */
    explicit Trie_dechets(QWidget *parent = nullptr);
    ~Trie_dechets();
    /* Check if the button clicked is the right one */
    void verif_click(int);
    /* show or hide widgets related to the game */
    void game_show(bool);
    /* overload the function close to send signal to room1 */
    bool close(){emit closing(); return QWidget::close();}

private slots:
    void on_yellowBin_pushButton_clicked();

    void on_greenBin_pushButton_clicked();

    void on_blueBin_pushButton_clicked();

    void on_brownBin_pushButton_clicked();

    void on_compost_pushButton_clicked();

    void on_next_pushButton_clicked();

private:
    Ui::Trie_dechets *ui;
    const vector<int> answer{2,5,1,1,2,1,1,3,5,4};

signals :
    /* signal to say that the window is closing */
    void closing();

};

#endif // TRIE_DECHETS_H
