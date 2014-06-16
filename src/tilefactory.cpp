#include "tilefactory.h"

vector<EntityGraphic> TileFactory::m_vector;



void TileFactory::loadTile(int clue)
{
    int width=AnimationFactory::get(clue).getFrame(0)->getSize().x, ///largeur de la première frame, postulat de la constance.
        height=AnimationFactory::get(clue).getFrame(0)->getSize().y;///hauteur de la première frame

    ConvexShape c=Graphics::createSquare(0,0,width,height); ///Changement: S'adapte maintenant à la texture qu'elle reçoit.
    Animation a(AnimationFactory::get(clue));
    EntityGraphic tg(a,c);
    m_vector.push_back(tg);
}

void TileFactory::load()
{

    ConvexShape c=Graphics::createSquare(0,0,Global::TILE_WIDTH,Global::TILE_HEIGHT);

    ///12 Tiles, doit correspondre avec Global::NB_TOTAL_TILE
    for(int i(Global::ID[TILE_NONE]);i<Global::NB_TOTAL_TILE;i++){loadTile(i);}
    cout<<"Tiles loaded !"<<endl;
}

EntityGraphic TileFactory::get(int i)
{
    if(i>=0 && i< m_vector.size())
    {
        return m_vector[i];
    }
    else
    {
        cerr<<"ERREUR TILEFACTORY "<<i<<endl;
        return m_vector[Global::ID[TILE_NONE]];
    }
}
















TileFactory::TileFactory()
{
    //ctor
}
TileFactory::~TileFactory()
{
    //dtor
}
