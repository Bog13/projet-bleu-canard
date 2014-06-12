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
        Editor(RenderWindow* window, View* mainView, View* menuView);

        void Modify(Vector2f pos, int id);
        const void draw();
        const void drawMenu();
        const void DrawArea();
        const void DrawVisibleArea();
        //const area* GetArea() {return m_currentArea;} Pas utile, encore.
        const void SaveCurrentArea(string name);
        const void LoadArea(string name);
        void Update(Vector2i mouseWindowPosition,bool interact, bool movingRight, bool movingLeft, bool movingUp, bool movingDown);
        void synchroniseTiles();
        virtual ~Editor();
    protected:
        RenderWindow* m_window;

        Area* m_currentArea;            ///Area sur laquelle on bosse
        AreaGraphic* m_ag;              ///L'apparence qui en découle
        Graphics* m_graphics;           ///L'outils qui affiche le tout ( ou presque, voir drawVisibleArea )
        vector<EntityGraphic> m_vector; ///Stockage des 11 tiles différentes

        Vector2i m_mouseWindowPosition; ///Position de la souris depuis le Haut gauche de la fenetre
        Vector2f m_mouseMenuPosition;   ///Position de la souris depuis la view menu (en bas)
        Vector2f m_mouseGlobalPosition; ///Position de la souris depuis le hautgauche du MONDE ( absolu )

        View* m_mainView;               ///Vue de l'area
        View* m_menuView;               ///Vue du menu

        bool m_isTheMouseInTheMenu;     ///Parle de lui-même, sert à savoir quoi faire si vrai ou faux
        int m_currentModifer;           ///Indice de la tile qui serait crée par un clique
    private:
};

#endif // EDITOR_H
