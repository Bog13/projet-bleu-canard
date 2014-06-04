#ifndef ANIMATIONFACTORY_H
#define ANIMATIONFACTORY_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "graphics.h"
#include "animation.h"
#include "texturefactory.h"
#include "global.h"
#include "tilefactory.h"
using namespace std;
using namespace sf;
extern int TYPE_GRASS;

class AnimationFactory
{
    public:
        AnimationFactory();
        virtual ~AnimationFactory();

        static void load();
        static Animation get(int i);
    protected:
        static vector<Animation> m_vector;
    private:
};

#endif // ANIMATIONFACTORY_H
