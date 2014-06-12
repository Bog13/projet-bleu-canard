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

        void Modify(Vector2f pos, int id);
        const void draw();
        const void drawMenu();
        const void DrawArea();
        void zoom(float f){m_mainView->zoom(f);}
        const void SaveCurrentArea(string name);
        const void LoadArea(string name);
        void Update(Vector2i mouseWindowPosition,bool interact);
        void moveView(float x,float y);
        void synchroniseTiles();
        virtual ~Editor();
    protected:
        RenderWindow* m_window;

        Area* m_currentArea;            ///Area sur laquelle on bosse
        AreaGraphic* m_ag;              ///L'apparence qui en d�coule
        Graphics* m_graphics;           ///L'outils qui affiche le tout ( ou presque, voir drawVisibleArea )
        vector<EntityGraphic> m_vector; ///Stockage des 11 tiles diff�rentes

        Vector2i m_mouseWindowPosition; ///Position de la souris depuis le Haut gauche de la fenetre
        Vector2f m_mouseMenuPosition;   ///Position de la souris depuis la view menu (en bas)
        Vector2f m_mouseGlobalPosition; ///Position de la souris depuis le hautgauche du MONDE ( absolu )

        View* m_mainView;               ///Vue de l'area
        View* m_menuView;               ///Vue du menu

        bool m_isTheMouseInTheMenu;     ///Parle de lui-m�me, sert � savoir quoi faire si vrai ou faux
        int m_currentModifer;           ///Indice de la tile qui serait cr�e par un clique
    private:
};

#endif // EDITOR_H
