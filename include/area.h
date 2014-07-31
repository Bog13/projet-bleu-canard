#ifndef AREA_H
#define AREA_H
#include <iostream>
#include <vector>
/*
#include "tile.h"
#include "global.h"
#include "object.h"
#include "positionable.h"
#include "movable.h"*/
using namespace std;

class Object;
class Tile;
class Movable;

class Area
{
    public:
        Area(int w,int h);
        void initTile();
        void newSize(int w,int h);
        void addTiles(int w, int h);
        void killTiles();
        void killObjects();
        void setTiles(vector<vector<int> > values);
        Tile* getTile(int x,int y);
        bool modifyTile(int x, int y, int id);
        Object* getObject(int i);
        void addObject(Object* o){m_objects.push_back(o);}

        void addObject(Object* o, float x, float y);
        int nbObject(){return m_objects.size();}
        bool in(int i,int j){return (i>=0 && i<m_width && j>=0 && j<m_height);}
        void update();
        void updateObjects();
        void updateTiles();

        int getWidth(){return m_width;}
        int getHeight(){return m_height;}

        void getInfo();

        bool isAccessible(Movable &pos);

        virtual ~Area();
    protected:
        int m_width;
        int m_height;
        vector<vector<Tile*> > m_tiles;
        vector<Object* > m_objects;
    private:
};

#endif // AREA_H
