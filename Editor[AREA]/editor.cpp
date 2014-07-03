#include "editor.h"
/*
 public:






        void update(Vector2i mouseWindowPosition,bool interact);
        void synchroniseTiles();
        virtual ~Editor();

    private:
        RenderWindow* m_window;

        Area* m_currentArea;            ///Area sur laquelle on bosse
        AreaGraphic* m_ag;              ///L'apparence qui en découle
        Graphics* m_graphics;           ///L'outils qui affiche le tout ( ou presque, voir drawVisibleArea )
     negligé   vector<EntityGraphic> m_vector; ///Stockage des 11 tiles différentes

        Vector2i m_mouseWindowPosition; ///Position de la souris depuis le Haut gauche de la fenetre
        Vector2f m_mouseMenuPosition;   ///Position de la souris depuis la view menu (en bas)
        Vector2f m_mouseGlobalPosition; ///Position de la souris depuis le hautgauche du MONDE ( absolu )

        View* m_mainView;               ///Vue de l'area
        View* m_menuView;               ///Vue du menu

        bool m_isTheMouseInTheMenu;     ///Parle de lui-même, sert à savoir quoi faire si vrai ou faux
        int m_currentModifer;           ///Indice de la tile qui serait crée par un clique
*/
Editor::Editor(RenderWindow* window)
{
    ///INITIALISATION
    m_window=window;
    m_currentArea=new Area(20,20);
    m_ag=new AreaGraphic(m_currentArea);
    m_graphics=new Graphics(m_window,m_ag);
    m_viewCenter=pair<float,float>(0,0);

    m_mouseWindowPosition=Vector2i(0,0); ///Position de la souris depuis le Haut gauche de la fenetre
    m_mouseMenuPosition=Vector2f(0,0);   ///Position de la souris depuis la view menu (en bas)
    m_mouseGlobalPosition=Vector2f(0,0); ///Position de la souris depuis le hautgauche du MONDE ( absolu )

    m_isTheMouseInTheMenu=false;     ///Parle de lui-même, sert à savoir quoi faire si vrai ou faux
    m_currentModifer=0;           ///Indice de la tile qui serait crée par un clique

    ///SETTINGS
    m_graphics->enableCamera(true);
    m_graphics->getCamera()->setTarget(new Positionable(m_currentArea,m_viewCenter));
}

void Editor::modifyTile(Vector2f pos, int id)
{
    if(m_currentArea->modifyTile(Global::toTileWidth(pos.x),Global::toTileHeight(pos.y),id))
    {
    }else {cerr<<"Veuillez cliquer dans la zone."<<endl;}
}

void Editor::zoom(float f)
{
    m_graphics->getCamera()->zoom(f);
}


const void Editor::saveCurrentArea(string name)
{
    AreaFactory::saveArea(m_currentArea, name);
}
const void Editor::loadArea(string name)
{
    AreaFactory::loadArea(m_currentArea,name);
}

const void Editor::draw()
// TODO (j0sh-u_a#4#): Affichage du menu
{
    ///Mainview
        //m_window->setView(*m_mainView);
        m_graphics->drawVisibleArea();
        m_graphics->drawObjects();

    ///Menuview
       // m_window->setView(*m_menuView);
        drawMenu();
}


void Editor::synchroniseTiles()
{
    m_ag->synchroniseTiles(0);
}

const void Editor::drawMenu()
{
    /*for(int i(0);i<Global::NB_TOTAL_TILE;i++)
    {
        EntityGraphic e= TileFactory::get(i);
        e.getConvexShape()->setPosition(i*Global::TILE_WIDTH,0);
        m_graphics->drawEntity(&e);
    }*/
}

const void Editor::drawArea()
{
    m_graphics->drawVisibleArea();
}


void Editor::updateMouse(Vector2i mouseWindowPosition)
{
    ///Actualisation de la position de la souris
    m_mouseWindowPosition=mouseWindowPosition;
    m_mouseMenuPosition=m_window->mapPixelToCoords(m_mouseWindowPosition,*m_graphics->getCamera()->getView());
    m_mouseGlobalPosition=m_window->mapPixelToCoords(m_mouseWindowPosition,*m_graphics->getCamera()->getView());
}

void Editor::updateMenu()
///OBSOLETE!
{
    //for(int i(0);i<m_vector.size();i++){m_vector[i].update();} ///Affiche les animations en bas
}

void Editor::update(Vector2i mouseWindowPosition,bool interact)
/**
    Globalement:
        * la position de la souris est actualisée
        * la vue est supposée bougée mais j'ai remarqué que les bool étaient inversés, à comprendre.
        * Modification de l'area si clique activé
**/
{
    m_ag->updateTiles();
    m_graphics->update();
    updateMouse(mouseWindowPosition);
    updateMenu();///NON

    ///Est-elle dans le menu ?
     if(m_mouseWindowPosition.y>m_window->getSize().y*0.88){m_isTheMouseInTheMenu=true;} //0.88 c'est précis hein ? :p J'ai pas trouvé mieux pour le moment.
            else m_isTheMouseInTheMenu=false;

    ///Elle clique
        ///dans le monde donc on modifie
    if(interact && m_isTheMouseInTheMenu==false) {modifyTile(m_mouseGlobalPosition, m_currentModifer);}

        ///dans le menu donc on sélectionne.
    else if(interact && m_isTheMouseInTheMenu)
    {
// TODO (j0sh-u_a#2#): Afficher le menu sur plusieurs lignes
        int clue=int(Global::toTileWidth(m_mouseMenuPosition.x));

        cout <<"clue = " << clue << endl; ///Assurance de la tile qu'on a en ce moment
        if(clue<=Global::NB_TOTAL_TILE){m_currentModifer=clue;}
            else {cerr << " Warning, trying to modify with error value" << endl;}
    }

}




Editor::~Editor()

{
    delete m_currentArea;
    delete m_ag;
    delete m_graphics;

}
