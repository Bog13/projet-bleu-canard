#ifndef TEXTUREFACTORY_H
#define TEXTUREFACTORY_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "graphics.h"
#include "animation.h"
#include "tilegraphic.h"
#include "global.h"
using namespace std;
using namespace sf;

class TextureFactory
{
    public:
        TextureFactory();
        virtual ~TextureFactory();

        static void load();
        static Texture* get(int i);

    protected:
        static vector<Texture> m_vector;
    private:
};

#endif // TEXTUREFACTORY_H
