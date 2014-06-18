#include "core.h"

enum
{
    RIGHT=0,
    DOWN=1,
    LEFT=2,
    UP=3
};

Core::Core(RenderWindow* window)
{

    m_window=window;
    m_graphic=new Graphics(m_window);
    m_graphic->setViewSize(Global::WINDOW_WIDTH,Global::WINDOW_HEIGHT);
    m_controller=new KeyboardController();

    /// test area
    m_a=new Area(20,20);
    //AreaFactory::loadArea(m_a,"areaTest.txt");

    Object* pine1=new Object(m_a,PINE_TREE,100,100,128,128,true);
    pine1->setHitbox((1/3.)*pine1->getWidth(),(3/4.)*pine1->getHeight(),(1/3.)*pine1->getWidth(),(1/4.)*pine1->getHeight());

    Object* o;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            o=new Object(m_a,PINE_TREE,100,100,128,128,true);
            o->setHitbox(pine1->getHitbox());
            o->setPosition(128*i+5,128*j+5);
            m_a->addObject(o);
        }

    }

    m_a->addObject(new Player(m_a,m_controller,CHAR_NONE,10,300,32,64,true));

    IddleBehavior* ib=new IddleBehavior(0);
    Object* test= new NPC(ib,m_a,CHAR_NONE,80,400,32,64,true);
    ib->setObject(test);
    m_a->addObject(test);





    m_ag=new AreaGraphic(m_a);
    m_ag->getObjectGraphic(0)->getAnimation()->setDelay(125);

    ///


    m_fps=0;
    m_clockFps=0;
    m_clock.restart();

    m_viewActivated=false;
}


void Core::update()
{
    //MaJ données
    m_ag->sortObj();
    m_ag->getArea()->update();
    //MaJ Graphique
    m_ag->update();


    if(time(NULL)-m_clockFps>=1)
    {
        m_window->setTitle(Global::intToStr(m_fps)+" fps");

        m_clockFps=time(NULL);
    }

    m_graphic->update();
}

void Core::lookAtControl()
{


}

void Core::draw()
{
     m_window->clear(Color(4,139,154));
     m_graphic->drawVisibleArea(m_ag);
     m_graphic->drawObjects(m_ag);
}




void Core::run()
{
    bool viewMoovement[4]; ///Bool pour le contrôle de la view
    for(int i(0);i<4;i++){viewMoovement[i]=false;}


    while (m_window->isOpen())
    {
        m_clock.restart();

        while(m_window->pollEvent(*m_controller->getEvent()))
        {
            switch(m_controller->getEvent()->type)
            {

                case Event::Closed:
                    m_window->close();
                    break;

                case Event::KeyPressed:

                    switch((*m_controller->getEvent() ).key.code)
                    {

                        case Keyboard::Escape:
                            m_window->close();
                            break;

                        case Keyboard::Space:


                            break;


                        /**
                        La suite sert temporairement à tester la vue. CdC- ID 001 (Dropbox)
                            Concrètement, appuyer sur V inverse la présence d'une vue et les flèches dirigent.
                        **/
                         /// Ouvre avec le '+' à gauche si nécessaire.

                        case Keyboard::V:

                            m_viewActivated=!m_viewActivated;
                            m_graphic->enableView(m_viewActivated);
                            break;

                        case Keyboard::Right:
                            viewMoovement[RIGHT]=true;
                            break;

                        case Keyboard::Left:
                            viewMoovement[LEFT]=true;
                            break;

                        case Keyboard::Up:
                            viewMoovement[UP]=true;
                            break;

                        case Keyboard::Down:
                            viewMoovement[DOWN]=true;
                            break;


                        default:
                            break;
                    }break;



                case Event::KeyReleased:

                    switch(( *m_controller->getEvent() ).key.code)
                    {
                        case Keyboard::Right:
                            viewMoovement[RIGHT]=false;
                            break;

                        case Keyboard::Left:
                            viewMoovement[LEFT]=false;
                            break;

                        case Keyboard::Up:
                            viewMoovement[UP]=false;
                            break;

                        case Keyboard::Down:
                            viewMoovement[DOWN]=false;
                            break;

                        default:
                            break;
                        }

                        default:
                            break;
                    }
                    break;



            }

        lookAtControl();

        ///View Update
        if(viewMoovement[RIGHT]){m_graphic->moveViewRight(0.5);}
        if(viewMoovement[UP]){m_graphic->moveViewUp(0.5);}
        if(viewMoovement[LEFT]){m_graphic->moveViewLeft(0.5);}
        if(viewMoovement[DOWN]){m_graphic->moveViewDown(0.5);}
        else{}
        ///

        draw();
        update();
        m_window->display();


        ///fps
        if(m_clock.getElapsedTime().asMilliseconds() != 0) m_fps= 1000/m_clock.getElapsedTime().asMilliseconds();
        ///
    }
}

Core::~Core()
{
    delete m_ag;delete m_a;//test area
    delete m_graphic;
    delete m_controller;
}
