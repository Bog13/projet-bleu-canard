#ifndef AREA_H
#define AREA_H
#include <iostream>
#include <vector>
#include "tile.h"
#include "global.h"
#include "object.h"
#include "positionable.h"
using namespace std;

class Object;
class Positionable;
class Area
{
    public:
        Area(int w,int h);
        void initTile();
        void newSize(int w,int h);
        void addTiles(int w, int h);
        void killTiles();
        void killObjects();
        void modifyTile(int x, int y, int tileID);
        void setTiles(vector<vector<int> > values);
        Tile* getTile(int x,int y);
        Object* getObject(int i);
        void addObject(Object* o){m_objects.push_back(o);}
        int nbObject(){return m_objects.size();}
        bool in(int i,int j){return (i>=0 && i<m_width && j>=0 && j<m_height);}
        void update();
        void updateObjects();
        void updateTiles();

        int getWidth(){return m_width;}
        int getHeight(){return m_height;}

        void getInfo();

        bool isAccessible(Positionable *pos,Positionable *zone);

        virtual ~Area();
    protected:
        int m_width;
        int m_height;
        vector<vector<Tile*> > m_tiles;
        vector<Object* > m_objects;
    private:
};

#endif // AREA_H
