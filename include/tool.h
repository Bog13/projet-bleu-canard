#ifndef TOOL_H
#define TOOL_H
#include <iostream>
#include <utility>
#include <string>
#include <fstream>
#include <cmaths>

/*
    Contient les méthodes générales (sauvegarder dans un fichier par ex)
*/

class Tool
{
    public:
        Tool();

        static std::pair<int,int> toIso(int x,int y);
        std::pair<int,int> toInvIso(int x,int y);
        static const void Save(std::string name, std::string text);




        virtual ~Tool();
    protected:

    private:
};

#endif // TOOL_H
