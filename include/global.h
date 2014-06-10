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

        static const int NB_STATE_CHAR_NONE=6;

        static const int ID_NONE=0;
        static const int ID_GROUND=ID_NONE+1;
        static const int ID_GRASS=ID_NONE+2;
        static const int ID_ROCK=ID_NONE+3;

        static const int ID_CHAR_NONE=4;
        static const int ID_CHAR_MONSTER=ID_CHAR_NONE+ NB_STATE_CHAR_NONE;
        //static const int ID_CHAR_MONSTER=ID_CHAR_MONSTER+NB_STATE_CHAR_MONSTER; pour l'exemple

        static  int GET_ID_CHAR(int id);

        static string intToStr(int n);
        static int strToInt(string str);
        static float strToFloat(string str);
        static bool strToBool(string str);
        static bool inScreen(int i,int j){return (i>=0 && i<NB_TILE_WIDTH && j>=0 && j<NB_TILE_HEIGHT);}


         template<typename T> static T strTo(string str);
        static int sizeWithoutSpace(string str);

    protected:


    private:
};

#endif // GLOBAL_H
