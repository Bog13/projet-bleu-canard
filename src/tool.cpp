#include "../include/tool.h"

Tool::Tool()
{
    //ctor
}

std::pair<int,int> Tool::toIso(int x,int y)
{
    std::pair<int,int> iso;
    int i=0;
    int j=0;

    i=x;
    j=y;

    iso.first=i;
    iso.second=j;
    return iso;
}

Tool::~Tool()
{
    //dtor
}
