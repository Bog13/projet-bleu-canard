#ifndef TILE_H
#define TILE_H


/*
Classe essentielle de l'affichage consistant en la case �l�mentaire de chaque zone du monde. Sert notamment � l'affichage.
*/


class Tile
{
    public:
        Tile();
        virtual ~Tile();
    protected:
        int m_id;
        int m_posX;
        int m_posY;
    private:
};

#endif // TILE_H
