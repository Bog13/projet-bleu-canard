#ifndef TILEFACTORY_H
#define TILEFACTORY_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

/*
#include "entitygraphic.h"
#include "graphics.h"
#include "animation.h"
#include "animationfactory.h"
#include "global.h"
*/
using namespace std;
using namespace sf;



class EntityGraphic;

class TileFactory
{
    public:
        TileFactory();
        virtual ~TileFactory();

        static void load();
        static void loadTile(int clue);
        static EntityGraphic get(int i);


    protected:
        static vector<EntityGraphic> m_vector;
    private:
};

#endif // TILEFACTORY_H
