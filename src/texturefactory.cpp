#include "texturefactory.h"

vector<Texture> TextureFactory::m_tiles;
vector<vector<Texture> > TextureFactory::m_characters;

Texture* TextureFactory::getTile(int i)
{

    if(i>=0);return &m_tiles[i];
    cerr << " Tentative d'acc�der � un tile n�gatif (TextureFactory::getTile())"<<endl;
    return 0;
}

Texture* TextureFactory::getChar(int IDchar, int i)
/**
    Cette m�thode permet l'acc�s aux textures de chaque char. Le vector de vector est n�cessaire dans la mesure
    o� il existe plusieurs characters aux textures diff�rentes (NPC,pet,perso);
**/
{
    if(i>=0);return &m_characters[IDchar-Global::ID_FIRST_CHAR][i]; ///C'est l� que j'ai eu un soucis d'acc�s aux vector puisque pas le m�me.
    cerr << " Tentative d'acc�der � un character n�gatif (TextureFactory::getChar())"<<endl;
    return 0;
}


vector<Texture> TextureFactory::loadPNG(string nameTXT, int nbTileHauteur, int nbTileLargeur, int tileWidth, int tileHeight)
    /**En gros, cette m�thode all�che le code. Elle permet de charger une image (tileset etc.) avec des crit�res modifiables.**/
    {
        vector<Texture> tiles;
        for(int i=0;i<nbTileLargeur;i++)
        {
            for(int j=0;j<nbTileHauteur;j++)
            {
                Texture texture;
                if(!texture.loadFromFile(nameTXT.c_str(),IntRect(i*tileWidth,j*tileHeight,tileWidth,tileHeight)))
                {
                    cerr<<"Erreur chargement des textures des tiles ! [TextureFactory::loadPNG()]"<<endl;
                }
                tiles.push_back(texture);
            }
        }
        return tiles;
    }



void TextureFactory::load()
{
    ///tile
    m_tiles=loadPNG("data/img/tileset.png",1,4);
    ///

    ///Characters
    m_characters.push_back(loadPNG("data/img/player.png",2,3));
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
