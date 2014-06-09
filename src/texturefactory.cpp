#include "texturefactory.h"

vector<Texture> TextureFactory::m_textures;


Texture* TextureFactory::get(int i)
{

    if(i>=0);return &m_textures[i];
    cerr << " Tentative d'acc�der � un tile n�gatif (TextureFactory::getTile())"<<endl;
    return 0;
}




void TextureFactory::loadPng(string nameTXT, int nbTileHauteur, int nbTileLargeur, int tileWidth, int tileHeight)
    /**En gros, cette m�thode all�ge le code. Elle permet de charger une image (tileset etc.) avec des crit�res modifiables.**/
    {

        for(int i=0;i<nbTileHauteur;i++)//pour chaque ligne
        {
            for(int j=0;j<nbTileLargeur;j++)//on r�cup�re les �l�ments
            {
                Texture texture;
                if(!texture.loadFromFile(nameTXT.c_str(),IntRect(j*tileWidth,i*tileHeight,tileWidth,tileHeight)))
                {
                    cerr<<"Erreur chargement des textures des tiles ! [TextureFactory::loadPng()]"<<endl;
                }
                m_textures.push_back(texture);
            }
        }

    }



void TextureFactory::load()
{
    ///tile
    loadPng("data/img/tileset.png",1,4);
    ///

    ///Characters
    loadPng("data/img/player.png",2,3);
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
