#ifndef GLOBAL_H
#define GLOBAL_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>
using namespace std;
using namespace sf;

class Global
{
    public:
        Global();
        virtual ~Global();


        static const int WINDOW_WIDTH=640;
        static const int WINDOW_HEIGHT=480;

        static const int TILE_WIDTH=32;
        static const int TILE_HEIGHT=32;

        static const int NB_TILE_WIDTH=WINDOW_WIDTH/TILE_WIDTH;
        static const int NB_TILE_HEIGHT=WINDOW_HEIGHT/TILE_HEIGHT;

        static const int ID_NONE=0;
        static const int ID_GROUND=1;
        static const int ID_GRASS=2;
        static const int ID_ROCK=3;


        static string intToStr(int n);
        static int strToInt(string str);
        static int sizeWithoutSpace(string str);

    protected:


    private:
};

#endif // GLOBAL_H
