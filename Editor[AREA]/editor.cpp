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


    if( m_currentArea->in(x_tile,y_tile) )
    {
        m_currentArea->modifyTile(x_tile,y_tile,id);
        m_ag->getTileGraphic(x_tile,y_tile)->setGraphicalType(id);
    }


}
void Editor::Update()
{
    m_ag->update();
}

const void Editor::Draw()
{

    m_graphics->drawArea(m_ag);
}

Editor::~Editor()
{
    delete m_currentArea;
    delete m_ag;
    delete m_graphics;
}
