#ifndef ROOM_H
#define ROOM_H

class Room
{
public:
    Room(){};

    /* Pure virtual function : show or hide widgets related to the second game */
    virtual void game2_show(bool) =0;
    /* Pure virtual function : Check if it's the good answer in each  */
    virtual void verif_click(int) =0;

protected:
    int _level;
};

#endif // ROOM_H
