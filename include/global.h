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



        /**J'ai eu des soucis d'acc�s aux vectors, j'ai trouv� un moyen simple de parer ca:
            Ca consiste en gros a donner � ID_FIRST_CHAR la valeur juste apr�s la derni�re TILE
            et d'en d�duire r�cursivement l'ID des character.
            Cela permet de n'avoir � changer qu'un nombre pour d�caler tous les char.

            Rq: Je suis tent� par l'id�e de le faire �galement chez les TILE.

        **/

        static const int ID_FIRST_CHAR=4;
        static const int ID_JOSH=ID_FIRST_CHAR+0;
        static const int ID_AUTRE_PERSO=ID_FIRST_CHAR+1;


        static string intToStr(int n);
        static int strToInt(string str);
        static float strToFloat(string str);
        static bool strToBool(string str);

         template<typename T> static T strTo(string str);
        static int sizeWithoutSpace(string str);

    protected:


    private:
};

#endif // GLOBAL_H
