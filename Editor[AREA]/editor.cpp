#include "editor.h"


Editor::Editor(RenderWindow* window)
{
    m_window=window;
    m_currentArea= new Area(10,10);
    m_ag= new AreaGraphic(m_currentArea);
    m_graphics= new Graphics(m_window);
}

void Editor::Modify(Vector2i pos, int id)
{
    float   x=pos.x,
            y=pos.y;
    int x_tile=int(x/Global::TILE_WIDTH),
        y_tile=int(y/Global::TILE_HEIGHT);

    m_currentArea->modifyTile(x_tile,y_tile,id);
    m_currentArea->getInfo();
    m_ag->getInfo();



}

const void Editor::Draw()
{
    m_ag->update();
    m_graphics->drawArea(m_ag);
}

Editor::~Editor()
{
    //dtor
}
