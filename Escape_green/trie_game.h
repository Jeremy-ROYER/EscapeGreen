#ifndef TRIE_GAME_H
#define TRIE_GAME_H

#include <stdlib.h>
#include <vector>
#include "game.h"

using namespace std;

class Trie_game : public Game
{
public:
    Trie_game(){};

protected:
    vector<int> answer{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    const int comptMax = answer.size();
    int compt = 0;

};


#endif // TRIE_GAME_H
