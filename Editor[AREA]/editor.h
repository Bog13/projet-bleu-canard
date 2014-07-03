#ifndef EDITOR_H
#define EDITOR_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include"../include/global.h"
#include "../include/graphics.h"
#include "../include/areafactory.h"



using namespace std;
using namespace sf;


class Editor
{
    public:
        Editor(RenderWindow* window);

        void modifyTile(Vector2f pos, int id);
        const void draw();
        const void drawMenu();
        const void drawArea();
        void zoom(float f);
        const void saveCurrentArea(string name);
        const void loadArea(string name);

        void update(Vector2i mouseWindowPosition,bool interact);
        void updateMenu();
        void updateMouse(Vector2i mouseWindowPosition);
        inline Camera* getCamera() {return m_graphics->getCamera();}
        void synchroniseTiles();
        virtual ~Editor();

    private:
        RenderWindow* m_window;

        Area* m_currentArea;            ///Area sur laquelle on bosse
        AreaGraphic* m_ag;              ///L'apparence qui en découle
        Graphics* m_graphics;           ///L'outils qui affiche le tout ( ou presque, voir drawVisibleArea )
       // vector<EntityGraphic> m_vector; ///Stockage des 11 tiles différentes

        Vector2i m_mouseWindowPosition; ///Position de la souris depuis le Haut gauche de la fenetre
        Vector2f m_mouseMenuPosition;   ///Position de la souris depuis la view menu (en bas)
        Vector2f m_mouseGlobalPosition; ///Position de la souris depuis le hautgauche du MONDE ( absolu )

        bool m_isTheMouseInTheMenu;     ///Parle de lui-même, sert à savoir quoi faire si vrai ou faux
        int m_currentModifer;           ///Indice de la tile qui serait crée par un clique
        pair<float,float> m_viewCenter;

};

#endif // EDITOR_H
