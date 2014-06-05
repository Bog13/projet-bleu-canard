#ifndef CHARACTERGRAPHIC_H
#define CHARACTERGRAPHIC_H


#include "tilegraphic.h"

class CharacterGraphic: public TileGraphic
{
    public:

        CharacterGraphic(Animation a, ConvexShape cs);
        virtual ~CharacterGraphic();

    protected:
    private:
        //Animation m_animation;

};

#endif // CHARACTERGRAPHIC_H
