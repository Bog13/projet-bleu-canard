#include "tilefactory.h"

vector<EntityGraphic> TileFactory::m_vector;


void TileFactory::load()
/**
    Je préconise une méthode qui allègerait ce code ! :p Sinon, c'est juste une initialisation banale.
**/
{

    ConvexShape c=Graphics::createSquare(0,0,Global::TILE_WIDTH,Global::TILE_HEIGHT);

    ///12 Tiles, doit correspondre avec Global::NB_TOTAL_TILE
    {Animation a(AnimationFactory::get(Global::ID_NONE));EntityGraphic tg(a,c);m_vector.push_back(tg);}
    {Animation a(AnimationFactory::get(Global::ID_HIGHT_GRASS));EntityGraphic tg(a,c);m_vector.push_back(tg);}
    {Animation a(AnimationFactory::get(Global::ID_HIGHT_GRASS_tGROUND_UL));EntityGraphic tg(a,c);m_vector.push_back(tg);}
    {Animation a(AnimationFactory::get(Global::ID_HIGHT_GRASS_tGROUND_UR));EntityGraphic tg(a,c);m_vector.push_back(tg);}
    {Animation a(AnimationFactory::get(Global::ID_HIGHT_GRASS_tGROUND_DL));EntityGraphic tg(a,c);m_vector.push_back(tg);}
    {Animation a(AnimationFactory::get(Global::ID_HIGHT_GRASS_tGROUND_DR));EntityGraphic tg(a,c);m_vector.push_back(tg);}
    {Animation a(AnimationFactory::get(Global::ID_DESERT));EntityGraphic tg(a,c);m_vector.push_back(tg);}
    {Animation a(AnimationFactory::get(Global::ID_SNOW_1));EntityGraphic tg(a,c);m_vector.push_back(tg);}
    {Animation a(AnimationFactory::get(Global::ID_SNOW_2));EntityGraphic tg(a,c);m_vector.push_back(tg);}
    {Animation a(AnimationFactory::get(Global::ID_SNOW_3));EntityGraphic tg(a,c);m_vector.push_back(tg);}
    {Animation a(AnimationFactory::get(Global::ID_SNOW_4));EntityGraphic tg(a,c);m_vector.push_back(tg);}
    {Animation a(AnimationFactory::get(Global::ID_SNOW_5));EntityGraphic tg(a,c);m_vector.push_back(tg);}

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
