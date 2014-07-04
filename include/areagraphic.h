#ifndef AREAGRAPHIC_H
#define AREAGRAPHIC_H
#include <iostream>
#include <vector>
#include <iomanip>
#include "tile.h"
#include "global.h"
#include "entitygraphic.h"
#include "tilefactory.h"
#include "area.h"
#include "camera.h"
#include "graphics.h"
using namespace std;

class EntityGraphic;
class Graphics;
class AreaGraphic
{
    public:
        AreaGraphic(Area *a,Graphics *g=0);
        void initTiles();
        void initObjects();

        EntityGraphic* getTileGraphic(int x,int y);
        EntityGraphic* getObjectGraphic(int i);
        EntityGraphic* getVisibleObjectGraphic(int i);
        int lowestObj(int maxIndex);
        void sortObj() const;
        void initSortObj();

        void setGraphics( Graphics* g) {m_graphic=g;}

        int nbObject(){return m_area->nbObject();}
        int nbVisibleObject(){return m_visibleObjects.size();}
        void updateTiles();
        void updateTiles(int i,int j);
        void verifyTiles();

        void updateVisibleObject(unsigned int i);
        void updateObjects();
        void update();
        void synchroniseTiles(int f);

        int getWidth(){return m_width;}
        int getHeight(){return m_height;}
        Area* getArea(){return m_area;}
        const void getInfo();



        virtual ~AreaGraphic();
    protected:
        int m_width;
        int m_height;
        Area *m_area;
        Graphics* m_graphic;
        vector<vector<EntityGraphic*> > m_tiles;
        vector<EntityGraphic* > m_objects;
        vector<EntityGraphic* > m_visibleObjects;

    private:
};
#endif // AREAGRAPHIC_H
