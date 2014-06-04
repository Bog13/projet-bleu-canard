#ifndef TILE_H
#define TILE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
using namespace sf;



class Tile
{
    public:
        Tile();
        void setType(int type){m_type=type;}
        virtual ~Tile();
    protected:
        int m_type;
    private:
};

#endif // TILE_H
