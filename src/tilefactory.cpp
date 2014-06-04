#include "tilefactory.h"

vector<TileGraphic> TileFactory::m_vector;


void TileFactory::load()
{
    ///ground
    Animation a(AnimationFactory::get(0));
    ConvexShape c=Graphics::createSquare(0,0,Global::TILE_WIDTH,Global::TILE_HEIGHT);

    TileGraphic tg(a,c);
    m_vector.push_back(tg);

    cout<<"Tiles loaded !"<<endl;


}

TileGraphic TileFactory::get(int i)
{
    if(i>=0 && i< m_vector.size())
    {
        return m_vector[i];
    }
    else cerr<<"ERREUR TILEFACTORY "<<i<<endl;
}
















TileFactory::TileFactory()
{
    //ctor
}
TileFactory::~TileFactory()
{
    //dtor
}
