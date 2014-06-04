#include "global.h"

Global::Global()
{

}

string Global::intToStr(int n)
{
    ostringstream oss;
    oss<<n;
    return oss.str();
}

Global::~Global()
{

}
