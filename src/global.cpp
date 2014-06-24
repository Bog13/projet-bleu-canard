#include "global.h"

Global::Global()
{

}


int Global::FPS=-1;

int const Global::ID[]=
/// Création de texture 3:AJOUTER LE NOM ICI (4 plus bas)
{
    TILE_NONE,
    HIGHT_GRASS,
    HIGHT_GRASS_tGROUND_1,
    HIGHT_GRASS_tGROUND_2,
    HIGHT_GRASS_tGROUND_3,
    HIGHT_GRASS_tGROUND_4,
    DESERT,
    SNOW,
    FLOOR_WOOD,
    FLOOR_PAVEMENT,
    PINE_TREE,
    CHAR_NONE
};

int const Global::NB_FRAME_ID[]=
///Création de texture 4: AJOUTER LES FRAMES (5 dans Texturefactory)
{
    1,
    4,
    1,
    1,
    1,
    1,
    7,
    1,
    1,
    1,
    8,
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

bool Global::inCollision(float Ax,float Ay, float Aw, float Ah,float Bx,float By, float Bw, float Bh)
{
    float Au=Ay,
    Ad=Ay+Au,
    Al=Ax,
    Ar=Ax+Aw;

    float Bu=By,
    Bd=By+Bu,
    Bl=Bx,
    Br=Bx+Bw;

    return !(Ay>Bh || Ah<By || Aw<Bx || Ax>Bw);


}

Global::~Global()
{

}
