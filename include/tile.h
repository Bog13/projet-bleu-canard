#ifndef TILE_H
#define TILE_H


/*
Classe essentielle de l'affichage consistant en la case �l�mentaire de chaque zone du monde. Sert notamment � l'affichage.
*/


class Tile
{
    public:
        Tile();
        Tile(int id,int x,int y);
        Tile(int x,int y);

        float getPositionX() {return m_posX;}
        float getPositionY() {return m_posY;}
        virtual ~Tile();
    protected:
        int m_id;
        int m_posX;
        int m_posY;
    private:
};

#endif // TILE_H
