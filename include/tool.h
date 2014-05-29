#ifndef TOOL_H
#define TOOL_H
#include <iostream>
#include <utility>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include "../include/Global.h"


/*
    Contient les méthodes générales (sauvegarder dans un fichier par ex)
*/

class Tool
{
    public:
        Tool();
        static std::pair<float,float>   toIso(float x,float y);
        static std::pair<float,float>   toInvIso(float x,float y);
        static std::pair<float,float>   toOrtho(float x,float y);
        static float                    toOrthoX(float x);
        static float                    toOrthoY(float y);
        static const void Save(std::string name, std::string text);
        static std::string Load(std::string name);




        virtual ~Tool();
    protected:

    private:
};

#endif // TOOL_H
