#include "objectfactory.h"

vector<Object> ObjectFactory::m_objects;

ObjectFactory::ObjectFactory()
{
    //ctor
}

Object* ObjectFactory::create(Area* a,int id,float x,float y,float w,float h,bool solid)
{


    if(id==CHAR_NONE)
        {
            NPC* n=new NPC(new IddleBehavior, a, id,x,y,w,h,solid);
//            n->setParameter(SHOWLOVE);
            return n;
        }
    else
        {
            Object* obj=new Object(a,id,x,y,w,h,solid);

            if(id==PINE_TREE)
            {
                obj->setHitbox(m_objects[PINE_TREE].getHitbox());
                ///DEBUG
//                obj->setParameter(SHOWHELLO);
            }
            else
            {
                ///Autre obj
            }

            return obj;
        }



}
Object ObjectFactory::get(int id)
{
    if(id>=0 && id<(int)(m_objects.size()))
    {

        //if (id==PINE_TREE) {m_objects[id]<<(cout);}
        return m_objects[id];
    }else {cerr << " Tentative d'accèder à un ID incorrect (ObjectFactory::get(" << id << "). "  << endl; return 0;}
}

void ObjectFactory::load()
{
    for(int i(0);i<Global::NB_TOTAL_ID;i++)
    {
        Object o(0,i,0,0,Global::TILE_WIDTH,Global::TILE_HEIGHT,false);
        o.setHitbox(0,0,o.getWidth(),o.getHeight());


        switch(i)
        {
        case PINE_TREE:
            {
                o.setWidth(128); o.setHeight(128);
                o.setHitbox((1/3.)*o.getWidth(),(3/4.)*o.getHeight(),(1/3.)*o.getWidth(),(1/4.)*o.getHeight());
                o.setSolid(true);
            }break;
        default:break;
        }

        m_objects.push_back(o);
    }
}

ObjectFactory::~ObjectFactory()
{

}
