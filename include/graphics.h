#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "tilefactory.h"
#include "entitygraphic.h"
#include "areagraphic.h"

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
        void drawVisibleArea(AreaGraphic *ag);
        void drawObjects(AreaGraphic *ag);
        void drawCharacter(EntityGraphic t);
        void setVisibleEntities(AreaGraphic *ag);
        void setVisibleObjects(AreaGraphic *ag);
        bool inView(AreaGraphic *ag, float i,float j);
        void update();

        ///Controle de la view
        void enableView     (bool b);
        void setViewPosition(float x=0, float y=0);
        void setView(View const &view);
        View* getView(){return& m_mainView;}

        ///Mouvement de bases pouvant servir plus tard, éventuellement...
        void moveView       (float right, float left, float up, float down);
        void moveViewUp     (float d);
        void moveViewDown   (float d);
        void moveViewRight  (float d);
        void moveViewLeft   (float d);
        void setViewSize(int w,int h);

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
