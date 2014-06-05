#ifndef AREAGRAPHIC_H
#define AREAGRAPHIC_H
#include <iostream>
#include <vector>
#include "tile.h"
#include "global.h"
#include "entitygraphic.h"
#include "tilefactory.h"
#include "area.h"
using namespace std;

class AreaGraphic
{
    public:
        AreaGraphic(Area *a);
        void initTile();
        EntityGraphic* getTileGraphic(int x,int y);
        void update();

        int getWidth(){return m_width;}
        int getHeight(){return m_height;}


        virtual ~AreaGraphic();
    protected:
        int m_width;
        int m_height;
        Area *m_area;
        vector<vector<EntityGraphic> > m_tiles;
    private:
};
#endif // AREAGRAPHIC_H
