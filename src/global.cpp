#include "global.h"

Global::Global()
{

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

Global::~Global()
{

}
