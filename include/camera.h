#ifndef CAMERA_H
#define CAMERA_H
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



class Camera
{
    public:
        Camera(AreaGraphic *ag,Positionable* target);

        void setViewSize(int w,int h);

        float getX(){return m_viewX;}
        float getY(){return m_viewY;}
        int getW(){return m_viewWidth;}
        int getH(){return m_viewHeight;}
        int getHH(){return (m_viewHeight>>1);}
        int getHW(){return (m_viewWidth>>1);}

        void moveView       (bool right, bool left, bool up, bool down);
        void moveViewUp     (float d);
        void moveViewDown   (float d);
        void moveViewRight  (float d);
        void moveViewLeft   (float d);

        void enableView     (bool b){m_viewActivated=b;};
        void setViewPosition(float x=0, float y=0);
        void setView(View const &view);
        View* getView(){return& m_mainView;}

        void setTarget(Positionable* p);

        bool isMoving(){return m_isViewMoving;}
        bool wasMoving(){return (getLastMove()<=VIEW_REFRESH_DELAY);}
        int getLastMove(){return m_lastViewMoving;}
        bool mustRefresh(){return (time(NULL)%m_autoRefresh==0);}
        bool isActivated(){return m_viewActivated;}

        bool inView(float i,float j);
        bool inView(Object* obj);
        vector<Object*>* getObjectInView();

        void verifyViewInArea();

        void updateViewMoving();
        void updateAreaTilesInView();
        void update(RenderWindow* window);

        virtual ~Camera();
    protected:

        View m_mainView;
        AreaGraphic *m_ag;
        Positionable* m_target;

        int m_viewWidth;
        int m_viewHeight;
        float m_viewX;
        float m_viewY;
        int m_viewSpeed;

        bool  m_viewActivated;
        bool m_isViewMoving;
        int m_autoRefresh;
        int m_lastViewMoving;
        const int VIEW_REFRESH_DELAY;
    private:
};

#endif // CAMERA_H
