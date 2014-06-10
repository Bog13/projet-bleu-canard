#include "global.h"

Global::Global()
{

}

bool Global::isInTheRect(float xTarget,float yTarget,float x,float y,float w,float h)
{
    if(xTarget>=x && xTarget<=x+w
     &&yTarget>=y && yTarget<=y+h )
    {
        return true;
    }
    return false;
}

    int Global::GET_ID_CHAR(int id)
    {
        return ID_CHAR_NONE+id;
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
