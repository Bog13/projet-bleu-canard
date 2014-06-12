#include "texturefactory.h"

vector<vector<Texture> > TextureFactory::m_textures;


Texture* TextureFactory::get(unsigned int i, unsigned int j)
{

    if(i>=0 && i<Global::NB_TOTAL_TILE)
    {
        if( j>=0 && j<Global::NB_FRAME_ID[i] )
        {
            return &m_textures[i][j];
        }
        else cerr << " Tentative d'accéder à un tile impossible (TextureFactory::get("<<i<<","<<j<<"))"<<endl;
    }
    else cerr << " Tentative d'accéder à un tile impossible (TextureFactory::get("<<i<<","<<j<<"))"<<endl;
    return 0;
}




bool TextureFactory::loadPng(string nameTXT, int nbTileHauteur, int nbTileLargeur, int tileWidth, int tileHeight)
    /**En gros, cette méthode allège le code. Elle permet de charger une image (tileset etc.) avec des critères modifiables.**/
    {
        vector<Texture> temp;

        for(int i=0;i<nbTileHauteur;i++)//pour chaque ligne
        {
            for(int j=0;j<nbTileLargeur;j++)//on récupère les éléments
            {
                Texture texture;
                if(!texture.loadFromFile(nameTXT.c_str(),IntRect(j*tileWidth,i*tileHeight,tileWidth,tileHeight)))
                {
                    cerr<<"Erreur chargement des textures des tiles. [TextureFactory::loadPng(" <<nameTXT<<")]"<<endl;
                    return false;
                }
                temp.push_back(texture);
            }
        }
    m_textures.push_back(temp);
    return true;
    }

bool TextureFactory::loadPngRect(string nameTXT, int x,int y, int tileWidth, int tileHeight)
{
        vector<Texture> temp;

        Texture texture;
        if(!texture.loadFromFile(nameTXT.c_str(),IntRect(x*tileWidth,y*tileHeight,tileWidth,tileHeight)))
        {
            cerr<<"Erreur chargement des textures des tiles. [TextureFactory::loadPng(" <<nameTXT<<")]"<<endl;
            return false;
        }
        temp.push_back(texture);


    m_textures.push_back(temp);
    return true;
}


bool TextureFactory::load(string path)
{

    if(
            ///tileSets
          loadPng(path+"NONE.png",1,1)
       && loadPng(path+"hight_grass.png",1,Global::NB_FRAME_ID[HIGHT_GRASS])
       && loadPngRect(path+"grass-transition-ground.png",0,0)
       && loadPngRect(path+"grass-transition-ground.png",1,0)
       && loadPngRect(path+"grass-transition-ground.png",2,0)
       && loadPngRect(path+"grass-transition-ground.png",3,0)
       && loadPng(path+"desert.png",1,Global::NB_FRAME_ID[DESERT])
       && loadPng(path+"snow.png",1,Global::NB_FRAME_ID[SNOW])
            ///Characters
       &&loadPng(path+"player.png",2,3)){cout<<"Textures loaded !"<<endl;}
        else{cerr<<"Problem appeared during textures loading." << endl;}



    ///


    ///


}

bool TextureFactory::load()
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
