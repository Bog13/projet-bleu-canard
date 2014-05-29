#ifndef GLOBAL_H
#define GLOBAL_H
/*
    Contient toutes les constantes
*/

class Global
{
    public:
        Global();
        virtual ~Global();

        static const int WINDOW_WIDTH=640;
        static const int WINDOW_HEIGHT=480;

        static const int TILE_WIDTH=32;
        static const int TILE_HEIGHT=32;

        static const int VIEW_WIDTH= 10*TILE_WIDTH;
        static const int VIEW_HEIGHT= 5*TILE_HEIGHT;



        static const int NB_TILE_WIDTH=WINDOW_WIDTH/TILE_WIDTH;
        static const int NB_TILE_HEIGHT=WINDOW_HEIGHT/TILE_HEIGHT;



    protected:
    private:
};

#endif // GLOBAL_H
