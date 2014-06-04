#include "texturefactory.h"

vector<Texture> TextureFactory::m_vector;

Texture* TextureFactory::get(int i)
{
    return &m_vector[i];
}

void TextureFactory::load()
{
    ///tile
    int nbTileHauteur=1;
    int nbTileLargeur=4;

    for(int i=0;i<nbTileLargeur;i++)
    {
        for(int j=0;j<nbTileHauteur;j++)
        {
            Texture texture;
            if(!texture.loadFromFile("data/img/tileset.png",IntRect(i*Global::TILE_WIDTH,j*Global::TILE_HEIGHT,Global::TILE_WIDTH,Global::TILE_HEIGHT)))
            {
                cerr<<"Erreur chargement des textures !"<<endl;
            }
            m_vector.push_back(texture);
        }
    }



    ///

    cout<<"Textures loaded !"<<endl;

}

























TextureFactory::TextureFactory()
{
    //ctor
}

TextureFactory::~TextureFactory()
{
    //dtor
}
