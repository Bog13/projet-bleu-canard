#ifndef TEXTUREFACTORY_H
#define TEXTUREFACTORY_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "graphics.h"
#include "animation.h"
#include "tilegraphic.h"
#include "global.h"
using namespace std;
using namespace sf;

class TextureFactory
{
    public:
        TextureFactory();
        virtual ~TextureFactory();

        static void load();
        static vector<Texture>loadPNG(string nameTXT, int nbTileHauteur, int nbTileLargeur, int tileWidth=Global::TILE_WIDTH, int tileHeight=Global::TILE_HEIGHT);
        static Texture* getTile(int i);
        static Texture* getChar(int IDchar, int i);

    protected:
        static vector<Texture> m_tiles;
        static vector<vector<Texture> > m_characters; ///Nécessité de plusieurs textures par character.
    private:
};

#endif // TEXTUREFACTORY_H
