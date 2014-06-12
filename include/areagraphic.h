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

class EntityGraphic;
class AreaGraphic
{
    public:
        AreaGraphic(Area *a);
        void initTiles();
        void initObjects();
        EntityGraphic* getTileGraphic(int x,int y);
        EntityGraphic* getObjectGraphic(int i);
        int nbObject(){return m_area->nbObject();}
        void updateTiles();
        void verifyTiles();
        void updateObjects();
        void update();
        void synchroniseTiles(int f);

        int getWidth(){return m_width;}
        int getHeight(){return m_height;}

        const void getInfo();



        virtual ~AreaGraphic();
    protected:
        int m_width;
        int m_height;
        Area *m_area;
        vector<vector<EntityGraphic*> > m_tiles;
        vector<EntityGraphic* > m_objects;
    private:
};
#endif // AREAGRAPHIC_H
