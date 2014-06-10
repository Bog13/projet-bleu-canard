#ifndef EDITOR_H
#define EDITOR_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include"../include/global.h"
#include "../include/graphics.h"



using namespace std;
using namespace sf;


class Editor
{
    public:
        Editor(RenderWindow* window);

        void Modify(Vector2i pos, int id);
        const void Draw();
        void Update();
        virtual ~Editor();
    protected:
        RenderWindow* m_window;
        Area* m_currentArea;
        AreaGraphic* m_ag;
        Graphics* m_graphics;
    private:
};

#endif // EDITOR_H
