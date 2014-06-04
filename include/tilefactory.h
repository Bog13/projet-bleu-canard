#ifndef TILEFACTORY_H
#define TILEFACTORY_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "tilegraphic.h"
#include "graphics.h"
#include "animation.h"
#include "animationfactory.h"
#include "global.h"
using namespace std;
using namespace sf;




class TileFactory
{
    public:
        TileFactory();
        virtual ~TileFactory();

        static void load();
        static TileGraphic get(int i);


    protected:
        static vector<TileGraphic> m_vector;
    private:
};

#endif // TILEFACTORY_H
