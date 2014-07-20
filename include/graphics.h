#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "tilefactory.h"
#include "entitygraphic.h"
#include "areagraphic.h"
#include "object.h"
#include "camera.h"

using namespace std;
using namespace sf;

class Camera;
class AreaGraphic;
class Graphics
{
    public:
        Graphics(RenderWindow* window,AreaGraphic *ag);
        static ConvexShape createSquare(int x,int y,int w,int h);
        void drawEntity(EntityGraphic *t);

        void drawVisibleArea();
        void drawVisibleAreaUnoptimized();
        void drawObjects();
        void drawCharacter(EntityGraphic t);

        void setVisibleObjects();
        bool collideWithObject(int i,int j);

        Camera* getCamera(){return m_cam;}
        void setCamera(Camera* cam) {m_cam=cam;}
        void enableCamera(bool b);


        void updateAreaTilesInCamera();
        void update();


        void setAreaGraphic(AreaGraphic* ag) {if(ag!=0)m_ag=ag;}

        virtual ~Graphics();
    protected:
        RenderWindow* m_window;
        AreaGraphic *m_ag;
        Camera *m_cam;


    private:
};

#endif // GRAPHICS_H
