#include "global.h"

Global::Global()
{

}




int const Global::ID[]=
{
    TILE_NONE,
    HIGHT_GRASS,
    HIGHT_GRASS_tGROUND_1,
    HIGHT_GRASS_tGROUND_2,
    HIGHT_GRASS_tGROUND_3,
    HIGHT_GRASS_tGROUND_4,
    DESERT,
    SNOW,
    CHAR_NONE
};

int const Global::NB_FRAME_ID[]=
{
    1,
    4,
    1,
    1,
    1,
    1,
    7,
    1,
    3
};
  /*static const int NB_STATE_NONE=0;
        static const int NB_STATE_HIGHT_GRASS=4;
        static const int NB_STATE_HIGHT_GRASS_tGROUND=4; //
        static const int NB_STATE_DESERT=7;
        static const int NB_STATE_SNOW=5;   //
        static const int NB_STATE_CHAR_NONE=6;*/


bool Global::isInTheRect(float xTarget,float yTarget,float x,float y,float w,float h)
{
    if(xTarget>=x && xTarget<=x+w
     &&yTarget>=y && yTarget<=y+h )
    {
        return true;
    }
    return false;
}


int Global:: sizeWithoutSpace(string str)
{
    int strSize=0;
    for(int i=0;i<str.size();i++)if(str[i]!=' ')strSize++;
    return strSize;
}

string Global::intToStr(int n)
{
    ostringstream oss;
    oss<<n;
    return oss.str();
}

int Global::strToInt(string str)
{
    istringstream iss(str);
    int n;
    iss>>n;
    return n;
}

bool Global::strToBool(string str)
{
    istringstream iss(str);
    bool b;
    iss>>b;
    return b;
}


template <class T> T Global::strTo(string str)
{
    istringstream iss(str);
    T t;
    iss>>t;
    return t;
}

float Global::strToFloat(string str)
{
    istringstream iss(str);
    float f;
    iss>>f;
    return f;
}

Global::~Global()
{

}
