#ifndef GLOBAL_H
#define GLOBAL_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>

using namespace std;
using namespace sf;

enum
{
    TILE_NONE=0,
    HIGHT_GRASS=1,
    HIGHT_GRASS_tGROUND_1=2,
    HIGHT_GRASS_tGROUND_2=3,
    HIGHT_GRASS_tGROUND_3=4,
    HIGHT_GRASS_tGROUND_4=5,
    DESERT=6,
    SNOW=7,
    FLOOR_WOOD=8,
    CHAR_NONE=9
};

class Global
{
    public:
        Global();
        virtual ~Global();

         /**
        Légende:
            XXX_tYYY: Image X en transition avec Y
            U=Up    L=LEFT
            D=Down  R=RIGHT

            Exemples:
            Tile simple indice n:            ID_XXX_n
            Transition de X a Y:    ID Type: ID_XXX_tYYY_UL
        **/

        //Window
        static const int WINDOW_WIDTH=640;
        static const int WINDOW_HEIGHT=480;
        //Tile
        static const int TILE_WIDTH=32;
        static const int TILE_HEIGHT=32;

        static const int NB_TILE_WIDTH=WINDOW_WIDTH/TILE_WIDTH;
        static const int NB_TILE_HEIGHT=WINDOW_HEIGHT/TILE_HEIGHT;







        static const int NB_TOTAL_TILE=10;
        static const int NB_TOTAL_ID=NB_TOTAL_TILE;

        static const int ID[NB_TOTAL_ID];
        static const int NB_FRAME_ID[NB_TOTAL_ID];


        static string intToStr(int n);
        static int strToInt(string str);
        static float strToFloat(string str);
        static bool strToBool(string str);
        static bool inScreen(int i,int j){return (i>=0 && i<NB_TILE_WIDTH && j>=0 && j<NB_TILE_HEIGHT);}
        static bool isInTheRect(float xTarget,float yTarget,float x,float y,float w,float h);


         template<typename T> static T strTo(string str);
        static int sizeWithoutSpace(string str);

    protected:


    private:
};

#endif // GLOBAL_H
