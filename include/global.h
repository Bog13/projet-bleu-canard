#ifndef GLOBAL_H
#define GLOBAL_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace sf;

enum
///Cr�ation de texture 1: AJOUTER LE NOM ICI (2 plus bas)
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
    FLOOR_PAVEMENT=9,
    PINE_TREE=10,
    CHAR_NONE=11
};

class Global
{
    public:
        Global();
        virtual ~Global();

         /**
        L�gende:
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






    ///Cr�ation de texture 2:INCREMENTER LE TOTAL (3 dans le cpp)
        static const int NB_TOTAL_TILE=12;
        static const int NB_TOTAL_ID=NB_TOTAL_TILE;

        static const int ID[NB_TOTAL_ID];
        static const int NB_FRAME_ID[NB_TOTAL_ID];


        static string intToStr(int n);
        static int strToInt(string str);
        static float strToFloat(string str);
        static bool strToBool(string str);
        static bool inScreen(int i,int j){return (i>=0 && i<NB_TILE_WIDTH && j>=0 && j<NB_TILE_HEIGHT);}
        static bool isInTheRect(float xTarget,float yTarget,float x,float y,float w,float h);
        static bool inCollision(float Ax,float Ay, float Aw, float Ah,float Bx,float By, float Bw, float Bh);
        static int random(int a,int b){return rand()%(b-a)+a;}

         template<typename T> static T strTo(string str);
        static int sizeWithoutSpace(string str);

    protected:


    private:
};

#endif // GLOBAL_H
