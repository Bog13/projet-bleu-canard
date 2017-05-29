#ifndef TILE_H
#define TILE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "typable.h"
using namespace std;
using namespace sf;


class Tile: public Typable
{
    public:
        Tile();
        Tile(int type);
        virtual void update();
        virtual ~Tile();
    protected:

    private:
};

#endif // TILE_H
