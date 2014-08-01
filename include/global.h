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
{
    RIGHT=0,
    DOWN=1,
    LEFT=2,
    UP=3
};

enum
///Création de texture 1: AJOUTER LE NOM ICI (2 plus bas)
{
    //TILE
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
    //Object
    PINE_TREE=10,
    //CHAR
    CHAR_NONE=11
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
        
        static const string PATH_IMG;
        static const string PATH_LVL;
        //Tile
        static const int TILE_WIDTH=32;
        static const int TILE_HEIGHT=32;

        static const int NB_TILE_WIDTH=WINDOW_WIDTH/TILE_WIDTH;
        static const int NB_TILE_HEIGHT=WINDOW_HEIGHT/TILE_HEIGHT;






    ///Création de texture 2:INCREMENTER LE TOTAL (3 dans le cpp)
        static const int NB_TOTAL_TILE=10;
        static const int NB_TOTAL_OBJECT=1;
        static const int NB_TOTAL_CHAR=1;
        static const int NB_TOTAL_ID=NB_TOTAL_TILE+NB_TOTAL_OBJECT+NB_TOTAL_CHAR;

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
        static string loadingString(int now,int max);
        static void clearConsole();
        static int FPS;

        static inline int toTileWidth(float nb) {return nb/TILE_WIDTH;}
        static inline int toTileHeight(float nb) {return nb/TILE_HEIGHT;}

        template<typename T> static T strTo(string str);
        /// La méthode suivante s'utilise comme ceci:
        /**
            Positionable* p=Global::convertInto(laChoseATester,p)
                et se lit
            "Le positionable p devient la conversion de laChoseATester"
        **/
        template<typename Type1, typename Type2> static Type2 convertInto(Type1 target) {return dynamic_cast<Type2>(target);} ///Tant attendu et fonctionne à merveille !

        /// La méthode suivante s'utilise comme ceci: !!! (pas encore testée) !!!
        /**
            Positionable* p;
            Global::directConvertInto(p,laChoseDontSinspirer)
                et se lit
            "Transforme p en laChoseDontSinspirer"
        **/
        template<typename Type1, typename Type2> static void directConvertInto(Type1 target,Type2 newType) {target=dynamic_cast<Type2>(target);}

        static int sizeWithoutSpace(string str);



    protected:


    private:
};

#endif // GLOBAL_H
