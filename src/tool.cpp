#include "../include/tool.h"

Tool::Tool()
{
    //ctor
}

std::pair<int,int> Tool::toIso(int x,int y)
{
    std::pair<int,int> iso;
    float demiSqrDeux= sqrt(2)/2;
    float demi = 0.5;

    float xRes= demiSqrDeux*x+demiSqrDeux*y;
    float yRes= demi*(x-y);

    iso.first=xRes;
    iso.second=yRes;
    return iso;
}

std::pair<int,int> Tool::toInvIso(int x,int y)
{
    std::pair<int,int> iso;
    float demiSqrDeux= sqrt(2)/2;

    float xRes= demiSqrDeux*x-y;
    float yRes= demiSqrDeux*x+y;

    iso.first=xRes;
    iso.second=yRes;
    return iso;
}

const void Tool::Save(std::string name,std::string text)
{
    std::fstream writter(name.c_str(),std::ios::out);
    if(!writter) {std::cout<<"There was a problem writting the " << name << " file." << std::endl;}
        {
            writter<<text;
        }
    writter.close();
}



Tool::~Tool()
{
    //dtor
}
