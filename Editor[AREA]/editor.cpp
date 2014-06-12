#include "editor.h"


Editor::Editor(RenderWindow* window)
{

    m_window=window;
    ///Members
        //data
    m_currentArea= new Area(25,25);
    m_ag= new AreaGraphic(m_currentArea);
    m_graphics= new Graphics(m_window);
        //tools
    m_mouseWindowPosition=Vector2i(0,0);
    m_mouseMenuPosition=Vector2f(0,0);
    m_isTheMouseInTheMenu=false;
    m_currentModifer=0;
        //graphics
    ///view
    m_mainView=m_graphics->getView();
    m_mainView->setViewport(FloatRect(0,0,1,0.88));

    m_menuView=new View(FloatRect(0,0,Global::TILE_WIDTH*Global::NB_TOTAL_TILE,Global::TILE_WIDTH*10));

    m_menuView->setViewport(FloatRect(0,0.88f,1,1));



    ///Remplissage du vector possèdant les différentes tiles. Peut surement être supprimé.
    /// A la base il devait surtout stoquer des positions pour savoir quelle tile sélectionner.
    for(int i(0);i<Global::NB_TOTAL_TILE;i++)
        {m_vector.push_back(TileFactory::get(i));}
}

void Editor::Modify(Vector2f pos, int id)
/**
    Modifie une tile précise de l'area. Utilise en général la position de la souris d'où l'usage d'un Vector2f
**/
{
    //position absolue
    float   x=pos.x,
            y=pos.y;
    //position dans un tableau de tile
    int x_tile=int(x/Global::TILE_WIDTH),
        y_tile=int(y/Global::TILE_HEIGHT);

    //Si est dans la zone
    if( m_currentArea->in(x_tile,y_tile) )
    {
        m_currentArea->modifyTile(x_tile,y_tile,id);
        m_ag->getTileGraphic(x_tile,y_tile)->setGraphicalType(id);
        synchroniseTiles();
    }


}

void Editor::synchroniseTiles()
{
    m_ag->synchroniseTiles(0);
}

const void Editor::draw()
/**
    Regroupement de tous les draw.
    Rappel:
        Pour chaque view il faut dessiner quelque chose.
        Tout ce qui est dessiner après un SetView() sera situé sur la vue en arguement.
**/
{

        ///Mainview
        m_window->setView(*m_mainView);
        m_graphics->drawVisibleArea(m_ag);
        m_graphics->drawObjects(m_ag);

        ///Menuview
        m_window->setView(*m_menuView);
        drawMenu();

}

const void Editor::drawMenu()
/**
    Methode explicite par son nom.
    A la ligne marquée il y aura tôt ou tard un problème avec la variation de Global::NB_TOTAL_TILE.
    De plus, je précise que le vector<Entity> est peut-être optimisable en pointeur, j'ai failli.

**/
{
    for(int i(0);i<m_vector.size();i++)
    {
        m_vector[i].getConvexShape()->setPosition(i*Global::TILE_WIDTH,5); /// A revoir prochainement
        m_graphics->drawEntity(&m_vector[i]);
    }


}

void Editor::moveView(float x,float y)
{
    m_mainView->move(x,y);
}


void Editor::Update(Vector2i mouseWindowPosition,bool interact)
/**
    Globalement:
        * la position de la souris est actualisée
        * la vue est supposée bougée mais j'ai remarqué que les bool étaient inversés, à comprendre.
        * Modification de l'area si clique activé
**/
{


    //m_mainView->move(movingLeft*-0.5,movingUp*-0.5); fonctionne surement mais pas avec les bool actuels

    ///Actualisation de la position de la souris
    m_mouseWindowPosition=mouseWindowPosition;
    m_mouseMenuPosition=m_window->mapPixelToCoords(m_mouseWindowPosition,*m_menuView);
    m_mouseGlobalPosition=m_window->mapPixelToCoords(m_mouseWindowPosition,*m_mainView);

    ///Est-elle dans le menu ?
     if(m_mouseWindowPosition.y>m_window->getSize().y*0.88){m_isTheMouseInTheMenu=true;} //0.88 c'est précis hein ? :p J'ai pas trouvé mieux pour le moment.
            else m_isTheMouseInTheMenu=false;

    ///Elle clique
        //dans le monde donc on modifie
    if(interact && m_isTheMouseInTheMenu==false) {Modify(m_mouseGlobalPosition, m_currentModifer);}

        //dans le menu donc on sélectionne.
    else if(interact && m_isTheMouseInTheMenu)
    {

        int clue=int(m_mouseMenuPosition.x/Global::TILE_WIDTH);
            ///Ca va probablement faire chier quand il y aura trop de tile
            ///Faudra penser à faire une seconde ligne pour garder Global::TILE_WIDHT (c'était mon idée de base)

        cout <<"clue = " << clue << endl; ///Assurance de la tile qu'on a en ce moment
        if(clue<=Global::NB_TOTAL_TILE){m_currentModifer=clue;}
            else {cerr << " Warning, trying to modify out of the area's borders." << endl;}
    }



    for(int i(0);i<m_vector.size();i++){m_vector[i].update();} ///Affiche les animations en bas

    ///actualisation de la view Graphics
    m_ag->updateTiles();


}




const void Editor::DrawArea()
///Explicite, précisons que l'on parle de l'area membre.
{
    m_graphics->drawArea(m_ag);
}




const void Editor::SaveCurrentArea(string name)
/**
    Merci pour ce gain de temps :3
**/
{
    AreaFactory::saveArea(m_currentArea, name);
}

const void Editor::LoadArea(string name)
/**
     Re-merci...
**/
{
    m_currentArea=new Area(0,0);
    AreaFactory::loadArea(m_currentArea, name);
    m_ag=new AreaGraphic(m_currentArea);

}


Editor::~Editor()
/**
   Normalement y'a tout !
**/
{
    delete m_currentArea;
    delete m_ag;
    delete m_graphics;

}
