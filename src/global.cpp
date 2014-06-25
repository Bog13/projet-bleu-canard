#include "global.h"

Global::Global()
{

}


int Global::FPS=-1;
const string Global::PATH="data/img/";

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

void Global::clearConsole()
{
    #ifdef WIN32
        system("cls");
    #else
        system("clear");
    #endif

}

string Global::loadingString(int i,int N)
{

    string load="";
    string percent="    ";
    int sizeOfLoading=20;

    string loading="";

    int n= (int)( sizeOfLoading*((float)i)/((float)N) );

    //anim horloge
    loading+="LOADING... ";
    if(time(NULL)%4==0)loading+="_o_";
    else if(time(NULL)%4==1)loading+="\\o/";
    else if(time(NULL)%4==2)loading+="|o| *clap*";
    else loading+="\\o/";
    //

    loading +="\n\n";

    for(int k=0;k<sizeOfLoading+2;k++)   loading+='-';
    loading+='\n';

    loading+='|';

    for(int k=0;k<sizeOfLoading;k++)load+=' ';
    for(int k=0;k<n;k++)load[k]='|';

    percent=intToStr( (int)( 100*((float)i)/((float)N) ) ) + "%";

    for(int k=(sizeOfLoading>>1)-2;k<(sizeOfLoading>>1)+2;k++) load[k]=percent[k - ((sizeOfLoading>>1)-2)];



    loading+=load+"|\n";

    for(int k=0;k<sizeOfLoading+2;k++)    loading+='-';
    loading+='\n';

    return loading;


}
int Global:: sizeWithoutSpace(string str)
{
    int strSize=0;
    for(int i=0;i<(int)(str.size());i++)if(str[i]!=' ')strSize++;
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
    return !(Ay>Bh || Ah<By || Aw<Bx || Ax>Bw);


}

Global::~Global()
{

}
