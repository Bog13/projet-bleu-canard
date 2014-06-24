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
using namespace std;
using namespace sf;

class AreaGraphic;
class Graphics
{
    public:
        Graphics(RenderWindow* window,AreaGraphic *ag);
        static ConvexShape createSquare(int x,int y,int w,int h);
        void drawEntity(EntityGraphic *t);

        void drawVisibleArea();
        void drawObjects();
        void drawCharacter(EntityGraphic t);
        void setVisibleEntities();
        void setVisibleObjects();
        bool inView(float i,float j);
        bool inView(Object* obj);
        bool collideWithObject(int i,int j);
        void updateViewMoving();
        vector<Object*>* getObjectInView();
        void update();
        void verifyViewInArea();

        ///Controle de la view
        void enableView     (bool b);
        void setViewPosition(float x=0, float y=0);
        void setView(View const &view);
        View* getView(){return& m_mainView;}

        ///Mouvement de bases pouvant servir plus tard, éventuellement...
        void moveView       (bool right, bool left, bool up, bool down);
        void moveViewUp     (float d);
        void moveViewDown   (float d);
        void moveViewRight  (float d);
        void moveViewLeft   (float d);
        void setViewSize(int w,int h);

        virtual ~Graphics();
    protected:
        RenderWindow* m_window;
        AreaGraphic *m_ag;
        View m_mainView;
        float m_viewWidth;
        float m_viewHeight;
        float m_viewX;
        float m_viewY;
        float m_viewSpeed;
        bool  m_viewActivated;
        bool m_isViewMoving;
        int m_autoRefresh;
        int m_lastViewMoving;
        const int VIEW_REFRESH_DELAY;

    private:
};

#endif // GRAPHICS_H
