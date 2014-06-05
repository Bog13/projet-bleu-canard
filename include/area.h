#ifndef AREA_H
#define AREA_H
#include <iostream>
#include <vector>
#include "tile.h"
#include "global.h"
using namespace std;

class Area
{
    public:
        Area(int w,int h);
        void initTile();
        void newSize(int w,int h);
        void killTiles();
        void setTiles(vector<vector<int> > values);
        Tile* getTile(int x,int y);

        void update();

        int getWidth(){return m_width;}
        int getHeight(){return m_height;}

        virtual ~Area();
    protected:
        int m_width;
        int m_height;
        vector<vector<Tile*> > m_tiles;
    private:
};

#endif // AREA_H