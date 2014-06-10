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

        /**
            Peut-être à renommer, mais ici ça défini le nombre d'image dans un tileSet en même temps ( pour les marquées) .
        **/
        static const int NB_STATE_HIGHT_GRASS=4;
        static const int NB_STATE_HIGHT_GRASS_tGROUND=4; //
        static const int NB_STATE_DESERT=7;
        static const int NB_STATE_SNOW=5;   //
        static const int NB_STATE_CHAR_NONE=6;


        static const int NB_TOTAL_TILE=12; /// /!\ A Incrémenter à chaque ajout de tile


        static const int ID_NONE=0;

        static const int ID_HIGHT_GRASS=ID_NONE+1;
            //Transition Ground
            static const int ID_HIGHT_GRASS_tGROUND_UL=ID_NONE+2;
            static const int ID_HIGHT_GRASS_tGROUND_UR=ID_NONE+3;
            static const int ID_HIGHT_GRASS_tGROUND_DL=ID_NONE+4;
            static const int ID_HIGHT_GRASS_tGROUND_DR=ID_NONE+5;

        static const int ID_DESERT=ID_NONE+6;


        static const int ID_SNOW_1=ID_NONE+7;
        static const int ID_SNOW_2=ID_NONE+8;
        static const int ID_SNOW_3=ID_NONE+9;
        static const int ID_SNOW_4=ID_NONE+10;
        static const int ID_SNOW_5=ID_NONE+11;

        /**Impoooortant !
        Permet l'accès à la bonne texture et donc la série qui va avec. Voir textureFactory
        **/
        static const int ID_TEXTURE_NONE=0;
        static const int ID_TEXTURE_HIGHT_GRASS=1;
        static const int ID_TEXTURE_HIGHT_GRASS_tGROUND=5;
        static const int ID_TEXTURE_DESERT=9;
        static const int ID_TEXTURE_SNOW=16;


        /* USELESS
        static const int ID_ROCK=ID_NONE+3;
        */

        static const int ID_CHAR_NONE=21;
        static const int ID_CHAR_MONSTER=ID_CHAR_NONE+ NB_STATE_CHAR_NONE;
        //static const int ID_CHAR_MONSTER=ID_CHAR_MONSTER+NB_STATE_CHAR_MONSTER; pour l'exemple (pas compris)

        static  int GET_ID_CHAR(int id);


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
