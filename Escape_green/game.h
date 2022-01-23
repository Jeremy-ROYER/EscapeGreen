#ifndef GAME_H
#define GAME_H


class Game
{
public:
    Game(){};

    /* Pure virtual function : show or hide widgets related to the game */
    virtual void game_show(bool) =0;
    /* Pure virtual function : Check if it's the good answer in each  */
    virtual void verif_click(int = 0) =0;


};

#endif // GAME_H
