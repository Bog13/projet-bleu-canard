#ifndef CHARACTERGRAPHIC_H
#define CHARACTERGRAPHIC_H


#include "entitygraphic.h"

class CharacterGraphic: public EntityGraphic
{
    public:

        CharacterGraphic(Animation a, ConvexShape cs);
        void update();
        virtual ~CharacterGraphic();

    protected:
    private:
        //Animation m_animation;

};

#endif // CHARACTERGRAPHIC_H
