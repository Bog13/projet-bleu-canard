#ifndef TEXTUREFACTORY_H
#define TEXTUREFACTORY_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "graphics.h"
#include "animation.h"
#include "entitygraphic.h"
#include "global.h"
using namespace std;
using namespace sf;

class TextureFactory
{
    public:
        TextureFactory();
        virtual ~TextureFactory();

        static bool load();
        static bool load(string path);
        static bool loadPng(string nameTXT, int nbTileHauteur, int nbTileLargeur, int tileWidth=Global::TILE_WIDTH, int tileHeight=Global::TILE_HEIGHT);
        static Texture* get(unsigned int i, unsigned int j);

    protected:
        static vector<vector<Texture> >m_textures;
    private:
};

#endif // TEXTUREFACTORY_H
