#include "tilefactory.h"

vector<EntityGraphic> TileFactory::m_vector;


void TileFactory::load()
{

    ConvexShape c=Graphics::createSquare(0,0,Global::TILE_WIDTH,Global::TILE_HEIGHT);

    {Animation a(AnimationFactory::get(Global::ID_NONE));EntityGraphic tg(a,c);m_vector.push_back(tg);}
    {Animation a(AnimationFactory::get(Global::ID_GROUND));EntityGraphic tg(a,c);m_vector.push_back(tg);}
    {Animation a(AnimationFactory::get(Global::ID_GRASS));EntityGraphic tg(a,c);m_vector.push_back(tg);}
    {Animation a(AnimationFactory::get(Global::ID_ROCK));EntityGraphic tg(a,c);m_vector.push_back(tg);}





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
        return m_vector[Global::ID_NONE];
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
