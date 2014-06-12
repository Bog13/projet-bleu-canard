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

        static void load();
        static void load(string path);
        static void loadPng(string nameTXT, int nbTileHauteur, int nbTileLargeur, int tileWidth=Global::TILE_WIDTH, int tileHeight=Global::TILE_HEIGHT);
        static Texture* get(int i, int j);

    protected:
        static vector<vector<Texture> >m_textures;
    private:
};

#endif // TEXTUREFACTORY_H
