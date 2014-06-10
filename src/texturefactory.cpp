#include "texturefactory.h"

vector<Texture> TextureFactory::m_textures;


Texture* TextureFactory::get(int i)
{

    if(i>=0&&i<m_textures.size());return &m_textures[i];
    cerr << " Tentative d'acc�der � un tile impossible (TextureFactory::getTile())"<<endl;
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


void TextureFactory::load(string path)
{
    ///tileSets
    loadPng(path+"NONE.png",1,1);
    loadPng(path+"hight_grass.png",1,4);
    loadPng(path+"grass-transition-ground.png",1,4);
    loadPng(path+"desert.png",1,7);
    loadPng(path+"snow.png",1,5);
    ///

    ///Characters
    loadPng(path+"player.png",2,3);
    ///

    cout<<"Textures loaded !"<<endl;
}

void TextureFactory::load()
{
    TextureFactory::load("data/img/");
}

























TextureFactory::TextureFactory()
{
    //ctor
}

TextureFactory::~TextureFactory()
{
    //dtor
}
