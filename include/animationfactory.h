#ifndef ANIMATIONFACTORY_H
#define ANIMATIONFACTORY_H
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <vector>
/*
#include "graphics.h"
#include "animation.h"
#include "texturefactory.h"
#include "global.h"
#include "tilefactory.h"
*/
using namespace std;
using namespace sf;

class Animation;

class AnimationFactory
{
    public:
        AnimationFactory();
        virtual ~AnimationFactory();

        static void load();
        static bool loadFileAnimation(Animation *a,string fileName);
        static void loadAnimation(int id);
        static Animation get(unsigned int i);
    protected:
        static vector<Animation> m_vector;
    private:
};

#endif // ANIMATIONFACTORY_H
