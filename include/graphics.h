#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "tilefactory.h"
#include "entitygraphic.h"
#include "areagraphic.h"
#include "character.h"
using namespace std;
using namespace sf;

class AreaGraphic;
class Graphics
{
    public:
        Graphics(RenderWindow* window);
        static ConvexShape createSquare(int x,int y,int w,int h);
        void drawEntity(EntityGraphic *t);
        void drawArea(AreaGraphic *ag);
        void drawCharacter(EntityGraphic t);
        void update();

        ///Controle de la view
        void enableView     (bool b);
        void setViewPosition(float x=0, float y=0);

        ///Mouvement de bases pouvant servir plus tard, éventuellement...
        void moveView       (float right, float left, float up, float down);
        void moveViewUp     (float d);
        void moveViewDown   (float d);
        void moveViewRight  (float d);
        void moveViewLeft   (float d);

        virtual ~Graphics();
    protected:
        RenderWindow* m_window;

        View m_mainView;
        float m_viewWidth;
        float m_viewHeight;
        float m_viewPositionX;
        float m_viewPositionY;
        bool  m_viewActivated;
    private:
};

#endif // GRAPHICS_H
